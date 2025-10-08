#include<iostream>
#include<unordered_map>
#include<vector>

std::vector<int> topKFrequent(std::vector<int>& nums, int k){
    std::vector<int> ans(0,0);
    std::unordered_map<int, int> counter;

    // As a first step, count the frequency of each number in nums
    for(int i=0; i<nums.size(); i++){
        counter[nums[i]]++; 
    }

    /* Definitely sorting the entire map would be one way to solve this problem, 
    but it would be inefficient.  A better way would be to use a bucket sort approach, 
    where we create an array of vectors, where the index represents the frequency of the numbers.

    In this method, we take an 'n' sized vector. These are our 'n' buckets.
    Now, each of these buckets represents a frequency count.
    i.e. how many times a number could have repeated.
    This works because if nums is of size 'n', 
    the maximum number of times any num in nums might have repeated is 'n' itself.

    Now arrange all numbers into the bucket, where the bucket's index decides how
    many times a num has repeated in the nums array/vector.
    */
    std::vector<std::vector<int>> buckets(nums.size(), std::vector<int>(0,0));
    for(std::pair<const int, int> kv: counter){
        // std::cout << "Key: " << kv.first << ", Value: " << kv.second << std::endl;
        buckets[kv.second - 1].push_back(kv.first);
    }


    /* Now that buckets are ready with the lists of numbers that repeat 
    a certain number of times.
    
    We can go through them in reverse order to pass the top k most frequent elements.
    */
    for (int i=buckets.size()-1; i>=0; i--){
        for (int j=0; j<buckets[i].size(); j++){
            if (ans.size() < k){
                ans.push_back(buckets[i][j]);
            } else {
                return ans;
            }
        }
    }

    return ans;
}


int main(){
    // std::vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3};
    // int k = 2;

    // std::vector<int> nums = {1, 2, 3, 4};
    // int k = 2;

    std::vector<int> nums = {7, 7, 7, 7, 7};
    int k = 1;


    
    std::vector<int> result = topKFrequent(nums, k);

    std::cout << "Top " << k << " frequent elements are: ";
    for(int i=0; i<result.size(); i++){
        std::cout << result[i] << " ";
    }

    return 0;
}