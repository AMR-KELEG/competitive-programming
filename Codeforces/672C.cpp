#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	
	long double totaldis=0;
	long long int ax,ay,bx,by,tx,ty,n,xi,yi,mina=LLONG_MAX,minb=LLONG_MAX,mina_1=LLONG_MAX,minb_1=LLONG_MAX,ai=-1,ai1=-1,bi=-1,bi1=-1;
	cin>>ax>>ay>>bx>>by>>tx>>ty>>n;
	std::vector<long long int> x(n+2),y(n+2),taken(n+2,0);
	long long int disa,disb;
	if(n==1)
	{
		cin>>x[0]>>y[0];
		disa=( (x[0]-ax)*(x[0]-ax) ) +( (y[0]-ay)*(y[0]-ay) ) ;
		disb=( (x[0]-bx)*(x[0]-bx) ) +( (y[0]-by)*(y[0]-by) ) ;
		totaldis=sqrt( ((x[0]-tx)*(x[0]-tx) ) +( (y[0]-ty)*(y[0]-ty) ));

		if(disa<disb)
		{
			totaldis+=sqrt(disa);
		}
		else
		{
			totaldis+=sqrt(disb);
		}
		cout<<totaldis;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
			disa=( (x[i]-ax)*(x[i]-ax) ) +( (y[i]-ay)*(y[i]-ay) ) ;
			disb=( (x[i]-bx)*(x[i]-bx) ) +( (y[i]-by)*(y[i]-by) ) ;
			if(disa<mina)
			{
				mina_1=mina;
				mina=disa;
				ai1=ai;
				ai=i;
			}
			else if(disa<mina_1)
			{
				mina_1=disa;
				ai1=i;
			}
			if(disb<minb)
			{
				minb_1=minb;
				minb=disb;
				bi1=bi;
				bi=i;
			}
			else if(disb<minb_1)
			{
				minb_1=disb;
				bi1=i;
			}
		}
		cout<<mina<<" "<<ai<<" "<<minb<<" "<<bi<<endl;
		disa=( (x[ai]-tx)*(x[ai]-tx) ) +( (y[ai]-ty)*(y[ai]-ty) );
		disb=( (x[bi]-tx)*(x[bi]-tx) ) +( (y[bi]-ty)*(y[bi]-ty) );
		if(mina-disa<minb-disb)
		{
			//take a
			totaldis+=sqrt(mina)+sqrt(disa);
			taken[ai]=1;
			if(ai==bi)
			{
				minb=minb_1;
				bi=bi1;
			}
			mina=mina_1;
			ai=ai1;

			cout<<mina<<" "<<ai<<" "<<minb<<" "<<bi<<endl;

			disb=( (x[bi]-tx)*(x[bi]-tx) ) +( (y[bi]-ty)*(y[bi]-ty) );
			if(minb<disb)
			{
				totaldis+=sqrt(minb)+sqrt(disb);
				taken[bi]=1;
			}
		}
		else
		{
			//take b
			totaldis+=sqrt(minb)+sqrt(disb);
			taken[bi]=1;
			if(ai==bi)
			{
				mina=mina_1;
				ai=ai1;
			}
			minb=minb_1;
			bi=bi1;

			cout<<mina<<" "<<ai<<" "<<minb<<" "<<bi<<endl;
			
			disa=( (x[ai]-tx)*(x[ai]-tx) ) +( (y[ai]-ty)*(y[ai]-ty) );
			if(mina<disa)
			{
				totaldis+=sqrt(mina)+sqrt(disa);
				taken[ai]=1;
			}

		}

		for(int i=0;i<n;i++)
		{
			if(!taken[i])
			{
				disa=( (x[ai]-tx)*(x[ai]-tx) ) +( (y[ai]-ty)*(y[ai]-ty) );
				totaldis+=sqrt(disa)*2;
			}
		}

		cout<<totaldis;

	}


}