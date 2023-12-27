class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<long long, int> m1;
        
        for(int i=0; i<nums1.size()-1; i++){
            for(int j=i+1; j<nums1.size(); j++){
                long long prod = nums1[i]*1LL*nums1[j];
                m1[prod]++;
            }
        }
        
        int count = 0;
        
        for(auto e: nums2){
            long long prod = e*1LL*e;
            if(m1.find(prod)!= m1.end()){
                count+=m1[prod];
            }
        }
        
        unordered_map <long long, int> m2;
        
        for(int i=0; i<nums2.size()-1; i++){
            for(int j=i+1; j<nums2.size(); j++){
                long long prod = nums2[i]*1LL*nums2[j];
                m2[prod]++;
            }
        }
        
        for(auto e: nums1){
            long long prod = e*1LL*e;
            if(m2.find(prod)!=m2.end()){
                count+=m2[prod];
            }
        }
        
        return count;
    }
};