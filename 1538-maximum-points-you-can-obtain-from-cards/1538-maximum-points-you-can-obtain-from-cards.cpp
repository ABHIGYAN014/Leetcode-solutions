class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int rightsum=0;
        int leftsum=0;
        int final_sum=0;

        for(int i=0;i<k;i++)
        {
            leftsum+=cardPoints[i];
        }
        final_sum=leftsum;
        

        int rindex=cardPoints.size()-1;

        for(int i=k-1;i>=0;i--)
        {
            leftsum-=cardPoints[i];
            rightsum+=cardPoints[rindex];
            rindex--;

            final_sum=max(final_sum,leftsum+rightsum);
        }

        return final_sum;
    }

};