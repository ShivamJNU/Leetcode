//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    
	    int zero_pointer=-1;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]==0){
	            zero_pointer=i;
	            break;
	        }
	    }
	    
	    if(zero_pointer!=-1){
	        for(int i=zero_pointer+1;i<n;i++){
	            if(arr[i]!=0){
	                swap(arr[i],arr[zero_pointer]);
	                zero_pointer++;
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends