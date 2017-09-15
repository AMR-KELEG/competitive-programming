#include "bits/stdc++.h"
using namespace std;
string pattern,all;
std::vector<int> lps;
bool found=0;
void computeLPSArray()
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < pattern.size())
    {
       if (pattern[i] == pattern[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example 
           // AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
void KMPSearch()
{
    int M = pattern.size();
    int N = all.size();
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray();
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pattern[j] == all[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
      	found=1;
        printf("%d\n", i-j);
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if (i < N && pattern[j] != all[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int temp;
	while(cin>>temp)
	{
		found=0;
		cin>>pattern>>all;
		lps.resize(temp+1);
		/*
		for(int i=0;i<pattern.size();i++)
		{
			cout<<lps[i]<<" ";
		}
		cout<<endl;
		*/
		KMPSearch();
		if(!found)
			printf("\n");
	}

}