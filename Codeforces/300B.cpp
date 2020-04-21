// AC
/*
Difficulty:
	Easy idea / moderate implementation
Idea:
- Use BFS to determine the size of components
- If there is a component of more than 3 member then there is no solution
- If the number of components of two members > number of components of 1 member,
    then there is no solution
 - Otherwise, form the teams
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int n,m;
	cin>>n>>m;
	vector<vector<int> > adjlist(n);
	int a,b;
	for(int i=0; i<m;i++){
		cin>>a>>b;
		a--;
		b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	vector<bool> visited(n, 0);
	vector< vector<int> > components[4];
	for (int start_node=0; start_node<n; start_node++){
		if(visited[start_node])
			continue;

		vector<int> cur_component;
		// Do BFS
		queue<int> q;
		q.push(start_node);
		visited[start_node] = true;

		while(!q.empty()){
			int node = q.front();
			q.pop();
			cur_component.push_back(node);

			for(auto neighbour: adjlist[node]){
				if (visited[neighbour]){
					continue;
				}
				q.push(neighbour);
				visited[neighbour] = true;
			}
		}
		if(cur_component.size() > 3)
		{
			cout<<-1;
			return 0;
		}
		components[cur_component.size()].push_back(cur_component);
	}

	// Form the teams
	if (components[1].size() < components[2].size())
	{
		cout<<-1;
	}
	else{
		for (auto team: components[3]){
			cout<<team[0]+1<<" "<<team[1]+1<<" "<<team[2]+1<<endl;
		}
		for(int two_member_team_index=0; two_member_team_index< components[2].size();two_member_team_index++){
			cout<<components[2][two_member_team_index][0]+1<<" ";
			cout<<components[2][two_member_team_index][1]+1<<" ";
			cout<<components[1][two_member_team_index][0]+1<<endl;
		}
		for(int one_team_member=components[2].size(); one_team_member<components[1].size(); one_team_member +=3){
			cout<<components[1][one_team_member][0]+1<<" ";
			cout<<components[1][one_team_member+1][0]+1<<" ";
			cout<<components[1][one_team_member+2][0]+1<<endl;
		}
	}
	return 0;
}
