#include <list>
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }

    /** Push element x onto stack. */
    void push(int x) {
        lst.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = lst.back();
        lst.pop_back();
        return t;
    }

    /** Get the top element. */
    int top() {
        return lst.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return lst.empty();
    }
private:
    std::list<int> lst;
};
