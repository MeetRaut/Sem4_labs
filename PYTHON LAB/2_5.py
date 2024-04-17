class student:
    def __init__ (self, name, mmarks=0, dmarks=0, cmarks=0, dlmarks=0, dsmarks=0, amarks=0):
        self.name=input("Enter Your Name: ")
        self.mmarks=int(input("Enter MATHS Marks: "))
        self.dmarks=int(input("Enter DSA Marks: "))
        self.cmarks=int(input("Enter CG Marks: "))
        self.dlmarks=int(input("Enter DLCA Marks: "))
        self.dsmarks=int(input("Enter DSGT Marks: "))
        self.amarks=float(self.mmarks+self.dmarks+self.cmarks+self.dlmarks+self.dsmarks)/5

    def result_display (self):
        print("STUDENT NAME: ",self.name)
        print("Average Marks: ",self.amarks)
        
        if (self.amarks >= 80):
              print("You got Distinction Class")
        elif (self.amarks >= 60):
            print("You got First Class")
        elif (self.amarks >=40):
            print("You have Passes")
        else:
            print("You are Failed")
name=""
mmarks=0
dmarks=0
cmarks=0
dlmarks=0
dsmarks=0
amarks=0
ob = student(name, mmarks, dmarks, cmarks, dlmarks, dsmarks, amarks)
print("------------YOUR RESULT -------------")
ob.result_display()
