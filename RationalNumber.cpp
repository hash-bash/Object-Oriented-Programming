#include<iostream>

using namespace std;

class Ration {
    int num, den;

public:
    Ration(int n, int d) {
        num = d < 0 ? -n : n;
        den = d < 0 ? -d : d;
        reduce();
    }

    Ration() {
        num = 0;
        den = 1;
    }

    Ration operator+(Ration a) {
        Ration t;
        t.num = a.num * den + a.den * num;
        t.den = a.den * den;
        t.reduce();
        return t;
    }

    Ration operator-(Ration s) {
        Ration t;
        t.num = s.den * num - den * s.num;
        t.den = s.den * den;
        t.reduce();
        return t;
    }

    Ration operator*(Ration m) {
        Ration t;
        t.num = m.num * num;
        t.den = m.den * den;
        t.reduce();
        return t;
    }

    Ration operator/(Ration v) {
        Ration t;
        t.num = v.den * num;
        t.den = den * v.num;
        t.reduce();
        return t;
    }

    bool operator>(Ration v) {
        float f1 = num / float(den);
        float f2 = v.num / float(v.den);
        if (f1 > f2)
            return true;
        else
            return false;
    }

    bool operator<(Ration v) {
        float f1 = num / float(den);
        float f2 = v.num / float(v.den);
        if (f1 < f2)
            return true;
        else
            return false;
    }

    bool operator>=(Ration v) {
        float f1 = num / float(den);
        float f2 = v.num / float(v.den);
        if (f1 >= f2)
            return true;
        else
            return false;
    }

    bool operator<=(Ration v) {
        float f1 = num / float(den);
        float f2 = v.num / float(v.den);
        if (f1 <= f2)
            return true;
        else
            return false;
    }

    bool operator==(Ration v) {
        float f1 = num / float(den);
        float f2 = v.num / float(v.den);
        if (f1 == f2)
            return true;
        else
            return false;
    }

    bool operator!=(Ration v) {
        float f1 = num / float(den);
        float f2 = v.num / float(v.den);
        if (f1 != f2)
            return true;
        else
            return false;
    }

    void printRation() {
        if (den == 0)
            cout << "Cannot divide by 0.";
        else if (num == 0)
            cout << 0;
        else
            cout << num << "/" << den;
    }

    void reduce() {
        int n = num < 0 ? -num : num;
        int d = den;
        int largest = n > d ? n : d;
        int gcd = 0;
        for (int loop = largest; loop >= 2; loop--) {
            if (num % loop == 0 && den % loop == 0) {
                gcd = loop;
                break;
            }
            if (gcd != 0) {
                num /= gcd;
                den /= gcd;
            }
        }
    }
};

int main() {
    Ration r1, r2, r3;
    int n, d;
    int choice;
    char ch;

    cout << "\nEnter first ration number's numerator and denominator: ";
    cin >> n >> d;
    r1 = Ration(n, d);
    cout << "\nEnter second ration number's numerator and denominator: ";
    cin >> n >> d;

    r2 = Ration(n, d);
    do {
        cout << "\n========================MENU========================";
        cout << "\nOperations are: ";
        cout << "\n1. +\n2. -\n3.*\n4. /\n5. >\n6. <\n7. >=\n8. <=\n9. !=\n10. ==\n11. Print\n12. Exit";
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\n";
                r3 = r1 + r2;
                r3.printRation();
                break;
            case 2:
                cout << "\n";
                r3 = r1 - r2;
                r3.printRation();
                break;
            case 3:
                cout << "\n";
                r3 = r1 * r2;
                r3.printRation();
                break;
            case 4:
                cout << "\n";
                r3 = r1 / r2;
                r3.printRation();
                break;
            case 5:
                if (r1 > r2) {
                    cout << "\n";
                    r1.printRation();
                    cout << " is greater than ";
                    r2.printRation();
                }
                break;
            case 6:
                if (r1 < r2) {
                    cout << "\n";
                    r2.printRation();
                    cout << " is greater than ";
                    r1.printRation();
                }
                break;
            case 7:
                if (r1 >= r2) {
                    cout << "\n";
                    r1.printRation();
                    cout << " is greater than or equal to ";
                    r2.printRation();
                }
                break;
            case 8:
                if (r1 <= r2) {
                    cout << "\n";
                    r2.printRation();
                    cout << " is greater than or equal to ";
                    r1.printRation();
                }
                break;
            case 9:
                if (r1 != r2) {
                    cout << "\n";
                    r1.printRation();
                    cout << " is not equal to ";
                    r2.printRation();
                }
                break;
            case 10:
                if (r1 == r2) {
                    cout << "\n";
                    r1.printRation();
                    cout << " is equal to ";
                    r2.printRation();
                }
                break;
            case 11:
                r1.printRation();
                cout << "\nSecond rational number: ";
                r2.printRation();
                cout << "\nThird rational number: ";
                r3.printRation();
                break;
            case 12:
                exit(0);
        }
        cout << "\nDo you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
