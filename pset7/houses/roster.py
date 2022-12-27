from sys import argv, exit
import cs50
import csv

# Prompt User for specifiv entry via argv
if len(argv) != 2:
    print("Usage: python roster.py (Hogwarts house name)")
    exit(1)

# acquire databse
db = cs50.SQL("sqlite:///students.db")

# making it equal to records, prompt for particular qury
records = db.execute("SELECT first, middle, last, birth FROM students WHERE house LIKE ? ORDER BY last, first", argv[1])

# print info
for row in records:
    if row["middle"] == None:
        print(f'{row["first"]} {row["last"]}, born {row["birth"]}')

    else:
        print(f'{row["first"]} {row["middle"]} {row["last"]}, born {row["birth"]}')
