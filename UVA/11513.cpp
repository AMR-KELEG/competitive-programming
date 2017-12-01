//AC
#include "bits/stdc++.h"
using namespace std;
const int des_value = 987654321;
std::vector<std::vector<int> > cur_grid(3,std::vector<int> (3));
int states =0;
int find_value(const std::vector<std::vector<int> > & grid)
{
	int ans = 0;
	int mul = 1;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			ans+= mul * grid[i][j];
			mul *=10;
		}
	}
	return ans;
}

void find_grid(int value)
{
	int mul = 1;
	for (int r=0;r<3;r++)
	{
		for(int c=0;c<3;c++)
		{
			cur_grid[r][c] = int(value/mul) % 10; 
			mul *=10;
		}
	}

}

queue<int> q;
unordered_map<int,char> par_c;
unordered_map<int,int> par_int;
unordered_map<int,int> prev_state;
unordered_map<int,int> ANS;

void add_states(int state,int cost)
{
	find_grid(state);
	for (int r=0;r<3;r++)
	{
		swap(cur_grid[r][1],cur_grid[r][2]);
		swap(cur_grid[r][0],cur_grid[r][2]);
		int cur_val = find_value(cur_grid);

		if (prev_state.find(cur_val) == prev_state.end())
		{
			par_c[cur_val] = 'H';
			par_int[cur_val] = r;
			// par[cur_val] = {'H',r};
			q.push(cur_val);
			ANS[cur_val] = cost + 1;
			prev_state[cur_val] = state;
		}
		swap(cur_grid[r][0],cur_grid[r][2]);
		swap(cur_grid[r][1],cur_grid[r][2]);
	}
	for (int c=0;c<3;c++)
	{
		swap(cur_grid[0][c],cur_grid[2][c]);
		swap(cur_grid[1][c],cur_grid[2][c]);
		int cur_val = find_value(cur_grid);
		if (prev_state.find(cur_val) == prev_state.end())
		{
			par_c[cur_val] = 'V';
			par_int[cur_val] = c;
			q.push(cur_val);
			ANS[cur_val] = cost + 1;
			prev_state[cur_val] = state;
		}
		swap(cur_grid[1][c],cur_grid[2][c]);
		swap(cur_grid[0][c],cur_grid[2][c]);
	}
}


void bfs(int state)
{
	q.push({state});
	ANS[state] = 0;
	prev_state[state] = 0;
	while (!q.empty())
	{
		int cur_state = q.front();
		q.pop();
		add_states(cur_state,ANS[state]);
	}
}



int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	bfs(des_value);
	std::vector<std::vector<int> > grid(3,std::vector<int> (3));
	cin>>grid[0][0];
	while(grid[0][0])
	{
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				if (i==j && i==0)
					continue;
				cin>>grid[i][j];
			}
		}
		int initial_value = find_value(grid);
		if (ANS.find(initial_value) == ANS.end())
		{
			printf("Not solvable\n");
		}
		else
		{
			queue<char> moves;
			queue<int> nos;
			int cur_state = initial_value;
			while (prev_state[cur_state] !=0)
			{
				moves.push(par_c[cur_state]);
				nos.push(par_int[cur_state]+1);
				cur_state = prev_state[cur_state];
			}
			printf("%d ",(int)nos.size());
			while(!nos.empty())
			{
				printf("%c%d", moves.front(),nos.front());
				nos.pop();
				moves.pop();
			}
			printf("\n");
		}
		cin>>grid[0][0];
	}	
}