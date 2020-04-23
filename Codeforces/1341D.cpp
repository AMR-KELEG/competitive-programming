//AC
#include<bits/stdc++.h>
#define INF 10000

using namespace std;

string valid_strings[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

vector<string> displays;

// Can convert from one string to another
int convert(string a, string b){
    // is it impossible??
    for(int i=0; i<a.size(); i++){
        if (a[i] == '1' && b[i] == '0'){
            return INF;
        }
    }
    // No of steps = ??
    int no_steps = 0;
    for(int i=0; i< a.size(); i++){
        no_steps += a[i] != b[i];
    }
    return no_steps;
}

// index, remaining steps
int dp[2000][2001];
int val[2000][2001];

bool can_solve(int pos, int remaining_steps, int & n){
    if (pos == n)
        return remaining_steps == 0;
    if (dp[pos][remaining_steps]!=-1)
        return dp[pos][remaining_steps];
    // try changing to one of the displays
    for(int i=9; i>=0; i--){
        int no_of_steps = convert(displays[pos], valid_strings[i]);
        if (remaining_steps < no_of_steps)
            continue;
        // try changing
        if (can_solve(pos+1, remaining_steps - no_of_steps, n)){
            val[pos][remaining_steps] = i;
            return dp[pos][remaining_steps] = true;
        }
    }
    return dp[pos][remaining_steps] = false;
}


void print_sol(int pos, int remaining_steps, int & n){
    if (pos == n)
        return;
    // try to solve
    for(int i=9; i>=0; i--){
        int no_of_steps = convert(displays[pos], valid_strings[i]);
        if (remaining_steps < no_of_steps)
            continue;
        // try changing
        if (can_solve(pos+1, remaining_steps - no_of_steps, n)){
            cout<<i;
            print_sol(pos+1, remaining_steps - no_of_steps, n);
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    memset(dp, -1, sizeof dp);
    displays = vector<string>(n);
    for(int i=0; i<n; i++){
        cin>>displays[i];
    }
    if (!can_solve(0, k, n))
        cout<<-1;
    else
        print_sol(0, k, n);
}
