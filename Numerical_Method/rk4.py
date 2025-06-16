def rk4_method(f, y0, x0, x_end, h):
    n = int((x_end - x0) / h)
    x_values = [x0]
    y_values = [y0]

    for i in range(n):
        k1 = h * f(x0, y0)
        k2 = h * f(x0 + h / 2, y0 + k1 / 2)
        k3 = h * f(x0 + h / 2, y0 + k2 / 2)
        k4 = h * f(x0 + h, y0 + k3)
        
        y0 += (k1 + 2 * k2 + 2 * k3 + k4) / 6
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

x_values, y_values = rk4_method(f, y0, x0, x_end, h)

for x, y in zip(x_values, y_values):
    print(f"x: {x:.2f}, y: {y:.4f}")
