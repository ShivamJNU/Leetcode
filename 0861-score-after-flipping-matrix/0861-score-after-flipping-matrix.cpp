class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]!=1){
                for(int j=0;j<grid[0].size();j++){
                    grid[i][j]=(grid[i][j])^1;
                }
            }
        }

        vector<int>vec1;

        for(int j=1;j<grid[0].size();j++){
            int zeroes_count=0, one_count=0;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]==0){
                    zeroes_count++;
                }else{
                    one_count++;
                }
            }
            vec1.push_back(max(zeroes_count,one_count));
        }

        reverse(vec1.begin(),vec1.end());

        int sum=0;

        for(int i=0;i<vec1.size();i++){
            sum+=vec1[i]*pow(2,i);
        }

        sum+=grid.size()*pow(2,(grid[0].size()-1));

        return sum;
    }
};