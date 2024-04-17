from tkinter import *

base = Tk()
base.title("Registration Form")

# Name
lb1 = Label(base, text="Name:", font=("arial", 12))
lb1.grid(row=0, column=0, padx=10, pady=10, sticky="w")
en1 = Entry(base)
en1.grid(row=0, column=1, padx=10, pady=10)

# Email
lb3 = Label(base, text="Email:", font=("arial", 12))
lb3.grid(row=1, column=0, padx=10, pady=10, sticky="w")
en3 = Entry(base)
en3.grid(row=1, column=1, padx=10, pady=10)

# Contact Number
lb4 = Label(base, text="Contact Number:", font=("arial", 12))
lb4.grid(row=2, column=0, padx=10, pady=10, sticky="w")
en4 = Entry(base)
en4.grid(row=2, column=1, padx=10, pady=10)

# Select Country
lb2 = Label(base, text="Select Country:", font=("arial", 12))
lb2.grid(row=4, column=0, padx=10, pady=10, sticky="w")
cv = StringVar()
cv.set("Select")
drplist = OptionMenu(base, cv, *("United States", "India", "Nepal", "Germany"))
drplist.grid(row=4, column=1, padx=10, pady=10, sticky="w")

# Enter Password
lb6 = Label(base, text="Enter Password:", font=("arial", 12))
lb6.grid(row=5, column=0, padx=10, pady=10, sticky="w")
en6 = Entry(base, show='*')
en6.grid(row=5, column=1, padx=10, pady=10)

# Re-Enter Password
lb7 = Label(base, text="Re-Enter Password:", font=("arial", 12))
lb7.grid(row=6, column=0, padx=10, pady=10, sticky="w")
en7 = Entry(base, show='*')
en7.grid(row=6, column=1, padx=10, pady=10)

# Register Button
Button(base, text="Register", width=10).grid(row=7, column=1, pady=20)

base.mainloop()