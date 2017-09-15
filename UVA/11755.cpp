//AC
#include "bits/stdc++.h"
#define EPS 0.0000000001
using namespace std;

long double p1,p2; 

long double dpc[22][22];
int t;
int visc[22][22];

long double getC(int pt1 , int pt2)
{
  if(visc[pt1][pt2] == t) return dpc[pt1][pt2];
  if(pt1 == 21 || pt2 == 21) return 0;
  if(pt1 == 20 && pt2 == 20) return 1;
  visc[pt1][pt2] = t;
  bool p1turn = !(((pt1+pt2)/5)%2);
  if(p1turn)
    return dpc[pt1][pt2] = p1*getC(pt1+1,pt2) + (1-p1)*getC(pt1,pt2+1);
  else
    return dpc[pt1][pt2] = p2*getC(pt1+1,pt2) + (1-p2)*getC(pt1,pt2+1);
}

long double prob1[22][22];
int visprob1[22][22];

long double getProbP1(int pt1 , int pt2)
{
  if(visprob1[pt1][pt2] == t) return prob1[pt1][pt2];
  
  if(pt1 == 21) return 1;
  if(pt2 == 21) return 0;
  
  if(pt1 == 20 && pt2 == 20) return 0;
  
  visprob1[pt1][pt2] = t;
  bool p1turn = !(((pt1+pt2)/5)%2);
  if(p1turn)
    return prob1[pt1][pt2] = p1*getProbP1(pt1+1,pt2) + (1-p1)*getProbP1(pt1,pt2+1);
  else
    return prob1[pt1][pt2] = p2*getProbP1(pt1+1,pt2) + (1-p2)*getProbP1(pt1,pt2+1);
}

long double dp[22][22];
int vis[22][22];

long double solve(int pt1 , int pt2)
{
  if(vis[pt1][pt2] == t) return dp[pt1][pt2];
  if(pt1 == 21) return 1;
  if(pt2 == 21) return 0;
  if(pt1 == 20 && pt2 == 20) return dp[15][15];
  vis[pt1][pt2] = t;
  bool p1turn = !(((pt1+pt2)/5)%2);
  if(p1turn)
    return dp[pt1][pt2] = p1*solve(pt1+1,pt2) + (1-p1)*solve(pt1,pt2+1);
  else
    return dp[pt1][pt2] = p2*solve(pt1+1,pt2) + (1-p2)*solve(pt1,pt2+1);
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int tc; cin>>tc;
  for(t = 1 ; t <=tc; t++)
  {
    string s; 
    getline(cin,s);
    getline(cin,s);
    // cin>>s;
    p1 = -1;
    p2 = -1;
    cin>>p1>>p2;
    bool ok =1;
    int tot1=0,tot2=0;
    for(int i=0; i<s.length() && ok;i++)
    {
      bool p1turn = !((i/5)%2);
      if(s[i] == 'W')
      {
        tot1++;        
        // TODO: Changes here
        if(p1turn && abs(p1)<=EPS) ok=0;
        else if(!p1turn && abs(p2)<=EPS) ok=0;
      }
      else
      {
        tot2++;
        // TODO: Changes here
        if(p1turn && abs(p1-1)<=EPS) ok = 0;
        else if(!p1turn && abs(p2-1)<=EPS) ok=0;     
      }
      if ((tot1==21 || tot2==21) && i+1<s.size())
      {
        ok=0;
        break;
      }
      if (tot1 == 20 && tot2 == 20)
      {
        tot1 = 15;
        tot2 = 15;
      }
    }    
    // TODO: Changes here
    if(!ok) {
      cout<<fixed<<setprecision(6)<<"Case "<< t<<": -1.000000\n";
      continue;
    }
    
    // cout<<tot1<<" "<<tot2<<endl;
    // c==1 ??? !!!
    long double c = getC(15,15);
    if (abs(c-1)<=EPS)
    {
      // cout<<fixed<<setprecision(6)<<"Case "<< t<<": 0.000000\n";
      cout<<fixed<<setprecision(6)<<"Case "<< t<<": 0.000000\n";
      continue; 
    }
    long double cwin = getProbP1(15,15);
    dp[15][15]= cwin / (1-c);
    vis[15][15] = t;
    long double ans = solve(tot1,tot2);
    if(abs(ans)<EPS)
      ans = 0;
    cout<<fixed<<setprecision(6)<<"Case "<< t<<": "<<ans<<"\n";
  } 
}