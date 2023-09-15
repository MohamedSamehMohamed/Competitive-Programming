import sys

n = 0
m = 0
h = []
sz = []
s = []
mini = []
dp = []

def get(j, q, i):
    global m, sz, h, s, dp

    if j > q:
        return float('inf')

    if q < m:
        need = q - j
        if need < 1 or need > sz[i]:
            return float('inf')
        return max(dp[i + 1][q] - h[q], 1) + s[i][need]
    else:
        need = max(1, q - j)
        if need < 1 or need > sz[i]:
            return float('inf')
        return max(dp[i + 1][q] - h[q], 1) + s[i][need]

def solve(l, r, tl, tr, i):
    global dp, mini

    if l > r:
        return
    m = (l + r) // 2
    p = tl
    for j in range(tl, tr + 1):
        if get(m, j, i) < get(m, p, i):
            p = j

    dp[i][m] = get(m, p, i)
    if dp[i][m] < 1e15:
        mini[i] = min(mini[i], m)
    solve(l, m - 1, tl, p, i)
    solve(m + 1, r, p, tr, i)

def main():
    global n, m, h, sz, s, mini, dp

    n, m = map(int, sys.stdin.readline().split())
    h = [0] + list(map(int, sys.stdin.readline().split()))
    sz = [0] * (n + 1)
    s = [[0] for _ in range(n + 1)]
    mini = [1e9] * (n + 1)
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        s[i] = list(map(int, sys.stdin.readline().split()))
        sz[i] = s[i][0]
        s[i][0] = 0
        s[i].sort()
        
        for j in range(1, sz[i] + 1):
            s[i][j] += s[i][j - 1]
        for j in range(1, sz[i] + 1):
            s[i][j] += s[i][j - 1]

    for j in range(1, m + 1):
        need = max(1, m - j)
        if need > sz[n]:
            dp[n][j] = float('inf')
        else:
            dp[n][j] = s[n][need] + 1
            mini[n] = min(mini[n], j)

    for i in range(n - 1, 0, -1):
        solve(1, m, 1, m, i)

    print(dp[1][1])

if __name__ == "__main__":
    main()
