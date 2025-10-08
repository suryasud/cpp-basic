#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> numsMap;

        for (int num: nums){
            numsMap[num]++;
            if (numsMap[num] > 1){
                return true;
            }
        }

        return false;
    }
};

int main(){
    std::vector<int> nums = {1,2,3,1};

    Solution sol;
    bool ans = sol.hasDuplicate(nums);

    std::cout << std::boolalpha << ans << ": Contains a duplicate" << std::endl;

    return 0;
}