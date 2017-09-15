#include "iostream"
#include "queue"
#include "set"
#include "utility"
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	set<int>queue_numbers;
	pair<int,int>node;
	queue< pair<int,int> >next_node;
	node.first=n;
	node.second=0;
	next_node.push(node);
	queue_numbers.insert(n);
	while(!next_node.empty())
	{
		node=next_node.front();
		next_node.pop();
		if(node.first==m)
		{
			cout<<node.second;
			break;
		}
		if(node.first>1)
		{
			if(queue_numbers.find(node.first-1)==queue_numbers.end())
			{
				queue_numbers.insert(node.first-1);
				next_node.push(pair<int,int>(node.first-1,node.second+1));
			}
		}
		if(2*node.first<=10000)
		{
			if(queue_numbers.find(node.first*2)==queue_numbers.end())
			{
				queue_numbers.insert(node.first*2);
				next_node.push(pair<int,int>(node.first*2,node.second+1));
			}	
		}
	}
	return 0;
}