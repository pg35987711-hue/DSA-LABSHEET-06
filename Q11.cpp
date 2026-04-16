#include <iostream>
#include <stack>
using namespace std;

// CLASS
class PalindromeCheck {
public:
    bool isPalindrome(string str) {
        stack<char> s;

        for (char c : str)
            s.push(c);

        for (char c : str) {
            if (c != s.top())
                return false;
            s.pop();
        }
        return true;
    }
};

// MAIN
int main() {
    PalindromeCheck obj;
    cout << (obj.isPalindrome("madam") ? "Palindrome" : "Not Palindrome");
    return 0;
}