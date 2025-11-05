//3.5.6运行超时，4段错误

#include <stdio.h>
#include <stdlib.h>
#define min(a, b) (a < b ? a : b)
int findway(int a, int b, int n)
{
    int count = 0;
    int minx = b + 1;
    int k1[b + 2];
    for (int i = 0; i < b + 2; i++)
        k1[i] = 0;
    k1[a] = 1;
    while (1)
    {
        if (k1[b])
            break;
        count++;
        for (int i = 0; i < b + 2; i++)
        {
            if (k1[i] == count)
            {
                if (i - 1 > 0)
                    k1[i - 1] = count + 1;
                if(i+1<=b)k1[i + 1] = count + 1;
                if (i * n <= b)
                    k1[i * n] = count + 1;
                else
                    minx = min(minx, count + i * n - b);
            }
        }
    }
    return min(count, minx);
}
int findroad(int a, int b, int n)
{
    int count = 0;
    if ((a * b > 0 && abs(a) > abs(b)) || b == 0)
        return abs(a - b);
    if (a * b < 0)
    {
        if (a < 0)
        {
            count += 1 - a;
            a = 1;
        }
        else
        {
            a *= -1;
            b *= -1;
            count += 1 - a;
            a = 1;
        }
    }
    if (a < 0 && b < 0)
    {
        a = -a;
        b = -b;
    }
    if (b == 0)
        return abs(a);
    count += findway(a, b, n);

    return count;
}

int main()
{
    int t;
    scanf("%d", &t);
    int a, b, n;
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d%d", &a, &b, &n);
        int count = findroad(a, b, n);
        printf("%d\n", count);
    }
}
