import matplotlib.pyplot as plt
import numpy as np

def f(x):
    return x**3 - x - 2

def bisection(a, b, tol):
    if f(a)*f(b) >= 0:
        print("Invalid Interval, No root in [{}, {}]".format(a, b))
        return None

    midpoints = []

    while (b - a) / 2 > tol:
        c = (a + b) / 2
        print("Current interval: [{}, {}], midpoint: {}".format(a, b, c))
        midpoints.append(c)

        if f(c) == 0:
            return c, midpoints
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c

    return (a + b) / 2, midpoints

# --- Interval 1 ---
a = 1
b = 2
print("Input: A = {}, B = {}".format(a, b))
tolerance = 0.0001
result, mids = bisection(a, b, tolerance)
print("\nApproximate root:", result)

# --- Plotting directly (no function) ---
x_vals = np.linspace(a - 1, b + 1, 400)
y_vals = f(x_vals)

plt.figure(figsize=(8, 5))
plt.plot(x_vals, y_vals, label='f(x)')
plt.axhline(0, color='black', linewidth=0.5)

for m in mids:
    plt.plot(m, f(m), 'ro')  # Midpoints

plt.title(f"Bisection Method in [{a}, {b}]")
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()
plt.grid(True)
plt.show()
