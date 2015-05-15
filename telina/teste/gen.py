#!/usr/bin/python3
import sys
import random
import string

test_limits = [5, 10, 15, 100, 1000,
        1500, 20000, 200000, 250000, 300000,
        500000, 500000, 600000, 600000, 700000,
        1000000, 1000000, 1000000, 1000000, 1000000];
print len(test_limits)

def randomword(length):
   return ''.join(random.choice(string.lowercase) for i in range(length))

def main():
    for idx_item in range(len(test_limits)):
        item = test_limits[idx_item]

        f = open(str(idx_item) + "-" + "telina" + ".in", "w")
        f.write(randomword(item))
        f.close()
    return 0

if __name__=="__main__":
    main()
