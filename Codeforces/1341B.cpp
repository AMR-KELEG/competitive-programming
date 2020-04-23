//AC
#include<bits/stdc++.h>

using namespace std;

int lengths[200000];
int no_peaks[200000];

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++)
            cin>>lengths[i];

        no_peaks[0] = 0;
        for(int i=1; i<n-1; i++){
            no_peaks[i] = no_peaks[i-1];
             if (lengths[i] > max(lengths[i-1], lengths[i+1]))
             {
                 no_peaks[i] = no_peaks[i-1] + 1;
             }
        }
        no_peaks[n-1] = no_peaks[n-2];
        
        // Find the range ; no_of_peaks is max
        int max_no_of_peaks = 0;
        int max_l=0;
        for(int l=0; l+k-1<n ; l++){
            // What is the number of peaks here?
            int cur_no_of_peaks = no_peaks[l+k-2] - no_peaks[l];
            if(cur_no_of_peaks > max_no_of_peaks)
            {
                max_no_of_peaks = cur_no_of_peaks;
                max_l = l;
            }
        }
        cout<<max_no_of_peaks+1<<" "<<max_l+1<<endl;
    }
}
