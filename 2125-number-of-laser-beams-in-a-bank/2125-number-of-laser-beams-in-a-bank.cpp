class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> vec1;
        
        for(int i=0; i<bank.size(); i++){
            int count = 0;
            for(int j=0; j<bank[i].length(); j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            
            if(count!=0){
                vec1.push_back(count);
            }
            
        }
        
        if(vec1.size()==0 || vec1.size()==1){
            return 0;
        }
        
        int ans = 0;
        
        for(int i=0; i<(vec1.size()-1); i++){
            ans += (vec1[i]*vec1[i+1]);
        }
        
        return ans;
    }
};