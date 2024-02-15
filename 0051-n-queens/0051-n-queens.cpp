class Solution {
public:
    vector<vector<string>>Glob;
    
    vector<int>First;
    vector<int>Second;
    vector<int>Third;
    
    void func(int index, int n, vector<string>& board){
        if(index==n){
            Glob.push_back(board);
            return;
        }
        
//  Filling the current row:
//  Current row = index and column would be i
        
        for(int i=0; i<n; i++){
            if(First[n-1+index-i]==0 && Second[index+i]==0 && Third[i]==0){
                First[n-1+index-i]=1;
                Second[index+i]=1;
                Third[i]=1;
                
                board[index][i]='Q';
                func(index+1, n, board);
                
                board[index][i]='.';
                First[n-1+index-i]=0;
                Second[index+i]=0;
                Third[i]=0;
            }
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0; i<n; i++){
            s.push_back('.');
        }
        
        vector<string> board;
        for(int i=0; i<n; i++){
            board.push_back(s);
        }
        
        for(int i=0; i<(2*n-1); i++){
            First.push_back(0);
        }
        
        for(int i=0; i<(2*n-1); i++){
            Second.push_back(0);
        }
        
        for(int i=0; i<n; i++){
            Third.push_back(0);
        }
        
        // vector<int>First((2*n-1), 0);  // Top-Left
        // vector<int>Second((2*n-1), 0); // Down-Left
        // vector<int>Third((n), 0); // For Row
        
        func(0, n, board);
        
        
        return Glob;
    }
};