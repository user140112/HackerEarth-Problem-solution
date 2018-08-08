#include<bits/stdc++.h>
using namespace  std;

#define ll long long
vector<ll> v[50];
stack<ll> st;
int N;

int Binary_search(int i, int val)
{
	int l = 0, r = v[i].size();
	while(l<r)
	{
		int mid = (l+r)/2;
		if(v[i][mid]>val)
			r = mid;
		else
			l = mid+1;
	}
	if(v[i][l]>val)
		return l;
	return -1;
}
bool check()
{
		ll cur = st.top();
		for(int i=1;i<N;i++)
		{
			int ans = Binary_search(i,cur);
			if(ans==-1)
				return false;
			else
				cur = v[i][ans];
		}
		return true;
}


int main()
{
    int X,Y,q;
    cin>>N;

    for( int i=0; i<N; i++)
    {
        cin>>X;
        for( int j=0; j<X; j++ )
        {
            cin>>Y;
            v[i].push_back(Y);
        }
    }

    st.push(v[0][0]);
	for(int i=1;i<v[0].size();i++)
	{
		if(v[0][i]<st.top())
		{
			st.push(v[0][i]);
		}
		else
			st.push(st.top());
	}

	cin>>q;
	ll ind,k,val;
	int c=0;
	for(int i=0;i<q;i++)
	{
		cin>>ind;

		if(ind==1)
		{
			cin>>k>>val;
			k--;
			v[k].push_back(val);
			if(k==0)
			{

				if(val<st.top())
				{
					st.push(val);
				}
				else
				{
					st.push(st.top());
				}
			}
		}
		else if(ind==0)
		{
			cin>>k;
			k--;
			v[k].pop_back();
			if(k==0)
				st.pop();
		}
		else
		{
			if(check())
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}

	}

    return 0;
}

