#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	std::vector<int> x,y;
	std::vector<bool> inhull;
	int n;
	int temp;
	bool done=0;
	while(!done)
	{
		cout<<t<<endl;
		while(t--)
		{	
			cin>>n;
			x=std::vector<int> (n);
			y=std::vector<int> (n);
			inhull=std::vector<bool> (n,0);
			n--;
			for(int i=0;i<n+1;i++)
			{
				cin>>x[i]>>y[i];
				//cout<<x[i]<<" "<<y[i]<<endl;
			}
			cin>>x[0]>>y[0];
			int start=0;
			for(int i=0;i<n+1;i++)
			{
				if(y[i]<y[start])
					start=i;
				else if(y[i]==y[start])
				{
					if(x[i]<x[start])
						start=i;
				}
				cout<<x[i]<<" "<<y[i]<<endl;
			}
			cout<<"s "<<start<<" "<<x[start]<<" "<<y[start]<<endl;
			int first=start;
			int second=n+1;
			int v1x,v1y,v2x,v2y; 
			inhull[start]=1;
			while(second!=start)
			{
				second=start;
				for(int i=0;i<n;i++)
				{
					if(!inhull[i])
					{
						second=i;
						for(int j=0;j<n;j++)
						{
							v1x=x[j]-x[second];
							v1y=y[j]-y[second];
							v2x=x[first]-x[second];
							v2y=y[first]-y[second];
							if(v1x*v2y>v2x*v1y)
								second=j;
						}
						cout<<x[first]<<" "<<y[first]<<" "<<x[second]<<" "<<y[second]<<endl;
						inhull[second]=1;
						first=second;
						i=n;
					}
				}				
			}
			cout<<endl;
			std::vector<int> ver;
			int i=start;
			do
			{
				if(inhull[i])
					ver.push_back(i);
				i=(i+1)%n;
			}
			while(i!=start);
			cout<<ver.size()+1<<endl;
			for(int i=0;i<ver.size();i++)
				cout<<x[ver[i]]<<" "<<y[ver[i]]<<endl;
			cout<<x[ver[0]]<<" "<<y[ver[0]]<<endl;

			if(t>0)
			{
				cin>>temp;
				cout<<-1<<endl;
			}
			else if(cin>>t)
			{
				if(t==0)
				{
					done=1;
					break;
				}
				cout<<endl<<t<<endl;
			}
			else
			{
				done=1;
				break;
			}

		}


	}	
}