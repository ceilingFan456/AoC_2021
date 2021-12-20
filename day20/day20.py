def read_file(name):
    file = open(name, "r")
    table = file.readline()[:-1]
    file.readline()
    img = []
    for line in file:
        if line[-1] == '\n':
            line = line[:-1]
        row = []
        for c in line:
            if c == "#":
                c = 1
            else:
                c = 0
            row.append(c)
        img.append(row)
    return (table, img)

def line_buffer(buffer, n):
    return [buffer for i in range(n)]

def add_buffer(img, buffer):
    n = len(img)
    for i in range(n):
        img[i].insert(0, buffer)
        img[i].append(buffer)
    img.insert(0, line_buffer(buffer, n+2))
    img.append(line_buffer(buffer, n+2))

def translate(table, crop):
    a = 0
    for i in range(3):
        for j in range(3):
            a = a*2 + crop[i][j]
    a = table[a]
    if a == "#":
        return 1
    else:
        return 0

def update_img(table, img):
    n = len(img)
    copy = [[0 for i in range(n)] for j in range(n)]
    for i in range(1, n-1):
        for j in range(1, n-1):
            crop = []
            crop.append(img[i-1][j-1:j+2])
            crop.append(img[i][j-1:j+2])
            crop.append(img[i+1][j-1:j+2])
            bit = translate(table, crop)
            copy[i][j] = bit
    for i in range(1, n-1):
        for j in range(1, n-1):
            img[i][j] = copy[i][j]

def update_buffer(table, img, buffer):
    n = len(img)
    crop = [[buffer for i in range(3)] for j in range(3)]
    buffer = translate(table, crop)
    for i in range(n):
        img[0][i] = buffer
        img[n-1][i] = buffer
        img[i][0] = buffer
        img[i][n-1] = buffer
    return buffer

def count(img):
    n = len(img)
    c = 0
    for i in range(n):
        for j in range(n):
            if img[i][j] == 1:
                c += 1
    return c

def print_img(img):
    n = len(img)
    for i in range(n):
        for j in range(n):
            if img[i][j] == 0:
                c = '. '
            else:
                c = '#'
            print(c, end="")
        print()
        

def main():
    table, img = read_file("1.in")
    enhance = 50
    buffer = 0
    add_buffer(img, buffer)
    for n in range(enhance):
        add_buffer(img, buffer)
        update_img(table, img)
        buffer = update_buffer(table, img, buffer)
##        print("=====after change=====")
##        print("buffer is ", end='')
##        print(buffer)
##        print_img(img)
    print(count(img))

if __name__ == "__main__":
    main()
