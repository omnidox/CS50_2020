from sys import argv, exit
import cs50
import csv

# Prompt User for specifiv entry via argv
if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)
# Create database
open("students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")

# Create table
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

# Open CSV file
with open(argv[1], "r") as titles:

    # Create DictReader
    reader = csv.DictReader(titles)

    # Iterate over CSV file
    for row in reader:

        # make birth into int
        birth = int(row["birth"])

        # Split names and distinguish between three name vs two names
        spl_names = row["name"].split()
        if len(spl_names) == 2:
            first = spl_names[0]
            middle = None
            last = spl_names[1]

        else:
            first = spl_names[0]
            middle = spl_names[1]
            last = spl_names[2]

        # insert values into SQL DB
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   first, middle, last, row["house"], birth)