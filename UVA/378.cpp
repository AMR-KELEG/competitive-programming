//AC
#include "bits/stdc++.h"
using namespace std;
typedef complex<long double> point;
#define X real
#define Y imag
#define cross(p1,p2) (conj((p1))*(p2)).imag()
#define EPS 0.000000001

/*
  p1=a-bi
  p2=c+di
  
  ad-bc
  
  (ac+bd)+i(ad-bc)

*/
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int t;
  cin>>t;

  // p3---------p4   p1-----------p2
  printf("INTERSECTING LINES OUTPUT\n");
  while(t--) 
  {
    int x,y;
    point p1,p2,p3,p4;
    cin>>x>>y;
    p1=point(x,y);
    cin>>x>>y;
    p2=point(x,y);
    cin>>x>>y;
    p3=point(x,y);
    cin>>x>>y;
    p4=point(x,y);
    // Check collinear
    long double c1=cross(p3-p1,p3-p4);
    long double c2=cross(p3-p2,p3-p4);
    if(abs(c1)<EPS && abs(c2)<EPS)
    {
      printf("LINE\n");
    }
    else
    {
      //Check parallel
      long double s1=(arg(p3-p4));
      long double s2=(arg(p1-p2));
      // cout<<s1<<" "<<s2<<endl;
      if(abs(s1-s2)<EPS || abs(abs(s1-s2)-(2*acos(0)))<EPS)
      {
        printf("NONE\n");
      }
      else
      {
        // FIND INTERSECTION!!!!!!!!!!!!!!!!
        //y=mx+c
        //DELTAX*y=DELTAY*x+c
        // a=DELTAY;
        // b=-DELTAX;
        // c=DELTAX*y-DELTAY*X;
        int dx=p1.X()-p2.X();
        int dy=p1.Y()-p2.Y();
        long double a1=dy,b1=-dx;
        long double c1=-(dx*p1.Y())+(dy*p1.X());
        dx=p3.X()-p4.X();
        dy=p3.Y()-p4.Y();
        long double a2=dy,b2=-dx;
        long double c2=-(dx*p3.Y())+(dy*p3.X());
        long double det=a1*b2-(b1*a2);
        long double ax=(b2*c1-b1*c2)/det;
        long double ay=(a1*c2-a2*c1)/det;
        printf("POINT %.2Lf %.2Lf\n", ax,ay);
      }
    }
  }
  printf("END OF OUTPUT\n");
}