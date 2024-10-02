class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};  // If array is empty, return empty result
        
        // Step 1: Create a sorted list of unique elements
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());  // Remove duplicates
        
        // Step 2: Create a map of element to rank
        unordered_map<int, int> rankMap;
        for (int i = 0; i < sortedArr.size(); ++i) {
            rankMap[sortedArr[i]] = i + 1;  // Rank starts from 1
        }
        
        // Step 3: Replace each element in the original array with its rank
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }
        
        return result;
    }
};
