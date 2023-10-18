class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost=0;
        vector<int>vec1;
        vec1.push_back(neededTime[0]);
        for(int i=1;i<colors.length();i++){
            
            if(colors[i]!=colors[i-1]){
                if(vec1.size()>0){
                    sort(vec1.begin(),vec1.end());
                for(int i=0;i<vec1.size()-1;i++){
                    cost+=vec1[i];
                }
                //vec1.clear();
                }
                vec1.clear();
                
            }
            vec1.push_back(neededTime[i]);
        }

        if(vec1.size()>1){
                    sort(vec1.begin(),vec1.end());
                for(int i=0;i<vec1.size()-1;i++){
                    cost+=vec1[i];
                }
                vec1.clear();
                }

        return cost;
    }
};