import math

def hyp(a, b):
    c = math.sqrt(a*a + b*b)

    return c

# printstars(n):  prints n *'s to the terminal.
def printstars(n):

    print("*"*n)

    return

def main():
    x = float(input("Enter a side length: "))
    y = float(input("Enter another side length: "))

    z = hyp(x, y)

    print("The hyp. of a right tri with side lengths {} and {} is {}.".format(
        x, y, z))

    printstars(40)

    return

main()

