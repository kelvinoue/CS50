from cs50 import get_int

# Credit card verification program

# Gets credit card number from user
n = get_int("Number: ")

digits = [0] * 16
ddigits = [0] * 8
total = 0

# Calculates checksum
# Gets digits (#1-16)
i = 0
while i < 16:
    digits[i] = n % (10 ** (16 - i)) // (10 ** (15 - i))
    i += 1

# For each digit (#1,3,5,7,9,11,13,15), multiplies it by 2 and gets the sum of the resulting digits
i = 0
while i < 8:
    ddigits[i] = (digits[i * 2] * 2 % 10) + (digits[i * 2] * 2 % 100 // 10)
    i += 1

# Gets sum of multiplied digits (#1,3,5,7,9,11,13,15) plus the sum of digits #2,4,6,8,10,12,14,16
i = 0
while i < 8:
    total = total + digits[i * 2 + 1] + ddigits[i]
    i += 1

# Final step of checksum
csum = total % 10


# Checks for card length, starting digits, and checksum
# For 16 digit cards
if n > 999999999999999 and n < 10000000000000000:
    if csum == 0:
        # For VISA (4)
        if digits[0] == 4:
            print("VISA")
        # For MASTERCARD (51-55)
        elif digits[0] == 5 and digits[1] > 0 and digits[1] < 6:
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")

# For 15 digit cards
elif n > 99999999999999 and n < 1000000000000000:
    # For AMEX (34,37)
    if csum == 0 and digits[1] == 3 and (digits[2] == 4 or digits[2] == 7):
        print("AMEX")
    else:
        print("INVALID")

# For 13 digit cards
elif n > 999999999999 and n < 10000000000000:
    # For VISA (4)
    if csum == 0 and digits[3] == 4:
        print("VISA")
    else:
        print("INVALID")

else:
    print("INVALID")