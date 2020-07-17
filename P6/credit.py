from cs50 import get_int

n = get_int("Number: ")

digits = [0] * 16
ddigits = [0] * 8
total = 0

i = 0
while i < 16:
    digits[i] = n % (10 ** (16 - i)) // (10 ** (15 - i))
    i += 1

i = 0
while i < 8:
    ddigits[i] = (digits[i * 2] * 2 % 10) + (digits[i * 2] * 2 % 100 // 10)
    i += 1

i = 0
while i < 8:
    total = total + digits[i * 2 + 1] + ddigits[i]
    i += 1

csum = total % 10


if n > 999999999999999 and n < 10000000000000000:
    if csum == 0:
        if digits[0] == 4:
            print("VISA")
        elif digits[0] == 5 and digits[1] > 0 and digits[1] < 6:
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")

elif n > 99999999999999 and n < 1000000000000000:
    if csum == 0 and digits[1] == 3 and (digits[2] == 4 or digits[2] == 7):
        print("AMEX")
    else:
        print("INVALID")

elif n > 999999999999 and n < 10000000000000:
    if csum == 0 and digits[3] == 4:
        print("VISA")
    else:
        print("INVALID")

else:
    print("INVALID")