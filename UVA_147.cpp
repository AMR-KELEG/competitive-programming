//AC
#include <bits/stdc++.h>
using namespace std;
long long notes[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
long long dp2[30001][11]={};

int main() {
	freopen("in.txt","r",stdin);
	
	for(int in=0;in<11;in++)
	{
		dp2[notes[in]][in]=1;
	}

	for(long long int val=0;val<=30000;val++)
	{
		for(int in=0;in<11;in++)
		{
			if(val+notes[in]<=30000)
			{
				dp2[val+notes[in]][in]+=dp2[val][in];
			}
			for(int start=in+1;start<11;start++)
			{
				if(val+notes[start]<=30000)		
					dp2[val+notes[start]][start]+=dp2[val][in];			
			}
		}
	} 
	long double v;
	cin>>v;
	int val=round(v*100);

	while(val!=0)
	{
		long long int sol2=0;
		for(int i=0;i<11;i++)
			sol2+=dp2[val][i];

		cout<<fixed<<setw(6)<<setprecision(2)<<val/100.0;
		cout<<fixed<<setw(17)<<sol2<<endl;
		cin>>v;
	    val=round(v*100);
	}
	return 0;
}