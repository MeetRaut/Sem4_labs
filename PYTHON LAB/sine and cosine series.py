# Write a program to print the sine and cosine series
import math
print("Meet Raut    S21     2201084")
print("***MENU***")
print("1. Sine series   2. Cosine series")
choice = int(input("Enter your choice: "))
x = int(input("Enter x: "))


if(choice == 1):
    sum = x
    num = 1
    print("This is Sine serie")
    for i in range (0, 84):
        #print(sum, end = " ")

        #sum = sum + ((-1)**i) * ((x**num)/ math.factorial(num))
        print(((-1)**i) * ((x**num)/ math.factorial(num)), end = " ")
        num = num + 2
elif(choice == 2):
    print("This is Cosine series")
    sum = 1
    num = 0

    for i in range (0, 84):
        
        #print(sum, end = " ")

        #sum = sum + ((-1)**i) * ((x**num)/ math.factorial(num))
        print(((-1)**i) * ((x**num)/ math.factorial(num)), end = " ")
        num = num + 2
        
else:
    print("Invalid choice")
