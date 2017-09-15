//AC
#include "bits/stdc++.h"
#define INF 1000000
using namespace std;
std::vector<int> noOfInf;
std::vector<int> tree;
std::vector<int> cards;
int n;
long long int ans=0;

int brute(std::vector<int> card)
{
	int rem=0;
	int cur=0;
	int steps=0;
	while(rem<n)
	{
		if(card[cur]==INF)
		{
			cur=(cur+1)%n;
			continue;
		}
		int mi=INF;
		for(int i=0;i<n;i++)
			mi=min(mi,card[i]);
		if(card[cur]==mi)
		{
			rem++;
			card[cur]=INF;
		}
		cur=(cur+1)%n;		
		steps++;
	}
	return steps;
}

void build(int l,int r,int node=1)
{
	if(l==r)
	{
		tree[node]=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,2*node);
	build(1+mid,r,1+2*node);
	tree[node]= (cards[tree[2*node]]<=cards[tree[2*node+1]])?
				tree[2*node]:
				tree[2*node+1];
}

int indxOfMin(int l,int r,int rl,int rr,int node=1)
{
	if(rl>rr)
		return n;
	if(l>r)
		return n;
	if(rl>r || rr<l)
	{
		return n;
	}
	if(l>=rl && r<=rr)
		return tree[node];
	int mid=(l+r)>>1;
	int li = indxOfMin(l,mid,rl,rr,2*node);
	int ri = indxOfMin(1+mid,r,rl,rr,1+2*node);
	if(cards[li]<=cards[ri])
		return li;
	return ri;
}

void update(int l,int r,int indx,int node=1)
{
	if(l>indx || r<indx)
		return;
	if(l==r)
	{
		cards[l]=INF;
		noOfInf [node]=1;
		return ;
	}
	int mid=(l+r)>>1;
	update(l,mid,indx,2*node);
	update(1+mid,r,indx,2*node+1);
	int li= tree[2*node];
	int ri= tree[2*node+1];
	noOfInf[node]= noOfInf[2*node] + noOfInf[1+2*node];
	if(cards[li]<=cards[ri])
	{
		tree[node]=li;
		return;
	}
	tree[node]=ri;
}

int qInf(int l,int r,int rl,int rr,int node=1)
{
	if(rl>rr)
		return 0;
	if(l>r)
		return 0;
	if(l>rr || r<rl)
		return 0;
	if(l>=rl && r<=rr)
		return noOfInf[node];
	int mid=(l+r)>>1;
	return qInf(l,mid,rl,rr,2*node)+qInf(1+mid,r,rl,rr,1+2*node);
}

int nextStep(int cur,int lv,int rv,int li,int ri)
{
	if(rv<=lv)
	{
		// GO TO ri
		int skip = qInf(0,n-1,cur,ri);
		ans += ri-cur-skip;
		// cout<< skip<<" "<<(ri-cur-skip)<<endl;
		return ri;
	}
	// GO to n-1 then to li
	int skip = qInf(0,n-1,cur,n-1)+qInf(0,n-1,0,li); // last may be cur not cur-1
	ans += (n-cur)+(li)-skip;
	// cout<<skip<<" "<<(n-cur)+(li)-skip<<endl;
	return li;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	cards = vector<int>(n+1);
	tree = vector<int>(4*n);
	noOfInf = vector<int>(4*n,0);
	cards[n] = INF;
	for(int i=0;i<n;i++)cin>>cards[i];
	int br=brute(cards);
	build(0,n-1);
	int cur =0;
	int nInf =0;
	int mini=indxOfMin(0,n-1,0,n-1);
	if(cards[mini]<cards[0])
	{
		ans+=mini;
		cur=mini;
	}
	while(nInf<n)
	{
		// int indxOfMin(int l,int r,int rl,int rr,int node=1)
		int li=indxOfMin(0,n-1,0,cur-1);
		int ri=indxOfMin(0,n-1,cur+1,n-1);
		int lv=cards[li];
		int rv=cards[ri];
		update(0,n-1,cur);
		nInf++;
		ans++;
		if(nInf==n)
			break;
		else
			cur=nextStep(cur,lv,rv,li,ri);
	}
	if(ans!=br)
	{
		cout<<"ERROR"<<endl;
		cout<<ans<<" "<<br;
	}
}