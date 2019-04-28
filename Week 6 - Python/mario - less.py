
from cs50 import get_int

# main function


def main():
    i = get_positive_int("Height: ")
    pyramid(i)


# check if user input is positive integer

def get_positive_int(prompt):
    while True:
        n = get_int(prompt)
        if n > 0 and n < 9:
            break
    return n


# print number the pyramid

def pyramid(n):
    for i in range(1, n+1):
        print(" "*(n-i), end="")
        print("#"*i)


if __name__ == '__main__':
    main()