from cs50 import get_string

# Readability checker program

# Gets text input from user
text = get_string("Text: ")

# Initializes vars for letters(l), sentences(s) and words(w) to 0
l = 0
s = 0
w = 0

# Checks if first character in text is a letter, adds 1 to word count
if text[0].isalpha():
    w += 1

# Checks if first character in text is a non-space char followed by a letter, adds 1 to word count
elif text[0].isprintable() and text[1].isalpha():
    w += 1

# Checks each character and counts the number of letters, sentences and words
i = 0
while i < len(text):
    # #1 Adds 1 to letter count if the current character is an uppercase or lowercase letter
    if text[i].isalpha():
        l += 1
    # #2 Adds 1 to sentence count if the current character is a period, exclamation point, or question mark (no exception handling)
    elif text[i] == '.' or text[i] == '!' or text[i] == '?':
        s += 1
    # Alt #3 Adds 1 to word count if the current char is a space, followed by A) a letter, or B) a non-space char + letter after
    elif text[i] == ' ' and text[i + 1].isalpha():
        w += 1
    elif text[i] == ' ' and text[i + 1].isprintable() and text[i + 2].isalpha():
        w += 1
    i += 1

# Calculates letters per 100 words (L), sentences per 100 words (S), index (index), and rounded index (rindex)
L = l / w * 100
S = s / w * 100
index = 0.0588 * L - 0.296 * S - 15.8
rindex = round(index)

# Prints readability checker results
# Grades 1-15
if rindex > 0 and rindex < 16:
    print("Grade", rindex)
    # Note: In this instance using + to concatenate doesn't work (str + int)
# Before Grade 1
elif rindex < 1:
    print("Before Grade 1")
# Grades 16+
elif rindex > 15:
    print("Grade 16+")