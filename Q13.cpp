#include <iostream>
using namespace std;

// CLASS
class TwoStacks {
    int arr[100];
    int top1, top2;

public:
    TwoStacks() {
        top1 = -1;
        top2 = 100;
    }

    void push1(int x) {
        if (top1 < top2 - 1)
            arr[++top1] = x;
    }

    void push2(int x) {
        if (top1 < top2 - 1)
            arr[--top2] = x;
    }

    void pop1() {
        if (top1 >= 0) top1--;
    }

    void pop2() {
        if (top2 < 100) top2++;
    }

    void display() {
        cout << "Stack1: ";
        for (int i = 0; i <= top1; i++)
            cout << arr[i] << " ";

        cout << "\nStack2: ";
        for (int i = 99; i >= top2; i--)
            cout << arr[i] << " ";
    }
};

// MAIN
int main() {
    TwoStacks obj;
    obj.push1(10);
    obj.push2(20);
    obj.push1(30);
    obj.push2(40);

    obj.display();
    return 0;
}