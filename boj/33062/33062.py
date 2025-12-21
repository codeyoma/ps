# https://www.acmicpc.net/problem/33062
import sys
input = sys.stdin.readline

t = int(input())

def opt_solution():
	lower_bound = [0] * 11
	upper_bound = [0] * 11
	scope = [0] * 11

	lower_bound[1] = 4
	upper_bound[1] = 4

	for i in range(2, 11):
		lower_bound[i] = lower_bound[i - 1] * 10 + 4
		upper_bound[i] = upper_bound[i - 1] * 10 + 9
		scope[i] = scope[i - 1] * 10 + 5

	for _ in range(t):
		n = int(input())
		ans = 0

		for i in range(1, 11):
			if lower_bound[i] >= n:
				break

			if n > upper_bound[i]:
				ans += scope[i]
			else:
				ans += (n - (lower_bound[i] + 1)) + 1
		
		print(ans)



def naive_solution():

	for _ in range (t):
		n = int(input())

		dec = 10
		chain_low = 4
		chain_high = 4
		chain_low_bias = 4
		chain_high_bias = 9

		ans = 0

		while dec < n:
			dec *= 10
			chain_low *= 10
			chain_low += chain_low_bias
			chain_high *= 10
			chain_high += chain_high_bias
			if(n > chain_high):
				ans += (chain_high - (chain_low + 1) + 1)
			elif n > chain_low:
				ans += (n - (chain_low + 1) + 1)

		print(ans)

opt_solution()