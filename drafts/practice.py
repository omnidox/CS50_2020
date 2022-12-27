import csv

with open('databases/small.csv') as csv_file:
    csv_reader = csv.DictReader(csv_file, delimiter=',')
    for row in csv_reader:
        print(f'\t{row["name"]} {row["AGATC"]} {row["AATG"]} {row["TATC"]}')
        