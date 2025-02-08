int findKRotation(vector<int> &nums){
    int low = 0, high = nums.size() - 1;
    int mn = 1e9, idx = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[low] <= nums[mid]) {
            if (nums[low] < mn) {
                mn = nums[low];
                idx = low;
            }
            low = mid + 1;
        } else {
            if (nums[mid] < mn) {
                mn = nums[mid];
                idx = mid;
            }
            high = mid - 1;
        }
    } 

    return idx;
}

/*
APPROACH
Just find the index of the minimum element of the array

TIME COMPLEXITY: O(LogN)
*/
