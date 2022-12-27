from sys import argv, exit
import csv

def main():

    if len(argv) != 3:
        print("missing csv and txt file")
        exit(1)
    
    load(argv[1])
    listdna = read(argv[2], headers)
    
    # print (headers)

def load(dictionary):
    with open(dictionary) as csv_file:
        csv_reader = csv.DictReader(csv_file)
        global headers
        headers = csv_reader.fieldnames
        
        k = len((list(csv_reader))
        rlist = [0] * 25
        j = 0
        for line in csv_reader:
            rlist[j] = line
            j += 1
            # list = line
        print(rlist[22][headers[0]])
    return

def read(txt, headers):
    with open(txt, "r") as txt_file:
        read_file = txt_file.read()
        # print(read_file)
        # headers
        # print(headers)
        counter = 0
        max_counter = [0] * len(headers)
        for l in range(1,len(headers),1):
            n = len(headers[l])
            STR = [read_file[i:i+n] for i in range(0, len(read_file), 1)]
            for i in range (0, len(STR),1):
                if STR[i] == headers[l] and counter == 0:
                    counter += 1
                    
                if STR[i] == headers[l] and STR[i - n] == headers[l]:
                    counter += 1
                    
                if STR[i] == headers[l] and STR[i + n] != headers[l]: 
                    if counter > max_counter[l] :
                        max_counter[l] = counter
                    counter = 0
        
        # for l in range(1,len(headers),1):
        #     print(headers[l])
        #     print(max_counter[l])
    return max_counter

main()