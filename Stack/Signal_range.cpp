#include<bits/stdc++.h>
using namespace std;

int A[1000100],rs[1000100];

int main()
{
    int T;
    cin>>T;
    while(T--){

        int N;
        cin>>N;

        for( int i=1; i<=N; i++ ) cin>>A[i];
        for( int i=1; i<=N; i++ ) rs[i]=1;

        stack<int> st;

        st.push(1);
        for( int i=2; i<=N; i++ ){
            while( st.size() and ( A[st.top()] <= A[i] ) ){
                rs[i]=rs[i]+rs[st.top()];
                st.pop();
            }
            st.push(i);
        }

        for( int i=1; i<=N; i++ )
            printf("%d ",rs[i]);
        printf("\n");

        while(!st.empty()) st.pop();

    }

    return 0;
}

