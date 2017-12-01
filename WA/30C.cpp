#include <bits/stdc++.h>
#define EPS 0.0000000001
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > pts(n);
    vector<long double> p(n);
    vector<int> ti(n);

    for(int i=0;i<n;i++)
    {
        cin>>pts[i].first>>pts[i].second;
        cin>>ti[i]>>p[i];
    }
    long double Mans=0;
    for(int t=0;t<n;t++)
    {
        int x0=pts[t].first;
        int y0=pts[t].second;
        long double ans=p[t];
        for(int i=0;i<n;i++)
        {
            if(i==t)continue;
            long double rt = (pts[i].first-x0)*(pts[i].first-x0)+
                     (pts[i].second-y0)*(pts[i].second-y0);
            rt = sqrt(rt);
            if(abs(rt-ti[i])<=EPS)
            {
                ans+=p[i];
            }
        }
        Mans=max(Mans,ans);
    }
    cout<<Mans;
}
