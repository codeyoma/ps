L=[]
stack=[]

N=int(input())

for i in range(N):
    L.append(input())
    for j in range(len(L[i])):
        if L[i][j]=='(':
            stack.append(L[i][j])
        else:
            if stack and stack[-1] == '(':
                stack.pop(-1)
            else:
                stack.append(')')

    if len(stack)==0:
        print('YES')
    else:
        print('NO')
        stack=[]