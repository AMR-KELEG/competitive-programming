//AC
#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int>>ran;
int n,k;
bool valid(int len)
{
	int in=0;
	priority_queue<pair<int,bool>>q;//-time , isStart
	for(int i=0;i<n;i++)
	{
		if(ran[i].first.second+1-ran[i].first.first<len)
			continue;
		q.push({-ran[i].first.first,1});
		q.push({-(ran[i].first.second-(len-1)),0});
	}
	while(!q.empty())
	{
		if(in==k)
			return 1;
		if(q.top().second)
			in++;
		else
			in--;
		q.pop();
	}
	if(in==k)
		return 1;
	return 0;
}
int main() {
	scanf("%d %d",&n,&k);
	ran=vector<pair<pair<int,int>,int>>(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&ran[i].first.first,&ran[i].first.second);
		ran[i].second=i;
	}
	sort(ran.begin(),ran.end());
	long long int l=0,r=(2*1000000000)+1;
	long long int mid=(l+r+1)>>1;
	while(l<r)
	{
		if(valid(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
		mid=(l+r+1)>>1;
	}
	printf("%d\n",mid);
	if(mid==0)
	{
		for(int i=1;i<=k;i++)
			printf("%d ",i);
		return 0;
	}
	vector<bool>isIn(n,0);
	int in=0;
	priority_queue<pair<pair<int,bool>,int>>q;//-time , isStart
	for(int i=0;i<n;i++)
	{
		if(ran[i].first.second+1-ran[i].first.first<mid)
			continue;
		q.push({{-ran[i].first.first,1},ran[i].second});
		q.push({{-(ran[i].first.second-(mid-1)),0},ran[i].second});
	}
	while(!q.empty())
	{
		if(in==k)
			break;
		if(q.top().first.second)
		{
			in++;
			isIn[q.top().second]=1;
		}
		else
		{
			in--;
			isIn[q.top().second]=0;
		}
		q.pop();
	}
	for(int i=0;i<n;i++)
	{
		if(isIn[i])
			printf("%d ",i+1);
	}
}