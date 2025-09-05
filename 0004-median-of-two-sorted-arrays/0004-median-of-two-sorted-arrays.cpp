class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();
        vector<int> temp(m + n);
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                temp[k++] = nums1[i++];
            }

            else {
                temp[k++] = nums2[j++];
            }
        }
        while (i < n) {
            temp[k++] = nums1[i++];
        }
        while (j < m) {
            temp[k++] = nums2[j++];
        }

        int sizee = temp.size();
        double ans;
        int low = 0;
        int high = sizee - 1;
        int mid1 = 0;
        int mid2 = 0;

        if (sizee % 2 != 0) {
            return temp[sizee / 2];
        }

        else {
            while (low < high) {
                mid1 = low;
                mid2 = high;

                low++;
                high--;
            }

            ans = (temp[mid1] + temp[mid2]) / 2.0;
            return ans;
        }
    }
};