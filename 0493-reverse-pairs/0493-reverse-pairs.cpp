class Solution {
public:
    void merge(vector<int>& nums, int lo, int mid, int hi){
        int n1 = mid-lo+1, n2 = hi-mid;
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i=0;i<n1;i++) left[i]=nums[lo+i];
        for(int j=0;j<n2;j++) right[j]=nums[mid+1+j];
        int i=0,j=0,k=lo;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]) nums[k++]=left[i++];
            else nums[k++]=right[j++];
        }
        while(i<n1) nums[k++]=left[i++];
        while(j<n2) nums[k++]=right[j++];
    }
    int countPairs(vector<int>& nums, int lo, int mid, int hi){
        int count=0;
        int right=mid+1;
        for(int i=lo;i<=mid;i++){
            while(right<=hi && (long long)nums[i] > 2LL * nums[right]) right++;
            count += (right-(mid+1));
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int lo, int hi){
        int count=0;
        if(lo>=hi) return count;
        int mid=lo+(hi-lo)/2;
        count+=mergeSort(nums,lo,mid);
        count+=mergeSort(nums,mid+1,hi);
        count+=countPairs(nums,lo,mid,hi);
        merge(nums,lo,mid,hi);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};