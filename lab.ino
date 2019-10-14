#include <RadioHead.h>
#include <RHCRC.h>
#include <RHDatagram.h>
#include <RHEncryptedDriver.h>
#include <RHGenericDriver.h>
#include <RHGenericSPI.h>
#include <RHHardwareSPI.h>
#include <RHMesh.h>
#include <RHNRFSPIDriver.h>
#include <RHReliableDatagram.h>
#include <RHRouter.h>
#include <RHSoftwareSPI.h>
#include <RHSPIDriver.h>
#include <RHTcpProtocol.h>
#include <RH_ASK.h>
#include <RH_CC110.h>

#include <SPI.h>
#include <RH_RF95.h>
#include <RH_Serial.h>
#include <RH_TCP.h>

#include <SPI.h>
#include <RH_RF95.h>
// Singleton instance of the radio driver
RH_RF95 rf95;
float frequency = 868.1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) ;
   rf95.setFrequency(frequency);
    // Setup Power,dBm
  rf95.setTxPower(13);

  // Setup Spreading Factor (6 ~ 12)
  rf95.setSpreadingFactor(7);
  
  // Setup BandWidth, option: 7800,10400,15600,20800,31250,41700,62500,125000,250000,500000
  //Lower BandWidth for longer distance.
  rf95.setSignalBandwidth(125000);
  
  // Setup Coding Rate:5(4/5),6(4/6),7(4/7),8(4/8) 
  rf95.setCodingRate4(5);
  

}

unsigned long begin_time;
unsigned long end_time;
int SF;

void loop()
{
  
  
  
  //100 packets for SF = 7
  SF = 7;
  rf95.setSpreadingFactor(SF);
  for(int i=0; i<100; ++i){
  
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
 
  unsigned long ToA = end_time-begin_time;

  Serial.print("soumaya ");
  Serial.print(SF);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }

  //100 packets for SF = 9
  SF = 9;
  rf95.setSpreadingFactor(SF);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
 
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(SF);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  
  }

  //100 packets for SF = 10
  SF = 10;
  rf95.setSpreadingFactor(SF);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
  
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(SF);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }
  

  
  delay(10000);
}
