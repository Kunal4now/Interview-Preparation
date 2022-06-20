int Solution::solve(vector<int> &a) {
    int n = a.size();
	vector<int> sufOdd(n), sufEven(n);
	sufEven[n - 1] = ((n - 1) % 2 == 0 ? a[n - 1] : 0);
	sufOdd[n - 1] = ((n - 1) % 2 != 0 ? a[n - 1] : 0);

	for (int i = n - 2; i >= 0; i--) {
		if (i % 2 == 0) {
			sufEven[i] = sufEven[i + 1] + a[i];
			sufOdd[i] = sufOdd[i + 1];
		}
		else {
			sufOdd[i] = sufOdd[i + 1] + a[i];
			sufEven[i] = sufEven[i + 1];
		}
	}

	int curEven = 0, curOdd = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int tmpEvenSuf = (i + 1 < n ? sufEven[i + 1] : 0);
		int tmpOddSuf = (i + 1 < n ? sufOdd[i + 1] : 0);
		if (i % 2 == 0) {
			if (curEven + tmpOddSuf == curOdd + tmpEvenSuf) {
				cnt++;
			}
		}
		else {
			if (curOdd + tmpEvenSuf == curEven + tmpOddSuf) {
				cnt++;
			}
		}
		curEven += (i % 2 == 0 ? a[i] : 0);
		curOdd += (i % 2 != 0 ? a[i] : 0);
	}
    
    return cnt;
}

/*
APPROACH: 
=> Maintain suffix sum for odd and even indices
=> at every index the even and odd behind this index will remain unaffected
=> after removing the i'th element the even suffix sum and odd suffix sum will get swapped
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
