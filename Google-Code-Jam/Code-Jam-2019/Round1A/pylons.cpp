/* Passes visible test set
The idea is to use a brute force solution to check
whether there is a way to place numbers in the grid or not.
*/
#include<bits/stdc++.h>

using namespace std;
std::vector<std::vector<int> > path;
int off = 4;
bool ok(int R, int C, std::vector<std::vector<int> > & grid, int step=1){
	grid[R][C] = 1;
	path[R][C] = step;
	int no = 0;
	for (int r=0;r<grid.size();r++){
		for(int c=0;c<grid[0].size();c++)
			no+=grid[r][c];
	}
	if (no == (int(grid[0].size()) * int(grid.size()))){
		grid[R][C] = 0;
		return 1;
	}
	bool can = false;
	for (int r=max(0, R-off);r<grid.size() && r<R+off;r++){
		for(int c=max(0, C-off);c<grid[0].size() && c<C+off;c++){
			if (c==C || r==R)
				continue;
			if ((r-c == R-C) || (r+c == R+C))
				continue;
			if (grid[r][c])
				continue;
			if(ok(r, c, grid, step+1)){
				can=true;
				r = grid.size();
				break;
			}
			
		}
	}
	grid[R][C] = 0;
	return can;
}

bool can_solve(int r, int c){
	std::vector<std::vector<int> > grid(r, std::vector<int> (c, 0));
	path = std::vector<std::vector<int> >(r, std::vector<int> (c, 0));
	for (int R=0;R<grid.size();R++){
		for(int C=0;C<grid[0].size();C++){
			if (ok(R,C, grid))
				return true;
		}
	}
	return false;
}

int main(){
	for(int t=1;t<=T;t++){
		int r, c;
		cin>>r>>c;
		cout<<"Case #"<<t<<": ";
		if (!can_solve(r, c)){
			cout<<"IMPOSSIBLE\n";
		}
		else{
			cout<<"POSSIBLE\n";
			std::map<int, pair<int,int> > pts;
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					pts[path[i][j]]={i+1, j+1};
				}
			}
			for(auto p:pts){
				cout<<p.second.first<<" "<<p.second.second<<endl;
			}
		}
	}
}