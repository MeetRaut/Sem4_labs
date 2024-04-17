from tkinter import *
import sqlite3

def initialize_database():
    connection = sqlite3.connect('registration.db')
    cursor = connection.cursor()
    cursor.execute('''CREATE TABLE IF NOT EXISTS users (
                    id INTEGER PRIMARY KEY,
                    name TEXT,
                    email TEXT,
                    contact_number TEXT,
                    gender TEXT,
                    branch TEXT,
                    password TEXT)''')
    connection.commit()
    connection.close()

def register_action():
    name = en1.get()
    email = en3.get()
    contact_number = en4.get()
    gender = "Male" if vars.get() == 1 else "Female" if vars.get() == 2 else "Others"
    branch = cv.get()
    password = en6.get()
    re_password = en7.get()
    if password != re_password:
        print("Passwords do not match")
        return
    connection = sqlite3.connect('registration.db')
    cursor = connection.cursor()
    cursor.execute('''INSERT INTO users (name, email, contact_number, gender, branch, password)
                    VALUES (?, ?, ?, ?, ?, ?)''', (name, email, contact_number, gender, branch, password))
    connection.commit()
    connection.close()
    print("\nRegistration Successful!")

def view_users():
    connection = sqlite3.connect('registration.db')
    cursor = connection.cursor()
    cursor.execute('''SELECT * FROM users''')
    rows = cursor.fetchall()
    user_info = ""
    for row in rows:
        user_info += "ID: {}\nName: {}\nEmail: {}\nContact Number: {}\nGender: {}\nBranch: {}\n\n".format(row[0], row[1], row[2], row[3], row[4], row[5])
    text_box.delete(1.0, END)
    text_box.insert(END, user_info)
    connection.close()

def delete_user():
    name = en1.get()
    connection = sqlite3.connect('registration.db')
    cursor = connection.cursor()
    cursor.execute('''DELETE FROM users WHERE name=?''', (name,))
    connection.commit()
    connection.close()
    print("User {} deleted successfully.".format(name))

base = Tk()
base.title("Registration Form")

# Styling
base.configure(bg="#f0f0f0")
font_style = ("Calibri", 12)

lb1 = Label(base, text="Enter Name", font=font_style, bg="#f0f0f0")
lb1.grid(row=0, column=0, padx=10, pady=5, sticky="w")
en1 = Entry(base, font=font_style)
en1.grid(row=0, column=1, padx=10, pady=5)

lb3 = Label(base, text="Enter Email", font=font_style, bg="#f0f0f0")
lb3.grid(row=1, column=0, padx=10, pady=5, sticky="w")
en3 = Entry(base, font=font_style)
en3.grid(row=1, column=1, padx=10, pady=5)

lb4 = Label(base, text="Contact Number", font=font_style, bg="#f0f0f0")
lb4.grid(row=2, column=0, padx=10, pady=5, sticky="w")
en4 = Entry(base, font=font_style)
en4.grid(row=2, column=1, padx=10, pady=5)

lb5 = Label(base, text="Select Gender", font=font_style, bg="#f0f0f0")
lb5.grid(row=3, column=0, padx=10, pady=5, sticky="w")
vars = IntVar()
Radiobutton(base, text="Male", variable=vars, value=1, font=font_style, bg="#f0f0f0").grid(row=3, column=1, padx=10, pady=5)
Radiobutton(base, text="Female", variable=vars, value=2, font=font_style, bg="#f0f0f0").grid(row=3, column=2, padx=10, pady=5)
Radiobutton(base, text="Others", variable=vars, value=3, font=font_style, bg="#f0f0f0").grid(row=3, column=3, padx=10, pady=5)

list_of_branches = ("Computers", "IT", "AI & DS", "Chemical")
cv = StringVar()
cv.set("Computers")
lb2 = Label(base, text="Select Branch", font=font_style, bg="#f0f0f0")
lb2.grid(row=4, column=0, padx=10, pady=5, sticky="w")
drplist = OptionMenu(base, cv, *list_of_branches)
drplist.config(font=font_style)
drplist.grid(row=4, column=1, padx=10, pady=5)

lb6 = Label(base, text="Enter Password", font=font_style, bg="#f0f0f0")
lb6.grid(row=5, column=0, padx=10, pady=5, sticky="w")
en6 = Entry(base, show='*', font=font_style)
en6.grid(row=5, column=1, padx=10, pady=5)

lb7 = Label(base, text="Re-Enter Password", font=font_style, bg="#f0f0f0")
lb7.grid(row=6, column=0, padx=10, pady=5, sticky="w")
en7 = Entry(base, show='*', font=font_style)
en7.grid(row=6, column=1, padx=10, pady=5)

Button(base, text="Register", command=register_action, font=font_style).grid(row=7, column=1, padx=10, pady=10)
Button(base, text="View", command=view_users, font=font_style).grid(row=7, column=2, padx=10, pady=10)
Button(base, text="Delete", command=delete_user, font=font_style).grid(row=7, column=3, padx=10, pady=10)

text_box = Text(base, width=50, height=15, font=font_style)
text_box.grid(row=8, columnspan=4, padx=10, pady=10)

initialize_database()
base.mainloop()