  #include "bits/stdc++.h"
  using namespace std;
  double dp[4][3][30009]={};// gameindx noofwins diff+15000
  bool solved[4][3][30009]={};

  vector<int>validdiff(5005,0);// Loser-Winner
  double totalperm=0;
  double solve(int gameidx=0,int nowins=0,int diff=0)
  {
	  if(solved[gameidx][nowins][diff])
		  return dp[gameidx][nowins][diff];
	  double ans=0;
	  for(int i=0;i<=5000;i++)
	  {
		  if(validdiff[i]>0)
		  {
			  ans+=(validdiff[i]/totalperm)*solve(gameidx+1,nowins,diff+i);
			  ans+=(validdiff[i]/totalperm)*solve(gameidx+1,nowins+1,diff-i);
		  }
	  }
	  solved[gameidx][nowins][diff]=1;
	  return dp[gameidx][nowins][diff]=ans;
  }
  int main()
  {
	  std::ios::sync_with_stdio(false);
	  #ifndef ONLINE_JUDGE
		  freopen("in.txt","r",stdin);
	  #endif
	  int n;
	  cin>>n;
	  vector<int>balls(n);
	  for(int i=0;i<n;i++)cin>>balls[i];
	
	  int cdiff;
	  for(int i=0;i<n;i++)
	  {
		  for(int j=i+1;j<n;j++)
		  {
			  totalperm++;
			  cdiff=balls[i]-balls[j];
			  cdiff=(cdiff<0)?-cdiff:cdiff;
			  validdiff[cdiff]++;
		  }
	  }
	  cout<<solve();
  }
