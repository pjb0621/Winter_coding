
# N = int(input())
# for i in range(N):
#     count = 0
#     L = list(map(int, input().split(' ')))
#     Average = sum(L[1:]) / L[0]
#     for j in L[1:]:
#         if j>Average:
#             count += 1
#
#     print(  "{:.3f}%".format((count*100/L[0])) )

# L = list(map(int, input().split()))
# L.sort()
# print(L[0]*L[-1])
N = int(input())
L=[]
for i in range(N):
    a = int(input())
    L.append(a)
L.sort()
for i in L:
    print(i)
# for i in range(N):
#     A, B = input().split(' ')
#     A = int(A)
#     B = int(B)
#     C, D = A, B
#     if (A < B):
#         A, B = B, A
#
#     while (B > 0):
#         tmp = A
#         A = B
#         B = tmp % B
#
#     print(int(C * D / A))








