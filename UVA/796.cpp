//AC
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define sz(v)       ((int)((v).size()))
#define clr(v, d)     memset(v, d, sizeof(v))
#define repi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define repa(v)       repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)     repi(i, 0, sz(v))
#define lp(i, cnt)      repi(i, 0, cnt)
#define lpi(i, s, cnt)    repi(i, s, cnt)
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
#define pb          push_back
#define MP          make_pair

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef long double ld;

const int MAXN = 1000;


std::vector<std::vector<int> > adjlist;
std::vector<int> low, dfn;
int num, n;
vector<pair<int, int> > bridges;

void art_bridges(int i, int p) {
  low[i] = dfn[i] = ++num;

  for (int j = 0; j < adjlist[i].size(); ++j) 
    if (adjlist[i][j] != p) {
      if (dfn[adjlist[i][j]] == 0) {
        art_bridges(adjlist[i][j], i);
        low[i] = min(low[i], low[adjlist[i][j]]);
        if (low[adjlist[i][j]] == dfn[adjlist[i][j]])
          bridges.push_back(make_pair(min(i, adjlist[i][j]), max(i, adjlist[i][j])));
      } 
      else
        low[i] = min(low[i], dfn[adjlist[i][j]]);
    }

}

void run_art_bridges() {
  lp(i, n)  low[i] = -1, dfn[i] = 0;

  bridges.clear();

  lp(i, n) if (!dfn[i])
    art_bridges(i, -1);

  sort(all(bridges));

}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  int to, cnt, from;
  char ch;

  while (cin >> n) {

    int m;
    low=std::vector<int> (n);
    dfn=std::vector<int> (n);
    adjlist=std::vector<std::vector<int> > (n);
    for(int i=0;i<n;i++)
    {
      int from;
      cin>>from;
      cin>>ch>>m>>ch;
      for(int j=0;j<m;j++)
      {
        cin>>to;
        adjlist[from].push_back(to);
      } 
    }
    run_art_bridges();

    cout << bridges.size() << " critical links\n";
    rep(i, bridges)
      cout << bridges[i].first << " - " << bridges[i].second << "\n";

    cin >> ws;
    cout << "\n";

  }
  return 0;
}
