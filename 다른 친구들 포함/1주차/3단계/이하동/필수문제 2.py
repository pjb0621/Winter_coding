#10871번 - X보다 작은 수
N, X = input().split(' ')
N = int(N)
X = int(X)
L = list(input().split(' '))
for i in range(N):
    if(int(L[i])<X):
        print(L[i],end=" ")
