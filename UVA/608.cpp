/* AC

Hints:
- If the balance shows even, then all the coins are good
- If the balance shows up or down, then all the (missing) coins are good.
"The bad coin is already on the balance, all the other coins are good"
- Brute force on all the feasible solutions (coins that aren't known to be good)
and validate the rules.
*/
#include <bits/stdc++.h>
using namespace std;
string left_s[3], right_s[3], result[3];
map<char, bool> coins;
#define EPS (1e-9)

bool in_str(char c, string s){
	for(int i=0; i< s.size(); i++)
	{
		if(c==s[i])
			return 1;
	}
	return 0;
}

string find_missing(string a, string b){
	string missing = "";
	for(char c='A'; c<='L'; c++){
		if(in_str(c, a) || in_str(c, b))
			continue;
		missing += string(c, 1);
	}
	return missing;
}

long double get_weight(string s, char c, bool up){
	long double weight = 0;
	for(auto i:s){
		if(c==i){
			if(up)
				// Give the bad coin higher weight
				weight += 1.5;
			else
				// Give the bad coin lower weight
				weight += 0.5;
		}
		else{
			// The default weight of the coin
			weight += 1;
		}
	}
	return weight;
}

bool validate(string l, string r, string res, char c, bool up){
	long double lw = get_weight(l, c, up);
	long double rw = get_weight(r, c, up);
	if (abs(lw-rw)<EPS){
		return res == "even";
	}
	if(lw>rw){
		return res == "up";
	}
	return res == "down";
}

int main(){
	int n;
	cin>>n;
	while(n--){
		coins.clear();
		for(int i=0;i<3;i++){
			cin>>left_s[i]>>right_s[i]>>result[i];
			string equal;
			if (result[i] == "even"){
				equal = left_s[i] + right_s[i];
			}
			else{
				equal = find_missing(left_s[i], right_s[i]);
			}
			for(auto c: equal)
			{
				coins[c] = 1;
			}
		}

		for(char c='A'; c<='L'; c++){
			if(coins[c])
				continue;
			for(int up=0;up<2;up++){
				int valid_rules = 0;
				for(int i=0; i<3; i++){
					if(validate(left_s[i], right_s[i], result[i], c, up))
						valid_rules++;
				}
				if(valid_rules == 3){
					// Done
					printf("%c is the counterfeit coin and it is ", c);
					if(up)
						printf("heavy.\n");
					else
						printf("light.\n");
					c = 'M';
					break;
				}
			}
		}
	}
}