// AC
#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("mosalah.in", "r", stdin);
	int T;
	cin>>T;
	while(T--){
		int last_avg, cur_goals, games_played, games_rem;
		cin>>last_avg>>cur_goals>>games_played>>games_rem;
		if(games_rem ==0 && (last_avg * games_played > cur_goals))
		{
			printf("-1\n");
			continue;
		}
		int min = 0, max=1000000;
		while(min<max){
			int mid = (min+max)>>1;
			if (cur_goals + mid >= last_avg * (games_played + games_rem)){
				max = mid;
			}
			else{
				min = mid+1;
			}
		}
		printf("%d\n", (min+max)>>1);
	}
}