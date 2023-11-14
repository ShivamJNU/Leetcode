class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>prefix(n, vector<int>(m, 0));
        vector<vector<int>>suffix(n, vector<int>(m, 0));
        
        int prod=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                prefix[i][j]=prod;
                prod=(grid[i][j]*1LL*prod)%12345;
            }
        }
          
         prod=1;                         
        
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[0].size()-1;j>=0;j--){
                suffix[i][j]=prod;
                prod=(grid[i][j]*1LL*prod)%12345;
                
            }
        }
        
        vector<vector<int>>product(n, vector<int>(m, 0));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int p=(prefix[i][j]*1LL*suffix[i][j])%12345;
                product[i][j]=p;
            }
        }
        
        return product;
        
    }
};