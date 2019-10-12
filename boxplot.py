from matplotlib import pyplot as plt
import collections

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

def make_boxplot(parameter, dictio):
    labels, data = dictio.keys(), dictio.values()

    fig, ax1 = plt.subplots()
    fig.canvas.set_window_title(str(parameter)+" boxplot")
    ax1.set_axisbelow(True)
    ax1.set_title('Distribution of ToA for a variation of '+str(parameter))
    ax1.set_xlabel(str(parameter))
    ax1.set_ylabel('ToA')

    plt.boxplot(data)
    plt.xticks(range(1, len(labels) + 1), labels)
    plt.show()

def main(parameter, file_name):
    make_boxplot(parameter, make_dict(file_name))
