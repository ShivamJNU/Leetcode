class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int xor_element=0;

        for(auto &e: pref){
            e=xor_element^e;
            xor_element=e^xor_element;
        }

        return pref;
    }
};