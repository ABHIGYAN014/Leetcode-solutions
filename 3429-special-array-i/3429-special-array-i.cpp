class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=i+1;
        while(i<=n-1 && j<=n-1)
        {
            if(nums[i]%2==0 && nums[j]==0  ||  nums[i]%2!=0 && nums[j]%2!=0)
            {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};