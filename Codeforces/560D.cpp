//AC
#include "bits/stdc++.h"
using namespace std;
int base [] = {26,27};
int MOD [] = {1000000007, 179424673};
std::vector<long long int> hash1[2];
std::vector<long long int> hash2[2];
std::vector<int> cs1[26];
std::vector<int> cs2[26];
std::vector<long long int> shifts_val[2];
std::vector<long long int> inverse_shifts_val[2];
int modpow (long long int val,int p,const int & mod) 
{
	if(p==0)
		return 1;
	if(p==1)
		return val;
	long long int ans = modpow(val,p/2,mod);
	ans = (ans*ans)%mod;
	if (p%2)
	{
		ans = ans*val;
	}
	return ans %mod;
}

int inverse(int val, const int & mod)
{
	return modpow(val,mod-2,mod);
}

string s1,s2;
bool eq(int l1,int r1,int l2,int r2)
{
	// cout<<"Range1: "<<l1<<" "<<r1<<" Range2: "<<l2<<" "<<r2<<endl;
	if (l1==r1)
	{
		return s1[l1-1]==s2[l2-1];
	}
	for(int i=0;i<26;i++)
	{
		int cf = cs1[i][r1]- cs1[i][l1-1];
		int cs = cs2[i][r2]- cs2[i][l2-1];
		if(cf!=cs)
			return 0;
	}
	// find values of hash 1 
	long long int val1 []={0,0};
	long long int val2 []={0,0}; 
	long long int inv1 []= {1,1};
	long long int inv2 []= {1,1};

	for(int i=0;i<2;i++)
	{
		inv1[i] = inverse_shifts_val[i][l1-1];//modpow(base[i],l1-1,MOD[i]);
		inv2[i] = inverse_shifts_val[i][l2-1];//modpow(base[i],l2-1,MOD[i]);
	}

	for(int i =0;i<2;i++)
	{
		val1[i] = hash1[i][r1]-hash1[i][l1-1];
		while(val1[i]<0)
			val1[i] += MOD[i];
		val2[i] = hash2[i][r2]-hash2[i][l2-1];
		while(val2[i]<0)
			val2[i] += MOD[i];
	}

	for(int i =0;i<2;i++)
	{
		if(inv1[i]!=1)
			val1[i] = (val1[i] * inv1[i]) % MOD[i];
		if(inv2[i]!=1)
			val2[i] = (val2[i] * inv2[i]) % MOD[i];
		// cout<<" OK?? "<<(inv2[i]* shifts_val[i][l2-1] ) % MOD[i]<<endl;
		// cout<<"Hash Values: "<<val1[i]<<" "<<val2[i]<<endl;
	}
	// cout<<endl;
	for(int i =0;i<2;i++)
	{
		if(val1[i]!=val2[i])
		{
			if ((r1-l1+1) %2)
				return 0;
			int mid1 = (l1+r1)>>1;
			int mid2 = (l2+r2)>>1; 
			return (eq (l1,mid1,mid2+1,r2) && eq(mid1+1,r1,l2,mid2) ) || 
				   (eq (l1,mid1,l2,mid2) && eq(mid1+1,r1,mid2+1,r2) );
		}
	}
	return 1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>s1>>s2;
	// find hashes of two strings 
	for(int i=0;i<2;i++)
	{
		hash1[i]=std::vector<long long int> (s1.size()+1,0);
		hash2[i]=std::vector<long long int> (s1.size()+1,0);
		shifts_val[i] = std::vector<long long int> (s1.size()+1,1);
		inverse_shifts_val[i] = std::vector<long long int> (s1.size()+1,1);
	}
	
	for (int i=1;i<s1.size();i++)
	{
		for (int j=0;j<2;j++)
		{
			shifts_val[j][i] = (shifts_val[j][i-1] * base[j]) % MOD[j];
			inverse_shifts_val[j][i] = inverse(shifts_val[j][i], MOD[j]);
		}
	}

	for(int i=0;i<26;i++)
	{
		cs1[i] = std::vector<int> (s1.size()+1,0);
		cs2[i] = std::vector<int> (s1.size()+1,0);
	}


	long long int mult1[] ={1,1};
	long long int mult2[] ={1,1};
	for(int in=1;in<= s1.size();in++)
	{
		int cur_char = s1[in-1]-'a';
		cs1[cur_char][in]++;
		for(int i=0;i<26;i++)
		{
			cs1[i][in] += cs1[i][in-1];
		}
		cur_char = s2[in-1]-'a';
		cs2[cur_char][in]++;
		for(int i=0;i<26;i++)
		{
			cs2[i][in] += cs2[i][in-1];
		}
		for(int i=0;i<2;i++)
		{
			hash1[i][in] = ((s1[in-1]-'a'+1) * mult1[i])% MOD[i];
			hash1[i][in] = (hash1[i][in]+hash1[i][in-1])%MOD[i];
			mult1[i] = (mult1[i] * base[i]) % MOD[i]; 
			hash2[i][in] = ((s2[in-1]-'a'+1) * mult2[i])% MOD[i];
			hash2[i][in] = (hash2[i][in]+hash2[i][in-1])%MOD[i];
			mult2[i] = (mult2[i] * base[i]) % MOD[i]; 
		}
	}
	
	// if same -> OK
	if (eq(1,s1.size(),1,s1.size()))
	{
		cout<<"YES";
	}
	else
		cout<<"NO";
	// 
}