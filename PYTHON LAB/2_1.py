print("Meet Raut-S21-2201084")
class A:
    def sum(self, A=None, B=None, C=None):
        if (A is not None and B is not None and C is not None):
            print("Sum of A, B & C is:", A+B+C)
        elif (A is not None and B is not None and C is None):
            print("Sum of A & B is:",A+B)
        elif (A is not None and B is None and C is None):
            print("A=",A)
        else:
            print("Sum not possible!!")

ob=A()
ob.sum(12,10,20)
ob.sum(12,10)
ob.sum(12)
ob.sum()