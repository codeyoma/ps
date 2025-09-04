
t = int(input()) #테스트케이스 개수

for i in range(t):
    p = input() #수행할 함수
    n = int(input()) #배열에 들어있는수의 개수
    j = input() #주어진 배열
    flag = 0
    f = 0
    l = []
    
    if len(j) > 2:
        j = j[1:-1]
        # print('짤른 j',j[1:-1])
        l = list(map(int,j.split(',')))
        # print('추출된 l','l: ',l)
    
    for e in p:
        if e == 'R' and flag == 0:
            flag = 1
        elif e == 'R' and flag == 1:
            flag = 0
        elif e == 'D' and len(l)>0:
            if flag == 0:
                l.remove(l[0])
            elif flag == 1:
                l.remove(l[-1])
        elif e == 'D' and len(l) == 0:
            print('error')
            f = 1
            break
        
    if flag == 0 and f == 0:
        print('[',end='')
        for i in range(len(l)):
            if i == (len(l) - 1) :
                print(l[i],end='')
            else :
                print(l[i],end=',')
        print(']')
    elif flag == 1 and f == 0:
        L = l[::-1]
        print('[',end='')
        for i in range(len(L)):
            if i == (len(L) - 1) :
                print(L[i],end='')
            else :
                print(L[i],end=',')
        print(']')