#include<iostream>

using namespace std;

class Overload {
    float rno, ino;
public:
    Overload() {
        rno = 0;
        ino = 0;
    }

    Overload(float a, float b) {
        rno = a;
        ino = b;
    }

    Overload operator+(Overload c1) {
        Overload temp;
        temp.rno = rno + c1.rno;
        temp.ino = ino + c1.ino;
        return temp;
    }

    Overload operator-(Overload c1) {
        Overload temp;
        temp.rno = rno - c1.rno;
        temp.ino = ino - c1.ino;
        return temp;
    }

    Overload operator*(Overload c1) {
        Overload temp;
        temp.rno = (rno * c1.rno) - (ino * c1.ino);
        temp.ino = (ino * c1.rno) + (rno * c1.ino);
        return temp;
    }

    Overload operator/(Overload c1) {
        Overload temp, c2;
        c2.ino = -c1.ino;
        float x;
        temp.rno = (rno * c1.rno) - (ino * (c2.ino));
        temp.ino = (rno * c1.rno) + (rno * (c2.ino));
        x = (c1.rno) * (c1.rno) + (c1.ino) * (c1.ino);
        temp.rno = temp.rno / x;
        temp.ino = temp.ino / x;
        return temp;
    }

    friend ostream &operator<<(ostream &out, Overload &c) {
        out << c.rno << " + " << c.ino << "i";
        return out;
    }

    friend istream &operator>>(istream &in, Overload &c) {
        in >> c.rno >> c.ino;
        return in;
    }
};

int main() {
    Overload c1, c2, c3;
    int choice;
    x:
    cout << "\n==========================MENU==========================";
    cout
            << "\n1.Addition of complex number\n2.Subtraction of complex number\n3.Multiplication of complex number\n4.Division of complex number";
    cout << "\n\tEnter your choice: ";
    cin >> choice;
    cout << "Enter real and imaginary part of first complex number: \n";
    cin >> c1;
    cout << "Enter real and imaginary part of second complex number: \n";
    cin >> c2;
    switch (choice) {
        case 1:
            c3 = c1 + c2;
            cout << "\nAddition is: ";
            cout << c3;
            break;
        case 2:
            c3 = c1 - c2;
            cout << "\nSubtraction is: ";
            cout << c3;
            break;
        case 3:
            c3 = c1 * c2;
            cout << "\nMultiplication is: ";
            cout << c3;
            break;
        case 4:
            c3 = c1 / c2;
            cout << "\nDivision is: ";
            cout << c3;
            break;
        default:
            cout << "\nWrong choice.";
    }
    char ch;
    cout << "\nDo you want to continue? (y/n): ";
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
        goto x;
    return 0;
}
