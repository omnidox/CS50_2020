from sys import argv, exit
import cs50
import csv

if len(argv) != 2:
        print("Usage: python roster.py (Hogwarts house name)")
        exit(1)

# Create database
db = cs50.SQL("sqlite:///students.db")

# Create table
records = db.execute("SELECT first_name, middle_name, last_name, birth FROM students WHERE house LIKE ? ORDER BY last_name, first_name" , argv[1])

for row in records:
    if row["middle_name"] == "NULL":
        print(f'{row["first_name"]} {row["last_name"]}, born {row["birth"]}')

    else:
        print(f'{row["first_name"]} {row["middle_name"]} {row["last_name"]}, born {row["birth"]}')
