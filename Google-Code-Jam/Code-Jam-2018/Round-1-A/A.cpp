// AC
#include <bits/stdc++.h>
using namespace std;

std::vector<string> grid;
std::vector<int> ver;
std::vector<int> hor;
int main()
{
	freopen("A-input", "r", stdin);
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		int R,C,H,V;
		cin>>R>>C>>H>>V;
		grid = std::vector<string> (R);
		ver = std::vector<int> (C,0);
		hor = std::vector<int> (R,0);
		int choco = 0;
		for (int r=0;r<R;r++)
		{
			cin>>grid[r];
			for (int c=0;c<C;c++)
			{
				if (grid[r][c]=='@')
				{
					ver[c]++;
					hor[r]++;
					choco++;
				}
			}
		}
		printf("Case #%d: ", t);
		if (choco==0)
		{
			printf("POSSIBLE\n");
			continue;
		}
		if (choco%(V+1) || choco%(H+1))
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		// do the checks
		int parts = 1;
		int cur_choco = 0;
		int req_choco = choco/(V+1);
		bool ok = 1;
		std::vector<int> ver_cuts;
		ver_cuts.push_back(0);
		for (int v=0;v<C;v++)
		{
			if (cur_choco+ver[v]<=req_choco)
			{
				cur_choco+=ver[v];
			}
			else if(cur_choco<req_choco)
			{
				ok=0;
				break;
			}
			else if (ver[v]<=req_choco)
			{
				ver_cuts.push_back(v);
				parts++;
				cur_choco= ver[v];
			}
			else
			{
				ok = 0;
				break;
			}
		}
		ok = ok && (parts==V+1);
		if (!ok)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		ver_cuts.push_back(C);
		parts = 1;
		cur_choco = 0;
		req_choco = choco/(H+1);
		std::vector<int> hor_cuts;
		hor_cuts.push_back(0);
		for (int h=0;h<R;h++)
		{
			if (cur_choco+hor[h]<=req_choco)
			{
				cur_choco+=hor[h];
			}
			else if (cur_choco<req_choco)
			{
				ok=0;
				break;
			}
			else if (hor[h]<=req_choco)
			{
				hor_cuts.push_back(h);
				parts++;
				cur_choco= hor[h];
			}
			else
			{
				ok = 0;
				break;
			}
		}
		ok = ok && (parts==H+1);
		if (!ok)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		req_choco = choco / ((H+1)*(V+1));
		hor_cuts.push_back(R);
		for (int i=0;i<ver_cuts.size()-1;i++)
		{
			for(int j=0;j<hor_cuts.size()-1;j++)
			{
				int rs = hor_cuts[j];
				int re = hor_cuts[j+1]-1;
				int cs = ver_cuts[i];
				int ce = ver_cuts[i+1]-1;
				cur_choco = 0;
				for (int r=rs;r<=re;r++)
				{
					for (int c=cs;c<=ce;c++)
					{
						if (grid[r][c]=='@')
						{
							cur_choco++;
						}
					}
				}
				if (cur_choco!=req_choco)
				{
					printf("IMPOSSIBLE\n");
					i=ver_cuts.size();
					ok=0;
					break;
				}
			}
		}
		if (ok)
			printf("POSSIBLE\n");
	}	
	return 0;
}
