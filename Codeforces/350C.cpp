//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<pair<int,int> >b(n);
	std::vector<int> x(n);
	std::vector<int> y(n);
	int k=0;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		k+=2+(2*( (x[i]!=0) + (y[i]!=0)) );
		b[i]=pair<int,int>((abs(x[i])+abs(y[i])),i);
	}	
	sort(b.begin(), b.end());
	cout<<k<<endl;
	int index;
	for(int i=0;i<n;i++)
	{
		index=b[i].second;
		if(x[index]>0)
		{
			printf("%c %d %c\n",'1',x[index],'R');
		}
		else if(x[index]<0)
		{
			printf("%c %d %c\n",'1',-x[index],'L');	
		}
		if(y[index]>0)
		{
			printf("%c %d %c\n",'1',y[index],'U');
			
		}
		else if(y[index]<0)
		{
			printf("%c %d %c\n",'1',-y[index],'D');
		}
		printf("%c\n",'2');
		if(x[index]>0)
		{
			printf("%c %d %c\n",'1',x[index],'L');
		}
		else if(x[index]<0)
		{
			printf("%c %d %c\n",'1',-x[index],'R');	
		}
		if(y[index]>0)
		{
			printf("%c %d %c\n",'1',y[index],'D');
		}
		else if(y[index]<0)
		{
			printf("%c %d %c\n",'1',-y[index],'U');
		}
		printf("%c\n",'3');
		
	}
}