import cs50
import sys

# Program for printing roster from SQL database

# Terminates program if there is more/less than 1 command-line argument
if len(sys.argv) != 2:
    print("Usage: python roster.py <house>")
    sys.exit(1)


# Opens SQL database in sqlite3
db = cs50.SQL("sqlite:///students.db")

# Executes SQL query using command-line user input <house>
# Selects the corresponding rows and sorts by last, then first
roster = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", sys.argv[1].lower().capitalize())


# Prints roster
for row in roster:

    # For rows with no middle name
    if row['middle'] == None:
        print(row['first'], row['last'] + ",", "born", row['birth'])

    # For others
    else:
        print(row['first'], row['middle'], row['last'] + ",", "born", row['birth'])