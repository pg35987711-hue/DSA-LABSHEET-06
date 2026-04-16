#include <iostream>
#include <stack>
using namespace std;

// CLASS
class Browser {
    stack<string> backStack, forwardStack;
    string current;

public:
    void visit(string url) {
        if (!current.empty())
            backStack.push(current);
        current = url;

        while (!forwardStack.empty())
            forwardStack.pop();
    }

    void back() {
        if (!backStack.empty()) {
            forwardStack.push(current);
            current = backStack.top();
            backStack.pop();
        }
    }

    void forward() {
        if (!forwardStack.empty()) {
            backStack.push(current);
            current = forwardStack.top();
            forwardStack.pop();
        }
    }

    void display() {
        cout << "Current Page: " << current << endl;
    }
};

// MAIN
int main() {
    Browser obj;
    obj.visit("google.com");
    obj.visit("youtube.com");
    obj.back();
    obj.display();
    return 0;
}