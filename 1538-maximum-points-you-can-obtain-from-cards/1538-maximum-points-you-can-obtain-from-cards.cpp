class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalPoints = 0;

        for (int i = 0; i < n; i++) {
            totalPoints += cardPoints[i];
        }

        int minScore = 0;
        for (int i = 0; i < n - k; i++) {
            minScore += cardPoints[i];
        }

        int maxScore = totalPoints - minScore;
        for (int i = n - k; i < n; i++) {
            minScore = minScore - cardPoints[i - (n - k)] + cardPoints[i];
            maxScore = max(maxScore, totalPoints - minScore);
        }

        return maxScore;
    }
};
