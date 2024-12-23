class Solution {
public:
    int lastRemaining(int n) {
        int remaining = n;
        int step = 1;
        int head = 1;
        bool leftToRight = true;

        while (remaining > 1) {
            if (leftToRight || remaining % 2 == 1) {
                head += step;
            }
            remaining /= 2;
            step *= 2;
            leftToRight = !leftToRight;
        }

        return head;
    }
};