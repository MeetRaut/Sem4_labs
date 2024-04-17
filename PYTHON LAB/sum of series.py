# Write a program to find sum of series
print("Meet Raut    S21     2201084")
n = int(input("Enter number: "))
sum = 0
for i in range (1, n+1):
    sum = sum + (1/i)
    i = i + 1


print("Summation of series is: ", sum)
