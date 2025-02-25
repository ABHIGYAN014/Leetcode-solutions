class Solution {
public:
    void merge(vector<int>& nums, vector<int>& temp, int start, int end, int mid) {
        int i = start, j = mid + 1, k = start;

        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= end) {
            temp[k++] = nums[j++];
        }

        for (int x = start; x <= end; x++) {
            nums[x] = temp[x]; 
        }
    }

    void mergesort(vector<int>& nums, vector<int>& temp, int start, int end) {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;
        mergesort(nums, temp, start, mid);
        mergesort(nums, temp, mid + 1, end);
        merge(nums, temp, start, end, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergesort(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};
