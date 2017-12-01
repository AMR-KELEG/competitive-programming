/* AC
   ACPC 2016
   - Merge Intersecting Lines -- O(n^2)
   - Find Count of Each Point
   - Find relation between points' counts and digits
*/
#include "bits/stdc++.h"
using namespace std;
#define Line pair<int, pair<int,int> >
map<pair<int,int>, int> point_to_indx;
std::vector<int> occurences;
std::vector<int> par;
int indx;
void generate_map(stack<Line> h, stack<Line> v)
{
	indx = 0;
	point_to_indx.clear();
	while(!h.empty())
	{
		Line l = h.top();
		h.pop();
		int y = l.first;
		int x1 = l.second.first;
		int x2 = l.second.second;
		if (point_to_indx.find({x1,y})==point_to_indx.end())
		{
			point_to_indx[{x1,y}] = indx++;
		}
		if (point_to_indx.find({x2,y})==point_to_indx.end())
		{
			point_to_indx[{x2,y}] = indx++;
		}
	}
	while(!v.empty())
	{
		Line l = v.top();
		v.pop();
		int x = l.first;
		int y1 = l.second.first;
		int y2 = l.second.second;
		if (point_to_indx.find({x,y1})==point_to_indx.end())
		{
			point_to_indx[{x,y1}] = indx++;
		}
		if (point_to_indx.find({x,y2})==point_to_indx.end())
		{
			point_to_indx[{x,y2}] = indx++;
		}
	}
	par = std::vector<int> (indx);
	for (int i=0;i<indx;i++)
	{
		par[i] = i;
	}
	occurences = std::vector<int> (indx,0);
}

int find(int a)
{
	if (a==par[a])
		return a;
	int cur_occ = occurences[a];
	occurences[a] = 0;
	par[a] = find(par[a]);
	occurences[par[a]]+= cur_occ;
	return par[a];
}

void merge(int a,int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa==pb)
		return ;
	if (pa>pb)
		swap(pa,pb);
	occurences[pa] += occurences[pb];
	occurences[pb] = 0;
	par[pb] = pa;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int no_lines;
		scanf("%d", &no_lines);
		// get all lines
		int x1,y1,x2,y2;
		priority_queue<Line>horz,vert;
		for (int i=0;i<no_lines;i++)
		{
			scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
			if (x1==x2)
			{
				// vert
				if (y2<y1)
					swap(y1,y2);
				vert.push({x1,{y2,y1}});
			}
			else
			{
				// horz
				if (x2<x1)
					swap(x2,x1);
				horz.push({y1,{x2,x1}});
			}
		}
		stack<Line>final_horz,final_vert;
		while(!horz.empty())
		{
			Line l = horz.top();
			horz.pop();
			if (final_horz.empty())
			{
				final_horz.push(l);
			}
			else
			{
				int cur_y = l.first;
				int last_y = final_horz.top().first;
				if (cur_y!=last_y)
				{
					final_horz.push(l);
				}
				else
				{
					// check intersection
					int cur_min = l.second.second;
					int cur_max = l.second.first;
					int last_min = final_horz.top().second.second;
					int last_max = final_horz.top().second.first;
					if ((cur_min>=last_min && cur_min<=last_max) ||
						(cur_max>=last_min && cur_max<=last_max))
					{
						//merge
						int final_max = max(cur_max, last_max);
						int final_min = min(cur_min, last_min);
						final_horz.pop();
						final_horz.push({cur_y,{final_max, final_min}});
					}
					else
					{
						final_horz.push(l);
					}
				}
			}
		}

		while(!vert.empty())
		{
			Line l = vert.top();
			vert.pop();
			if (final_vert.empty())
			{
				final_vert.push(l);
			}
			else
			{
				int cur_x = l.first;
				int last_x = final_vert.top().first;
				if (cur_x!=last_x)
				{
					final_vert.push(l);
				}
				else
				{
					// check intersection
					int cur_min = l.second.second;
					int cur_max = l.second.first;
					int last_min = final_vert.top().second.second;
					int last_max = final_vert.top().second.first;
					
					if ((cur_min>=last_min && cur_min<=last_max) ||
						(cur_max>=last_min && cur_max<=last_max))
					{
						//merge
						int final_max = max(cur_max, last_max);
						int final_min = min(cur_min, last_min);
						final_vert.pop();
						final_vert.push({cur_x,{final_max, final_min}});
					}
					else
					{
						final_vert.push(l);
					}
				}
			}
		}
		
		generate_map(final_horz, final_vert);
		while(!final_horz.empty())
		{
			Line l = final_horz.top();
			final_horz.pop();
			int y = l.first;
			int x1=  l.second.first;
			int x2 = l.second.second;
			int pa = point_to_indx[{x1,y}];
			int pb = point_to_indx[{x2,y}];
			occurences[pa]++;
			occurences[pb]++;
			merge(pa,pb);
		}
		while(!final_vert.empty())
		{
			Line l = final_vert.top();
			final_vert.pop();
			int x = l.first;
			int y1 = l.second.first;
			int y2 = l.second.second;
			int pa = point_to_indx[{x,y1}];
			int pb = point_to_indx[{x,y2}];
			occurences[pa]++;
			occurences[pb]++;
			merge(pa,pb);	
		}
		int ans[5]={};
		for (int i=0;i<indx;i++)
		{
			find(i);
		}
		for (int i=0;i<indx;i++)
		{
			if (!occurences[i])
			{
				continue;
			}
			if (occurences[i] == 8)
				ans[0]++;
			else if (occurences[i] == 2)
				ans[1]++;
			else if (occurences[i] == 10)
				ans[2]++;
			else if (occurences[i] == 6)
			{
				ans[3]++;
				ans[1]--;
			}
			else if (occurences[i] == 4)
			{
				ans[4]++;
				ans[1]--;
			}
		}
		printf("%d %d %d %d %d\n", ans[0],ans[1],ans[2],ans[3],ans[4]);
	}
}