

def lagrange(x,y,x_lag):
    n=len(x)
    result=0
    for i in range(n):
        term=y[i]
        for j in range(n):
            if i!=j:
                term*=(x_lag-x[j])/(x[i]-x[j])
            result+=term
        return result








x=[20,22,40,42,60,62,80,82]
y=[0.903,0.913,0.934,0.944,0.964,0.974,0.994,1.004]
x_lag= 50
result=lagrange(x,y,x_lag)
