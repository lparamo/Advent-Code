import re
with open('inputDay4.txt') as file:
    input = file.read().splitlines()

    cont1 = 0
    cont2 = 0
    for line in input:
        val = re.split(',|-', line)
        x1, y1, x2, y2 = [int(x) for x in val]
        if x1 <= x2 and y2 <= y1 or x2 <= x1 and y1 <= y2:
            cont1 += 1

        if x2 <= y1 and x1 <= y2:
            cont2 += 1

print(cont1)
print(cont2)