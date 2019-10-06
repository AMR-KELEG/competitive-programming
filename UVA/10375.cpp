// AC
#include <bits/stdc++.h>
using namespace std;

void add_to_queue(priority_queue<int> & q, int val){
	while(val>1){
		q.push(val--);
	}
}

int main(){
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
    #endif
	int p, q, r, s;
	while(cin>>p>>q>>r>>s){
		priority_queue<int> num;
		priority_queue<int> den;
		add_to_queue(num, p);
		add_to_queue(num, r-s);
		add_to_queue(num, s);
		add_to_queue(den, q);
		add_to_queue(den, p-q);
		add_to_queue(den, r);
		long double ans = 1;
		while (!num.empty() || !den.empty()){
			if (!num.empty())
			{
				ans *= num.top();
				num.pop();
			}

			if (!den.empty())
			{
				ans /= den.top();
				den.pop();
			}
		}
		printf("%0.5Lf\n", ans);
	}
}

