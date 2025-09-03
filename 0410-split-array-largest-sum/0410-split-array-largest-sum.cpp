class Solution {
public:

    int solve(vector<int>& nums, int maxsum)
    {
        int sizee=1;
        int currsum=0;

        for(int i=0;i<nums.size();i++)
        {
            if(currsum+nums[i]<=maxsum)
            {
                currsum+=nums[i];
            }
            else
            {
                sizee++;
                currsum=nums[i];
            }
        }
        return sizee;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(solve(nums,mid)<=k)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};