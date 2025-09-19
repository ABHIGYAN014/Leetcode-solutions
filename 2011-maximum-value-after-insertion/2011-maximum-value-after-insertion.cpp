class Solution {
public:
    string maxValue(string n, int x) {
        bool isNegative = (n[0] == '-');
        string res;

        if (!isNegative) {
            int i = 0;
            while (i < n.size() && (n[i] - '0') >= x) {
                res.push_back(n[i]);
                i++;
            }
            res.push_back('0' + x);
            res += n.substr(i);
        } else {
            res.push_back('-');
            int i = 1;
            while (i < n.size() && (n[i] - '0') <= x) {
                res.push_back(n[i]);
                i++;
            }
            res.push_back('0' + x);
            res += n.substr(i);
        }

        return res;
    }
};
