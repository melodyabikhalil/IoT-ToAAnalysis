import statistics


def make_list(file_name):
    numbers_list = []
    f=open(file_name,"r")
    for line in f:
        numbers_list.append(float(line.strip('\n')))
    f.close()
    return numbers_list

def get_stat(numbers_list):
    return statistics.mean(numbers_list)

def main(parameter, file_name):
    print("Calculating the ToA for "+parameter)
    print("Mean is "+str(get_stat(make_list(file_name))))

#Example:
main("bandwidth","raw_data.txt")
