# https://www.acmicpc.net/problem/33508
import sys
input = sys.stdin.readline


n = int(input())
a = list(map(int, input().split()))

answer = 0

left_table = set()
right_table = [0] * (n + 1)

for x in a:
	right_table[x] += 1

for x in a:

	if right_table[x] == 2:
		if x in left_table:
			answer += len(left_table) - 1
		else:
			answer += len(left_table)

	right_table[x] -= 1
	left_table.add(x)
	

# n^2
# table = {}

# for i in a:
# 	for x in table:
# 		if x == i:
# 			continue

# 		table[x][i] = table[x].get(i, 0) + 1

# 		if table[x][i] == 2:
# 			answer += 1

# 		pass

# 	if not i in table:
# 		table[i] = {}

# for _ in table:
# 	print(_)
print(answer)