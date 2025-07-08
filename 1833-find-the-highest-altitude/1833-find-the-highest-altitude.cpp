class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0, maxi = 0;
        for (int g : gain) {
            altitude += g;
            maxi = max(maxi, altitude);
        }
        return maxi;
    }
};
