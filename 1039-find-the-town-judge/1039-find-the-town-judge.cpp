class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> trustCount(n + 1, 0);
        vector<int> trustingCount(n + 1, 0);
        
        for (const auto& t : trust) 
        {
            int a = t[0], b = t[1];
            trustingCount[a]++; 
            trustCount[b]++;
        }
        
        for (int i = 1; i <= n; ++i) 
        {
            if (trustCount[i] == n - 1 && trustingCount[i] == 0) 
            {
                return i;
            }
        }
        
        return -1;
    }
};
