class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>miniutes;
        for(int i=0;i<timePoints.size();i++)
        {
            string curr=timePoints[i];
            int hrs=stoi(curr.substr(0,2));
            int min=stoi(curr.substr(3,2));
            int totalmin=(hrs*60)+min;
            miniutes.push_back(totalmin);
        }
        sort(miniutes.begin(),miniutes.end());

        int mini=INT_MAX;
        int n=miniutes.size();
       for(int i=0;i<n-1;i++)
       {
        int diff=miniutes[i+1]-miniutes[i];
        mini=min(mini,diff);
       }

       int lastdiff=miniutes[0]+1440-miniutes[n-1];
       mini=min(mini,lastdiff);

       return mini;
    }
};