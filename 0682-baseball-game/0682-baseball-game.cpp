class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;

        for (int i = 0; i < operations.size(); i++) {
            string op = operations[i];

            if (op == "C") {
                ans.pop_back();
            } else if (op == "D") {
                ans.push_back(2 * ans.back()); 
            } else if (op == "+") {
                int n = ans.size();
                ans.push_back(ans[n - 1] + ans[n - 2]);
            } else {
                ans.push_back(stoi(op));
            }
        }

        int total = 0;
        for (int score : ans)
            total += score;

        return total;
    }
};
