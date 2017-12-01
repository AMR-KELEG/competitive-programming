// TLE
#include "bits/stdc++.h"
using namespace std;
#define Pokemon pair<pair<int,int>, int>
int N,K;
#define X first.first
#define Y first.second
#define PT second
std::vector<Pokemon> pokemons;

bool valid(int S)
{
	for (int st=0;st<N;st++)
	{
		priority_queue<Pokemon> valid_pokemons;
		priority_queue<pair<int,int> > valid_y;
		for (int po=st;po<N && pokemons[po].X<=pokemons[st].X+S; po++)
		{
			// insert po
			Pokemon cur_pokemon = pokemons[po];
			valid_y.push(pair<int,int>(-cur_pokemon.Y, cur_pokemon.PT));
			swap (cur_pokemon.X, cur_pokemon.Y);
			cur_pokemon.X *= -1;
			valid_pokemons.push(cur_pokemon);
		}
		std::vector<int> no_of_pokemons_of_type(K,0);
		int no_of_inside_types = 0;
		while(!valid_y.empty())
		{
			int cur_y = - valid_y.top().first;
			int cur_t = valid_y.top().second;
			valid_y.pop();
			while(!valid_pokemons.empty() && (S+cur_y>= -valid_pokemons.top().X))
			{
				// insert pokemon
				Pokemon cur_pokemon = valid_pokemons.top();
				valid_pokemons.pop();

				no_of_pokemons_of_type[cur_pokemon.PT]++;
				if (no_of_pokemons_of_type[cur_pokemon.PT] == 1)
				{
					no_of_inside_types++;
				}
			}

			if (no_of_inside_types == K)
				return 1;
			no_of_pokemons_of_type[cur_t]--;
			if (no_of_pokemons_of_type[cur_t] == 0)
			{
				no_of_inside_types--;
			}
		}
	}
	return 0;
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
		scanf("%d %d",&N, &K);
		int x,y,t;
		pokemons = std::vector<Pokemon> (N);
		for (int i=0;i<N;i++)
		{
			scanf("%d %d %d",&x,&y,&t);
			t--;
			pokemons[i].X = x;
			pokemons[i].Y = y;
			pokemons[i].PT = t;
		}
		sort(pokemons.begin(), pokemons.end());
		long long int l= 1;
		long long int r = 2000000000;
		while(l<r)
		{
			int mid = (l+r)>>1;
			if (valid(mid))
			{
				r = mid;
			}
			else
			{
				l = mid+1;
			}
		}
		printf("%d\n", int((l+r)>>1));
	}
}