#include <iostream>
#include <stack>
using namespace std;

// CLASS
class PrefixEval {
public:
    int evaluate(string exp) {
        stack<int> s;

        for (int i = exp.length() - 1; i >= 0; i--) {
            if (isdigit(exp[i]))
                s.push(exp[i] - '0');
            else {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();

                switch (exp[i]) {
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
    PrefixEval obj;
    cout << obj.evaluate("+9*26"); // 9+(2*6)
    return 0;
}