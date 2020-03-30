import csv, sqlite3, sys

raw_data = csv.DictReader((open(sys.argv[1])), skipinitialspace = True)
data = sqlite3.connect("students.db")
cur = data.cursor()

for row in raw_data:
    student = []

    for element in row['name'].split():
        student.append(element)
    student.append(row['house'])
    student.append(row['birth'])

    if (len(student) == 5):
        cur.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                        student[:5])
    else:
        cur.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)",
                        student[:4])

data.commit()
data.close()
