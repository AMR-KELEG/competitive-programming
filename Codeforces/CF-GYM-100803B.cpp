/* AC
*/
#include "bits/stdc++.h"
using namespace std;
const long long int INF = 1000000000;
int result;
bool left_to_right(queue<long long int>NO, queue<char> op)
{
	stack<long long int> val;
	val.push(NO.front());
	NO.pop();
	while(!op.empty())
	{	
		char cur_op = op.front();
		op.pop();
		long long int right_no = min(INF,NO.front());
		NO.pop();
		long long int left_no = val.top();
		val.pop();
		if (cur_op=='+')
		{
			val.push(min(INF, right_no+ left_no));
		}
		else
		{
			val.push(min(INF, right_no* left_no));	
		}
	}
	return val.top() == result;
}

bool prec(queue<long long int >NO, queue<char> op)
{
	stack<long long int> val;
	val.push(NO.front());
	NO.pop();
	while(!op.empty())
	{
		char cur_op = op.front();
		op.pop();
		long long int right_no = min(INF,NO.front());
		NO.pop();
		if (cur_op=='+')
		{
			val.push(right_no);
		}
		else
		{
			long long int left_no = val.top();
			val.pop();
			val.push(min(INF, right_no* left_no));	
		}
	}
	long long int total_sum = val.top();
	val.pop();
	while(!val.empty())
	{
		total_sum = min(INF, total_sum + val.top());
		val.pop();
	}
	return total_sum == result;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	cin>>s;
	cin>>result;
	// Loop
	queue<char> op;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='+' || s[i] == '*')
		{
			op.push(s[i]);
			s[i] = ' ';
		}
	}
	istringstream iss(s);
	int x;
	queue<long long int> NO;
	while(iss>>x)
	{
		// PUSH
		NO.push(x);
	}
	bool l_ok = left_to_right(NO,op);
	bool pre_ok = prec(NO,op);
	if (l_ok && pre_ok)
		printf("U\n");
	else if (l_ok)
		printf("L\n");
	else if (pre_ok)
		printf("M\n");
	else
		printf("I\n");
}