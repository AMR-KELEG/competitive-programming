//AC
#include "bits/stdc++.h"
using namespace std;
int a,b,n;
#define ll long long
int mod=1000000007;
const int size=1001001;
ll fact[size];

void init(){
  fact[0]=1;
  for(int i=1;i<size;i++)
    fact[i]=(fact[i-1]*i)%mod;
}

ll powmod(ll x,ll n,ll mod) {
  ll res=1;
  while(n){
    if(n&1)res=(res*x)%mod;
    x=(x*x)%mod;
    n>>=1;
  }
  return res;
}

ll nci(int n,int i){return (fact[n]*powmod((fact[n-i]*fact[i])%mod,mod-2,mod))%mod;}

bool check(int ca,int cb)
{
	int no=(a*ca)+(b*cb);
	//cout<<no<<endl;
	while(no>0)
	{
		if(no%10!=a && no%10!=b)
		{
			return 0;
		}
		no/=10;
		//cout<<"IN "<<no<<endl;
	}

	return 1;

}

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	long long int count=0;
	cin>>a>>b>>n;
	init();
	for(int ca=0;ca<=n;ca++)
	{
		if(check(ca,n-ca))
		{
			//cout<<"ok\n";
			count+=nci(n,ca);
			count%=1000000007;
		}
	}
	cout<<count;
}