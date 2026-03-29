import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


n, k = map(int, input().split())
adj = [[] for _ in range(n + 1)]

for _ in range(n - 1):
	x, y = map(int, input().split())
	adj[x].append(y)
	adj[y].append(x)

on = 0

def dfs(node: int, parent: int) -> int:
	global on

	d1, d2 = 0, 0

	for child in adj[node]:
		if child == parent:
			continue

		cand = dfs(child, node) + 1

		if cand > d1:
			d1, cand = cand, d1

		d2 = max(d2, cand)

	if d1 + d2 >= k:
		on += 1
		return -1

	return d1

dfs(1, 0)
print(on)

