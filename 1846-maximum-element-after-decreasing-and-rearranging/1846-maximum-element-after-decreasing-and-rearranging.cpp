class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        arr[0]=1;

        int max_element=arr[0];

        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]){
                continue;
            }else if(arr[i]-arr[i-1]==1){
                max_element=arr[i];
            }else if(arr[i]-arr[i-1]>1){
                arr[i]=arr[i-1]+1;
                max_element=arr[i];
            }
        }

        return max_element;
    }
};