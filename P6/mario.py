from cs50 import get_int

n = 0
while n < 1 or n > 8:
    n = get_int("Height: ")

i = 0
while i < n:

    j = 0
    while j < (n - i - 1):
        print(" ", end="")
        j += 1

    k = 0
    while k < (i + 1):
        print("#", end="")
        k += 1

    print("  ", end="")

    l = 0
    while l < (i + 1):
        print("#", end="")
        l += 1

    print("")

    i += 1