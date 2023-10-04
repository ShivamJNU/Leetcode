//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
                vector<int> vec1;

                for (auto r : str)
                {
                    if (r == 'I')
                        vec1.push_back(1);
                    if (r == 'V')
                        vec1.push_back(5);
                    if (r == 'X')
                        vec1.push_back(10);
                    if (r == 'L')
                        vec1.push_back(50);
                    if (r == 'C')
                        vec1.push_back(100);
                    if (r == 'D')
                        vec1.push_back(500);
                    if (r == 'M')
                        vec1.push_back(1000);
                }

                int return_integer = 0;

                for (int i = 0; i < str.length(); i++)
                {
                    if (i != str.length() - 1 && vec1[i] <vec1[i + 1])
                    {
                        return_integer -= vec1[i];
                    }
                    else
                    {
                        return_integer += vec1[i];
                    }
                }

                return return_integer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends