//26-12-2025 2
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
       std::unordered_map<int,int> map;
        for (auto num:nums){
            map[num]++;
        }
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<>>pq;
        for (const auto& [num,freq]:map){
            pq.push(std::pair(freq,num));
            if (pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()){
            auto top =pq.top();
            pq.pop();
            res.push_back(top.second);
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
};