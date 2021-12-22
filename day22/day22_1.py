def read_file(name):
    file = open(name, "r")
    row = []
    for line in file:
        if line[-1] == '\n':
            line = line[:-1]
        ele = []
        op = 0
        if line[1] == "n":
            op = 1
            line = line[3:]
        else:
            op = 0
            line = line[4:]
        line = line.split(",")
        for axis in line:
            ele.append(list(map(lambda x: int(x) + 50, axis[2:].split(".."))))
        ele.append(op)
        row.append(ele)
    return row[:20]

def main():
    ins = read_file("1.in")
    cube = [[[0 for i in range(101)] for j in range(101)] for k in range(101)]
    for line in ins:
        x, y, z, op = line
        print(line)
        for i in range(x[0], x[1]+1):
            for j in range(y[0], y[1]+1):
                for k in range(z[0], z[1]+1):
                    cube[i][j][k] = op
    count = 0
    for i in range(101):
        for j in range(101):
            for k in range(101):
                count += cube[i][j][k]
    print(count)

if __name__ == "__main__":
    main()
            
            
