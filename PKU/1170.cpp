#include "iostream"
#include "vector"
#include "map"
#include <cstring>
using namespace std;
map<int,int> mp; // code to indx
int products;
std::vector<int> prices,offers_prices;
std::vector<vector<int> > offers;
int dp[6][6][6][6][6][99];
int solve(int fi,int se,int th,int fo,int fv,int offer_indx = 0)
{
	if(offer_indx == int(offers.size()))
	{
		//Done
		return fi*prices[0]+se*prices[1]+th*prices[2]+fo*prices[3]+fv*prices[4];
	}
	if(dp[fi][se][th][fo][fv][offer_indx]!=-1)
		return dp[fi][se][th][fo][fv][offer_indx];
	int ans =solve(fi,se,th,fo,fv,offer_indx+1);
	if(fi>=offers[offer_indx][0] &&
	   se>=offers[offer_indx][1] &&
	   th>=offers[offer_indx][2] &&
	   fo>=offers[offer_indx][3] &&
	   fv>=offers[offer_indx][4])
		ans = min(ans,offers_prices[offer_indx] + 
			solve(fi-offers[offer_indx][0],
				se-offers[offer_indx][1],
				th-offers[offer_indx][2],
				fo-offers[offer_indx][3],
				fv-offers[offer_indx][4],
				offer_indx+1));
	return dp[fi][se][th][fo][fv][offer_indx]= ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp,-1,sizeof dp);
	cin>>products;
	std::vector<int> req(5,0);
	prices = std::vector<int> (5,0);
	int code;
	for(int i=0;i<products;i++)
	{
		cin>>code;
		int indx =i;
		if(mp.find(code)!=mp.end())
		{
			indx = mp[code];
		}
		mp[code]=indx;
		int r,p;
		cin>>r>>p;
		req[indx]+=r;
		prices[indx]=p;
	}
	int no_offers;
	cin>>no_offers;
	offers = std::vector<std::vector<int> > (no_offers,std::vector<int> (5,0));
	offers_prices = std::vector<int> (no_offers,0);
	for(int i=0;i<no_offers;i++)
	{
		//no of pro / key and quan / price
		int n;
		cin>>n;
		bool imp_offer = false;
		while(n--)
		{
			int k,q;
			cin>>k>>q;
			if(mp.find(k)==mp.end())
			{
				// Ignore this offer
				imp_offer=true;
				continue;
			}
			offers[i][mp[k]]+=q;
		}
		cin>>offers_prices[i];
		if(imp_offer)
			offers_prices[i]=999*25;
	}
	cout<<solve(req[0],req[1],req[2],req[3],req[4]);
}