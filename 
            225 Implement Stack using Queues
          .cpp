class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        while (!q.empty()) {
            tmp.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q, tmp;
};
