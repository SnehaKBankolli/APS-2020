n=int(input())
arr=[[[0,0]for i in range(n)]for j in range(2*n)]
pm=[dict() for i in range(n+5)]
pw=[dict() for i in range(n+5)]
mpc=[0]*(n+5)
wpc=[0]*(n+5)
porp=[0]*(n+5)
for i in range(n):
    u=[int(o) for o in input().split()]
    for j in range(n):
        arr[i][j][0]=u[j]
        pm[i+1][u[j]]=j+1

for i in range(n):
    u=[int(o) for o in input().split()]
    for j in range(n):
        arr[i][j][1]=u[j]
        pw[j+1][i+1]=u[j]
for _ in range(n):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if mpc[i]==0:
                porp[pm[i][j]]+=1;
                if not wpc[pm[i][j]] or wpc[pm[i][j]]>pw[pm[i][j]][i]:
                    mpc[wpc[pm[i][j]]]=0
                    wpc[pm[i][j]]=i
                    mpc[i]=pm[i][j]
for _ in range(int(input())):
    print(porp[int(input())])
