class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();

        int froww = 0;  
        int nof1 = 0;   

        for (int i = 0; i < n; i++) {
            int count1 = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    count1++;
                }
            }

            if (count1 > nof1) {
                nof1 = count1;
                froww = i;  
            }
        }

        ans.push_back(froww);
        ans.push_back(nof1);

        return ans;
    }
};
