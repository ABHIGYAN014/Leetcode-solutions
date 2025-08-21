class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n = grid.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                mp[grid[i][j]]++;
            }
        }

        int repeated = -1, missing = -1;
        for(int k=1; k<=n*n; k++) {
            if(mp[k] == 2) repeated = k;
            else if(mp[k] == 0) missing = k;
        }

        ans.push_back(repeated);
        ans.push_back(missing);

        return ans;
    }
};
