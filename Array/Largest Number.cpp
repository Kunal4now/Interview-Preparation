string Solution::largestNumber(const vector<int> &A) {
    vector<int> a = A;
    sort(a.begin(), a.end(), [&](int &x, int &y) {
        string a = to_string(x) + to_string(y);
        string b = to_string(y) + to_string(x);
        return a > b;
    });
    
    string ans = "";
    for (auto c: a) {
        ans += to_string(c);
    }
    
    string ans2 = "";
    int i = 0;
    while (i < ans.size() and ans[i] == '0') {
        i++;
    }
    
    for (int idx = i; i < ans.size(); i++) {
        ans2 += ans[i];
    }
    
    if (ans2.size() == 0) {
        ans2 += '0';
    }
    
    return ans2;
}


/*
APPROACH:
=> Sort the array by the result we get appending a[i] with a[j] or with a[j] and a[i]
*/

/*
Time Complexity: O(NLogN)
Space Complexity: O(N)
*/
