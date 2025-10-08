#include<iostream>
#include<string>
#include<vector>

bool isAnagram(std::string str1, std::string str2){
    if (str1.length() != str2.length()){
        return false;
    }

    std::vector<int> alphabet(26, 0);

    for(char c1: str1){
        alphabet[c1 - 'a']++;
    }

    for(char c1: str2){
        alphabet[c1 - 'a']--;
    }

    for(int i=0; i<26; i++){
        if (alphabet[i] != 0){
            return false;
        }
    }

    return true;
}
    
int main() {
    std::string strA = "cate";
    std::string strB = "bat";

    if (isAnagram(strA, strB)){
        std::cout << "Words are anagram" << std::endl;
    } else {
        std::cout << "Words are not anagram" << std::endl;
    }
    
    return 0;
}