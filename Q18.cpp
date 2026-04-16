#include <iostream>
#include <stack>
using namespace std;

// CLASS
class StockSpan {
public:
    void calculate(int price[], int n) {
        stack<int> s;
        int span[n];

        s.push(0);
        span[0] = 1;

        for (int i = 1; i < n; i++) {
            while (!s.empty() && price[s.top()] <= price[i])
                s.pop();

            span[i] = (s.empty()) ? (i + 1) : (i - s.top());
            s.push(i);
        }

        for (int i = 0; i < n; i++)
            cout << span[i] << " ";
    }
};

// MAIN
int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = 7;

    StockSpan obj;
    obj.calculate(price, n);

    return 0;
}