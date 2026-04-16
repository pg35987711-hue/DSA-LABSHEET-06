#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

// CLASS
class MultiDigitEval {
public:
    int evaluate(string exp) {
        stack<int> s;
        stringstream ss(exp);
        string token;

        while (ss >> token) {
            if (isdigit(token[0]))
                s.push(stoi(token));
            else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                if (token == "+") s.push(a + b);
                else if (token == "-") s.push(a - b);
                else if (token == "*") s.push(a * b);
                else if (token == "/") s.push(a / b);
            }
        }
        return s.top();
    }
};

// MAIN
int main() {
    MultiDigitEval obj;
    cout << obj.evaluate("12 3 * 2 +");
    return 0;
}