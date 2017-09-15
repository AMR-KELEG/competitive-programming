//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	std::vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int zer=0,dec=0;
	priority_queue<int>inc;
	int maxH= (1.5*100000) +1;
	// maxH = 6;
	long long int minOp=0;
	if(n%2==0)
	{
		inc.push(-(maxH-a[n/2]));
		minOp+=(maxH-a[n/2])>0;
		inc.push(-(maxH-a[(n/2)-1]));
		minOp+=(maxH-a[(n/2)-1])>0;
		for(int in=(n/2)-2,off=-1;in>=0;in--,off--)
		{
			inc.push(-(maxH+off-a[in]));
			minOp+=(maxH+off-a[in])>0;
		}
		for(int in=(n/2)+1,off=-1;in<n;in++,off--)
		{
			inc.push(-(maxH+off-a[in]));
			minOp+=(maxH+off-a[in])>0;
		}
	}
	else
	{
		inc.push(-(maxH-a[n/2]));
		minOp+=(maxH-a[n/2])>0;
		for(int in=(n/2)-1,off=-1;in>=0;in--,off--)
		{
			inc.push(-(maxH+off-a[in]));
			minOp+=(maxH+off-a[in])>0;
		}
		for(int in=(n/2)+1,off=-1;in<n;in++,off--)
		{
			inc.push(-(maxH+off-a[in]));
			minOp+=(maxH+off-a[in])>0;
		}
	}
	long long int ans=minOp;
	maxH--;
	for(int decOp=1;maxH>=ceil(n/2.0);decOp++)
	{
		dec+=zer;
		zer=0;
		while(!inc.empty() && (-inc.top())==decOp)
		{
			inc.pop();
			zer++;
		}
		long long int op=inc.size()+dec;
		maxH--;
		ans=min(ans,op);
	}
	cout<<ans;
}