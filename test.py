import sys
input = sys.stdin.readline

N, K = map(int, input().split())

total = [0] * 20
potential_correct = [[0] * 20 for _ in range(20)]
potential_correct_exclude = [[[0] * 20 for _ in range(20)] for __ in range(20)]

for _ in range(K):
    x, y, z = map(int, input().split())
    x -= 1
    y -= 1
    z -= 1

    total[x] += 1
    broken[x][y] += 1
    broken[x][z] += 1
    overlap_broken[x][y][z] += 1
    overlap_broken[x][z][y] += 1

maxScore = 0
ways = 0

for mask in range(1 << N):
    score = 0

    for x in range(N):
        if not (mask & (1 << x)):
            continue

        cnt = 0

        for i in range(N):
            if mask & (1 << i):
                cnt += broken[x][i] #include

        for i in range(N):
            if not (mask & (1 << i)):
                continue

            for j in range(i + 1, N):
                if mask & (1 << j):
                    cnt -= overlap_broken[x][i][j] #exclude

        score += total[x] - cnt 

    if score > maxScore:
        maxScore = score
        ways = 1
    elif score == maxScore:
        ways += 1

print(maxScore, ways)

