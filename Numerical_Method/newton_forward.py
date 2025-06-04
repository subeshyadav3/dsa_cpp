import numpy as np
# x = [100,150,200,250,300,350,400]
# y = [10.63,13.03,15.04,16.81,18.42,19.90,21.27]
x = [1, 2, 3, 4, 5]
y = [1, 4, 9, 16, 25]


diff = []
y_copy = y.copy()

def calc_diff(x, y):
    for i in range(len(x)-1):
        temp = []
        for j in range(len(y)-1):
            temp.append(round(y[j+1] - y[j], 2))
        diff.append(temp)
        y = temp

calc_diff(x, y)
print("")
print("")
print("")
print("Input: x =", x)
print("Input: y =", y)

print("Difference Table:", diff)
# xp = 218
xp = 3.5  # should interpolate to about 12.25
h = x[1] - x[0]
p = (xp - x[0]) / h
yp = y_copy[0]
product = 1

for i in range(1, len(y_copy)):
    product *= (p - i + 1) / i
    yp += product * diff[i-1][0]

print("The value of yp: ",round(yp, 4))
print("")
print("")
print("")