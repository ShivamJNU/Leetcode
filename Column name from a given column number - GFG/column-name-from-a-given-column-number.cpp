//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        vector<char>vec1;
        
        while(n>0){
            if(n%26==0){
                vec1.push_back('Z');
                n=n/26-1;
            }else{
                vec1.push_back('A'+((n%26)-1));
                n=n/26;
            }
        }
        
        string return_string="";
        
        for(int i=vec1.size()-1;i>=0;i--){
            return_string+=vec1[i];
        }
        
        return return_string;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends