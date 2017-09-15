//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	long long int sum=0;
	long long int size=1;
	priority_queue< pair<int,int> >qu;//store the end,value	
	stack<int>num;
	int t;
	int x,a,k;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(t==1)
		{
			//a and x
			cin>>a>>x;
			qu.push(pair<int,int>(a,x));//a is the end
			sum+=(a*x);
		}
		else if(t==2)
		{
			cin>>k;
			num.push(k);
			sum+=k;
			size++;
		}
		else
		{
			//remove
			int ei=size,v=0;
			int eni=0,val=0;
			
			while(!qu.empty() && ei==size)
			{
				v=qu.top().second;
				ei=qu.top().first;
				if(ei==size)
				{
					eni=ei-1;
					sum-=v;
					val+=v;
					qu.pop();
				}
			}
			if(eni>0)
				qu.push(pair<int,int>(eni,val));
			sum-=num.top();
			num.pop();
			size--;

		}
		printf("%0.10f\n",1.0*sum/size);
		//cout<<fixed<<setprecision(10)<<1.0*sum/size<<endl;
	}
}