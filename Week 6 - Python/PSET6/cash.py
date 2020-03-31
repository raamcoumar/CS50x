"""
Implement a program that calculates the minimum number of coins
required to give a user change.

"""

from cs50 import get_float #cs50 only availavle on cs50 IDE: https://ide.cs50.io
from math import floor


def main():
    while True:
        dollars_owed = get_float("Change owed: ")
        cents_owed = floor(dollars_owed * 100)

        if cents_owed > 0:
            break

    quarters = cents_owed // 25
    dimes = (cents_owed % 25) // 10
    nickels = ((cents_owed % 25) % 10) // 5
    pennies = ((cents_owed % 25) % 10) % 5

    print(f"{quarters + dimes + nickels + pennies}")


if __name__ == "__main__":
    main()
