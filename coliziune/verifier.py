
class Verifier(object):

    def __init__(self, m, b):
        self.m = m
        self.b = b

    def compute_hash(self, arg):

        hash_value = 0
        cur_base = 1

        for i in range(len(arg), 0, -1):
            idx = i - 1

            hash_value += (int(arg[idx]) + 1) * cur_base
            cur_base = (cur_base * self.b) % self.m
            hash_value = hash_value % self.m

        return hash_value

    def verify(self, first, second):
        if first == second:
            return False

        s1 = self.compute_hash(first)
        s2 = self.compute_hash(second)

        print("hash(" + first + ")" + "->"  + str(s1))
        print("hash(" + second + ")" + "->"  + str(s2))

        return s1 % m == s2 % m

with open('coliziune.in') as fin, open('coliziune.out') as fout:
    input_lines = fin.readlines()
    output_lines = fout.readlines()
    for line_number in range(len(input_lines)):
        m, b = [int(x) for x in input_lines[line_number].strip().split()]
        first, second = output_lines[line_number].strip().split()
        Ver = Verifier(m, b)

        if Ver.verify(first, second):
            print("{0} OK".format(line_number))
        else:
            print("{0} Wrong".format(line_number))

