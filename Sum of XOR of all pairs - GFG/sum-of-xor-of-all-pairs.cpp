//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	vector<long long>vec1(31,0);
    	
    	for(int i=0;i<n;i++){
    	    for(int j=0;j<31;j++){
    	        if((arr[i]>>j)&1){
    	            vec1[j]++;
    	        }
    	    }
    	}
    	
    	long long sum=0;
    	
    	for(int i=0;i<vec1.size();i++){
    	    sum+=(n-vec1[i])*1LL*(vec1[i])*pow(2,i);
    	}
    	
    	return sum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends