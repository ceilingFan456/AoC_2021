hall_points = [0, 1, 3, 5, 7, 9, 10]
room_entry = [2, 4, 6, 8]
hallway = [0 for i in range(11)]
rooms = [["D", "C"], ["A", "C"], ["B", "B"], ["A", "D"]] ## stack
energy = {"A":1, "B": 10, "C": 100, "D": 1000}

def print_board():
    for i in range(11):
        if hallway[i] != 0:
            print(hallway[i], end=" ")
        else:
            print("@", end="")
    print()
    for i in range(2):
        print("@@", end="")
        for j in range(4):
            if rooms[j][i] != 0:
                print(rooms[j][i], end=" @")
            else:
                print("@", end="@")
        print("@")


