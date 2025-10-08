#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            std::unordered_map<char, int> countMap;

            for (int j = 0; j < 9; j++){
                char c1 = board.at(i).at(j);

                if (c1 != '.'){ 
                    countMap[c1]++;
                    if (countMap[c1] > 1){
                        return false;
                    }
                }
            }
        }

        for (int j = 0; j < 9; j++){
            std::unordered_map<char, int> countMap;

            for (int i = 0; i < 9; i++){
                char c1 = board.at(i).at(j);

                if (c1 != '.'){ 
                    countMap[c1]++;
                    if (countMap[c1] > 1){
                        return false;
                    }
                }
            }
        }

        for (int l=0; l < 3; l++){
            for(int k=0; k < 3; k++){
                std::unordered_map<char, int> countMap;
                for(int j=0; j < 3; j++){
                    for(int i=0; i < 3; i++){
                        char c1 = board.at(i+(k*3)).at(j+(l*3));

                        if (c1 != '.'){
                            countMap[c1]++;
                            if (countMap[c1] > 1){
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};


int main(){
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution sol;
    bool ans = sol.isValidSudoku(board);

    if (ans){
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}