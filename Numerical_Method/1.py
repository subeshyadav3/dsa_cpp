import matplotlib.pyplot as plt
import numpy as np

# Define the function
def f(x):
    return x**3 - x - 2

# Initial interval
a = 1
b = 2
tolerance = 0.01

# Store points for graph
intervals = []
midpoints = []

# Bisection method
while abs(b - a) > tolerance:
    c = (a + b) / 2
    intervals.append((a, b))
    midpoints.append(c)
    print("Current interval: [{}, {}], midpoint: {}".format(a, b, c))

    if f(a) * f(c) < 0:
        b = c
    else:
        a = c

# Plotting
x = np.linspace(0, 3, 400)
y = f(x)

plt.plot(x, y, label='f(x)')
plt.axhline(0, color='black', linewidth=0.5)
plt.title("Bisection Method Visualization")
plt.xlabel("x")
plt.ylabel("f(x)")

# Plot interval midpoints
for (a_i, b_i), c_i in zip(intervals, midpoints):
    plt.plot([a_i, b_i], [f(a_i), f(b_i)], 'k--', alpha=0.4)  # interval
    plt.plot(c_i, f(c_i), 'ro')  # midpoint

plt.legend()
plt.grid(True)
plt.show()
