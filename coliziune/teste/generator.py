import sys
from random import randint

def generate_tests(nteste, exponent):
    max_teste = nteste
    MAX_M = 10**exponent
    MAX_B = 10**exponent - 2
    MIN_SHIT = 5
    print(max_teste)

    for i in range(max_teste):
        print("{0} {1}".format(randint(MIN_SHIT, MAX_M),
                               randint(MIN_SHIT, MAX_B)))


if len(sys.argv) < 3:
    print("Ai uitat de numarul de teste si de exponent")
else:
    generate_tests(int(sys.argv[1]), int(sys.argv[2]))
