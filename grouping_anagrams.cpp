#include <unordered_map>
class Solution {
public:

    struct Key{
        std::array<int,26> freq{};
        bool operator==(const Key& other) const {
            return freq == other.freq;
        }
    };
    struct KeyHash {
        size_t operator()(const Key& k) const {
            size_t h = 0;
            for (int x : k.freq) {
                h = h * 31 + x;
            }
            return h;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<Key,vector<string>,KeyHash> map;
        
        for (auto str:strs) {
            Key key;
            for(auto ch: str){
                key.freq[ch-'a']++;
            } 
            map[key].push_back(str);
            
        }
        vector<vector<string>> result ;
        for (const auto& pair:map){
            result.push_back(pair.second);
        }
        return result;
    }
};





