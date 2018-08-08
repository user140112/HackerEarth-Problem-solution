#include<bits/stdc++.h>
using namespace std;

int ng[1000010],pg[1000010];
long long A[1000100];

int main()
{
    int N;
    cin>>N;

    for( int i=1; i<=N; i++ ) cin>>A[i];

    stack<int> st;

    st.push(1);

    for( int i=2; i<=N; i++ ){
        while( st.size() and A[st.top()] < A[i] ){
            ng[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }

    while(st.size()){
        ng[st.top()]=-1;
        st.pop();
    }


    st.push(N);

    for( int i=N-1; i>=1; i-- ){
        while( st.size() and A[st.top()] < A[i] ){
            pg[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }

    while(st.size()){
        pg[st.top()]=-1;
        st.pop();
    }

    for( int i=1; i<=N; i++ ){
        printf("%d",pg[i]+ng[i]);
        if( i != N )
            printf(" ");
    }

    printf("\n");

    return 0;
}

