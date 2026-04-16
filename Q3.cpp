#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// CLASS
class InfixToPrefix {
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

public:
    string convert(string exp) {
        reverse(exp.begin(), exp.end());

        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '(') exp[i] = ')';
            else if (exp[i] == ')') exp[i] = '(';
        }

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
                while (!s.empty() && precedence(s.top()) > precedence(c)) {
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

        reverse(result.begin(), result.end());
        return result;
    }
};

// MAIN
int main() {
    InfixToPrefix obj;
    cout << obj.convert("A+B*C");
    return 0;
}