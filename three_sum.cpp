//2-1-2026 1
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        std::unordered_map<int,int> map;
        for(int i =0;i <nums.size();i++){
           map[nums[i]]= i;
        }
        vector<vector<int>> res;
        for (int i =0;i <nums.size()-2;i++){
            if(nums[i]> 0){
                break;
            }
            if( i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size()-1;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int k = -nums[i]-nums[j];
                if (map.contains(k)){
                    auto idx = map[k];
                    if((idx>i && idx>j)){
                     res.push_back(vector<int>{nums[i],nums[j],k});
                    }
                }
            }
        }
        return res;
    }
};