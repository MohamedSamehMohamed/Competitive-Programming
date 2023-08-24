MOD = 10**9 + 7
N = 3010

m, n = map(int, input().split())
cnt = [0] * N
ans = 0
cur = []

def add(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def subtract(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def solve(pos, diff, prev):
    global ans
    if pos > m:
        if diff == n:
            ans += 1
            if ans >= MOD:
                ans -= MOD
        return
    if prev == -1:
        for i in range(1, n+1):
            cnt[i] += 1
            solve(pos + 1, 1, i)
            cnt[i] -= 1
    else:
        if prev > 1:
            cnt[prev - 1] += 1
            solve(pos + 1, diff + (1 if cnt[prev - 1] == 1 else 0), prev - 1)
            cnt[prev - 1] -= 1
        if prev < n:
            cnt[prev + 1] += 1
            solve(pos + 1, diff + (1 if cnt[prev + 1] == 1 else 0), prev + 1)
            cnt[prev + 1] -= 1

def stup(m1, n1):
    global m, n, cur, cnt, ans
    m = m1
    n = n1
    cur.clear()
    for i in range(1, n+1):
        cnt[i] = 0
    ans = 0
    solve(1, 0, -1)
    return ans

def get(m, n):
    dp = [[0] * (n+1) for _ in range(m+1)]
    for i in range(1, n+1):
        dp[1][i] = 1
    for i in range(2, m+1):
        for j in range(1, n+1):
            if j > 1:
                dp[i][j] = add(dp[i][j], dp[i-1][j-1])
            if j < n:
                dp[i][j] = add(dp[i][j], dp[i-1][j+1])
    ans = 0
    for i in range(1, n+1):
        ans = add(ans, dp[m][i])
    return ans

def f(m, n):
    if n <= 0:
        return 0
    return get(m, n)

ans = f(m, n)
tmp = f(m, n - 1)
tmp = add(tmp, tmp)
ans = subtract(ans, tmp)
tmp = f(m, n - 2)
ans = add(ans, tmp)
print(ans)
