#include "bits/stdc++.h"
#define EPS 0.00000000001
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("B-large.in","r",stdin);
		freopen("B-large-out.in","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int N,P;
		cin>>N>>P;
		std::vector<long long int> req(N);//INT???
		for(int i=0;i<N;i++)cin>>req[i];
		std::vector<std::vector<int> > q;
		for(int i=0;i<N;i++)
		{
			std::vector<int> curQ(P);
			for(int j=0;j<P;j++)cin>>curQ[j];
			sort(curQ.begin(), curQ.end());
			q.push_back(curQ);
		}
		std::vector<int> indx(N,0);
		int ans=0;
		bool done=0;
		do
		{
			bool valid=true;
			int minP=ceil(q[0][indx[0]]/(req[0]*1.1));
			int maxP=floor(q[0][indx[0]]/(req[0]*0.9));
			if(minP>maxP)
			{
				swap(minP,maxP);
			}
			long double val=q[0][indx[0]];
			val/=req[0]*minP;
			if(!
			((val>=0.9 || abs(val-0.9)<EPS)
						 && (val<=1.1 || abs(val-1.1)<EPS))
			)
			{
				minP++;
			}
			val=q[0][indx[0]];
			val/=req[0]*maxP;
			if(!
			((val>=0.9 || abs(val-0.9)<EPS)
						 && (val<=1.1 || abs(val-1.1)<EPS))
			)
			{
				maxP--;
			}
			int maxRes=0;
			if(minP>maxP)
			{
				//Invalid
				valid=0;
				indx[0]++;
				if(indx[0]==P)
					done=1;
			}
			for(int i=1;i<N && valid;i++)
			{
				int minV=ceil(q[i][indx[i]]/(req[i]*1.1));
				int maxV=floor(q[i][indx[i]]/(req[i]*0.9));
				if(minV>maxV)swap(minV,maxV);
				val=q[i][indx[i]];
				val/=req[i]*minV;
				if(!
				((val>=0.9 || abs(val-0.9)<EPS)
							 && (val<=1.1 || abs(val-1.1)<EPS))
				)
				{
					minV++;
				}
				val=q[i][indx[i]];
				val/=req[i]*maxV;
				if(!
				((val>=0.9 || abs(val-0.9)<EPS)
							 && (val<=1.1 || abs(val-1.1)<EPS))
				)
				{
					maxV--;
				}
				if(minV>maxV)
				{
					//Invalid
					valid=0;
					indx[i]++;
					if(indx[i]==P)
						done=1;
					break;
				}
				if(maxV<minP)
				{
					valid=false;
					indx[i]++;
					if(indx[i]==P)
					{
						//Done everything
						done=1;
					}
					break;
					//Need to move someone here
				}
				if(minV>maxP)
				{
					// One resp for max
					valid=0;
					indx[maxRes]++;
					if(indx[maxRes]==P)
					{
						done=1;
						//Done everything
					}
					break;
				}
				minP=max(minP,minV);
				if(maxV<maxP)
				{
					// i is the resp
					maxRes=i;
				}
				maxP=min(maxP,maxV);
			}
			// cout<<endl<<endl;
			if(valid)
			{
				if(maxP>0)
					ans++;
				for(int i=0;i<N;i++)
				{
					indx[i]++;
					if(indx[i]==P)
					{
						done=1;
					}
				}
			}
		}
		while(!done);
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}	
}