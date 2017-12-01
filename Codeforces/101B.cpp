//AC
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<int> tree;

void update(int node,int l,int r,int in,int add)
{
    if(l>in || r<in) return ;
    if(l==r && l==in)
    {
        long long int val = add + tree[node];
        val %= MOD;
        tree[node] = val;
        return ;
    }
    int mid = (l+r)>>1;
    update(2*node, l, mid, in, add);
    update(2*node+1, 1+mid, r, in, add);
    tree[node] = (tree[2*node] + tree[2*node+1]) % MOD;
}

int query(int node,int l,int r,int rl,int rr)
{
    if(l>rr || r<rl || l>r || l<0) return 0;
    if(l>=rl && r<=rr)
    {
        return tree[node];
    }
    int mid = (l+r)>>1;
    long long int ans = query(2*node,l,mid,rl,rr);
    ans += query(2*node+1,1+mid,r,rl,rr);
    ans %= MOD;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    // Need to reach station at n
    vector<pair<int,int> > buses(m); // end - start
    tree = vector<int> (4*m,0);
    for(int i=0;i<m;i++)
    {
        cin>>buses[i].second>>buses[i].first;
    }
    sort(buses.begin(), buses.end());
    auto it = buses.begin();
    pair<int,int> p;
    int a =0;
    for(int i=0;i<m;i++)
    {
        p.first = buses[i].second;
        p.second = -1;
        int st = lower_bound(buses.begin(),it,p) - buses.begin();
        p.first = buses[i].first;
        p.second = 0;
        int en = lower_bound(buses.begin(),it,p) - buses.begin();
        if (buses[en].first == buses[i].first)
            en--;
        long long int ans = ((buses[i].second == 0) +query(1,0,m-1,st,en)) % MOD;
        if (buses[i].first == n)
        {
            a = (a+ans)%MOD;
        }
        update (1,0,m-1,i,ans);
        it++;
    }
    cout << a;
}
