//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n;
	std::vector<int> av(n);
	for(int i=0;i<n;i++)cin>>av[i];
	cin>>m;
	std::vector<int> bv(m);
	for(int j=0;j<m;j++)cin>>bv[j];

	int maxdiff=3*(n-m),maxa=3*n,maxb=3*m,a,b;
	
	sort(av.begin(), av.end());
	sort(bv.begin(), bv.end());
	for(int i=0;i<m;i++)
	{
		b=2*(i+1)+3*(m-i-1);
		int j=upper_bound(av.begin(),av.end(),bv[i])-av.begin();
		a=(2*j)+(3*(n-j));
		if(a-b>maxdiff)
		{
			maxdiff=a-b;
			maxa=a;
			maxb=b;
		}	
		else if(a-b==maxdiff && a>maxa)
			maxa=a,maxb=b;
	}
	cout<<maxa<<":"<<maxb;
}