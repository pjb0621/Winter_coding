#1330번 - 두 수 비교하기
h, m = input().split(' ')
h = int(h)
m = int(m)
if(h>m):
    print(">")
elif(h==m):
    print("==")
else:
    print("<")
