import cs50
import csv
import sys

# Program for importing student database from csv to sql

# Terminates program if there is more/less than 1 command-line argument, or if the file extension is incorrectly entered
if len(sys.argv) != 2 or sys.argv[1].endswith(".csv") == False:
    print("Usage: python import.py data.csv")
    sys.exit(1)


# Opens/closes students.db database file (creates it if file does not exist) and opens it in sqlite3
open("students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")

# Executes SQL query to create a new table 'students', with the following columns
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")


# Opens csv and executes SQL query to import each row of csv data
with open(sys.argv[1], "r") as csvfile:

    reader = csv.DictReader(csvfile)

    for row in reader:

        # Splits name from csv into first, middle, last
        fullname = row["name"].split()

        first = fullname[0]

        if len(fullname) == 2:
            middle = None
            last = fullname[1]

        elif len(fullname) == 3:
            middle = fullname[1]
            last = fullname[2]

        # Executes SQL query to import data to SQL database
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
        first, middle, last, row["house"], row["birth"])