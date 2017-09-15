//AC
#include "iostream"
using namespace std;
long double x1,y1,x2,y2,r;
bool intersects()
{
  x1-=x2;
  y1-=y2;
  long double x3=52.5-x2,y3=3.66-y2;
  long double x4=52.5-x2,y4=-3.66-y2;
  y2=x2=0;
  long double dx,dy,dr,D;
  long double det;
  dx=x3-x1;
  dy=y3-y1;
  dr=(dx*dx)+(dy*dy);
  D=(x3*y1)-(x1*y3);
  det=(r*r*dr)-(D*D);
  if(det<0)
    return 0;
  swap(x3,x4);
  swap(y3,y4);
  dx=x3-x1;
  dy=y3-y1;
  dr=(dx*dx)+(dy*dy);
  D=(x3*y1)-(x1*y3);
  det=(r*r*dr)-(D*D);
  // cout<<det<<endl;
  if(det>=0)
    return 1;
  return 0;
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n;
  cin>>n;
  while(n--)
  {
    cin>>x1>>y1>>x2>>y2>>r;
    if( ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)) >(r*r) && x1>x2)// dis>r && x1>x2
    {
      cout<<"Goal!\n";
    }
    else if(intersects())
      cout<<"No goal...\n";
    else
      cout<<"Goal!\n";
  } 
}