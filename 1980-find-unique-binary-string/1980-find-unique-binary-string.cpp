class Solution {

    vector<string>vec1;

    unordered_map<string,bool>m1;

    void Generate(string &s,int i, int N){
        if(i==N){
            return;
        }

        m1[s]=true;

        //vec1.push_back(str);

        s[i]='1';
        m1[s]=true;
        Generate(s,i+1,N);
        s[i]='0';
        m1[s]=true;
        Generate(s,i+1,N);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string str="";

        for(int i=0;i<nums.size();i++){
            str.push_back('0');
        }

        Generate(str,0,nums.size());

        for(auto e:nums){
            m1[e]=false;
        }

        for(auto e:m1){
            if(e.second==true){
                return e.first;
            }
        }

        return str;
    }
};