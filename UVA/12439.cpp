/* AC
   Inclusion-Exclusion
   Skip a year if February has already passed
*/

#include <bits/stdc++.h>
using namespace std;

int find_no_of_leap(int year){
	// leap years from 0 to year inclusive
	return year/4 - year/100 + year/400;
}

int find_no_of_leap_in_range(int start_year, int end_year){
	return start_year>end_year?0:find_no_of_leap(end_year) - find_no_of_leap(start_year-1);
}

int main(){
	int T;
	cin>>T;
	char month[12];
	int day, start_year, end_year;
	for(int t=1; t<=T;t++){
		scanf("%s %d, %d", month, &day, &start_year);
		string m(month);
		if (m!="January" && m!="February"){
			// this year isn't included (February 29 have already passed if it's a leap year)
			start_year++;
		}
		scanf("%s %d, %d", month, &day, &end_year);
		m = string(month);
		if (m=="January" || (m=="February" && day<29)){
			// this year isn't included
			end_year--;
		}
		printf("Case %d: %d\n", t, find_no_of_leap_in_range(start_year, end_year));
	}
	return 0;
}