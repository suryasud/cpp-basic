// Find two sum of the target value in the array
#include <vector>
#include <unordered_map>
#include <iostream>

std::vector<int> twoSum(std::vector<int> v1, int target){
    std::unordered_map<int, int> hashTable;
    int complement;
    std::vector<int> ans;

    for (int i=0; i < v1.size(); i++){
        complement = target - v1.at(i);

        if (hashTable.find(complement) != hashTable.end()){
            ans.push_back(i);
            ans.push_back(hashTable[complement]);
            return ans;
        }

        hashTable[v1.at(i)] = i;
    }

    return ans;
}

int main(){
    //[6, 4, 5, 8, 4, 4, 4, 7, -3, 1]
    std::vector<int> v1 = {6, 4, 5, 8, 4, 4, 4, 7, -3};
    int target = 8;

    std::vector<int> ans = twoSum(v1, target);    
    std::cout << ans.at(0) << ", " << ans.at(1) << std::endl;

    return 0;
}