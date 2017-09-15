//AC
#include "bits/stdc++.h"
#define segmentProp pair<pair<long long int,long long int>,pair<long long int,long long int>>
#define segM first.first
#define segS first.second
#define segML second.first
#define segMR second.second
#define emptySeg {{-800000000,0},{-800000000,-800000000}}
using namespace std;
int n;
std::vector<long long int> v;
std::vector<long long int> maxS,maxLS,maxRS,tot;
std::vector<long long int> cs;
void build(int l,int r,int node=1)
{
	if(l==r)
	{
		tot[node]=maxS[node]=maxLS[node]=maxRS[node]=v[l];
		return ;
	}
	int mid=(l+r)>>1;
	int L=2*node,R=2*node+1;
	build(l,mid,L);
	build(1+mid,r,R);
	tot[node]=tot[L]+tot[R];
	maxLS[node]=max(maxLS[L],tot[L]+maxLS[R]);
	maxRS[node]=max(maxRS[R],maxRS[L]+tot[R]);
	maxS[node]=max(max(max(maxLS[node],maxRS[L]+maxLS[R]),max(maxS[L],maxS[R])),max(maxRS[node],tot[node]));
}

segmentProp query(int l,int r,int rl,int rr,int node=1)
{
	if(l>rr || r<rl)
	{
		return emptySeg;
	}
	if(l>=rl && r<=rr)
	{
		return {{maxS[node],tot[node]},{maxLS[node],maxRS[node]}};
	}
	int mid=(l+r)>>1;
	int L=2*node;
	int R=2*node+1;
	segmentProp lseg(query(l,mid,rl,rr,L));
	segmentProp rseg(query(mid+1,r,rl,rr,R));
	if(lseg==segmentProp(emptySeg))
		return rseg;
	if(rseg==segmentProp(emptySeg))
		return lseg;
	long long int stot=lseg.segS+rseg.segS;
	long long int smaxLS=max(lseg.segML,lseg.segS+rseg.segML);
	long long int smaxRS=max(rseg.segMR,rseg.segS+lseg.segMR);
	long long int smaxS=max(max(max(stot,lseg.segMR+rseg.segML)
					,max(lseg.segM,rseg.segM)),max(smaxLS,smaxRS));
	return {{smaxS,stot},{smaxLS,smaxRS}};
}

int findSum(int l,int r)
{
	int ans=0;
	for(int in=l;in<=r;in++)ans+=v[in];
	return ans;
}

int brute(int sl,int sr,int el,int er)
{
	int ans=findSum(sl,el);
	for(int l=sl;l<=sr;l++)
	{
		for(int r=el;r<=er;r++)
		{
			ans=max(ans,findSum(l,r));
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	/*
		The first line of the input consist of the number of tests cases <= 5. 
		Each case consist of the integer N and the sequence A. 
		Then the integer M. M lines follow, contains 4 numbers x1, y1, x2 y2.
	*/
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		v=std::vector<long long int> (n);
		cs=std::vector<long long int> (n+1,0);
		maxS=std::vector<long long int> (4*n);
		maxLS=std::vector<long long int> (4*n);
		maxRS=std::vector<long long int> (4*n);
		tot=std::vector<long long int> (4*n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			cs[i+1]=cs[i]+v[i];
		}
		build(0,n-1);
		int q;
		cin>>q;
		while(q--)
		{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			x1--;
			y1--;
			x2--;
			y2--;
			// cout<<brute(x1,y1,x2,y2)<<" ";
			// long long int br=brute(x1,y1,x2,y2);
			if(x2>=y1)
			{
				long long int tot=cs[x2+1]-cs[y1];
				long long int ans=tot;
				if(x1<y1)
				{
					ans+=max(0LL,query(0,n-1,x1,y1-1).segMR);//s=x1 e= 
				}
				if(x2<y2)
				{
					ans+=max(0LL,query(0,n-1,x2+1,y2).segML);//s= e=y2
				}
				// if(ans!=br)
				// {
				// 	cout<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1<<endl;
				// 	cout<<0<<" "<<ans<<" "<<br<<endl;
				// 	cout<<endl;
				// }
				printf("%d\n",ans);
			}
			else
			{
				long long int ans=query(0,n-1,x2,y1).segM;
				if(y1<y2)
				{
					long long int ans2=query(0,n-1,x2,y1).segMR+query(0,n-1,y1+1,y2).segML;
					ans=max(ans,ans2);
				}
				if(x1<x2)
				{
					long long int ans2=query(0,n-1,x1,x2-1).segMR+query(0,n-1,x2,y1).segML;
					ans=max(ans,ans2);	
				}
				if(x1<x2 && y1<y2)
				{
					long long int tot=cs[y1+1]-cs[x2];
					long long int ans2=tot+query(0,n-1,x1,x2-1).segMR+query(0,n-1,y1+1,y2).segML;
					ans=max(ans,ans2);		
				}
				// if(ans!=br)
				// {
				// 	cout<<1<<" "<<ans<<" "<<br<<endl;
				// }
				printf("%d\n",ans);
			}
		}
	}
}