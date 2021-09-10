print("\n\tUsing Tuples\n")
branch = ("BTECH", "BCA")
courses = ("Data Structures", "Alogorithm", "DBMS", "Web Development", "BME", "BEE", "BEC")
for i in range(len(courses)):
    print((branch[0]) + " -> " + (courses[i]))

for i in range(len(courses) - 3):
    print((branch[1] + " -> " + (courses[i])))
