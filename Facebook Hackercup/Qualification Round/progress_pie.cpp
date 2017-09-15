#include "bits/stdc++.h"
using namespace std;
typedef complex<long double> point;
#define X real
#define Y imag
#define PI (2*acos(0))
#define EPS 0.000000001
long double getPercentage(point p,point p1)
{
  long double angle=remainder(arg(p)-arg(p1),2*PI);
  long double percent=angle*100/(2*PI);
  if(percent<0)
    percent+=100;
  return percent;
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    // freopen("progress_pie_out.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  long double P,x,y;
  for(int t=1;t<=T;t++)
  {
    cin>>P>>x>>y;
    x-=50;
    y-=50;
    point p(0,50);
    point p1(x,y);
    if(abs(abs(p1)-50)<=EPS || abs(p1)<50)
    {
      //Find the theta
      long double percent=getPercentage(p,p1);
      if(percent<P || abs(percent-P)<EPS)
      {
        cout<<"Case #"<<t<<": black"<<endl;
      }
      else
      {
        cout<<"Case #"<<t<<": white"<<endl;
      }
    }
    else
    {
      cout<<"Case #"<<t<<": white"<<endl;
    }
  } 
}