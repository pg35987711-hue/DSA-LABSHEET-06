#include <iostream>
#include <stack>
using namespace std;

// CLASS
class StackTop {
public:
    void showTop(stack<int> s) {
        if (!s.empty()) {
            cout << "Top element: " << s.top();
        } else {
            cout << "Stack is empty";
        }
    }
};

// MAIN
int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    StackTop obj;
    obj.showTop(s);

    return 0;
}