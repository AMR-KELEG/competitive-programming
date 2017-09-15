//AC
#include "bits/stdc++.h"
using namespace std;
#define X real
#define Y imag
#define segment pair<pair<int,pair<int,int>>,bool >
typedef complex<int> point;
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
    int x1,y1,x2,y2;
    //Segment is x ymin ymax
    //x1 y1 y2
    cin>>x1>>y1>>x2>>y2;
    std::vector<segment> segments;
    segments.push_back(segment({{min(x1,x2),{min(y1,y2),max(y1,y2)}},0}));
    segments.push_back(segment({{max(x1,x2),{min(y1,y2),max(y1,y2)}},1}));
    cin>>x1>>y1>>x2>>y2;
    segments.push_back(segment({{min(x1,x2),{min(y1,y2),max(y1,y2)}},0}));
    segments.push_back(segment({{max(x1,x2),{min(y1,y2),max(y1,y2)}},1}));
    sort(segments.begin(), segments.end());
    int noIn=0;
    bool intersect=0;
    int minX,minY,maxX,maxY;
    for(int i=0;i<4;i++)
    {
      if(!segments[i].second)
      {
        noIn++;
        if(noIn==2)
        {
          minX=segments[i].first.first;
          vector<pair<int,int>>ranges;
          ranges.push_back(segments[0].first.second);
          ranges.push_back(segments[i].first.second);
          sort(ranges.begin(), ranges.end());
          if(ranges[1].first>=ranges[0].first && ranges[1].first<=ranges[0].second)
          {
            minY=ranges[1].first;
            maxY=min(ranges[1].second,ranges[0].second);
          }
          else
          {
            break;
          }
          //set range or break
        }
      }
      else
      {
        if(noIn==2)
        {
          //set out
          maxX=segments[i].first.first;
          intersect=1;
          break;
        }
        else
        {
          break;
        }
      }
    }
    if(!intersect || minX==maxX || minY==maxY)
    {
      printf("No Overlap\n");
    }
    else
    {
      printf("%d %d %d %d\n", minX,minY,maxX,maxY);
    }
    if(t)
      printf("\n");
  }   
}