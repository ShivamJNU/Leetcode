class Solution {
    bool possible(long long n,int N){
        long long res=n*(n+1);
        res/=2;

        if(res<=(long long)N){
            return true;
        }
        return false;
    }
public:
    int maximumGroups(vector<int>& grades) {
        int N=grades.size();
        long long low=1;
        long long high=N;

        while(high-low>1){
            long long mid=(high+low)/2;

            if(possible(mid,N)){
                low=mid;
            }else{
                high=mid;
            }
        }

        return low;

    }
};