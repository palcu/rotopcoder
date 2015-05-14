import sys
from random import randint

def generate_tests(exponent):
    MAX_M = 10**exponent
    MIN_SHIT = 5

    m = randint(MIN_SHIT, MAX_M)
    b = randint(MIN_SHIT, m-2)
    print("{0} {1}".format(m, b))


if len(sys.argv) < 2:
    print("Ai uitat de numarul de exponent")
else:
    generate_tests(int(sys.argv[1]))
