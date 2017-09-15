//AC
#include "bits/stdc++.h"
using namespace std;
typedef complex<long double> point;
#define X real()
#define Y imag()
#define reflect(p,a,b) a + conj((p - a) / (b - a)) * (b - a)

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  long double x,y;
  point x1,x2,x3,x4;
  while(cin>>x>>y)
  {
    x1=point(x,y);
    cin>>x>>y;
    x2=point(x,y);
    cin>>x>>y;
    x3=point(x,y);
    cin>>x>>y;
    x4=point(x,y); 
    if(norm(x3-x1)<0.00001)
    {
      swap(x1,x2);
    }
    else if(norm(x4-x1)<0.00001)
    {
      swap(x1,x2);
      swap(x3,x4);
    }
    else if(norm(x4-x2)<0.00001)
    {
      swap(x3,x4);
    }
    point ans=x4+x1-x2;
    cout<<fixed<<setprecision(3)<<ans.X<<" "<<ans.Y<<endl;
  }

}