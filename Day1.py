with open("inputDay1.txt", "r", encoding="utf-8") as input:
    data = input.read().splitlines()

calorias_elfo: list[int] = []
sum1 = 0

for value in data:
    if value:
        sum1 += int(value)
    else:
        calorias_elfo.append(sum1)
        sum1 = 0


# part 1
print(max(calorias_elfo))

# part 2
calorias_elfo.sort(reverse=True)
print(sum(calorias_elfo[:3]))