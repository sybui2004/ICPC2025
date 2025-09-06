MOD = 10**9 + 7

N, M = map(int, input().split())
INF = M + 1

dp = {(INF, INF, INF): 1}  
for _ in range(N):
    ndp = {}
    for (a, b, c), cnt in dp.items():
        for v in range(1, M + 1):
            if v <= a:
                nxt = (v, b, c)
            elif v <= b:
                nxt = (a, v, c)
            elif v <= c:
                nxt = (a, b, v)
            else:
                continue 
            ndp[nxt] = (ndp.get(nxt, 0) + cnt) % MOD
    dp = ndp

ans = 0
for (a, b, c), cnt in dp.items():
    if c <= M: 
        ans = (ans + cnt) % MOD

print(ans)

