#calculator
#Based on age identify the categories like kid, youth, old
#Implement the expression
#x2+2xy+y2
#x3+xyz+z2
#Xyz+xy2+xz2
print("Meet Raut    S21     2201084")
print("*-*-*-* MENU *-*-*-*")
print("1. Calculator    2. Age categories   3. Expressions")
c = int(input("Enter your choice: "))

if(c == 1):
    #Calculator

    print("*****MENU*****\n")
    print("1. Addition 2. Subtraction 3. Multiplication 4. Division 5. Exit\n")
    choice = 0

    while(choice != 5):

        choice = int(input("Enter your choice: "))

        if(choice == 1):
            a = int(input("Enter first value: "))
            b = int(input("Enter second value: "))
            print("Answer: ", a + b)

        elif(choice == 2):
            a = int(input("Enter first value: "))
            b = int(input("Enter second value: "))
            print("Answer: ", a - b)

        elif(choice == 3):
            a = int(input("Enter first value: "))
            b = int(input("Enter second value: "))
            print("Answer: ", a * b)

        elif(choice == 4):
            a = int(input("Enter first value: "))
            b = int(input("Enter second value: "))
            while(b == 0):
                print("Are you dumb!")
                b = int(input("Enter second value: "))
            print("Answer: ", a / b)

        elif(choice == 4):
            a = int(input("Enter value: "))
            print("Answer: ", a ** 2 )

        elif(choice == 5):
            break
        
        else: 
            print("Invalid choice")

    print("*****Exited*****")



elif(c == 2):
    #Age 
    age = int(input("Enter your age: "))
    if(age <= 0):
        print("WTF!!!! You dumb or what???")
    elif(age <= 12):
        print("You are a kid")
    elif(age <= 20):
        print("You are a teenager")
    elif(age <= 50):
        print("You are an adult")
    elif(age <= 100):
        print("You are old")
    elif(age > 100):
        print("Bore nahi hua kya! Give up bro! Be LMAO DED")
    else:
        print("WTF!!!! You dumb or what???")
    

elif(c == 3):
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




else:
    print("Invalid choice")