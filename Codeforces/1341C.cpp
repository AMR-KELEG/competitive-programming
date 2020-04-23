//AC
#include<bits/stdc++.h>

using namespace std;

int permutation[100000];
int counts[100000];
int prev_empty[100000];
int next_empty[100000];
int location_of_val[100000];

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    priority_queue<int> max_count;
    while(T--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>permutation[i];
            location_of_val[permutation[i] - 1] = i;
            counts[i] = 1;
            prev_empty[i] = i-1;
            next_empty[i] = i+1;
            max_count.push(1);
        }
        bool possible = true;
        for(int val=0; val<n; val++){
            int max_r_count = max_count.top();
            max_count.pop();
            
            int val_loc = location_of_val[val];
            // we need to put val in val_loc
            if (max_r_count != counts[val_loc]){
                // Not possible
                possible = false;
                break;
            }
            //possible
            if(prev_empty[val_loc] != -1)
                next_empty[prev_empty[val_loc]] = next_empty[val_loc];
            
            if(next_empty[val_loc] != n)
            {
                prev_empty[next_empty[val_loc]] = prev_empty[val_loc];
                counts[next_empty[val_loc]] += counts[val_loc];
                // max is actually this val
                max_count.pop();
                max_count.push(counts[next_empty[val_loc]]);
            }
        }
        if (possible)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        
    }
    
}
