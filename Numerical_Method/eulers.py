import numpy as np
import matplotlib.pyplot as plt



def euler_method(f, y0, x0, x_end, h):
    n = int((x_end - x0) / h)
    x_values = [x0]
    y_values = [y0]

    for i in range(n):
        y0 += h * f(x0, y0)
        x0 += h
        x_values.append(x0)
        y_values.append(y0)

    return x_values, y_values

def f(x, y):
    return x + y

y0 = 1
x0 = 0
x_end = 2
h = 0.1

x_values, y_values = euler_method(f, y0, x0, x_end, h)

for x, y in zip(x_values, y_values):
    print(f"x: {round(x,2)}, y: {round(y,2)}")


