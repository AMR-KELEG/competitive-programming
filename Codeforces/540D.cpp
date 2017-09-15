//AC
#include "bits/stdc++.h"
using namespace std;
long double rdp[105][105][105];
long double sdp[105][105][105]; 
bool solvedr[105][105][105]={};
bool solveds[105][105][105]={};
long double solver(int r,int s,int p)
{
	// cout<<r<<" "<<s<<" "<<p<<endl;
	if(r<0 || p<0 || s<0)
		return 0;
	if(r==0)
		return 0;
	if(s==0 && p==0 && r>0)
		return 1;
	/*
	Total=nPr(r+p+s,2)
	Cou(r,r)=r*(r-1)
	Cou(s,s)=s*(s-1)
	Cou(p,p)=p*(p-1)
	Cou(r,s)=2*r*s
	Cou(r,p)=2*r*p
	Cou(p,s)=2*p*s
	P(same)=Cou(r,r)+Cou(s,s)+Cou(p,p)/Total
	P(r,s)=Cou(r,s)/Total
	
	dp(r,p,s) = dp(r-1,p,s)* P(r,p)
	dp(r,p-1,s)* P(p,s)
	dp(r,p,s-1)* P(r,s)
	dp(r,p,s)* P(same)
	
	dp(r,p,s)=dp(r-1,p,s)* P(r,p)
	+dp(r,p-1,s)* P(p,s)
	+dp(r,p,s-1)* P(r,s)/(1-psame);

	*/
	if(solvedr[r][s][p])
		return rdp[r][s][p];
	long double total=(r+p+s)*(r+p+s-1);
	long double prp=2.0*r*p/total;
	long double pps=2.0*s*p/total;
	long double prs=2.0*r*s/total;
	long double psame=1.0*(r*(r-1)+s*(s-1)+p*(p-1))/total;
	// cout<<prp<<" "<<pps<<" "<<prs<<" "<<psame<<endl;
	if(r>0 && p>0 && s>0)
	{
		rdp[r][s][p]=(solver(r-1,s,p)*prp+solver(r,s-1,p)*prs+solver(r,s,p-1)*pps)/(1-psame);
		solvedr[r][s][p]=1;
		return rdp[r][s][p];	
	}
	if(p>0)
	{
		rdp[r][s][p]=(solver(r-1,s,p)*prp+solver(r,s,p-1)*pps)/(1-psame);
		solvedr[r][s][p]=1;
		return rdp[r][s][p];
	}
	rdp[r][s][p]=(solver(r-1,s,p)*prp+solver(r,s-1,p)*prs)/(1-psame);
	solvedr[r][s][p]=1;
	return rdp[r][s][p];
}

long double solves(int r,int s,int p)
{
	// cout<<r<<" "<<s<<" "<<p<<endl;
	if(r<0 || p<0 || s<0)
		return 0;
	if(s==0)
		return 0;
	if(r==0 && p==0 && s>0)
		return 1;
	/*
	Total=nPr(r+p+s,2)
	Cou(r,r)=r*(r-1)
	Cou(s,s)=s*(s-1)
	Cou(p,p)=p*(p-1)
	Cou(r,s)=2*r*s
	Cou(r,p)=2*r*p
	Cou(p,s)=2*p*s
	P(same)=Cou(r,r)+Cou(s,s)+Cou(p,p)/Total
	P(r,s)=Cou(r,s)/Total
	
	dp(r,p,s) = dp(r-1,p,s)* P(r,p)
	dp(r,p-1,s)* P(p,s)
	dp(r,p,s-1)* P(r,s)
	dp(r,p,s)* P(same)
	
	dp(r,p,s)=dp(r-1,p,s)* P(r,p)
	+dp(r,p-1,s)* P(p,s)
	+dp(r,p,s-1)* P(r,s)/(1-psame);

	*/
	if(solveds[r][s][p])
		return sdp[r][s][p];
	long double total=(r+p+s)*(r+p+s-1);
	long double prp=2.0*r*p/total;
	long double pps=2.0*s*p/total;
	long double prs=2.0*r*s/total;
	long double psame=1.0*(r*(r-1)+s*(s-1)+p*(p-1))/total;
	// cout<<prp<<" "<<pps<<" "<<prs<<" "<<psame<<endl;
	sdp[r][s][p]=(solves(r-1,s,p)*prp+solves(r,s-1,p)*prs+solves(r,s,p-1)*pps)/(1-psame);
	solveds[r][s][p]=1;
	return sdp[r][s][p];
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	memset(rdp,-1,sizeof rdp);
	memset(sdp,-1,sizeof sdp);
	int r,s,p;
	cin>>r>>s>>p;
	long double rw=solver(r,s,p);
	long double sw=solves(r,s,p);
	long double pw=1-sw-rw;
	cout<<std::fixed<<setprecision(12)<<rw<<" "<<sw<<" "<<pw;
}