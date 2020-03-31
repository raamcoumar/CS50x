"""
The Coleman-Liau index:

The Coleman-Liau index of a text is designed to output what (U.S.) grade level
is needed to understand the text. The formula is:
index = 0.0588 * L - 0.296 * S - 15.8

"""

from cs50 import get_string


def main():
    text = get_string("Text: ")
    length = len(text)
    letters = 0
    sentences = text.count('.') + text.count('!') + text.count('?')
    words = text.count(' ')+1
    for i in range(length):
        if (text[i].isalpha()):  # letters
            letters += 1

    L = letters / words * 100
    S = sentences / words * 100
    index = 0.0588 * L - 0.296 * S - 15.8  # index
    indexi = round(index)
    if (indexi >= 1 and indexi < 16):
        print(f"Grade {indexi}")
    if (indexi > 16):
        print("Grade 16+")
    if (indexi < 1):
        print("Before Grade 1")


if __name__ == "__main__":
    main()
