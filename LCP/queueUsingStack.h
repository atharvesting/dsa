#include <stack>

class MyQueue {

private:
    std::stack<int> q1, q2;

    void move2q2(void) {
        while (!q1.empty()) {
            q2.push(q1.top());
            q1.pop();
        }
    }

public:
    MyQueue() : q1(), q2() {}

    void push(int x) {
        q1.push(x);
    }

    bool empty() {
        return (q1.empty() && q2.empty());
    }

    int pop() {
        int c;
        if (q2.empty()) {
            move2q2();
        }
        c = q2.top();
        q2.pop();
        return c;
    }

    int peek() {
        if (this->empty()) return -1;
        if (q2.empty()) {
            move2q2();
        }
        return q2.top();
    }

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */