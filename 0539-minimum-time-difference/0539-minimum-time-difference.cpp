class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vec1;
        
        for(auto e: timePoints){
           int time = (10*(e[0]-'0')+(e[1]-'0'))*60 + 10*(e[3]-'0')+(e[4]-'0');
            vec1.push_back(time);
        }
        
        sort(vec1.begin(), vec1.end());
        
        int diff = 1440-vec1[vec1.size()-1]+vec1[0];
        
        for(int i=0; i<vec1.size()-1; i++){
            diff=min(diff, vec1[i+1]-vec1[i]);
        }
        
        return diff;
        
    }
};