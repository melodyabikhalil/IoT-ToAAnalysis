// rf95_client.pde
// Preferably Mega
// -*- mode: C++ -*-
// Example sketch showing how to create a simple messageing client
// with the RH_RF95 class. RH_RF95 class does not provide for addressing or
// reliability, so you should only use RH_RF95 if you do not need the higher
// level messaging abilities.
// It is designed to work with the other example rf95_server
// Tested with Anarduino MiniWirelessLoRa, Rocket Scream Mini Ultra Pro with the RFM95W

#include <SPI.h>
#include <RH_RF95.h>


// Singleton instance of the radio driver
RH_RF95 rf95;
//RH_RF95 driver(5, 2); // Rocket Scream Mini Ultra Pro with the RFM95W

// Need this on Arduino Zero with SerialUSB port (eg RocketScream Mini Ultra Pro)
//#define Serial SerialUSB

//The parameter are pre-set for 868Mhz used. If user want to use lower frenqucy 433Mhz.Better to set 
//rf95.setSignalBandwidth(31250);
//rf95.setCodingRate4(8);
float frequency = 868.1;

void setup()
{
  // Rocket Scream Mini Ultra Pro with the RFM95W only:
  // Ensure serial flash is not interfering with radio communication on SPI bus
  //  pinMode(4, OUTPUT);
  //  digitalWrite(4, HIGH);

  Serial.begin(115200);
  while (!Serial) ; // Wait for serial port to be available
  //Serial.println("initialization");
  if (!rf95.init())
    //Serial.println("init failed");
  // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on

  // The default transmitter power is 13dBm, using PA_BOOST.
  // If you are using RFM95/96/97/98 modules which uses the PA_BOOST transmitter pin, then
  // you can set transmitter powers from 5 to 23 dBm:
  //  driver.setTxPower(23, false);
  // If you are using Modtronix inAir4 or inAir9,or any other module which uses the
  // transmitter RFO pins and not the PA_BOOST pins
  // then you can configure the power transmitter power for -1 to 14 dBm and with useRFO true.
  // Failure to do that will result in extremely low transmit powers.
  //  driver.setTxPower(14, true);

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
  
  /*
  //Different Combination for distance and speed examples: 
  Example 1: Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on. Default medium range
    rf95.setSignalBandwidth(125000);
    rf95.setCodingRate4(5);
    rf95.setSpreadingFactor(7);
  Example 2: Bw = 500 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on. Fast+short range
    rf95.setSignalBandwidth(500000);
    rf95.setCodingRate4(5);
    rf95.setSpreadingFactor(7);
  Example 3: Bw = 31.25 kHz, Cr = 4/8, Sf = 512chips/symbol, CRC on. Slow+long range
    rf95.setSignalBandwidth(31250);
    rf95.setCodingRate4(8);
    rf95.setSpreadingFactor(9);
  Example 4: Bw = 125 kHz, Cr = 4/8, Sf = 4096chips/symbol, CRC on. Slow+long range
    rf95.setSignalBandwidth(125000);
    rf95.setCodingRate4(8);
    rf95.setSpreadingFactor(12); 
  */
}
unsigned long begin_time;
unsigned long end_time;
int long BW;

void loop()
{
  
  
  
  //100 packets for BW = 125000
  BW = 125000;
  rf95.setSignalBandwidth(125000);
  for(int i=0; i<100; ++i){
  
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
 
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(BW);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }

  //100 packets for BW = 7800
  BW = 7800;
  rf95.setSignalBandwidth(7800);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
 
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(BW);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  
  }

  //100 packets for BW = 10400
  BW = 10400;
  rf95.setSignalBandwidth(10400);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
  
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(BW);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }

  //100 packets for BW = 15600
  BW = 15600;
  rf95.setSignalBandwidth(15600);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
  
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(BW);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }

  //100 packets for BW = 20800
  BW = 20800;
  rf95.setSignalBandwidth(20800);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
  
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(BW);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }

   //100 packets for BW = 31250
  BW = 31250;
  rf95.setSignalBandwidth(31250);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
  
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(BW);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }

  //100 packets for BW = 41700
  BW = 41700;
  rf95.setSignalBandwidth(41700);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
  
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(BW);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }
  //100 packets for BW = 62500
  BW = 62500;
  rf95.setSignalBandwidth(62500);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
  
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(BW);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }

  //100 packets for BW = 250000
  BW = 250000;
  rf95.setSignalBandwidth(250000);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
  
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(BW);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }

   //100 packets for BW = 500000
  BW = 500000;
  rf95.setSignalBandwidth(500000);
  for(int i=0; i<100; ++i){
 
  uint8_t data[] = "Hi, from Soumaya!";
  
  rf95.send(data, sizeof(data));
  begin_time=micros();
  rf95.waitPacketSent();
  end_time=micros();
  
  unsigned long ToA = end_time-begin_time;
  
  Serial.print(BW);
  Serial.print(" ");
  Serial.print(ToA);
  Serial.println("");
  }
  

  
 
}
