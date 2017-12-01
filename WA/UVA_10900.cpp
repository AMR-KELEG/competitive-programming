// 11:51
#include <bits/stdc++.h>
#define EPS 0.00000000001
using namespace std;
int main()
{
    int n;
    long double t;
    cin>>n>>t;
    while(n!=0 || abs(t)>EPS)
    {
        long double ans = 1;
        if (t>=0.5)
        {
            ans = pow((1+t),n);
        }
        else
        {
            long double Alarge = (0.5)/(1-t);
            long double Asmall = 1-Alarge;
            long double r = 2*Alarge;
            ans = 0.75*pow(r,n);
            if (abs(r-1)<=EPS)
            {
                ans += Asmall;
            }
            else
            {
                ans += Asmall*((pow(0.75*r,n)-1)/(r-1));
            }
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
        cin>>n>>t;
    }
}
