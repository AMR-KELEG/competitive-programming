#include "bits/stdc++.h"
using namespace std;
vector<pair<int,int> >v;
int last=0;
bool can(int t)
{
	if(t==0)return 0;
	int start,endt;
	int d[107]={0};	
	int current_time=-1;
	while(current_time<=last)
	{
		current_time++;
		for(int i=0;i<v.size();i++){
			start=v[i].second;
			endt=v[i].first;
			if(start>current_time) continue;
			else if(endt<=current_time){
				if(d[i]!=t) return 0;
				continue;
			} else if(d[i]!=t) {
				d[i]++;break;
			}
		}
	}
	for (int i = 0; i < v.size(); ++i)
	{
		if(d[i]!=t)return 0;
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	int a,b;
	int min_interval=1<<29;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		last=max(last,b);
		min_interval=min(min_interval,b-a);
		v.push_back(pair<int,int>(b,a));
	}
	sort(v.begin(), v.end());
	int l=0,r=min_interval,mid;
	while(l< r)
	{
		mid=(l+r+1)/2;
		if(can(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
			// cout<<l<<" "<<mid<<" "<<r<<endl;
		}
	}
	cout<<l*n;
	return 0;
}
