int Solution::solve(string A) {
    stack<char> s;
    
    for (auto &x: A) {
        if (x == '(') {
            s.push('(');
        } else {
            if (x == ')' and s.empty()) {
                return 0;
            }
            else if (x == ')') {
                s.pop();
            }
            else {
                s.push('(');
            }
        }
    }
    
    return s.size() == 0;
}
