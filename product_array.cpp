//28-12-2025 1
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
      
        int acc =1;
        for (int i = 0;i <nums.size();i++){
           
            res[i]=acc;
             acc *= nums[i];
        }
        acc =1;
        for (int i = nums.size()-1;i >=0;i--){
            
            res[i]*=acc;
            acc *= nums[i];
        }

        return res;
    }
};