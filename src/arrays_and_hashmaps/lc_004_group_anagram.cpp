#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>


std::vector<std::vector<std::string>> groupAnagram(std::vector<std::string> strs_list){
    std::unordered_map<std::string, std::vector<std::string>> keys_map;

    for(int i=0; i<strs_list.size(); i++){
        std::string strCopy = strs_list[i];
        std::sort(strCopy.begin(), strCopy.end());

        keys_map[strCopy].push_back(strs_list[i]);
    }

    std::vector<std::vector<std::string>> sorted;
    for (std::pair<const std::string, std::vector<std::string>>& b1: keys_map){
        std::vector<std::string> sublist;

        // std::cout << "key: " << b1.first << std::endl;
        for (std::string str1: b1.second){
            // std::cout << str1 << std::endl;
            sublist.push_back(str1);
        }

        sorted.push_back(sublist);
    }

    return sorted;
}


int main(){
    std::vector<std::string> v1(7);
    v1[0] = "cat";
    v1[1] = "listen";
    v1[2] = "act";
    v1[3] = "silent";
    v1[4] = "bat";
    v1[5] = "tab";
    v1[6] = "inlets";

    std::vector<std::vector<std::string>> output;
    output = groupAnagram(v1);

    for(std::vector<std::string> v2: output){
        for(std::string str: v2){
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

// Time Complexity: O(NKlogK) where N is the number of strings in the input list and K is the maximum length of a string in the input list.
// Space Complexity: O(NK) where N is the number of strings in the input list

