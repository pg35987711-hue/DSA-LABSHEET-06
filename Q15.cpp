#include <iostream>
#include <stack>
using namespace std;

// CLASS
class CallStack {
public:
    void simulate() {
        stack<string> s;

        s.push("main()");
        s.push("function1()");
        s.push("function2()");

        while (!s.empty()) {
            cout << "Returning from " << s.top() << endl;
            s.pop();
        }
    }
};

// MAIN
int main() {
    CallStack obj;
    obj.simulate();
    return 0;
}