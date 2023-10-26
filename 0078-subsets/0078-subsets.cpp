class Solution {
public:
vector<vector<int>>vec1;
vector<int>temp;

void generate(vector<int>&nums, int index, int size){

if(index>=size){
    return;
}else{


temp.push_back(nums[index]);
vec1.push_back(temp);
generate(nums,index+1,size);

temp.pop_back();
generate(nums,index+1,size);


}

}

    vector<vector<int>> subsets(vector<int>& nums) {
        generate(nums,0,nums.size());

        vec1.push_back({});

        return vec1;
    }
};