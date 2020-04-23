//AC
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n, a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        int min_possible = n * (a-b);
        int max_possible = n * (a+b);
        
        int min_suggested = c-d;
        int max_suggested = c+d;
        cout<<"Possible: "<< min_possible<<" "<<max_possible<<endl;
        cout<<"Suggested: "<< min_suggested<<" "<<max_suggested<<endl;
        if (min_possible > max_suggested || min_suggested > max_possible){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }
}
