#include<bits/stdc++.h>
using namespace std;

int a[1000100],t[1000100];

int main()
{
    int n;
    cin>>n;
    for( int i=0; i<n; i++ ) cin>>a[i];
    sort( a, a+n);

    for( int i=0; i<n; i++ ) t[i]=1;
    int k=n-2;

    for( int i=n-1; i>=0; i-- )
    {
        while(k>=0)
        {
            if( a[k]<a[i] )
            {
                if(t[i]!=0)
                {
                    t[i]=1;
                }
                t[k]=0;
                k--;
                break;
            }
            k--;
        }
        if(k<0) break;
    }

    int ans=0;
    for( int i=0; i<n; i++ )
    {
        if(t[i]==1) ans+=a[i];
    }
    printf("%d\n",ans);

    return 0;
}
