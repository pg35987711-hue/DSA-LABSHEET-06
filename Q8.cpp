#include <iostream>
#include <stack>
using namespace std;

// CLASS
class ReverseNumber {
public:
    void reverse(int num) {
        stack<int> s;

        while (num > 0) {
            s.push(num % 10);
            num /= 10;
        }

        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
    }
};

// MAIN
int main() {
    ReverseNumber obj;
    obj.reverse(1234);
    return 0;
}