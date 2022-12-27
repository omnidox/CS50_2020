from cs50 import get_float
from math import floor


def main():

    dollars = get_positive_float()

    cents = round(dollars * 100)
    quarters = floor(cents / 25)

    rcentsq = cents % 25
    dimes = floor(rcentsq / 10)

    rcentsd = rcentsq % 10
    nickels = floor(rcentsd / 5)

    rcentsn = rcentsq % 5
    pennies = floor(rcentsn / 1)

    totcoins = quarters + dimes + nickels + pennies

    print(totcoins)


def get_positive_float():
    while True:
        n = get_float("Positive Float:")

        if n > 0:
            break
    return n


main()