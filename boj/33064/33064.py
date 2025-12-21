# https://www.acmicpc.net/problem/33064
import sys
from collections import defaultdict
import copy
import string

input = sys.stdin.readline

def is_moo(string):
	if string[0] != string[1] and string[1] == string[2]:
		return True
	return False

n, f = map(int, input().split())
s = input().strip()

d = defaultdict(set)
a = set()

# check default moo
for i in range(n - 2):
	temp = s[i:i+3]
	if is_moo(temp):
		d[temp].add(i)
		if len(d[temp]) >= f:
			a.add(temp)

# try
for i in range(n):
	for x in range(3):
		start = i - x
		end = start + 2
		if start < 0 or end >= n:
			continue

		t = s[start] + s[start + 1] + s[end]

		pos = 2 - x

		# make moo pattern
		for c in string.ascii_lowercase:
			tt = list(t)
			tt[pos] = c
			tt = "".join(tt)

			if is_moo(tt):
				# check intersection
				if len(d[tt]) + 1 >= f:
					conflict = False

					for prev in d[tt]:
						if abs(prev - start) <= 2:
							conflict = True
							break
					
					if conflict == False:
						a.add(tt)


# print
L=sorted(list(a))
print(len(L))
print(*L, sep="\n")