//AC
#include <bits/stdc++.h>
#define INF 1000000009
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    int k;
    cin>>k;
    long long int steps=0;
    while(k--)
    {
        int dx,dy;
        cin>>dx>>dy;
        int sx = (dx<0)?((x-1)/abs(dx)):
                 (dx==0)?INF:
                 (n-x)/dx;
        int sy = (dy<0)?((y-1)/abs(dy)):
                 (dy==0)?INF:
                 (m-y)/dy;
        steps += min(sx,sy);
        x += dx*min(sx,sy);
        y += dy*min(sx,sy);

    }
    cout<<steps;
}