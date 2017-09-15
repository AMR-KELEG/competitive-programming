//AC
#include "bits/stdc++.h"
using namespace std;
struct line
{
  long long int a,b,d;
  line(long long int la=0,long long int lb=0,long long int ld=0)
  {
    a=la,b=lb,d=ld;
  }
};

line findLine(int x1,int y1,int x2,int y2)
{
  long long int dx=x2-x1;
  long long int dy=y2-y1;
  long long int d=(y1*dx)-(dy*x1);
  return line(dy,-dx,d);
}

bool intesect(line l1,line l2,
  long long int x1,long long int y1,long long int x2,long long int y2,
  long long int x3,long long int y3,long long int x4,long long int y4)
{
  long long int det=((l1.a)*(l2.b))-((l1.b)*(l2.a));
  if(det==0)
  {
    return 0;
  }
  long long int xin=((l2.d)*(l1.b))-((l2.b)*(l1.d));
  long long int yin=((l2.a)*(l1.d))-((l2.d)*(l1.a));
  
  long long int xmin=min(x1,x2)*det;
  long long int xmax=max(x1,x2)*det;
  long long int ymin=min(y1,y2)*det;
  long long int ymax=max(y1,y2)*det;
  long long int xmin1=min(x3,x4)*det;
  long long int xmax1=max(x3,x4)*det;
  long long int ymin1=min(y3,y4)*det;
  long long int ymax1=max(y3,y4)*det;
  if(det<0)
  {
    xin*=-1;
    xmin*=-1;
    xmax*=-1;
    yin*=-1;
    ymin*=-1;
    ymax*=-1;
    xmin1*=-1;
    xmax1*=-1;
    ymin1*=-1;
    ymax1*=-1;
  }

  if(xin>=xmin && xin<=xmax && yin>=ymin && yin<=ymax
    && xin>=xmin1 && xin<=xmax1 && yin>=ymin1 && yin<=ymax1)
    return 1;
  return 0;
}

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    line l=findLine(x1,y1,x2,y2);
    int xl,yl,xr,yr;
    cin>>xl>>yl>>xr>>yr;
    
    if(x1>=min(xl,xr) && x1<=max(xl,xr) && y1>=min(yl,yr) && y1<=max(yl,yr))
    {
      cout<<"T\n";
    }
    else if(x2>=min(xl,xr) && x2<=max(xl,xr) && y2>=min(yl,yr) && y2<=max(yl,yr))
    {
      cout<<"T\n";
    }
    else if(intesect(l,findLine(xl,yl,xl,yr),x1,y1,x2,y2,xl,yl,xl,yr))
    {
      cout<<"T\n";
    }
    else if(intesect(l,findLine(xl,yl,xr,yl),x1,y1,x2,y2,xl,yl,xr,yl))
    {
      cout<<"T\n"; 
    }
    else if(intesect(l,findLine(xr,yr,xl,yr),x1,y1,x2,y2,xr,yr,xl,yr))
    {
      cout<<"T\n";
    }
    else if(intesect(l,findLine(xr,yr,xr,yl),x1,y1,x2,y2,xr,yr,xr,yl))
    {
      cout<<"T\n";
    }
    else
    {
      cout<<"F\n";
    }
  } 
}