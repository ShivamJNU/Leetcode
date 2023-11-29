class Solution {
public:
    
    bool func(vector<int>&weights, int capacity, int max_day){
        int sum=0;
        int day=1;
        
        for(int i=0;i<weights.size();i++){
            if(weights[i]>capacity){
                return false;
            }
            if(sum+weights[i]<=capacity){
                sum+=weights[i];
            }else{
                sum=weights[i];
                day++;
            }
        }
        
        if(day<=max_day){
            return true;
        }
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxa=weights[0];
        //int right=0;
        
        for(auto e: weights){
            if(e>maxa){
                maxa=e;
            }
            //right+=e;
        }
        
        int left=0;
        int right=maxa*weights.size();
        
        while(right-left>1){
            int mid=(right+left)/2;
            if(func(weights, mid, days)){
                right=mid;
            }else{
                left=mid;
            }
        }
        
        return right;
    }
};