class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        int distp1=abs(z-x);
        int distp2=abs(z-y);

        if(distp1<distp2)
        {
            return 1;
        }
        else if(distp1>distp2)
        {
            return 2;
        }

        return 0;
    }
};