import numpy as np
import matplotlib.pyplot as plt

# Data points
x = [1, 2, 3, 4, 5]
y = [1, 4, 9, 16, 25]

diff = []
y_copy = y.copy()

def calc_diff(x, y):
    for i in range(len(x) - 1):
        temp = []
        for j in range(len(y) - 1):
            temp.append(round(y[j + 1] - y[j], 2))
        diff.append(temp)
        y = temp

calc_diff(x, y)

print("\n\nInput: x =", x)
print("Input: y =", y_copy)
print("Difference Table:", diff)



# Interpolation point
xp = 3.5  # should interpolate to about 12.25
h = x[1] - x[0]
p = (xp - x[0]) / h
yp = y_copy[0]
product = 1

for i in range(1, len(y_copy)):
    product *= (p - i + 1) / i
    yp += product * diff[i - 1][0]

print("The value of yp:", round(yp, 4))


# ----------------------------
# Plotting
# ----------------------------
x_dense = np.linspace(min(x), max(x), 200)
y_dense = []

for xi in x_dense:
    p_i = (xi - x[0]) / h
    y_i = y_copy[0]
    prod_i = 1
    for i in range(1, len(y_copy)):
        prod_i *= (p_i - i + 1) / i
        y_i += prod_i * diff[i - 1][0]
    y_dense.append(y_i)

plt.figure(figsize=(8, 5))
plt.plot(x, y_copy, 'bo', label='Original Data Points')
plt.plot(x_dense, y_dense, 'g-', label='Interpolated Curve')
plt.plot(xp, yp, 'rX', label=f'Interpolated Value at x={xp}\n≈ {round(yp, 2)}')

plt.title('Newton Forward Interpolation')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid(True)
plt.show()
