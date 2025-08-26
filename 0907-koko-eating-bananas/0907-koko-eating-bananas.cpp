class Solution {
public:
    long long timereq(vector<int>& piles, int h) {
        long long time = 0;

        for (int i = 0; i < piles.size(); i++) {
            time += (piles[i] + h - 1) / h;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        long long l = 1;
        long long r = *max_element(piles.begin(), piles.end());
        long long ans = r;

        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (timereq(piles, mid) <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};