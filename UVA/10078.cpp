//AC
#include "bits/stdc++.h"
using namespace std;
typedef complex<long double> point;
#define X real
#define Y imag
#define cross(a,b) (conj((a))*(b)).imag()
std::vector<point> pts;

int isCW(int i)
{
  //p2-p1 X p3-p2
  long double ans=cross(pts[i+1]-pts[i],pts[i+2]-pts[i+1]);
  if(abs(ans)<0.0000001)
    return 0;
  if(ans>0)
    return 1;
  return -1;
}

int main()
{
  
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  #endif

  int n;
  cin>>n;
  while(n!=0)
  {
    pts=std::vector<point> (n);
    int x,y;
    for(int i=0;i<n;i++)
    {
      cin>>x>>y;
      pts[i].X(x);
      pts[i].Y(y);
    }

    // p1 p2 p3
    // p2 p3 p1
    // p3 p1 p2
    pts.push_back(pts[0]);
    pts.push_back(pts[1]);
    int orientation=isCW(0);
    bool ok=1;
    for(int i=1;i<n;i++)
    {
     if(orientation!=isCW(i))
      {
        ok=0;
        break;
      }
    }
    if(!ok)
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");  
    }
    cin>>n;
  } 
}