#include <iostream>
#include <unordered_map>
#include <vector>

int longestConsecutive(std::vector<int>& nums){
    std::unordered_map<int, int> flagMap;
    int ans = 0;

    // Adding all numbers to map to see which numbers exist.
    // For this, we do not need the count of how many times each number appears.
    // So, we just need to know if its present or not.
    for (int num: nums){
        flagMap[num] = true;
    }

    /* Now if a number exists, we can check if its previous number exists.
       If it does not exist, then this number is the start of a sequence.
       If it exists, then this number is not the start of a sequence.

       We only need to check for sequences for numbers which are the start of a sequence.
    */
    for (std::pair<const int, int> kv: flagMap){
        // We are now iterating over all the numbers in the map.
        int num = kv.first;
        int currentStreak = 0;

        if (flagMap.find(num - 1) == flagMap.end()){
            // This means that num is the start of a sequence. 
            // Because (num - 1) does not exist and it returns end().

            int currentNum = num;

            while (flagMap.find(currentNum) != flagMap.end()){
                currentStreak += 1;
                currentNum += 1;
            }
        }   
    
        // Now checking if the answer is already a larger number than 
        // what we have now. If yes, then replace.
        if (currentStreak > ans){
            ans = currentStreak;
        }
    } 

    return ans;
}


int main(){
    std::vector<int> nums = {0};

    int ans = longestConsecutive(nums);
    std::cout << ans << std::endl;

    return 0;
}