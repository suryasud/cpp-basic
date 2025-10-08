#include <iostream>
#include <vector>
#include <string>

std::string encode(std::vector<std::string>& strs){
    std::string combinedString = "";
    for(int i=0; i<strs.size(); i++){
        int len1 = strs.at(i).length();
        combinedString += std::to_string(len1) + "#" + strs.at(i);
    }

    return combinedString;
}

std::vector<std::string> decode(std::string s){
    // The result vector of words which contains the answer which we want
    std::vector<std::string> words(0);
    
    // The size of the string
    // This is including the delimiters 
    // which we have placed earlier while encoding.
    int sLength = s.length();


    int i = 0;
    std::string s1 = s.substr(i, sLength);


    while(s1.length() > 0){
        // Extracting the length of the word.
        // The length is present before the first '#'.
        i = 0;
        int wordLength = 0;
        std::string wordLen = "";

        // To find the length of the word,
        // we will keep moving 'i' until we find first '#'.
        // All characters before '#' will be the length of the word.
        while (s1.at(i) != '#'){
            wordLen.push_back(s1.at(i));
            i+= 1;
        }

        // 'i' is currently at the position of '#'.
        // So, the word starts from (i+1) and has length 'wordLength'.
        // First lets move i to i+1.
        i = i + 1;
        s1 = s1.substr(i, s1.length());

        // Now 'i' is at the start of the word.
        // We can now extract the word of length 'wordLength'.
        wordLength = std::stoi(wordLen);

        // Now that we know the word length,
        // let us now make the substring of the word.
        // The word starts from index 'i' in the substring s1
        // and has length 'wordLength'.
        std::string word = s1.substr(0, wordLength);

        // Now that we have extracted the word,
        // we can now update s1 to remove the part which we have already processed.
        s1 = s1.substr(wordLength, s1.length());

        // Now adding the word to the result vector.
        words.push_back(word);
    }

    return words;
}

int main(){
    std::vector<std::string> strs = {"The quick brown fox","jumps over the","lazy dog","1234567890","abcdefghijklmnopqrstuvwxyz", "Hello", "There", "Awesome"};

    std::string combinedStr = encode(strs);
    std::cout << combinedStr << std::endl;

    std::vector<std::string> words = decode(combinedStr);

    for(std::string s: words){
        std::cout << s << std::endl;
    }    

    return 0;
}
