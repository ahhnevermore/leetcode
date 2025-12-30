//30-12-2025 3
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        while(left < right){
            auto k = numbers[left] + numbers[right];
            if (k> target){
                right--;
            }
            else if (k<target){
                left++;
            }else{
                return vector<int>{left +1, right+1};
            }
        }
        return vector<int>{left,right};
    }
};