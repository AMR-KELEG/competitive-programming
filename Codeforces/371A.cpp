#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string ing;
	long long int nb,ns,nc,pb,ps,pc;
	long long int r,sand=0;
	long long int rb=0,rs=0,rc=0;
	cin>>ing;
	cin>>nb>>ns>>nc>>pb>>ps>>pc;
	cin>>r;
	for(int i=0;i<ing.size();i++)
	{
		if(ing[i]=='B')
			rb++;
		if(ing[i]=='S')
			rs++;
		if(ing[i]=='C')
			rc++;
	}	
	long long int av=1000;
	if(rb>0)
		av=min(av,nb/rb);
	if(rc>0)
		av=min(av,nc/rc);
	if(rs>0)
		av=min(av,ns/rs);
	av=(av==1000)?0:av;
	sand+=av;
	nb-=(rb*sand);
	ns-=(rs*sand);
	nc-=(rc*sand);
	av=0;
	if(rb==0)
		nb=0;
	if(rc==0)
		nc=0;
	if(rs==0)
		ns=0;
	bool can=1;
	while(r>0 && can && (nb>0 || ns>0 || nc>0))
	{
		can=0;
		if(r>=(pb*(max(rb-nb,0LL)))+(pc*(max(rc-nc,0LL)))+(ps*(max(rs-ns,0LL))))
		{
			can=1;
			sand++;
			r-=(pb*(max(rb-nb,0LL)))+(pc*(max(rc-nc,0LL)))+(ps*(max(rs-ns,0LL)));
			ns=max(ns-rs,0LL);
			nc=max(nc-rc,0LL);
			nb=max(nb-rb,0LL);			
			
		}
	}
	if(r>0)
	{
		sand+=r/((rb*pb)+(rs*ps)+(rc*pc));
	}
	/*
	*/
	cout<<sand;
}