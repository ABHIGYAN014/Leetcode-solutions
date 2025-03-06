class Solution {
public:
    bool canJump(vector<int>& nums) {

        int final=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i+nums[i]>=final)
            {
                final=i;
            }
        }
        return final==0;

    }
};