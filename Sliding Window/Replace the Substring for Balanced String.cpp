class Solution {
public:
    int balancedString(string s) {
		vector<int> freq(26, 0);
		for (int i = 0; i < s.size(); i++) {
			freq[s[i] - 'A']++;
		}		

		int left = 0;
		int target = s.size() / 4;
		int ans = s.size();

		for (int right = 0; right < s.size(); right++) {
			freq[s[right] - 'A']--;
			while (left < s.size() && freq['Q' - 'A'] <= target && freq['W' - 'A'] <= target && freq['E' - 'A'] <= target && freq['R' - 'A'] <= target) {
				freq[s[left] - 'A']++;
				ans = min(ans, right - left + 1);
				left++;
			}
		}

        return ans;
    }
};

/*
APPROACH:

1. We need to just replace a bad string that has more than required characters.
2. We can maintain two pointers the the right one keeps on discarding the frequencies of the encountering elements
3. The right one adds the frequency back once the frequencies in become <= target (target = n / 4)

Time Complexity: O(N)
Space Complexity: O(1)
*/
