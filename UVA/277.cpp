//AC
#include "bits/stdc++.h"
using namespace std;
string s(9,'0');
bool line_is_drawn[6][6]={};
void set_val(int i,int j,bool val=0)
{
	line_is_drawn[i][j]=line_is_drawn[j][i]=val;
}
void solve(int in)
{
	if(in==9)
	{
		//Found a line
		printf("%s\n", s.c_str());
		solve(in-1);
	}
	else if(in==0)
	{
		s[in]++;
		if(s[in]=='2')
			return ;
		solve(in+1);
	}
	else
	{
		if(s[in]!='0')
			set_val(s[in]-'0',s[in-1]-'0',0);
		s[in]++;
		while((s[in]<'6' && line_is_drawn[s[in]-'0'][s[in-1]-'0']) || s[in]==s[in-1])
			s[in]++;
		if(s[in]=='6')
		{
			s[in]='0';
			solve(in-1);
		}
		else
		{
			set_val(s[in]-'0',s[in-1]-'0',1);
			solve(in+1);
		}
	}
}
int main()
{
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			line_is_drawn[i][j]=1;
	set_val(1,2);
	set_val(1,3);
	set_val(1,5);
	set_val(2,3);
	set_val(2,5);
	set_val(3,5);
	set_val(3,4);
	set_val(4,5);
	solve(0);
	return 0;
}