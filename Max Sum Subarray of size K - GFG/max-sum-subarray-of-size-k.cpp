//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long max_sum=INT_MIN;
        long sum=0;
        int i=0,j=0;
        
        while(j<N && i<(N-K+1)){
            while(j-i+1<=K){
                sum+=Arr[j];
                j++;
            }
            max_sum=max(max_sum,sum);
            sum=sum-Arr[i];
            i++;
        }
        
        return max_sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends