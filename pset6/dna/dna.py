from sys import argv, exit
import csv


def main():

    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

# finding amount of lines in csv
    with open(argv[1]) as csv_file:
        csv_reader = csv.DictReader(csv_file)
        p = int(len((list(csv_reader))))

    csv_list = load(argv[1])

    # use headers to parse thorugh string txt
    listdna = read(argv[2], headers)

    csv_list2 = [0] * p

# convert strings in list to ints
    for o in range(0, p, 1):
        csv_list2[o] = list(map(int, csv_list[o][1:]))

# compare both list to each other
    for m in range(0, p, 1):
        if listdna[1:] == csv_list2[m]:
            print(csv_list[m][0])
            exit()
    print("no match")

#  loading csv files as list of values


def load(dictionary):

    # loading csv file with dictreader. applying length of lines in variable k
    with open(dictionary) as csv_file:
        csv_reader = csv.DictReader(csv_file)
        k = int(len((list(csv_reader))))

    with open(dictionary) as csv_file:
        csv_reader = csv.DictReader(csv_file)
        global headers

        # get indexes from dictionary
        headers = csv_reader.fieldnames

        rlist = [0] * k
        j = 0
        for line in csv_reader:
            # take values from dict and inputs it into list
            rlist[j] = list(line.values())
            j += 1
        return rlist


def read(txt, headers):
    with open(txt, "r") as txt_file:
        read_file = txt_file.read()
        counter = 0
        # initialize counter according to header amount
        max_counter = [0] * len(headers)

        # iterate through txt file and compare to the given headers
        for l in range(1, len(headers), 1):
            n = len(headers[l])
            STR = [read_file[i:i+n] for i in range(0, len(read_file), 1)]
            for i in range(0, len(STR), 1):
                if STR[i] == headers[l] and counter == 0:
                    counter += 1

                if STR[i] == headers[l] and STR[i - n] == headers[l]:
                    counter += 1

                if i + n >= len(STR):
                    if counter > max_counter[l]:
                        max_counter[l] = counter

                if i + n < len(STR):

                    if STR[i] == headers[l] and STR[i + n] != headers[l]:
                        if counter > max_counter[l]:
                            max_counter[l] = counter
                        counter = 0

    return max_counter


main()