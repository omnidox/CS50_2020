from cs50 import get_string
from math import floor


def main():

    s = get_string("Text: ")

    letters = count_letters(s)

    words = count_words(s)

    sentences = count_sentences(s)

    L = (letters / words) * 100

    S = sentences / words * 100

    index = 0.0588 * L - 0.296 * S - 15.8

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade", round(index))


def count_letters(str):
    letters = 0

    for i in range(0, len(str), 1):
        if str[i].isalpha():
            letters += 1
    return letters


def count_words(str):

    words = 0
    if str[0].isspace() != True:
        words += 1
    for i in range(0, len(str), 1):
        if (str[i]) == ' ' and (str[i+1].isspace() != True):
            words += 1
    return words


def count_sentences(str):

    sentences = 0

    for i in range(0, len(str), 1):
        if str[i] == '.' or str[i] == '?' or str[i] == '!':
            sentences += 1
    return sentences


main()