f1 = lambda x,y,z: (5.5-0.5*y-z)/2
f2 = lambda x,y,z: (7.2-2*x-0.2*z)/2
f3 = lambda x,y,z: (5.2-0.1*x-2*y)/3

x0 = 0
y0 = 0
z0 = 0

itter = int(input("Number of itteration: "))

print('\nCount\tx\ty\tz\n')

for i in range(itter):
    x1 = f1(x0,y0,z0)
    y1 = f2(x1,y0,z0)
    z1 = f3(x1,y1,z0)
    print('%d\t%0.4f\t%0.4f\t%0.4f\n' %(i+1, x1,y1,z1))

    x0 = x1
    y0 = y1
    z0 = z1