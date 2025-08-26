class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int numBouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
                if (count == k) { 
                    numBouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return numBouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalNeeded = 1LL * m * k;
        if (totalNeeded > bloomDay.size()) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canMakeBouquets(bloomDay, mid, m, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
