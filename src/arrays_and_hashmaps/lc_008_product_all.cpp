#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int productAll = 1;
        int zeroCount = 0;

        for (int num: nums){
            if (num!=0){
                productAll *= num;
            } else {
                zeroCount += 1;
            }
        }

        std::vector<int> ans(0);
        if (zeroCount == 0){
            for (int num: nums){
                int productRequired=1;

                productRequired = productAll/num;
                ans.push_back(productRequired);
            }
        } else if (zeroCount == 1){
            for (int num: nums){
                if (num == 0){
                    ans.push_back(productAll);
                } else {
                    ans.push_back(0);
                }

            }
        } else if (zeroCount > 1){
            for (int num: nums){
                ans.push_back(0);
            }
        }

        return ans;
    }
};

int main(){
    std::vector<int> nums = {1,2,3,4};

    Solution sol;
    std::vector<int> ans = sol.productExceptSelf(nums);

    for (int num: ans){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}