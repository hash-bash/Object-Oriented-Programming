#include<iostream>
#include<math.h>

using namespace std;

class Quad {
private :
    int a, b, c, x;
public:
    Quad() { a = b = c = 0; }

    Quad(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    friend ostream &operator<<(ostream &out, Quad &q) {
        out << "\nQuadratic equation: ";
        out << q.a << "X^2 + " << q.b << "X + " << q.c;
        return out;
    }

    friend istream &operator>>(istream &in, Quad &q) {
        cout << "\nEnter values of a, b and c: \n";
        in >> q.a >> q.b >> q.c;
        return in;
    }

    Quad operator+(Quad);

    void eval();

    void findRoots();
};

void Quad::eval() {
    cout << "\nEnter value of x: ";
    cin >> x;
    int result = (a * x * x) + (b * x) + c;
    cout << "\nFor X = " << x << " answer is: " << result << endl;
}

void Quad::findRoots() {
    int temp = (b * b) - (4 * a * c);
    if (temp > 0) {
        float r1 = (-b + sqrt(temp)) / (2.0 * a);
        float r2 = (-b - sqrt(temp)) / (2.0 * a);
        cout << "\nRoots are real and different.";
        cout << "\nRoot1 = " << r1;
        cout << "\nRoot2 = " << r2;
    } else if (temp == 0) {
        cout << "\nRoots are real and equal.";
        float r = (-b + sqrt(temp)) / (2.0 * a);
        cout << "\nEqual roots are: " << r;
    } else {
        cout << "\nRoots are complex and different.";
        float rno = -b / (2 * a);
        float ino = sqrt(-temp) / (2 * a);
        cout << "\nRoot1 = " << rno << "+" << ino << "i" << endl;
        cout << "\nRoot2 = " << rno << "-" << ino << "i" << endl;
    }
}

Quad Quad::operator+(Quad q) {
    Quad temp;
    temp.a = this->a + q.a;
    temp.b = this->b + q.b;
    temp.c = this->c + q.c;
    return temp;
}

int main() {
    Quad q1, q2, q3;
    cin >> q1;
    cin >> q2;
    q3 = q1 + q2;
    cout << "\nQuadratic equation 1, its roots and result: ";
    cout << q1;
    q1.findRoots();
    q1.eval();
    cout << "\nQuadratic equation 2, its roots and result: ";
    cout << q2;
    q2.findRoots();
    q2.eval();
    cout << "\nQuadratic equation 3, its roots and result: ";
    q3.findRoots();
    q3.eval();
    return 0;
}
