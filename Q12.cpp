#include <iostream>
#include <stack>
using namespace std;

// CLASS
class RemoveDuplicates {
public:
    string remove(string str) {
        stack<char> s;

        for (char c : str) {
            if (!s.empty() && s.top() == c)
                s.pop();
            else
                s.push(c);
        }

        string result = "";
        while (!s.empty()) {
            result = s.top() + result;
            s.pop();
        }
        return result;
    }
};

// MAIN
int main() {
    RemoveDuplicates obj;
    cout << obj.remove("aabbccdde");
    return 0;
}