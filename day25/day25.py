def print_sea(sea):
    for i in sea:
        for j in i:
            if j == ".":
                print(j, end=" ")
            else:
                print(j, end="")
        print()

def read_file(name):
    file = open(name, "r")
    sea = []
    for line in file:
        if line[-1] == '\n':
            line = line[:-1]
        row = []
        for word in line:
            row.append(word)
        sea.append(row)
##    print_sea(sea)
    return sea

def play_kind(sea, kind):
    m = len(sea)
    n = len(sea[0])
    moved = False
    lst = []
    for i in range(m):
        for j in range(n):
            if kind == "v" and sea[i][j] == "v":
                if sea[(i+1)%m][j] == ".":
                    lst.append((i, j))
                    moved = True

            elif kind == ">" and sea[i][j] == ">":
                if sea[i][(j+1)%n] == ".":
                    lst.append((i, j))
                    moved = True
    for p in lst:
        i, j = p
        if kind == "v":
            sea[(i+1)%m][j] = "v"
            sea[i][j] = '.'
        elif kind == ">":
            sea[i][(j+1)%n] = ">"
            sea[i][j] = "."
            
    return moved

def play_sea(sea):
    count = 0
    moved = True
    while (moved):
        count += 1
        moved = False
        moved = play_kind(sea, ">") or moved
        moved = play_kind(sea, "v") or moved
##        print(("count = ", count))
##        print_sea(sea)
    return count

def main():
    sea = read_file("1.in")
    count = play_sea(sea)
    print(count)

if __name__ == "__main__":
    main()
