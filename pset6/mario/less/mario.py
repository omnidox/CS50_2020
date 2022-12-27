from cs50 import get_int


def main():
    t = get_positive_int()

    for i in range(1, t+1, 1):
        for j in range(i, t, 1):
            print(" ", end="")
        for k in range(i):
            print("#", end="")
        print()


def get_positive_int():
    while True:
        n = get_int("Positive Integer, between 1 to 8 inclusive: ")

        if n > 0 and n < 9:
            break
    return n


main()