def verify(n, m, b, first, second):
    s1, s2 = 0, 0
    for i in range(len(first)):
        s1 += (int(first[i]) + 1) * b ** (n-i)
        s2 += (int(second[i]) + 1) * b ** (n-i)
    return s1 % m == s2 % m

with open('coliziune.in') as fin, open('coliziune.out') as fout:
    input_lines = fin.readlines()[1:]
    output_lines = fout.readlines()
    for line_number in range(len(input_lines)):
        n, m, b = [int(x) for x in input_lines[line_number].strip().split()]
        first, second = output_lines[line_number].strip().split()
        if verify(n, m, b, first, second):
            print("{0} OK".format(line_number))
        else:
            print("{0} Wrong".format(line_number))

