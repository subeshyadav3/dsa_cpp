def f(x):
    return x**3-x-2

print("")
print("")
print("")
def bisection(a,b,tol):
    if f(a)*f(b) >= 0:
        print("Invalid Interval, No root in [a,b]")
        return None
    
    while (b-a)/2 > tol:
        c = (a + b) / 2
        print("Current interval: [{}, {}], midpoint: {}".format(a, b, c))
        if f(c) ==0:
            return c
        elif f(a)*f(c) < 0:
                b = c
        else:
                a = c


    return (a + b) / 2

a=1
b=2
print("Input: A = {}, B = {}".format(a, b))
tolerance=0.0001
result = bisection(a, b, tolerance)


print("")

print("Approximate root: ", result)
        
print("")
print("")
print("")



a=2
b=3
print("Input: A = {}, B = {}".format(a, b))

tolerance=0.0001

result = bisection(a, b, tolerance)

print("")
print("Approximate root:", result)


a=1.5
b=2.5
print("Input: A = {}, B = {}".format(a, b))

tolerance=0.0001

result = bisection(a, b, tolerance)

print("")
print("Approximate root:", result)


a=-2
b=0
print("Input: A = {}, B = {}".format(a, b))

tolerance=0.0001

result = bisection(a, b, tolerance)

print("")
print("Approximate root:", result)