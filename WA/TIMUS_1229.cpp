#include <bits/stdc++.h>
#define OFF 100000
using namespace std;
int layer1[102][102]={};
int layer2[102][102]={};
bool done = 0;
int n,m;
int brick=0;
void solve(int r=1,int c=1,bool forward = 1)
{
    if(c==0)
    {
        solve(r-1,m,0);
        return;
    }
    if(r==0)
        return;
    if(c==m+1)
    {
        solve(r+1,1,1);
        return;
    }
    if(r==n+1)
    {
        done=1;
        return;
    }
    if(forward)
    {
        if(layer2[r][c]<0)
        {
            //Make it horizontal at first
            if(layer1[r][c]!=layer1[r][c+1])
            {
                if(layer1[r][c+1]!=0)
                {
                    layer2[r][c]=layer2[r][c+1]=brick++;
                    solve(r,c+2,1);
                    return;
                }
            }
            // Make it vertical
            if(layer1[r][c]!=layer1[r+1][c])
            {
                if(layer1[r+1][c]!=0)
                {
                    layer2[r][c]=layer2[r+1][c]=OFF+brick;
                    brick++;
                    solve(r,c+1,1);
                    return;
                }
            }
            solve(r,c-1,0);
            return;
        }
        else
        {
            solve(r,c+1,1);
            return ;
        }
    }
    
    // Another one removed me (-2)
    if(layer2[r][c]==-2)
    {
      layer2[r][c]=-1;
      // What can i do now??
      //Make it vert
      solve(r,c-1,0);
      return ;
    }
    if(layer2[r][c]==-3)
    {
      layer2[r][c]=-1;
      // What can i do now??
      if(layer1[r][c]!=layer1[r+1][c])
      {
          if(layer1[r+1][c]!=0)
          {
              layer2[r][c]=layer2[r+1][c]=OFF+brick;
              brick++;
              solve(r,c+1,1);
              return;
          }
      }
      solve(r,c-1,0);
      return ;
    }
    else if(layer2[r][c]<OFF)
    {
        //MAKE IT VERT
        if(layer2[r][c]==layer2[r][c-1])
        {
            layer2[r][c]=-1;
            layer2[r][c-1]=-2;
            solve(r,c-1,0);
        }

        if(layer1[r][c]!=layer1[r+1][c])
        {
            if(layer1[r+1][c]!=0)
            {
                layer2[r][c]=layer2[r+1][c]=OFF+brick;
                brick++;
                solve(r,c+1,1);
                return;
            }
        }

        solve(r,c-1,0);
        return ;
    }
    else
    {
        //REMOVE THE VERT
        if(layer2[r][c]==layer2[r-1][c])
        {
            layer2[r][c]=-1;
            layer2[r-1][c]=-2;
        }
        solve(r,c-1,0);
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<101;i++)
        for(int j=1;j<101;j++)
            layer2[i][j]=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>layer1[i][j];
        }
    }
    solve();
    if(done)
    {
        map<int,int> mp;
        int no=1;
        for(int r=1;r<=n;r++)
        {
            for(int c=1;c<=m;c++)
            {
                if(mp.find(layer2[r][c])==mp.end())
                    mp[layer2[r][c]]=no++;
                printf("%d ",mp[layer2[r][c]]);
            }
            printf("\n");
        }
    }
    else
    {
        cout<<-1;
    }
}
