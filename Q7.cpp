#include <iostream>
#include <stack>
using namespace std;

// CLASS
class DecimalToBinary {
public:
    void convert(int num) {
        stack<int> s;

        while (num > 0) {
            s.push(num % 2);
            num /= 2;
        }

        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
    }
};

// MAIN
int main() {
    DecimalToBinary obj;
    obj.convert(10);
    return 0;
}