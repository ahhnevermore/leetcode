//7-1-2026 1
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>stack;
        vector<int> res(temperatures.size(),0);
        for(int i =0; i<temperatures.size();i++){
            while(!stack.empty()&& temperatures[stack.back()]< temperatures[i]){
                res[stack.back()]=i-stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return res;
    }
};