// AC
// Lots of tricky statement conditions

#include <bits/stdc++.h>
#define EPS (1e-10)
using namespace std;

int main(){
	int H;

	// Use double for U
	long double U, D, F;
	cin>>H>>U>>D>>F;
	while(H!=0){
		long double lost_value = U * (0.01*F);
		long double height = 0;
		int day = 1;
		while(true){
			height += U;
			// Trick: Snail can reach the top before night (before going down again)
			if (height > H){
				// Success
				printf("success on day %d\n", day);
				break;
			}
			height -= D;
			// Trick: Avoid double comparison
			if (height<0 && abs(height)>EPS)
				break;
			U -= lost_value;

			// Trick: Snail can't climb negative values
			if (U<0)
				U = 0;
			day++;
		}
		if (height<H){
			// Failure
			printf("failure on day %d\n", day);
		}
		cin>>H>>U>>D>>F;
	}
}
