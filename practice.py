import csv

with open('small.csv') as csv_file:
    csv_reader = csv.Reader(csv_file, delimiter=',')
    line_count = 0
    for row in csv_reader:
        print(f'\t{row[0]} works in the {row[1]} department, and was born in {row[3]}')