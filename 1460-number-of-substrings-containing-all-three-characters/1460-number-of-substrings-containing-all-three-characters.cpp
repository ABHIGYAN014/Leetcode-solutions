class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            lastSeen[s[i] - 'a'] = i; 
            
            int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]});
            if (minIndex != -1) {
                count += minIndex + 1;
            }
        }
        
        return count;
    }
};
