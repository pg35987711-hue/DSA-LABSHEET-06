#include <iostream>
#include <stack>
using namespace std;

// CLASS
class PostfixEval {
public:
    int evaluate(string exp) {
        stack<int> s;

        for (char c : exp) {
            if (isdigit(c))
                s.push(c - '0');
            else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                switch (c) {
                    case '+': s.push(a + b); break;
                    case '-': s.push(a - b); break;
                    case '*': s.push(a * b); break;
                    case '/': s.push(a / b); break;
                }
            }
        }
        return s.top();
    }
};

// MAIN
int main() {
    PostfixEval obj;
    cout << obj.evaluate("23*5+"); // (2*3)+5
    return 0;
}