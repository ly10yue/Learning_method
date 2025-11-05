#include <stdio.h>
#define MOD 1000000007

long long powh(long long a, long long b)
{
    long long res = 1;
    while (b){
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long und(int k,int d){
    long long ret=0;
    ret=k*(powh(10,d+1)-1)*111111112%MOD;
    return ret;
}
int main(){
    char a[100001];
    scanf("%s",a);
    long long ans = 0;
    int len = 0;
    while(a[len]!='\0')
        len++;
    len--;
    int t = len;
    long long now=0;
    while(t>=0){
        if(a[t]!='0'){
        now = (now+und((int)(a[t]-'0'), len - t))%MOD;
        ans=(ans+now)%MOD;
    }
        t--;
    }
    printf("%lld",ans%MOD);
}
