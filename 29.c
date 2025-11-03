#include <stdio.h>
long long powh(long long a, long long b)
{
    long long res = 1;
    while (b){
        if (b & 1)
            res = res * a % 1000000007;
        a = a * a % 1000000007;
        b >>= 1;
    }
    return res;
}
long long count(long long t[], int i, int j)
{
    long long cou = 0;
    for (int x = i, y = j; x <= y; x++)
        cou = cou + t[x];
    return cou % 1000000007;
}
long long C[1001][1001];
void init_comb(){
    for (int i = 0; i <= 1000; i++){
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000006;
    }
}

long long trans(int n, int i, int j, int cut)
{
    int remain = n - j + i - 1;
    int piece = 2;
    if (i == 0)
        piece--;
    if (j == n - 1)
        piece--;
    if (piece == 0 || cut < 0)
        return 0;
    else
        return C[remain - piece][cut - piece];
}
int main()
{
    init_comb();
    int n, m;
    scanf("%d%d", &n, &m);
    long long t[n];
    long long ans = 1;
    for (int i = 0; i < n; i++)
        scanf("%lld", &t[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (trans(n, i, j, m - 1))
            {
                long long cc = trans(n, i, j, m - 1) % 1000000006;
                ans = (ans * powh(count(t, i, j), cc)) % 1000000007;
            }
        }
    }
    if (m == 1)
        printf("%lld", count(t, 0, n - 1));
    else
        printf("%lld", ans);
}

/*#include <stdio.h>
long long powh(long long a, long long b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % 1000000007;
        a = a * a % 1000000007;
        b >>= 1;
    }
    return res;
}
long long count(long long t[], int i, int j)
{
    long long cou = 0;
    for (int x = i, y = j; x <= y; x++)
        cou = cou + t[x];
    return cou % 1000000007;
}
long long C[1001][1001];
void init_comb()
{
    for (int i = 0; i <= 1000; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000006;
    }
}
long long trans(int n, int i, int j, int cut)
{
    int remain = n - j + i - 1;
    int piece = 2;
    if (i == 0)
        piece--;
    if (j == n - 1)
        piece--;
    if (piece == 0 || cut < 0)
        return 0;
    else
        return C[remain - piece][cut - piece];
}
int main()
{
    init_comb();
    int n, m;
    scanf("%d%d", &n, &m);
    long long t[n];
    long long ans = 1;
    for (int i = 0; i < n; i++)
        scanf("%lld", &t[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (trans(n, i, j, m - 1))
            {
                long long cc = trans(n, i, j, m - 1) % 1000000006;
                ans = (ans * powh(count(t, i, j), cc)) % 1000000007;
            }
        }
    }
    if (m == 1)
        printf("%lld", count(t, 0, n - 1));
    else
        printf("%lld", ans);
}*/