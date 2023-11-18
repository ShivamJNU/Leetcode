class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_set<int>s1;

        int bull=0,cow=0;

        unordered_map<int,int>m1,m2;

        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bull++;
                s1.insert(i);
            }
        }

        for(int i=0;i<secret.length();i++){
            if(s1.find(i)==s1.end()){
                m1[secret[i]]++;
            }
        }
        
        for(int i=0;i<secret.length();i++){
            if(s1.find(i)==s1.end()){
                m2[guess[i]]++;
            }
        }

        for(auto e: m2){
            // Map for Guess

            cow+=min(e.second,m1[e.first]);
        }

        string bull1=to_string(bull);
        string cow1=to_string(cow);

        string returning = bull1+"A"+cow1+"B";

        return returning;
    }
};