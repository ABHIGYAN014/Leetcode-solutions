#include <vector>
#include <algorithm> // for std::max
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int max_sum=nums[0];
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
      sum=sum+nums[i];
      if(sum>max_sum)
      {
        max_sum=sum;
      }

      if(sum<0)
      {
        sum=0;
      }
    }
    return max_sum;
    }
};
