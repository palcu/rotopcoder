import sys
from random import randint

def generate_tests(N, P):
    for i in range(N):

    MAX_M = 10**exponent
    MIN_SHIT = 5

    m = randint(10**(exponent-1), MAX_M)
    b = randint(5, m-2)
    print("{0} {1}".format(m, b))


if len(sys.argv) < 2:
    print("Ai uitat de numarul de exponent")
else:
    generate_tests(int(sys.argv[1]), int(sys.argv[2]))
