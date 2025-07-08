class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>ans(gain.size()+1);
        ans[0]=0;
        for(int i=1;i<=gain.size();i++)
        {
            ans[i]=ans[i-1]+gain[i-1];
        }

        int maxi=INT_MIN;
        for(int i=0;i<ans.size();i++)
        {
            maxi=max(maxi,ans[i]);
        }
        return maxi;
    }
};