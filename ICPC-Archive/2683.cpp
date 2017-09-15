//AC
#include "bits/stdc++.h"
using namespace std;
string to32int(int no)
{
	string ans(32,'0');
	int i=31;
	while(no>0)
	{
		ans[i--]=(no%2)+'0';
		no/=2;
	}
	// cout<<ans<<endl;
	return ans;
}
struct node
{
	node * haszero;
	node * hasone;
	node():haszero(nullptr),hasone(nullptr){};
};
struct trie
{
	node * root;
	trie():root(new node()){}
	long long int maxsum(const string &s)
	{
		long long int ans=0;
		node * no=root;
		int i=0;
		while(i<32)
		{
			if(s[i]=='0')
			{
				if(no->hasone)
				{
					ans+=ceil(pow(2,31-i));
					no=no->hasone;
					i++;
				}
				else
				{
					no=no->haszero;	
					i++;
				}
			}
			else
			{
				if(no->haszero)
				{
					ans+=ceil(pow(2,31-i));
					no=no->haszero;
					i++;
				}
				else
				{
					no=no->hasone;
					i++;
				}

			}
		}
		return ans;
	}
	void addno(const string &s)
	{
		int i=0;
		node * no=root;
		bool change=1;
		while(change && i<32)
		{
			change=0;
			if(s[i]=='0' && no->haszero!=nullptr)
			{
				no=no->haszero;
				change=1;
				i++;
			}
			else if(s[i]=='1' && no->hasone!=nullptr)
			{
				no=no->hasone;
				change=1;
				i++;
			}
		}
		if(i==32)
			return;
		while(i<32)
		{
			if(s[i]=='0')
			{
				node * newn=new node();
				no->haszero=newn;
				no=newn;
				i++;
			}
			else if(s[i]=='1')
			{
				node * newn=new node();
				no->hasone=newn;
				no=newn;
				i++;
			}
		}

	}
	void deleteno(node * root)
	{
		if(root!=nullptr)
		{
			deleteno(root->haszero);
			deleteno(root->hasone);
			delete root;
		}
	} 
	~trie()
	{
		deleteno(root);
	}
};
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		// cout<<t<<endl;
		cin>>n;
		long long int ans=0;
		int a;
		if(n==1)
		{
			cin>>a;
			ans=a;
		}
		else
		{
			long long int curval=0;
			cin>>a;
			curval^=a;
			trie t;
			t.addno(to32int(curval));
			n--;
			while(n--)
			{
				cin>>a;
				curval^=a;
				string s=to32int(curval);
				t.addno(s);
				ans=max(ans,t.maxsum(s));
				ans=max(ans,curval);
			}
	/*	
	*/
		}
		cout<<ans<<endl;
	}
}