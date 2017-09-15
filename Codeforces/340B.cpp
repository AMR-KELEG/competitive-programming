//AC
#include "bits/stdc++.h"
using namespace std;
#define X real()
#define Y imag()
#define cross(x,y) (conj(x)*y).imag()
#define dot(x,y) (conj(x)*y).real()
#define EPS 0.0000001
typedef complex<long double> point;

std::vector<point> pts;
std::vector<short> indexes(4);

long double findArea(short & f,short & s,short & t,short & r)
{
  indexes[0]=f;
  indexes[1]=s;
  indexes[2]=t;
  indexes[3]=r;
  long double fans=0,ans;
  sort(indexes.begin(), indexes.end());
  while(next_permutation(indexes.begin(), indexes.end()))
  {

    ans=0.5*(pts[indexes[3]].Y-pts[indexes[0]].Y)*(pts[indexes[3]].X+pts[indexes[0]].X);
    
    for(int i=0;i<3;i++)
    {
      ans+=0.5*(pts[indexes[i]].Y-pts[indexes[i+1]].Y)*(pts[indexes[i]].X+pts[indexes[i+1]].X);
    }
    fans=max(ans,fans);
  }
  return fans;
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  short n;
  cin>>n;
  pts=std::vector<point> (n);
  for(short i=0;i<n;i++)
  {
    short x,y;
    cin>>x>>y;
    pts[i]=point(x,y);
  }
  long double area=0;
  for(short f=0;f<pts.size();f++)
  {
    for(short s=f+1;s<pts.size();s++)
    {
      //Find equation of diagonal
      long double maxVal=0;
      long double minVal=1e9;
      short in=-1;
      short in2=-1;
      for(short p=0;p<pts.size();p++)
      {
        if(p==f || p==s)
          continue;
        if(abs(dot(pts[p]-pts[f],pts[s]-pts[f]))<EPS)
          continue;        

        long double curVal=cross(pts[p]-pts[f],pts[s]-pts[f]);

        if(curVal>maxVal)
        {
          in=p;
          maxVal=curVal;
        }
        if(curVal<minVal)
        {
          in2=p;
          minVal=curVal;
        }
      }
      
      if(in!=-1 && in2!=-1 && in!=in2)
      {
        // cout<<f<<" "<<in<<" "<<s<<" "<<in2<<endl;
        area=max(area,abs(findArea(f,in,s,in2)));
      }
    }
  }
  cout<<fixed<<setprecision(9)<<area;
}