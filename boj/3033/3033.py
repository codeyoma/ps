# https://www.acmicpc.net/problem/3033
import sys
input = sys.stdin.readline

L = int(input())
S = input()

base = 31
mod = 1234567891
po = [0] * L
po[0] = 1
for i in range(1, L):
	po[i] = po[i - 1] * base % mod

low = 1
high = L - 1
answer = 0

while low <= high:
	mid = low + ((high - low) // 2)

	found = False

	hash = 0
	for i in range(mid):
		hash *= 31
		hash %= mod
		hash += ord(S[i]) - ord('a') + 1
		hash %= mod 

	check = {}
	
	for i in range(0, L - mid + 1):

		if hash in check:
			for j in check[hash]:
				if S[j:j + mid] == S[i:i + mid]:
					found = True
					break
			check[hash].append(i)
			if found:
				break

		else:
			check[hash] = [i]

		hash += mod - (ord(S[i]) - ord('a') + 1) * po[mid - 1]
		hash %= mod
		hash *= base
		hash %= mod

		if i + mid < L:
			hash += ord(S[i + mid]) - ord('a') + 1
			hash %= mod

	if found:
		answer = mid
		low = mid + 1
	else:
		high = mid - 1

print(answer)
