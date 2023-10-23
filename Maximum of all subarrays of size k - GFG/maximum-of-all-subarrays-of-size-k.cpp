//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        
        multiset<int> pq;
        vector<int>vec1;

        for(int i=0;i<k;i++){
            pq.insert(arr[i]);
        }

        auto it=pq.rbegin();

        vec1.push_back(*it);

        for(int i=k;i<n;i++){
            pq.erase(pq.lower_bound(arr[i-k]));
            pq.insert(arr[i]);

            auto it=pq.rbegin();
            vec1.push_back(*it);
        }

        return vec1;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends