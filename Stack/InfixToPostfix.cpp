#include <iostream>
#include <string>
#include <cctype> // for isdigit()
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(char val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        Node* temp = top;
        char value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return top->data;
    }

    int precedence(char opr) {
        if (opr == '^') return 3;
        if (opr == '*' || opr == '/' || opr == '%') return 2;
        if (opr == '+' || opr == '-') return 1;
        return 0;
    }

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
    }

    void InfixtoPostfix(string infix) {
        Stack s;
        string postfix = "";

        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];

            if (c == ' ')
                continue;

            if (isdigit(c) || c == '.') {
                string num = "";
                while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
                    num += infix[i];
                    i++;
                }
                i--; 
                postfix += num + " ";
            }

            else if (c == '(') {
                s.push(c);
            }

       
            else if (c == ')') {
                while (!s.isEmpty() && s.peek() != '(') {
                    postfix += s.pop();
                    postfix += ' ';
                }
                if (!s.isEmpty() && s.peek() == '(')
                    s.pop(); // remove '('
                else {
                    cout << "Error: Unbalanced brackets!" << endl;
                    return;
                }
            }

            // operator
            else if (isOperator(c)) {
                while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                    postfix += s.pop();
                    postfix += ' ';
                }
                s.push(c);
            }

            // invalid character
            else {
                cout << "Invalid character: " << c << endl;
                return;
            }
        }

       
        while (!s.isEmpty()) {
            if (s.peek() == '(') {
                cout << "Error: Unbalanced brackets!" << endl;
                return;
            }
            postfix += s.pop();
            postfix += ' ';
        }

        cout << "\nPostfix: " << postfix << endl;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    Stack s;
    s.InfixtoPostfix(infix);

    return 0;
}