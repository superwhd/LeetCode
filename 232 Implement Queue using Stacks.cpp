class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        st1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        fill();
        st2.pop();
    }

    // Get the front element.
    int peek(void) {
        fill();
        return st2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st1.empty() && st2.empty();
    }
private:
    void fill() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
    }
    stack<int> st1, st2;
};
