#include <bits/stdc++.h>
using namespace std;
void show(vector<int> & v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

int findSwaps(vector<int> & v,vector<int> & in)
{
	int ans=0;
	vector<bool>vis(v.size(),0);
	for(int i=0;i<v.size();i++)
	{
		if(vis[i] || v[i]==in[i])
			continue;
		else
		{
			set<int>s;
			s.insert(i);
			vis[i]=1;
			int next;
			for(int j=0;j<v.size();j++)
			{
				if(v[j]==in[i])
				{
					next=j;
					break;
				}
			}
			while(s.find(next)==s.end())
			{
				vis[next]=1;
				s.insert(next);
				for(int j=0;j<v.size();j++)
				{
					if(v[j]==in[next])
					{
						next=j;
						break;
					}
				}	
			}
			ans+=(int)s.size()-1;
		}
		
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		cin>>n;
		vector<int> v(n),in(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			in[i]=v[i];
		}
		sort(v.begin(),v.end());
		int ans = n;
		do
		{
			//1) Check if inc then dec
			int i=1;
			bool valid=true;
			for(;i<v.size();i++)
			{
				if(v[i]<v[i-1])
				{
					i++;
					break;
				}
			}
			for(;i<v.size();i++)
			{
				if(v[i]>v[i-1])
				{
					valid=0;
					break;
				}	
			}
			if(valid)
				ans=min(ans,findSwaps(v,in));
		}while(next_permutation(v.begin(),v.end()));
		/*
			while(next_perm)
			{
				1) Check that the Nos are inc then dec
				2) If valid - find no of swaps req
			}
		
		*/
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}
