class Solution {
public:

int DP[105];

int func(string &s, int index){
if(index>=s.length()){
    return 1;
}

if(s[index]=='0'){
    return 0;
}

if(DP[index]!=-1){
    return DP[index];
}

int count = 0;

count += func(s, index+1);

if(index<s.length()-1 && s.substr(index, 2)<="26"){
    count += func(s, index+2);
}

return DP[index] = count;

}

    int numDecodings(string s) {
       memset(DP, -1, sizeof(DP));

       return func(s, 0);

    }
};