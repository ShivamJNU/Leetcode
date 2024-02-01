class Solution {
public:

long long pow1(long long p){
        long long x = 1;
        
        while(p--){
            x=x*1LL*10;
        }
        
        return x;
    }
    
    bool check_func (long long p){
        long long x = 1;
        while(p--){
            x=x*1LL*10;
            if(x>INT_MAX){
                return true;
            }
        }
        
        return false;
    } 

    int myAtoi(string s) {
        int idx = 0;
        while(s[idx]==' '){
            idx++;
        }

        if(idx==s.length()){
            return 0;
        }

        bool con = false;

        if(s[idx]=='-'){
            con = true;
            idx++;
        }else if(s[idx]=='+'){
            idx++;
        }

        long long num = 0;
        vector<int> vec1;
        
        bool con2 = true;

        for(int i=idx; i<s.length(); i++){
            
            if(con2 && s[i]=='0'){
                continue;
            }else{
                con2=false;
            }

            if(s[i]>='0' && s[i]<='9'){
                vec1.push_back(s[i]-'0');
            }else{
                break;
            }

        }

        for(int i=vec1.size()-1; i>=0; i--){
            
            bool check1 = check_func((long long)(vec1.size()-1-i));
            
            if(check1){
                if(con){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
            
            long long power1 = pow1((long long)(vec1.size()-1-i));
            
            
            
                num+=(vec1[i])*1LL*power1;

                if(con){
                    if((-1LL*num)<INT_MIN){
                        return INT_MIN;
                    }
                }else{
                    if(num>INT_MAX){
                    return INT_MAX;
                }
                }
            
        }

        if(con){
            return -1LL*num;
        }
        
        return num;
    }
};