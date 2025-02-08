class Solution {
public:
    int search(vector<int>& a, int x) {
        // No matter how many times an array has been rotated, one of its half will always be sorted
        int low = 0, high = a.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (a[mid] == x) {
                return mid;
            }
            else if (a[low] <= a[mid]) { // left half is sorted
                if (x >= a[low] && x <= a[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // right half is sorted
                if (x >= a[mid] && x <= a[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

/*
APPROACH:
No matter how many times you rotate a sorted array, one of the half will always remain sorted
You just have to find out which one is sorted, and once you identify, you can just search if the target exists in that half and eliminte the half if not found

To find the sorted left half, compare the a[low] with a[mid] it should hold the sorted property

TIME COMPLEXITY: O(LogN)
*/
