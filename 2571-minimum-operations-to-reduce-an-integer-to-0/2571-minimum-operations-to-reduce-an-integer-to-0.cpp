class Solution {
public:
    int minOperations(int n) {
        
        int set_bits=__builtin_popcount(n);

        if(set_bits==1){
            return 1;
        }

        int bigger_power_2 = pow(2, (int)log2(n)+1);
        int first_approach=minOperations(bigger_power_2-n)+1;

        int smaller_power_2 = pow(2, (int)log2(n));
        int second_approach=minOperations(n-smaller_power_2)+1;

        return min(first_approach,second_approach);


    }
};