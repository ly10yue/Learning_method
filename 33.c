#include <stdio.h>

int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a > n)
        a = n;
    if (b > n)
        b = n;
    long long count = 0;
    int turn = 1;
    int k[n + 1];
    for (int op = 0; op <= n; op++)
        k[op] = 0;
    k[0] = 1;
    while ((turn * (turn + 1) / 2) <= n)
    {
        for (int i = n; i >= 0; i--)
            if (i + turn <= n)
                k[i + turn] = (k[i + turn] + k[i]) % 1000000007;
        turn++;
    }
    for (int t = a; t >= n - b; t--)
        count += k[t];
    if (turn * (turn - 1) / 2 != n)
        printf("0");
    else
        printf("%lld", count % 1000000007);
}