class Solution {
    vector<int> matcher(string s, string a)
    {
        int n = s.size();
        int m = a.size();
        int i = 0;
        vector<int> res;

        while(i <= n - m)
        {
            if(s[i] == a[0])
            {
                int j = i;
                int k = 0;

                while(k<m && s[j] == a[k])
                {
                    j++;
                    k++;
                }

                if(k == m) res.push_back(i);
            }
            i++;
        }

        return res;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> aIndices = matcher(s, a);
        vector<int> bIndices = matcher(s, b);

        vector<int> res;

        for(int i = 0; i<aIndices.size(); i++)
        {
            int lower = lower_bound(bIndices.begin(), bIndices.end(), aIndices[i]-k) - bIndices.begin();

            if(lower != bIndices.size() && abs(bIndices[lower] - aIndices[i]) <= k)
                res.push_back(aIndices[i]); 
        }


        return res;
    }
};