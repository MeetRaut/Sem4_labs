#Calculator
print("Meet Raut    S21     2201084")
print("*-*-*-* MENU *-*-*-*")
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

