//28-12-2025 2
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<int, 9>rows{0} ;
        std::array<int, 9>cols{0} ;
        std::array<int, 9>boxes{0} ;
        for(int i =0;i < 9;i++){
            for(int j =0; j<9;j++){
                char c = board[i][j];
                if (c == '.'){
                    continue;
                }else{
                    int e = static_cast<int>(c-'1');
                    int bit = 1<< (e);

                    //check row
                    if(rows[i] & bit){
                        return false;
                    }
                    rows[i] |= bit;

                    //check col
                    if(cols[j] & bit){
                        return false;
                    }
                    cols[j]|=bit;

                    int boxNo =(j/3) *3  + i/3;
                    if(boxes[boxNo] & bit){
                        return false;
                    }
                    boxes[boxNo]|=bit;

                }
            }
        }

        return true;
    }
};