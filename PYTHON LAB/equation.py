#equation
print("Meet Raut    S21     2201084")
print("*-*-*-* MENU *-*-*-*")
print("1. x^2+2xy+y^2  2. x^3+xyz+z^2  3. xyz+xy^2+xz^2\n")
choice = int(input("Enter the equation which you want to solve: "))

if (choice == 1):
    x=int(input("Enter the value of x: "))
    y=int(input("Enter the value of y: "))
    print( x**2+2*x*y+y**2)

if (choice == 2):
    x=int(input("Enter the value of x: "))
    y=int(input("Enter the value of y: "))
    z=int(input("Enter the value of z: "))
    print( x**3+x*y*z+z**2)


if (choice == 3):
    x=int(input("Enter the value of x: "))
    y=int(input("Enter the value of y: "))
    z=int(input("Enter the value of z: "))
    print( x*y*z+x*(y**2)+x*(z**2))

