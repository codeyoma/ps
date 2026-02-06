# 4
# 3 3 3 3
# 3 3 6 3
# 2 2 6 6
# 6 2 1 5

n = int(input())

max_value = 0

for i in range(n):
	L = list(map(int, input().split()))
	s = dict()

	for e in L:
		if e in s:
			s[e] += 1
		else:
			s[e] = 1

	l_s = list(s)
		
	if len(l_s) == 1: # 다 같은 경우
		max_value = max(max_value, 50000 + max(l_s) * 5000 )
	elif len(l_s) == 4: # 다 다른 경우
		max_value = max(max_value, max(l_s) * 100 )
	elif len(s) == 3: # 어떤 값이 2개 등장함
		for e in s:
			if s[e] == 2:
				max_value = max(max_value, 1000 + e * 100 )
	else: # 2개, 2개 씩 등장 or 3개, 1개 케이스
		flag = True

		for e in s:
			if s[e] == 3:
				max_value = max(max_value, 10000 + e * 1000 )
				flag = False

		if flag == True:
			temp = list(s)
			max_value = max(max_value, 2000 + temp[0] * 500 + temp[1] * 500)


print(max_value)