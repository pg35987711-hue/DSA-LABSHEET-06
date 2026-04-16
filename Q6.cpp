#include <iostream>
#include <stack>
using namespace std;

// CLASS
class BalanceCheck {
public:
    bool check(string exp) {
        stack<char> s;

        for (char c : exp) {
            if (c == '(' || c == '{' || c == '[')
                s.push(c);
            else {
                if (s.empty()) return false;

                if ((c == ')' && s.top() != '(') ||
                    (c == '}' && s.top() != '{') ||
                    (c == ']' && s.top() != '['))
                    return false;

                s.pop();
            }
        }
        return s.empty();
    }
};

// MAIN
int main() {
    BalanceCheck obj;
    cout << (obj.check("{[()]}") ? "Balanced" : "Not Balanced");
    return 0;
}