#include <iostream>
#include <queue>
using namespace std;

// CLASS
class StackUsingQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (!q1.empty())
            q1.pop();
    }

    int top() {
        return q1.front();
    }
};

// MAIN
int main() {
    StackUsingQueues obj;
    obj.push(10);
    obj.push(20);
    cout << obj.top();
    return 0;
}