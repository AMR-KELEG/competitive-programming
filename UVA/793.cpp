//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> rep;
int find(int x)
{
	if(rep[x]!=x)
	{
		//cout<<x<<" "<<rep[x]<<endl;
		rep[x]=find(rep[x]);
	}
	return rep[x];
}
void join(int x,int y)
{
	int xrep=find(x);
	int yrep=find(y);
	if(xrep<yrep)
	{
		rep[yrep]=xrep;
	}
	else
	{
		rep[xrep]=yrep;
	}
//	cout<<x<<" "<<y<<" "<<rep[x]<<" "<<rep[y]<<endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
		/*
		int n=5;
		rep=std::vector<int> (n+2);
		for(int i=1;i<=n;i++)
			rep[i]=i;

		join(1,2);
		cout<<rep[1]<<" "<<rep[2]<<endl;
		find(1);
		if(find(1)==find(2))
			cout<<"con\n";
		else
			cout<<"not\n";
			*/
	int t;
	cin>>t;
	int n;
	int suc=0,fail=0;
	string c;
	int a,b;
	cin>>n;
	while(t--)
	{
		suc=0;
		fail=0;
		rep=std::vector<int> (n+2);
		for(int i=1;i<=n;i++)
			rep[i]=i;
		while(cin>>c)
		{
			if(c=="c")
			{
				cin>>a>>b;
				join(a,b);
				/*
				for(int i=1;i<=n;i++)
					cout<<i<<" ";
				cout<<endl;
				for(int i=1;i<=n;i++)
					cout<<rep[i]<<" ";
				cout<<endl<<endl;
				*/
			}
			else if(c=="q")
			{
				cin>>a>>b;
				/*
				find(a);
				find(b);
				cout<<"F\n";
				for(int i=1;i<=n;i++)
					cout<<i<<" ";
				cout<<endl;
				for(int i=1;i<=n;i++)
					cout<<rep[i]<<" ";
				cout<<endl;
				*/
				if(find(a)==find(b))
				{
	//				cout<<"suc\n"<<endl;
					suc++;
				}
				else
					fail++;
			}
			else
			{
				n=atoi(c.c_str());
				break;
			}
		}
		cout<<suc<<","<<fail<<endl;
		if(t>0)
			cout<<"\n";
	}	
		/*
	*/
}