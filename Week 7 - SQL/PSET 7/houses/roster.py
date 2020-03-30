import csv, sqlite3, sys

if (len(sys.argv) != 2):
    sys.exit("Usage: roster.py house_name")
# Make house name lower to avoid cap sensitivity
housename = sys.argv[1].lower()
if housename not in ["slytherin", "gryffindor", "ravenclaw", "hufflepuff"]:
    sys.exit("provide house name: Gryffindor, Hufflepuff, Slytherin or Ravenclaw.")
# Connect with the .db file and make a cursor
data = sqlite3.connect("students.db")
cur = data.cursor()

cur.execute('SELECT first, middle, last, birth FROM students WHERE lower(house) = "{}" ORDER BY last, first;'.format(housename))

# Fetchall gives us all the rows of the table as a list of tuples with strings.
houseroster = cur.fetchall()

# Do stuff with each row in table
for row in houseroster:

    if not row[1]:
        print("{} {}, born {}".format(row[0], row[2], row[3]))
    else:
        print("{} {} {}, born {}".format(row[0], row[1], row[2], row[3]))

data.close()
