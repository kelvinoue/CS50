from cs50 import get_int

# Mario pyramid generator program

# Gets height of pyramid from user, prompts user till input is between 1-8 inclusive
n = 0
while n < 1 or n > 8:
    n = get_int("Height: ")

# Prints n number of rows
i = 0
while i < n:
    # Prints n-i-1 number of spaces at the beginning of each row
    j = 0
    while j < (n - i - 1):
        print(" ", end="")
        j += 1

    # Prints i+1 number of #s for left side of pyramid
    j = 0
    while j < (i + 1):
        print("#", end="")
        j += 1

    # Prints 2 spaces (constant)
    print("  ", end="")

    # Prints i+1 number of #s for right side of pyramid
    j = 0
    while j < (i + 1):
        print("#", end="")
        j += 1

    print("")

    i += 1