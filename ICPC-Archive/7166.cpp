//11:28
#include "bits/stdc++.h"
using namespace std;
typedef complex<long double> point;
#define rotate(a,ang) ((a)*exp(point(0,ang)))
#define X real
#define Y imag  
#define INF 1000000000
#define EPS 0.0000000000001
#define dot(a,b) (conj(a)*b).X()
#define cross(a,b) (conj(a)*(b)).Y()
long double area(std::vector<point> &pts)
{
  pts.push_back(pts[0]);
  long double ans=0;
  for(int i=0;i<pts.size()-1;i++)
  {
    ans+=0.5*(pts[i+1].Y()-pts[i].Y())*(pts[i+1].X()+pts[i].X());  
  }
  pts.pop_back();
  return abs(ans);
}

bool amr=0;
point intersect(point a,point b,point c,point d)
{
  if(amr)
  {
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;    
  }
  long double a1=(a-b).Y();
  long double b1=(a-b).X();
  long double c1=-(a1*a.X()+b1*a.Y());

  long double a2=(c-d).Y();
  long double b2=(c-d).X();
  long double c2=-(a2*c.X()+b2*c.Y());
  if(abs(cross(b-a,d-c))<EPS && abs(c1-c2)<EPS)
  {
    return d;
  }
  long double det=(a1*b2)-(a2*b1);
  if(abs(det)<EPS)
  {
    return point(INF,INF);
  }
  long double x=(b1*c2)-(b2*c1);
  long double y=-(a1*c2)+(a2*c1);
  x/=det;y/=det;
  long double minX=min(c.X(),d.X()),maxX=max(c.X(),d.X());
  long double minY=min(c.Y(),d.Y()),maxY=max(c.Y(),d.Y());
  if(amr)
  {
    cout<<x<<" "<<y<<" ";
    cout<<det<<endl;
    cout<<"X "<<minX<<" "<<x<<" "<<maxX<<endl;
    cout<<"Y "<<minY<<" "<<y<<" "<<maxY<<endl;
  }
  if(x>=minX-EPS && x<=maxX+EPS)
    return point(x,y);
  return point(INF,INF);
}

pair<long double,long double> RightIsGreater(long double ang,std::vector<point> &pts)
{
  std::vector<point> rotatedPoints(pts.size());
  for(int i=0;i<pts.size();i++)
  {
    rotatedPoints[i]=rotate(pts[i],ang);
  }
  std::vector<point> outputPolygon;
  bool isleft=0;
  int i=0;
  while(i<rotatedPoints.size() && (abs(rotatedPoints[i].X())<EPS))
  {
    rotatedPoints[i].X(0);
    outputPolygon.push_back(rotatedPoints[i]);
    i++;
  }

  if(i<rotatedPoints.size() && rotatedPoints[i].X()<0)
  {
    isleft=1;
  }

  for(;i<rotatedPoints.size();i++)
  {
    if((rotatedPoints[i].X()<0 && (isleft))||(rotatedPoints[i].X()>0 && (!isleft)))
    {
      outputPolygon.push_back(rotatedPoints[i]);
    }
    else
    {
      point in=intersect(point(0,0),point(0,-1),rotatedPoints[i],rotatedPoints[i-1]);
      // point in=intersect(point(0,0),point(0,-1),rotatedPoints[i-1],rotatedPoints[i]);
      outputPolygon.push_back(in);
      // if(amr)
      // {
      //   cout<<rotatedPoints[i]<<" ";
      //   cout<<"Point is "<<in<<endl<<endl;
      // }
      break;
    }
  }
  // if(amr)
  // {
  //   for(int i=0;i<outputPolygon.size();i++)
  //   {
  //     cout<<outputPolygon[i]<<endl;
  //   }
  // }
  long double AL=area(outputPolygon);
  long double AR=area(rotatedPoints)-AL;
  if(!isleft)
  {
    swap(AL,AR);
  }
  
  return {AR,AL};
}


bool complexCMP(const point & a,const point & b)
{
  if((a.Y()<b.Y()) || ((abs(a.Y()-b.Y())<EPS) && a.X()<b.X()))
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
  for(int te=1;te<=t;te++)
  {
    int n;
    cin>>n;
    std::vector<point> pts(n);
    int x,y;
    for(int i=0;i<n;i++)
    {
      cin>>x>>y;
      pts[i]=point(x,y);
    }
    
    int steps=0;
    long double angle=0;
    auto areas1=RightIsGreater(0,pts);
    long double minDiff=abs((areas1.first)-(areas1.second));
    long double minAngle=0;
    for(;angle<4*acos(0);angle+=(2*acos(0)/180))
    {
      auto areas=RightIsGreater(angle,pts);
      if(abs(areas.first-areas.second)<minDiff)
      {
        minDiff=abs(areas.first-areas.second);
        minAngle=angle;
      }
    }

    long double left=minAngle-((2*acos(0))/8);
    long double right=minAngle+((2*acos(0))/8);
    long double leftArea=RightIsGreater(left,pts).first-RightIsGreater(left,pts).second;
    long double rightArea=RightIsGreater(right,pts).first-RightIsGreater(right,pts).second;
    if(leftArea>rightArea)
    {
      minAngle+=2*acos(0);
      left+=2*acos(0);
      right+=2*acos(0);
    }

    for(int it=0;it<500;it++)
    {
      long double mid=(left+right)/2;
      minAngle=mid;
      auto curArea=RightIsGreater(mid,pts);
      if(abs(curArea.first-curArea.second)<EPS)
      {
        amr=1;
        RightIsGreater(mid,pts);
        // cout<<"AREA "<<curArea.first<<" "<<curArea.second<<endl;
        break;
      }
      if(curArea.first>curArea.second)
      {
        right=mid;
      }
      else
      {
        left=mid;
      }
    }
    minAngle=(left+right)/2;
    // cout<<minAngle*180/(2*acos(0))<<endl;
    // cut by x axis
    // if area up>area down
    // add 180


    // 4.134357 -2.984475
    // -3.319389 -7.278850
    // cout<<endl<<endl<<intersect(point(4.134357,-2.984475),point(-3.319389,-7.278850),point(0,0),point(0,-1))<<endl<<endl;
    std::vector<point> rotatedPoints(pts.size());
    for(int i=0;i<pts.size();i++)
    {
      rotatedPoints[i]=rotate(pts[i],minAngle);
    }

    while(minAngle>4*acos(0))
      minAngle-=4*acos(0);
    // cout<<"Case "<<te<<":\n";
    // for(int i=0;i<pts.size();i++)
    // {
    //   point cur=rotate(pts[i],minAngle);
    //   if(abs(cur.X())<EPS)
    //     cur.X(0);
    //   if(abs(cur.Y())<EPS)
    //     cur.Y(0);
    //   cout<<fixed<<setprecision(6)<<cur.X()<<" "<<cur.Y()<<endl;
    // }

  } 
}