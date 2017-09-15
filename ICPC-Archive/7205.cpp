//AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<long long int> x,y;
std::vector<long long int> a;
long long int totalArea;
long long int area(int start,int NoOfPoints)
{
	long long int ans=0;
	int end=(start+NoOfPoints-1)%n;
	if(end<start)
	{
		ans+=a[n-1]-a[start];
		ans+=(x[0]-x[n-1])*(y[0]+y[n-1]);
		ans+=a[end]-a[0];
		ans+=(x[start]-x[end])*(y[start]+y[end]);
	}
	else
	{
		ans+=a[end]-a[start];
		ans+=(x[start]-x[end])*(y[start]+y[end]);
	}
	return abs(ans);
}
long long int f(int start,int NoOfPoints)
{
	long long int firstArea=area(start,NoOfPoints);
	return abs(totalArea-firstArea-firstArea);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	while(cin>>n)
	{
		x=std::vector<long long int> (n);
		y=std::vector<long long int> (n);
		a=std::vector<long long int> (n,0);
		int X,Y;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&X,&Y);
			x[i]=X;
			y[i]=Y;	
		}
		for(int i=1;i<n;i++)
			a[i]=a[i-1]+((x[i]-x[i-1])*(y[i]+y[i-1]));
		totalArea=area(0,n);
		long long int firstArea=totalArea;
		long long int diff=0;
		for(int i=0;i<n;i++)
		{
			int lo = 3, hi = n-1;
			while (hi - lo > 1){
			    int mid = (hi + lo)>>1;
			    if (f(i,mid) < f(i,mid + 1)) 
			         hi = mid;
			    else 
			         lo = mid;
			}
			//Check if i found a better solution
			long long int curArea1=area(i,hi);
			long long int diff1=abs(totalArea-curArea1-curArea1);
			long long int curArea2=area(i,lo);
			long long int diff2=abs(totalArea-curArea2-curArea2);
			if(diff1<diff2)
			{
				//diff1 is better
				if(abs(totalArea-curArea1-curArea1)>=diff)
				{
					diff=abs(totalArea-curArea1-curArea1);
					firstArea=curArea1;
				}
			}
			else
			{
				if(abs(totalArea-curArea2-curArea2)>=diff)
				{
					diff=abs(totalArea-curArea2-curArea2);
					firstArea=curArea2;
				}

			}
		}
		firstArea=max(firstArea,totalArea-firstArea);
		printf("%lld %lld\n",firstArea,totalArea-firstArea);
	}
}
