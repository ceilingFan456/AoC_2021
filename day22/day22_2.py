def find_min_max(lst):
    tmp = []
    for ele in lst:
        tmp.extend(ele)
    return (min(tmp), max(tmp))
    
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
            edges = list(map(lambda x: int(x), axis[2:].split("..")))
            edges[0], edges[1] = edges[0]-0.5, edges[1]+0.5
            ele.append(edges)
        ele.append(op)
        row.append(ele)
    return row

def change_to_dict(lst):
    dic_value_to_idx = {}
    dic_idx_to_value = {}
    for i in range(len(lst)):
        dic_value_to_idx[lst[i]] = i
        dic_idx_to_value[i] = lst[i]
    return (dic_value_to_idx, dic_idx_to_value)

def find_points(ins):
    lst = []
    for i in ins:
        lst.extend(i)
    lst = list(set(lst))
    lst.sort()
    return change_to_dict(lst)

def process_ins(ins, dic_x, dic_y, dic_z):
    new_ins = []
    for x, y, z, op in ins:
        new_x = list(map(lambda x: dic_x[x], x))
        new_y = list(map(lambda x: dic_y[x], y))
        new_z = list(map(lambda x: dic_z[x], z))
        new_ins.append([new_x, new_y, new_z, op])
    return new_ins

def main():
    ins = read_file("1.in")
    dic_x, table_x = find_points(list(map(lambda x: x[0], ins)))
    dic_y,table_y = find_points(list(map(lambda x: x[1], ins)))
    dic_z,table_z = find_points(list(map(lambda x: x[2], ins)))
    ins = process_ins(ins, dic_x, dic_y, dic_z) ## front is inclusive, back is exclusive
    result = 0
    for i in range(9):
        for j in range(9):
            for k in range(9):
                offset_x, offset_y, offset_z = 100 * i, 100 * j, 100 * k
                ## block 0-99, 100-199, 200-299, ...
                cube = [[[0 for p in range(100)] for q in range(100)] for r in range(100)]
                for x, y, z, op in ins:
                    x_lower = max(0, x[0] - offset_x)
                    x_upper = min(100, x[1] - offset_x)
                    y_lower = max(0, y[0] - offset_y)
                    y_upper = min(100, y[1] - offset_y)
                    z_lower = max(0, z[0] - offset_z)
                    z_upper = min(100, z[1] - offset_z)
                    for p in range(x_lower, x_upper):
                        for q in range(y_lower, y_upper):
                            for r in range(z_lower, z_upper):
                                cube[p][q][r] = op
                count = 0
                for p in range(100):
                    for q in range(100):
                        for r in range(100):
                            if cube[p][q][r] == 1:
                                x = p + offset_x
                                y = q + offset_y
                                z = r + offset_z
                                num_x = table_x[x+1] - table_x[x]
                                num_y = table_y[y+1] - table_y[y]
                                num_z = table_z[z+1] - table_z[z]
                                count += num_x * num_y * num_z
                result += count
                print("done with ", end="")
                print((i, j, k, result))
    print(result)
    
if __name__ == "__main__":
    main()
    
            
            
