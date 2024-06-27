class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> m;
        
        for(auto &e: edges){
            m[e[0]]++;
            m[e[1]]++;
        }
        
        int nod = -1, maxa = -1;
        
        for(auto &e: m){
            if(e.second>maxa){
                maxa = e.second;
                nod = e.first;
            }
        }
        
        return nod;
    }
};