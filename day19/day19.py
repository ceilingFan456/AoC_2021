def read_file():
    file = open("1.in", "r")
    sc = []
    n = 0
    cur = []
    for row in file:
        if row[:3] == "---":
            cur = []
            n += 1
        elif row[0] == '\n':
            sc.append(cur)
        else:
            point = list(map(lambda x: int(x), row.split(",")))
            cur.append(point)
    sc.append(cur)   
    return (n, sc)

def eye(n):
    return [[0 for i in range(n)] for i in range(n)]

def generate_direction(): ## generate a sequence of direction
    directions = []
    for i in range(3):
        for j in range(3):
            for k in range(-1, 3, 2):
                for l in range(-1, 3, 2):
                    if i == j:
                        continue
                    cur = eye(3)
                    cur[i][0] = k
                    cur[j][1] = l
                    cur[0][2] = cur[1][0]*cur[2][1] - cur[2][0]*cur[1][1]
                    cur[1][2] = cur[2][0]*cur[0][1] - cur[0][0]*cur[2][1]
                    cur[2][2] = cur[0][0]*cur[1][1] - cur[1][0]*cur[0][1]
                    directions.append(cur)
    return directions

def change_direction_vector(d, v):
    u1 = d[0][0]*v[0] + d[0][1]*v[1] + d[0][2]*v[2]
    u2 = d[1][0]*v[0] + d[1][1]*v[1] + d[1][2]*v[2]
    u3 = d[2][0]*v[0] + d[2][1]*v[1] + d[2][2]*v[2]
    return [u1, u2, u3]

def change_direction(d, sc):
    lst = []
    for p in sc:
        q = change_direction_vector(d, p)
        lst.append(q)
    return lst

def minus_coord(a, b):
    return [a[0]-b[0], a[1]-b[1], a[2]-b[2]]

def plus_coord(a, b):
    return [a[0]+b[0], a[1]+b[1], a[2]+b[2]]

def reverse_coord(a):
    return [-a[0], -a[1], -a[2]]

def relative_coord(cord, sc):
    lst = []
    for p in sc:
        q = minus_coord(p, cord)
        lst.append(q)
    return lst

def match(base, sc):
    directions = generate_direction()
    for d in directions:
        ## try each direction 
        other = change_direction(d, sc)
        for i in base:
            for j in other:
                ## assume base[i] is sc[j] and match two origins
                alter1 = relative_coord(j, other)
                rev = reverse_coord(i)
                alter2 = relative_coord(rev, alter1)
                common = 0
                for k in alter2:
                    if k in base:
                        common += 1
                if common >= 12:
                    origin = reverse_coord(j) ## origin relative to matching point
                    origin = plus_coord(i, origin)
                    print("=====successful match=====")
                    print(d)
                    print(origin)
                    return (True, d, origin)
    return (False, None, None)

def fuse(base, sc, origin):
    lst = []
    for i in sc:
        p = plus_coord(i, origin)
        lst.append(p)
    for i in lst:
        if i not in base:
            base.append(i)

def calculate_distance(a, b):
    x = abs(a[0]-b[0])
    y = abs(a[1]-b[1])
    z = abs(a[2]-b[2])
    return x+y+z

def main():
    n, sc = read_file()
    m = 1
    base = sc[0]

    visited = [0 for i in range(39)]
    visited[0] = 1

    all_sc = [[0, 0, 0]]
    
    while (m < n):
        for i in range(n):
            if visited[i] != 0:
                continue
            ret, direction, origin = match(base, sc[i])
            if ret:
                visited[i] = 1
                m += 1
                alter = change_direction(direction, sc[i])
                fuse(base, alter, origin)
                all_sc.append(origin)

    max_dis = 0
    for i in all_sc:
        for j in all_sc:
            dis = calculate_distance(i, j)
            if dis > max_dis:
                max_dis = dis
                
    print("=====number of beacons=====")       
    print(len(base))

    print("=====max distance=====")
    print(max_dis)
        
if __name__ == "__main__":
    main()
