import sys
import csv
import re
#check command line argument
if len(sys.argv)!=3:
    print ("Usage: python dna.py data.csv sequence.txt")
    exit(1)

genomes_names = [] #open csv file with names and numbers of repetitions
with open(sys.argv[1], "r") as csvfile:
    dna_data = csv.reader(csvfile)
    personal_data = list(dna_data)
    genomes_names = (personal_data[0][1:])

counter = 0 #open a file with sequences
file = open(sys.argv[2],"r")
sequence = file.read()

occurences = []
#read name of genomes and check the number of occurences
#function that counts repetitions I got from https://stackoverflow.com/questions/51690245/consecutive-substring-in-python
for i in range(0,len(genomes_names)):
    start = 0
    substr_count = 0
    tmp = 0
    while True:
        string = sequence
        substring = genomes_names[i]

        loc = string.find(substring,start)
        if loc == -1:
            break
        if loc != start:
            tmp = 0
            tmp+=1
        else:
            tmp+=1

        if tmp > substr_count:
            substr_count=tmp

        start = loc + len(substring)

    occurences.append(substr_count)
    substr_count = 0

#how many rows are there
rows_number = len(personal_data)

repetitions = []

match = 0
name = 0
no_match = False
for i in range(1,len(personal_data)):
    for j in range(1,len(personal_data[i])):
        repetitions.append(personal_data[i][j])
    for k in range(len(repetitions)):
        if int(repetitions[k]) == int(occurences[k]):
            match +=1
            no_match = True
        else:
            match = match
            no_match = False
    repetitions = []
    if match == len(occurences) and no_match == True:
        print(personal_data[i][0])
        name+=1
    else:
        no_match = False
        match = 0

if no_match == False and name == 0:
    print("No match")