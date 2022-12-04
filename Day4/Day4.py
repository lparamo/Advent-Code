with open('inputDay4.txt') as file:
    input = file.read().splitlines()

def part1(input):
    ans = 0
    for line in input:
        points = re.split(',|-', line)
        s1, e1, s2, e2 = [int(x) for x in points]
        if s1 <= s2 and e2 <= e1 or s2 <= s1 and e1 <= e2:
            ans += 1
    return ans

def part2(input):
    ans = 0
    for line in input:
        points = re.split(',|-', line)
        s1, e1, s2, e2 = [int(x) for x in points]
        if s2 <= e1 and s1 <= e2:
            ans += 1
    return ans

print(part1(input))
print(part2(input))