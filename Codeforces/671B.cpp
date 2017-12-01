//AC
#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
vector<int> c;
int n,k;
int mn = INF,mx = -INF;

bool valid_min(int mn_val)
{
    long long int op = 0;
    for(int i=0;i<n;i++)
    {
        if(c[i]<mn_val)
        {
            op += mn_val - c[i];
        }
    }
    return k >= op && mn_val <= mx;
}

bool valid_max(int mx_val)
{
    long long int op = 0;
    for(int i=0;i<n;i++)
    {
        if(c[i]>=mx_val)
        {
            op += c[i] - mx_val;
        }
    }
    return k >= op && mx_val >= mn;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>k;
    c = vector<int>(n);
    for(int i=0;i<n;i++) {
        cin>>c[i];
        mn=min(mn,c[i]);
        mx=max(mx,c[i]);
    }
    sort(c.begin(), c.end());

    long long int s = 0;
    for(int i=0;i<n;i++)
    {
        c[i]-=mn;
        s += c[i];
    }
    mx -= mn;
    mn = 0;

    long long int op = 0;
    long long int stab = s/n;
    for(int i=0;i<n;i++)
    {
        op += c[i]<stab? stab-c[i] : 0;
    }

    int l=0,r=INF;
    int mid = (l+r+1)>>1;
    while(l!=r)
    {
        mid = (l+r+1)>>1;
        if(valid_min(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    mid=(l+r+1)>>1;
    int min_val = mid;
    l=0,r=INF;
    while(l!=r)
    {
        mid=(l+r)>>1;
        if(valid_max(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    mid=(l+r>>1);
    int max_val = mid;
    if(min_val >= max_val)
    {
        cout<< (s%n==0?0:1);
    }
    else
    {
        cout<<max_val-min_val;
    }

}
