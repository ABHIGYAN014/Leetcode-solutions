class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,int start)
    {
        //base case
       if(start>=nums.size())
       {
          ans.push_back(nums);
          return;
       }
        //recursive
        for(int i=start;i<nums.size();i++)
        {
            swap(nums[i],nums[start]);
            solve(nums,ans,start+1);
                   swap(nums[i],nums[start]);
        }
 
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,ans,0);
        set<vector<int>>st;
        for(auto e: ans)
        {
            st.insert(e);
        }
        ans.clear();
        for(auto e: st)
        {
            ans.push_back(e);
        }
        return ans;
    }
};