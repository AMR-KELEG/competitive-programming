#include "bits/stdc++.h"
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	int m,s;
	cin>>m>>s;
	if(m==1 &&s==0)cout<<"0 0";
	else if(s==0)cout<<"-1 -1";
	else
	{
		string min_s="1"+string(m-1,'0');
		string max_s="1"+string(m-1,'0');
		//cout<<max_s<<endl;
		int min_m=s-1,max_m=s-1;

		for(int i=m-1;i>0 && min_m>0;i--)
		{
			min_s[i]+=min(9,min_m);
			min_m-=min(9,min_m);
		}
		min_s[0]+=min(8,min_m);
		min_m-=min(8,min_m);

		max_s[0]+=min(8,max_m);
		max_m-=min(8,max_m);
		for(int i=1;i<m && max_m>0;i++)
		{
			max_s[i]+=min(9,max_m);
			max_m-=min(9,max_m);
		}
		if(max_m==0 && min_m==0)
		{
			cout<<min_s<<" "<<max_s;
		}
		else
		{
			cout<<"-1 -1";
		}
	}	
	return 0;
}