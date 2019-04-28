from cs50 import get_int


# main function

def main():
    card_num = get_num("Number: ")
    result = check_card(card_num)

    if result == False:
        print("INVALID")
    else:
        card_name(card_num)


# check input num is valid
def get_num(prompt):
    while True:
        num = get_int(prompt)
        if num > 0:
            break

    return num


# check total value % 10 == 0
def check_card(n):
    n = str(n)

    r = []
    for i in range(1, len(n)+1):
        r.append(n[-i])

    total = 0
    for i in range(-1, -len(n)):
        if i % 2 == 0:
            total += int(r[i])

        else:
            x = int(r[i]) * 2
            total += int(x / 10)
            total += x % 10

    if total % 10 == 0:
        return True

    else:
        return False


# check card name

def card_name(n):
    n = str(n)
    if len(n) == 15 and n[0] == '3':
        print("AMEX")

    elif len(n) == 16 and n[0] == '5':
        print("MASTERCARD")

    elif (len(n) == 13 or len(n) == 16) and n[0] == '4':
        print("VISA")

    else:
        print("INVALID")


if __name__ == "__main__":
    main()