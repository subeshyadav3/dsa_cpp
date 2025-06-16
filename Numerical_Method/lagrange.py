import numpy as np
import matplotlib.pyplot as plt

def lagrange(x_values, y_values, x):
    n = len(x_values)
    result = 0
    for i in range(n):
        term = y_values[i]
        for j in range(n):
            if i != j:
                term *= (x - x_values[j]) / (x_values[i] - x_values[j])
        result += term
    return result

# Test Case 1: Given data (Steam Table approximation)
# x_vals = [20, 22, 40, 42, 60, 62, 80, 82]
# y_vals = [0.903, 0.913, 0.934, 0.944, 0.964, 0.974, 0.994, 1.004]

# x_interpolate = 50  # Test at x = 50

x_vals = [0, np.pi/2, np.pi, 3*np.pi/2, 2*np.pi]
y_vals = [np.sin(x/2) + 5 + np.cos(x) for x in x_vals]
x_interpolate = np.pi / 3  # Test at x = π/3


y_interpolate = lagrange(x_vals, y_vals, x_interpolate)
print(f"Interpolated value at x = {x_interpolate} is y = {y_interpolate}")

x_range = np.linspace(min(x_vals), max(x_vals), 200)
y_range = [lagrange(x_vals, y_vals, x) for x in x_range]

plt.plot(x_range, y_range, label='Lagrange Polynomial Curve', color='blue')
plt.scatter(x_vals, y_vals, color='green', label='Data Points')
plt.scatter(x_interpolate, y_interpolate, marker='X', color='red', s=100, label='Interpolated Point')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Lagrange Interpolation')
plt.legend()
plt.grid()
plt.show()
