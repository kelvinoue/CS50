import csv
import sys

# DNA profiling program


# Terminates program if there are more/less than 2 command-line arguments
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

# Terminates program if any of the file extensions are incorrectly entered
elif sys.argv[1].endswith(".csv") == False or sys.argv[2].endswith(".txt") == False:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)


# Opens and reads csv file, stores strs from column headers (from row 1) in 'strs'
# Note: File not closed as it is needed for matching later
csvfile = open(sys.argv[1], "r")
reader = csv.reader(csvfile)
strs = next(reader)

# Opens and reads txt file, stores dna sequence in 'dna', and closes file
with open(sys.argv[2], "r") as txtfile:
    dna = txtfile.read()


# Defines lists 'count' and 'maxcount' with x number of elements initialied to 0, where x is the number of strs in the csv
# 'Count' temporarily stores the number of times an str appears consecutively, beginning from the nucleotide (char) being checked
# 'Maxcount' stores the highest value that count reaches after checking all the nucleotides (chars) in 'dna'
count = [0] * (len(strs) - 1)
maxcount = [0] * (len(strs) - 1)


# Checks 'dna' for each of the strs in the csv
i = 0
while i < (len(strs) - 1):

    # Checks every nucleotide (char) in 'dna' for the current str
    j = 0
    while j < len(dna):
        count[i] = 0

        # Adds 1 to count if str is present
        if dna[j:(j + len(strs[i + 1]))] == strs[i + 1]:
            count[i] += 1

            # Checks for consecutive repeats and adds 1 to count for each consecutive repeat
            k = 0
            while k < (len(dna) - j):
                if dna[j + k + len(strs[i + 1]):(j + k + (2 * len(strs[i + 1])))] == strs[i + 1]:
                    count[i] += 1
                else:
                    break
                k += len(strs[i + 1])

            # Stores count in maxcount if the current value of count is larger than maxcount
            if count[i] > maxcount[i]:
                maxcount[i] = count[i]

        j += 1
    i += 1


# 'Match' stores the results of the profiling, initialized to False
match = False


# Generates profiling results
for row in reader:

    # Stores str values from csv (as int) in 'combi', for each individual
    combi = [0] * (len(strs) - 1)
    i = 0
    while i < (len(strs) - 1):
        combi[i] = int(row[i + 1])
        i += 1

    # Checks if 'maxcount' matches 'combi'
    if maxcount == combi:
        # If there is a match, stores the name of the individual in 'name', and updates 'match' to True
        name = row[0]
        match = True
        break


# Prints profiling results
if match == True:
    print(name)
else:
    print("No match")