#include <vector>
#include <unordered_map>

using namespace std;

// Time Complexity: O(N ^ 2)
// Space Complexity: O(1)
vector<int> findPair(const vector<int>& nums, int target){
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++){
            if ( (nums.at(i) + nums.at(j)) == target ){
                // Found 2 numbers that add up to the target
                // Return their indices
                return {i,j};
            }
        }
    }
    // Return an empty vector signal no answer was found
    return {};
}

// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> findPairHashMap(const vector<int>& nums, int target){
    int complement = 0;

    // Hash Map that stores Key(number) -> Value(index)
    unordered_map<int, int> seenNums;
    for (int i = 0; i < nums.size(); i++){
        // Get the current complement
        complement = target - nums.at(i);
        
        //If the complement has been seen (Note: Look up time-complexity is O(1))
        if (seenNums.find(complement) != seenNums.end()){
            // return the current index i and the index associated with the complement
            return {i, seenNums[complement]};
        }
        // Otherwise insert the key-value pair {current number : index} in the Hash Map
        // Note: insert time-complexity is O(1)
        seenNums.insert(nums.at(i), i);
    }

    // Return an empty vector signal no answer was found
    return {};
}


// Time Complexity: O(N)
// Space Complexity: O(1)
vector<int> findPairOptimal(const vector<int>& nums, int target){
    // Note: Remember the input vector is sorted

    int tempSum = 0;
    // start points at the index of the smallest number in the vector
    int start = 0;
    // end points at the index of the largest number in the vector
    int end = nums.size() - 1;

    while (start < end){
        // Add the numbers located at indices start and end
        tempSum = nums.at(start) + nums.at(end);

        // If the sum is less than the target
        if (target > tempSum){
            // We have to use bigger numbers
            // We know the number at index end is the largest number in the array
            // Let's move start one cell to the right to get a bigger sum on the next iteration
            start++;
        }
        else if (target < tempSum){
            // We have to use smaller numbers
            // We know the number at index start is the smallest number in the array
            // Let's move end one cell to the left to get a smaller sum on the next iteration
            end--;
        }
        // Otherwise the target was found
        else {
            return {start, end};
        }
    }
    // Return an empty vector signal no answer was found
    return {};
}