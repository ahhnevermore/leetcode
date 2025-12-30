//30-12-2025 1
//second attempt (after seeing set approach from solns)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int>seen;

        for (auto num:nums){
            seen.insert(num);
        }
        int longest =0;

        for(auto elem:seen){
            if (seen.contains(elem-1)){
                continue;
            }else{
                int current = 0;
                int currentNum =elem;
                while (seen.contains(currentNum++)){
                    current++;
                }
                current = current >0? current :current +1;
                longest = std::max(longest, current);
            }

        }
            
        return longest;
    }

   


};


// first attempt
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int,std::pair<int,int>> seqs;
        std::unordered_set<int>seen;

        for (auto num:nums){
            if (seen.contains(num)){
                continue;
            }
            seen.insert(num);
            int bos=num;
            int eos=num;
            if(seqs.contains(num-1)){
                bos= seqs[num-1].first;
            }
            if(seqs.contains(num+1)){
                eos = seqs[num+1].second;

            }
            
            seqs[bos]= std::pair(bos,eos);
            seqs[eos]=std::pair(bos,eos);
        }
        int longest =0;
        for(auto& [key,pair]:seqs){
            longest = std::max(longest,pair.second-pair.first +1);
        }
        return longest;
    }


};
