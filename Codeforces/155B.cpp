#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector< pair<int,int> >my_cards;
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		my_cards.push_back(pair<int,int>(b,a));
	}
	sort(my_cards.begin(),my_cards.end());
	int score=0,rem=1;
	while(rem>0 && my_cards.size())
	{
		rem--;
		score+=my_cards[my_cards.size()-1].second;
		rem+=my_cards[my_cards.size()-1].first;
		my_cards.erase(my_cards.end()-1);
	}
	cout<<score;

	return 0;
}