#include "bits/stdc++.h"
using namespace std;
int main()
{
	int m,a;
	cin>>a>>m;
	double d=log(m/a);
	double la=log2(a),lm=log2(m);
	double lt=la+lm;
	if(abs(d-int(d)) <=0.0000001 || abs(lt-int(lt)) <=0.0000001)cout<<"YES";
	else cout<<"NO";
	return 0;
}