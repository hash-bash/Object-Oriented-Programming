# include <iostream>

using namespace std;

class calc {
public:
    void init() {
        char op;
        float num1, num2;
        cout << "========================CALCULATOR========================";
        cout << "\nPlease enter first number then operator followed by second number: ";
        cin >> num1;
        cin >> op;
        cin >> num2;
        switch (op) {
            case '+':
                cout << num1 + num2;
                break;
            case '-':
                cout << num1 - num2;
                break;
            case '*':
                cout << num1 * num2;
                break;
            case '/':
                cout << num1 / num2;
                break;
            default:
                cout << "\nWrong operation.";
                break;
        }
    }

    void cont() {
        char ch;
        cout << "\nDo you want to continue? (y/n): ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y') {
            calc c1;
            c1.init();
        }
    }
};

int main() {
    calc c1;
    c1.init();
    c1.cont();
    return 0;
}
