#include<bits/stdc++.h>
using namespace std;

int a[100100],t[100100],f[100100],rs[100100];
stack<int> st;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
    int n;
    cin>>n;

    for( int i=0; i<n; i++ )
    {
        int x;
        cin>>x;
        a[i]=x;
        t[x]++;
    }

    for( int i=0; i<n; i++ )
    {
        f[i]=t[a[i]];
    }

    for( int i=0; i<n; i++ ) rs[i]=-1;
    st.push(0);

    for( int i=1; i<n; i++ )
    {
        while( st.size()  and f[i]>f[st.top()] )
        {
            rs[st.top()]=a[i];
            st.pop();
        }
        st.push(i);
    }

    for( int i=0; i<n; i++ ) printf("%d ",rs[i]);
    printf("\n");

    while(!st.empty()) st.pop();
    for(int i=0; i<100100; i++ ) t[i]=0;

    }

    return 0;
}

