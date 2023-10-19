class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end(),greater<int>());
        sort(tasks.begin(),tasks.end());

        int max_time=INT_MIN;

        for(int i=0;i<processorTime.size();i++){
            max_time=max(max_time,(processorTime[i]+tasks[4*i+3]));
        }

        return max_time;

    }
};