#include <iostream>
#include <stack>
using namespace std;

// CLASS
class InfixToPostfix {
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

public:
    string convert(string exp) {
        stack<char> s;
        string result = "";

        for (char c : exp) {
            if (isalnum(c))
                result += c;
            else if (c == '(')
                s.push(c);
            else if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    result += s.top();
                    s.pop();
                }
                s.pop();
            }
            else {
                while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                    result += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }

        while (!s.empty()) {
            result += s.top();
            s.pop();
        }

        return result;
    }
};

// MAIN
int main() {
    InfixToPostfix obj;
    cout << obj.convert("A+B*C");
    return 0;
}