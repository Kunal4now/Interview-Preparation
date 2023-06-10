int findIndex(int x, vector<int> &a, int l, int r, bool inc) {
		while (l <= r) {
		int mid = (l + r) >> 1;
		if (a[mid] == x) {
			return mid;
		}
		if (inc) {
			if (a[mid] > x) {
				r = mid - 1;
			}
			else if (a[mid] < x) {
				l = mid + 1;
			}
		}
		else {
			if (a[mid] > x) {
				l = mid + 1;
			}
			else if (a[mid] < x) {
				r = mid - 1;
			}	
		}
	}
	return -1;
}

int Solution::solve(vector<int> &a, int x) {
        int l = 0, r = a.size() - 1, mid;

		while (l <= r) {
			mid = (l + r) >> 1;
			if (a[mid] > a[mid + 1] and a[mid] > a[mid - 1]) {
				break;
			}
			else if (a[mid] > a[mid + 1] and a[mid] < a[mid - 1]) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		int left = findIndex(x, a, 0, mid, true);
        int right = findIndex(x, a, mid, a.size() - 1, false);
        
        return (left == -1 ? right : left);
}

/*
Time Complexity: O(LogN)
Space Complexity: O(1)
*/

/*
APPROACH:
=> Find the peak element in the array
=> the arrays in left and right of the peak would also be sorted so we can binary search two times to search the element
*/
