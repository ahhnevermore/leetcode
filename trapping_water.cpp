//3-1-2026 2
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right =height.size()-1;
        int total =0;
        int wl = height[left];
        int wr = height[right];
        while(left<right){
            if(wl< wr){
                left++;
                if(height[left]<wl){
                total += wl -height[left];
                }else{
                    wl = height[left];
                }
                
            }else{
                right--;
                 if(height[right]<wr){
                total += wr -height[right];
                }else{
                    wr = height[right];
                }
                
            }
        }
        return total;
        
    }
};