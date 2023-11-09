class Solution {
public:
    int countHomogenous(string s) {
        int mod=1e9+7;

        int len=1;
        vector<int>vec1;

        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                len++;
            }else{
                vec1.push_back(len);
                len=1;
            }
        }

        vec1.push_back(len);

        int count=0;

        for(auto e: vec1){
            long long ans=1;

            ans=(e*1LL*(e+1));
            ans/=2;
            ans%=mod;

            count+=ans;
            count%=mod;

        }

        return count;

        
    }
};