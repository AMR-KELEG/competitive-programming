//AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<int> M;
bool isvalid(long long int mid)
{
	long long int total=0;
	for(int i=0;i<M.size();i++)
	{
		total+=1+(mid/M[i]);
		if(total>=n)
			return 1;
	}
	if(total>=n)
		return 1;
	return 0;	
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("B-large-practice.in","r",stdin);
		freopen("B-large-out.in","w",stdout);
	#endif
	int T;
	cin>>T;

	for(int t=1;t<=T;t++)
	{
		int B;
		cin>>B>>n;
		M=std::vector<int> (B);
		for(int i=0;i<B;i++)
			cin>>M[i];
		long long int l=0,r=1000000000000000000LL;
		long long int mid=(l+r)/2;
		while(l!=r)
		{
			mid=(l+r)/2;
			if(isvalid(mid))
				r=mid;
			else
				l=mid+1;
		}
		mid=(l+r)/2;
		long long int people=0;
		// long long int p=0;
		for(int i=0;i<M.size();i++)
		{
			people+=1+((mid-1)/M[i]);
			// p+=1+(mid/M[i]);
		}

		int in=-1;
		for(int i=0;i<M.size();i++)
		{
			if(people==n)
			{
				in=i;
				break;
			}
			if(mid%M[i]==0)
			{
				people++;
			}
			if(people==n)
			{
				in=i+1;
				break;
			}
		}
		// cout<<people<<" "<<p<<" "<<n<<endl;
		cout<<"Case #"<<t<<": "<<in<<endl;
	}

	
}