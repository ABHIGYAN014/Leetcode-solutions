class Solution {
public:
    int smallestNumber(int n) {
        
        if(n==1) return 1;

        int val=0;
        for(int i=n+1; ;i++)
        {
            if ((i & (i-1)) == 0)
            {
                val=i;
                break;
            }
        }
        return val-1;
    }
};