#Age 
print("Meet Raut    S21     2201084")
print("*-*-*-* MENU *-*-*-*")
age = int(input("Enter your age: "))
if(age <= 0):
    print("INVALID")
elif(age <= 12):
    print("You are a kid")
elif(age <= 20):
    print("You are a teenager")
elif(age <= 50):
    print("You are an adult")
elif(age <= 100):
    print("You are old")
else:
    print("Invalid")
    
