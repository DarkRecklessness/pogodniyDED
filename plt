# importing the library
import time

import numpy as np
import matplotlib.pyplot as plt
from random import randint as rn

# data to be plotted
mas, mas_2 = [], []
xxx_inside = xxx_outside = 20
def graf():
    # if len(mas) < 30:
    #     mas.append(rn(1, 100))
    #     graf()
    #     return
    global xxx_inside, xxx_outside

    xxx_inside += min(rn(-5, 5), 30)
    xxx_outside += min(rn(-5, 5), 30)
    b,c=0,0
    with open("web/data.txt", 'w') as file:
        #data = list(map(int, file.readlines()))
        #data[0] = xxx
        data = [xxx_inside,xxx_outside,b,c]
        for i in data: file.write(f'{i}\n')
    mas.append(xxx_inside)
    mas_2.append(xxx_outside)
    if len(mas) >= 30:
        mas.pop(0)
        mas_2.pop(0)


    x_inside = np.arange(1, len(mas)+1)
    y_inside = np.array(mas)
    x_outside = np.arange(1, len(mas_2)+1)
    y_outside = np.array(mas_2)

    plt.title("Line graph") # Секунда X
    plt.xlabel("123")
    plt.xlabel("TIME")
    plt.ylabel("TEMP")
    plt.plot(x_inside, y_inside, color="red")
    plt.plot(x_outside, y_outside, color="blue")
    plt.savefig('web/graph.jpg')
    plt.close()

while 1:
    graf()
    time.sleep(1)
