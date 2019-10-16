from matplotlib import pyplot as plt
import collections
from pylab import *

def make_dict(file_name):
    values = {}
    f=open(file_name,"r")
    i = 0
    for line in f:
        i = 0
        while (i<len(line.split())):
            if float(line.split()[0]) not in values:
                values[float(line.split()[0])]=[]
            values[float(line.split()[0])].append(float(line.split()[1]))
            i+=1
    f.close()
    sorted_values = collections.OrderedDict(sorted(values.items()))
    return sorted_values


def get_average_dict(dictio):
    x_list = []
    y_list = []
    for key in dictio.keys():
        cum_sum = 0
        for value in dictio[key]:
            cum_sum += value
        average = cum_sum/len(dictio[key])
        x_list.append(float(key))
        y_list.append(float(average))
    return x_list,y_list


def make_graph(parameter, x_list, y_list):
    fig, ax1 = plt.subplots()
    fig.canvas.set_window_title(str(parameter)+" average graph")
    ax1.set_axisbelow(True)
    ax1.set_title('Average of ToA for a variation of '+str(parameter))
    ax1.set_xlabel(str(parameter))
    ax1.set_ylabel('ToA')
    
    plt.plot(y_list, x_list, 'ro')
    plt.show()

def main(parameter, file_name):
    tuple_xy = get_average_dict(make_dict(file_name))
    print(tuple_xy)
    make_graph(parameter, tuple_xy[1], tuple_xy[0])

#Example:
main("Coding Rate","./CR/CR_data.txt")
