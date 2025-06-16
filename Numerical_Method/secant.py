import numpy as np
import matplotlib.pyplot as plt

def f(x):
    return np.exp(-x) - x

def secant(x0, x1, tol):
    n = 0
    while True:
        if f(x1) - f(x0) == 0:
            print("Denominator zero, method fails.")
            return None

        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        n += 1

        print(f"Iteration {n}: x = {round(x2,6)}")

        if abs(x2 - x1) < tol:
            print(f"Root of eqn:", x2)
            return x2

        x0, x1 = x1, x2

x0 = 1.0
x1 = 2.0
tol = 0.0001
print("Secant Method for f(x) = exp(-x) - x")
print("Initial guesses: x0 =", x0, ", x1 =", x1)
root = secant(x0, x1, tol)

if root is not None:
    x = np.linspace(0, 3, 100)
    y = f(x)

    plt.plot(x, y, label='f(x) = exp(-x) - x')
    plt.axhline(0, color='black', lw=0.5, ls='--')
    plt.axvline(root, color='red', label=f'Root at x = {round(root, 6)}', ls='--')
    plt.title('Secant Method Visualization')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.legend()
    plt.grid()
    plt.show()
