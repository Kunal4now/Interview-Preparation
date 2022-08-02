class Solution {
public:
    vector<vector<int>> ans;
    void findSum(int i, int target, vector<int> &a, vector<int> &tmp, vector<vector<int>> &ans) {
        if (i >= a.size()) {
            if (target == 0) {
                ans.push_back(tmp);
            }
            return;
        }
        
        if (a[i] <= target) {
            tmp.push_back(a[i]);
            findSum(i, target - a[i], a, tmp, ans);
            tmp.pop_back();
        }
        
        findSum(i + 1, target, a, tmp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> ans;
        findSum(0, target, candidates, tmp, ans);
        return ans;
    }
};
