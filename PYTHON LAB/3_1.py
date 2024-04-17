class Person:  
    count = 0       # This is a class variable  
  
    def __init__(self, name, age):  
        self.name = name        # This is an instance variable  
        self.age = age  
        Person.count += 1   

person1 = Person("Aditya", 25)  
person2 = Person("Prasad", 30)  
print("Number of person: ", Person.count)     