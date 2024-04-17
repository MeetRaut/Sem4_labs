while True:
    print("Meet Raut    S21     2201084")
    print("\n*-*-*-*-* MENU *-*-*-*-*")
    n = int(input("1.List   2.Tuple     3.Dictionary    4.Set       5.Exit: "))
    
    if n == 1:
        l = []
        while True:
            a = int(input("1.Add    2.Remove    3.Number of Elements    4.Sort      5.Exit: "))
            if a == 1:
                l.append(int(input("Enter Value to add: ")))
                print(l)
            elif a == 2:
                try:
                    value = int(input("Enter a value to remove from the list: "))
                    l.remove(value)
                    print(l)
                except ValueError:
                    print("Value not found in the list.")
            elif a == 3:
                print(len(l))
            elif a == 4:
                print(sorted(l))
            else:
                break
                
    elif n == 2:
        t = tuple(map(int, input("Enter values separated by space: ").split()))
        while True:
            a = int(input("1.Print      2.Number of Elements    3.Sort      4.Exit: "))
            if a == 1:
                print(t)
            elif a == 2:
                print(len(t))
            elif a == 3:
                print(tuple(sorted(t)))    
            else:
                break
                
    elif n == 3:
        d = {}
        while True:
            a = int(input("1.Add    2.Remove    3.Number of Elements    4.Sort      5.Exit: "))
            if a == 1:
                key, value = input("Enter key value pair separated by space: ").split()
                d[key] = value
                print(d)
            elif a == 2:
                try:
                    key = input("Enter a key to remove from the dictionary: ")
                    d.pop(key)
                    print(d)
                except KeyError:
                    print("Key not found in the dictionary.")
            elif a == 3:
                print(len(d))
            elif a == 4:
                print(sorted(d.items()))
            else:
                break

    elif n == 4:
        s = set()
        while True:
            a = int(input("1.Add    2.Remove    3.Number of Elements    4.Sort      5.Exit: "))
            if a == 1:
                s.add(int(input("Enter Value to add: ")))
                print(s)
            elif a == 2:
                try:
                    value = int(input("Enter a value to remove from the set: "))
                    s.remove(value)
                    print(s)
                except KeyError:
                    print("Value not found in the set.")
            elif a == 3:
                print(len(s))
            elif a == 4:
                print(sorted(s))
            else:
                break
                
    elif n == 5:
        break
