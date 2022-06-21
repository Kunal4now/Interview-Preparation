stack<int> s1, s2;

MinStack::MinStack() {
    while (!s2.empty()) {
        s2.pop();
    }
    while (!s1.empty()) {
        s1.pop();
    }
}

void MinStack::push(int x) {
    s1.push(x);
    if (s2.empty()) {
        s2.push(x);
    } else {
        s2.push(min(s2.top(), x));
    }
}

void MinStack::pop() {
    if (!s1.empty()) {
        s1.pop();
        s2.pop();
    }
}

int MinStack::top() {
    if (!s1.empty()) {
        return s1.top();
    } else {
        return -1;
    }
}

int MinStack::getMin() {
    if (!s2.empty()) {
        return s2.top();
    }
    return -1;
}
