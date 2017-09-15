#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "bits/stdc++.h"
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
    #endif
    std::ios::sync_with_stdio(false);
    int n;
    long long int cases=0,j=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(), a.end());
    for(int fa=1;fa<n;fa++)
    {
        for(int fj=fa-1;fj>=0;fj--)
        {
            for(int sa=1;sa<n;sa++)
            {
                for(int sj=sa-1;sj>=0;sj--)
                {
                    for(int tj=1;tj<n;tj++)
                    {
                        for(int ta=tj-1;ta>=0;ta--)
                        {
                            cases++;
                            if(a[fj]+a[sj]+a[tj]>a[fa]+a[sa]+a[ta])
                            {
                                j++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<std::fixed<<setprecision(10)<<1.0*j/cases;

    return 0;
}
