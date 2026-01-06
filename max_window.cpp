//6-1-2026
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int> res;

        for(int right =0; right <nums.size();right++){
            if (!dq.empty()&& right - dq.front()+1 >k){
                dq.pop_front();
            }
            while(!dq.empty() &&nums[right] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(right);
            if(right >k-2){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};