#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A[31000],ng;
ll ns[31000];

int main()
{
    ll N;
    cin>>N;

    for( ll i=1; i<=N; i++ ) cin>>A[i];

    for( ll i=1; i<=N; i++ )
    {
        ll flag = -1;

        for( ll j=i+1; j<=N; j++ )
        {
            if( (flag == -1) and (A[j]>A[i]) )
            {
                ng = A[j];flag = -2;continue;
            }

            if( (flag==-2) and (A[j]<ng) )
            {
                ns[i]=A[j];flag=-3;break;
            }
        }

        if( (flag == -1) or (flag == -2) )
            ns[i]=-1;
    }

    for( ll i=1; i<=N; i++ )
        printf("%lld ",ns[i]);

    printf("\n");

    return 0;
}

