//AC 
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	long long int n,l,r,Ql,Qr,w;
	cin>>n>>l>>r>>Ql>>Qr;
	std::vector<long long int> cw(n);//from 1 to i
	cin>>w;
	cw[0]=w;
	for(int i=1;i<n;i++)
	{
		cin>>w;
		cw[i]=cw[i-1]+w;
	} 
	// all right
	long long int ans=r*cw[n-1]+Qr*(n-1),newans;
	ans=min(ans,l*cw[n-1]+Ql*(n-1));
	// cout<<ans<<endl;
	int left,right;
	//take some left 0->i l and from i+1-> n-1 right
	for(int i=0;i<n;i++)
	{
		newans=l*(cw[i])+r*(cw[n-1]-cw[i]);
		left=i+1;
		right=n-i-1;
		// i+1 lefts and n-1-i rights -- if(diff== 1 or 0)no overhead else max of both - min+1
		if(left>right+1)
		{
			//more lefts here 
			newans+=Ql*(left-1-right);
		}
		else if(right>1+left)
		{
			newans+=Qr*(right-1-left);
		}
		ans=min(ans,newans);
		// cout<<i<<" "<<newans<<" "<<ans<<endl;

	}
	cout<<ans;
	


}