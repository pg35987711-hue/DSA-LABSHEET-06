#include <iostream>
#include <stack>
using namespace std;

// CLASS
class UndoRedo {
    stack<string> undoStack, redoStack;
    string current = "";

public:
    void perform(string action) {
        undoStack.push(current);
        current = action;

        while (!redoStack.empty())
            redoStack.pop();
    }

    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(current);
            current = undoStack.top();
            undoStack.pop();
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(current);
            current = redoStack.top();
            redoStack.pop();
        }
    }

    void show() {
        cout << "Current State: " << current << endl;
    }
};

// MAIN
int main() {
    UndoRedo obj;
    obj.perform("A");
    obj.perform("B");
    obj.undo();
    obj.show();
    return 0;
}