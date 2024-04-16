class Solution {
public:
    int nthUglyNumber(int n) {
        
        int ptr2 = 0, ptr3 = 0, ptr5 = 0;
        
        vector<int> vec(n);
        
        vec[0] = 1;
        
        for(int i=1; i<n; i++){
            vec[i] = min({vec[ptr2]*2, vec[ptr3]*3, vec[ptr5]*5});
            
            if(vec[i]==vec[ptr2]*2){
                ptr2++;
            }
            
            if(vec[i]==vec[ptr3]*3){
                ptr3++;
            }
            
            if(vec[i]==vec[ptr5]*5){
                ptr5++;
            }
        }
        
        return vec[n-1];
    }
};