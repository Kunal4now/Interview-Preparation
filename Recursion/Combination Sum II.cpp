class Solution {
public:
    vector<vector<int>> ans;
    void helper(int i, int sum, vector<int> &a, vector<int> &tmp) {
        if (sum == 0) {
            ans.push_back(tmp);
        }
        for (int idx = i; idx < a.size(); idx++) {
            if (idx > i and a[idx] == a[idx - 1]) {
                continue;
            }
            if (a[idx] > sum) {
                break;
            }
            tmp.push_back(a[idx]);
            helper(idx + 1, sum - a[idx], a, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        helper(0, target, candidates, tmp);
        return ans;
    }
};
