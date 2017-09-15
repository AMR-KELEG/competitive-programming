//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<long double> a;
long double PI=(2*acos(0));

long double f(long double x)
{
  long double mult=1;
  long double ans=0;
  for(int i=0;i<a.size();i++)
  {
    ans+=a[i]*mult;
    mult*=x;
  }

  return ans*ans;
}

int Counter=0;

double simps(double a, double b) {
  Counter++;
  return PI*((f(a)) + 4*f((a+b)/2) + f(b))*(b-a)/6;
}

long double Vol(long double x1,long double x2)
{
  long double mid=(x1+x2)/2;
  long double lv=simps(x1,mid),rv=simps(mid,x2),tot=simps(x1,x2);
  if(abs(tot-(lv+rv))<0.000000000001)
    return tot;
  return Vol(x1,mid)+Vol(mid,x2);
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n;
  int t=0;
  // bool ok=1;
  // ok=bool(cin>>n);

  while(cin>>n)
  {
    t++;
    // cout<<n<<endl;
    a=std::vector<long double> (n+1);
    for(int i=0;i<=n;i++)
      cin>>a[i];
    long double xl,xh,inc;
    cin>>xl>>xh>>inc;
    printf("Case %d: %.2Lf\n", t,Vol(xl,xh));
    if(Vol(xl,xh)<inc)
    {
      printf("insufficient volume");
      // ok=bool(cin>>n);
      // if(ok)
        printf("\n");
    }
    else
    {
      //Binary Search here
      int pointIndx=0;
      long double XMIN=xl;
      while(Vol(xl,xh)>inc && pointIndx<8)
      {
        long double r=xh,l=xl;
        long double mid=(l+r)/2;
        while(abs(Vol(xl,mid)-inc)>0.0000001)
        {
          if(Vol(xl,mid)>inc)
          {
            r=mid;
          }
          else
          {
            l=mid;
          }
          mid=(l+r)/2;
        }
        if(pointIndx)
          printf(" ");
        printf("%.2Lf",mid-XMIN );
        // printf("%.2Lf %.2Lf %.2Lf\n",l,mid,r );
        xl=mid;
        pointIndx++;
        // break;
      }
    // ok=bool(cin>>n);
    // if(ok)
      printf("\n");
    }
  }
}