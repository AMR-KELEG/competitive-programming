// AC
#include <bits/stdc++.h>
using namespace std;

int dr[] = {0, 0, 1,-1,-1, 1,-1, 1};
int dc[] = {1,-1, 0, 0, 1, 1,-1,-1};
string s;
bool vis[4][4];
string grid[4];

bool dfs(int r,int c,int indx=0)
{
    if (indx == s.size()-1)
        return 1;
    vis[r][c] = 1;
    for (int k=0;k<8;k++)
    {
        int rn = r+dr[k];
        int cn = c+dc[k];
        if (rn<0 || rn==4 || cn<0 || cn==4)
            continue;
        if (vis[rn][cn])
            continue;
        if (grid[rn][cn] == s[indx+1])
        {
            if (dfs(rn,cn,indx+1))
            {
                vis[r][c] = 0;
                return 1;
            }
        } 
    }
    vis[r][c] = 0;
    return 0;
}

int main ()
{
    std::ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    int tc, score[17] = {0};
    score[3] = score[4] = 1;
    score[5] = 2;
    score[6] = 3;
    score[7] = 5;
    for(int i = 8; i < 17; i++)
        score[i] = 11;
    int test = 1;
    cin >> tc;
    while(tc--)
    {
        for(int i = 0; i < 4; i++)
        {
            cin>>grid[i];
        }

        int m, ans = 0;
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> s;
            bool ok = 0;
            for (int r=0;r<4;r++)
            {
                for (int c=0;c<4;c++)
                {
                    if (grid[r][c] == s[0] && dfs(r,c))
                    {
                        ok = 1;
                        c=r=4;
                    }
                }
            }
            if (ok)
            {
                ans += score[(int)s.size()];
            }
        }
        cout << "Score for Boggle game #" << test++ << ": " << ans << endl;
    }
    return 0;
}
