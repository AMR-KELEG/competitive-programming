// TLE
#include <bits/stdc++.h>
using namespace std;
long long int min_price =(1000000000000000000LL);
inline bool valid(int c2,const long long int & rem_time,const long long int & rem_bytes, const long long int & a2,const long long int & t2,const long long int & t0)
{
	long long int down_bytes2 = min(c2*a2, rem_bytes);
	long long int cur_time = (t2*down_bytes2) + (t0 * (rem_bytes - down_bytes2));
	return cur_time<=rem_time;
}

void solve(long long int f,long long int T,long long int t0,
		long long int a1,long long int t1,long long int p1,
		long long int a2,long long int t2,long long int p2)
{
	for (long long int c1=0;c1<=10000000;c1++)
	{
		long long int cur_price = c1 * p1;
		int rem_bytes = f - min(f, a1*c1);
		long long int rem_time = T - (min(f, a1*c1)*t1);
		if (rem_time<0)
			break;
		if (rem_bytes==0)
		{
			min_price = min(min_price, cur_price);
			break;
		}

		if(t0<=t2)
		{
			if (rem_bytes*t0 <= rem_time)
			{
				min_price = min(min_price, cur_price);				
			}
			continue;
		}
		int lim = ceil(rem_bytes/(long double)a2);
		int l=0,r=lim;
		while(l<r)
		{
			int mid = (l+r)>>1;
			if (valid(mid,rem_time,rem_bytes,a2,t2,t0))
			{
				r = mid;
			} 
			else
			{
				l = mid+1;
			}
		}
		if(l>r)
			continue;
		if (!valid(r,rem_time, rem_bytes,a2,t2,t0))
			continue;
		if (l>=0 && r<=lim)
		{
			cur_price += (p2*r);
			min_price = min(min_price, cur_price);
		}
	}
}
int main()
{
	// freopen("input.txt","r", stdin);
	long long int f, T;
	long long int t0,a1,t1,p1,a2,t2,p2;
	cin>>f>>T>>t0;
	cin>>a1>>t1>>p1>>a2>>t2>>p2;
	long long t = min(t0, min(t1, t2));
	if(f * t > T){
		puts("-1");
		return 0;
	}

	solve(f,T,t0,a1,t1,p1,a2,t2,p2);
	solve(f,T,t0,a2,t2,p2,a1,t1,p1);

	if (min_price == (1000000000000000000LL))
		cout<<-1;
	else
		cout<<min_price;
	return 0;
}