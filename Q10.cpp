#include <iostream>
#include <stack>
using namespace std;

// CLASS
class ReverseString {
public:
    void reverse(string str) {
        stack<char> s;

        for (char c : str)
            s.push(c);

        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
    }
};

// MAIN
int main() {
    ReverseString obj;
    obj.reverse("HELLO");
    return 0;
}