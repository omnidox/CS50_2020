from sys import argv, exit
import cs50
import csv


if len(argv) != 2:
        print("Usage: python import.py characters.csv")
        exit(1)
# Create database
open("students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")

# Create table
db.execute("CREATE TABLE students (first_name TEXT, middle_name TEXT, last_name TEXT, house TEXT, birth NUMERIC)")

# Open CSV file
# https://datasets.imdbws.com/title.basics.tsv.gz
with open(argv[1], "r") as titles:

    # Create DictReader
    reader = csv.DictReader(titles)

    # Iterate over TSV file
    for row in reader:

        # If non-adult TV show
        # if row["titleType"] == "tvSeries" and row["isAdult"] == "0":

        # If year not missing
        # if row["startYear"] != "\\N":

            # If since 1970
            birth = int(row["birth"])
            # if startYear >= 1970:

            # Remove \N from genres
            # genres = row["genres"] if row["genres"] != "\\N" else None

            # Insert show
            spl_names = row["name"].split()
            # print(spl_names)
            if len(spl_names) == 2:
                first_name = spl_names[0]
                middle_name = "NULL"
                last_name = spl_names[1]

            else:
                first_name = spl_names[0]
                middle_name = spl_names[1]
                last_name = spl_names[2]
            db.execute("INSERT INTO students (first_name, middle_name, last_name, house, birth) VALUES(?, ?, ?, ?, ?)",
                       first_name, middle_name, last_name, row["house"], birth)