from cs50 import get_float


# main function

def main():
    amount = get_positive_float("Change owed: ")
    print(count_coins(amount))


# check user input is positive float

def get_positive_float(prompt):
    while True:
        n = get_float(prompt)
        if n > 0:
            break
    return n


# count minimum number of coins

def count_coins(amount):
    count = 0
    amount = amount * 100

    if amount >= 25:
        count += int(amount / 25)
        amount = amount % 25

    if amount >= 10:
        count += int(amount / 10)
        amount = amount % 10

    if amount >= 5:
        count += int(amount / 5)
        amount = amount % 5

    if amount >= 1:
        count += int(amount)

    return count


if __name__ == "__main__":
    main()