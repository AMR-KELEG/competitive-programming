//AC
#include "bits/stdc++.h"
using namespace std;
int n,students;
std::vector<int> tangarines;
vector<int>mp(10000001,0);
std::vector<int> vis(10000001,0);
int curSearch=0;

int findVal(int ntan,int & mint)
{
	if(ntan<mint)
		return 0;
	if(ntan==mint)
		return 1;
	if(vis[ntan]==curSearch)
		return mp[ntan];
	vis[ntan]=curSearch;
	if(ntan%2)
		return mp[ntan]=max(1,findVal(ntan/2,mint)+findVal(ceil(ntan/2.0),mint));
	return mp[ntan]=max(1,2*findVal(ntan/2,mint));
}
bool valid(int minTangarine)
{
	curSearch++;
	long long int ok=0;
	for(int curTan=n-1;curTan>=0 && tangarines[curTan]>=minTangarine;curTan--)
	{
		ok+=findVal(tangarines[curTan],minTangarine);
		if(ok>=students)
			return 1;
	}
	return ok>=students;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>students;
	tangarines=std::vector<int> (n);
	for(int i=0;i<n;i++)
		cin>>tangarines[i];
	sort(tangarines.begin(), tangarines.end());
	int l=0,r=10000001;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(valid(mid))
			l=mid;
		else
			r=mid-1;
	}
	int mid=(l+r+1)>>1;
	if(mid==0)
		cout<<-1;
	else
		cout<<mid;
}