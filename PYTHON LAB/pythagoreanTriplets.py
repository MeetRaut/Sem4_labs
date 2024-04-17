print("Meet Raut    S21     2201084")
triplets = []
count = 0
print("1. With duplicates     2. Without duplicates")
choice = int(input("Your choice: "))

if(choice == 1):
     for a in range (1, 51):
          for b in range (1, 51):
               for c in range (1, 51):
                    if(a**2 + b**2 == c**2): 
                         count += 1
                         triplets.append((a,b,c))
elif(choice == 2):
     for a in range (1, 51):
          for b in range (a, 51):
               for c in range (1, 51):
                    if(a**2 + b**2 == c**2):
                         count += 1
                         triplets.append((a,b,c))
else:
     print("Invalid input")

if(choice == 1 or choice == 2):
     print("total number of triplets = ", count, "\nTriplets are: ")
     print(triplets)