class A:
    def __init__(self, Name, Age):
        self.Name = Name
        self.Age = Age

    def displayA(self):
        print("Parent: Name={0} || Age={1}".format(self.Name, self.Age))


class B(A):
    def __init__(self, Name, Age, Roll):
        super().__init__(Name, Age)
        self.Roll = Roll

    def displayB(self):
        print("Child: Name={0} || Age={1} || Roll No={2}".format(self.Name, self.Age, self.Roll))


class C(B):
    def __init__(self, Name, Age, Roll, Gender):
        super().__init__(Name, Age, Roll)
        self.Gender = Gender

    def displayC(self):
        print("GrandChild: Name={0} || Age={1} || Roll No={2} || Gender={3}".format(self.Name, self.Age, self.Roll,
                                                                                      self.Gender))


ob = C("Meet", 20, 72, "Male")
ob.displayA()
ob.displayB()
ob.displayC()
