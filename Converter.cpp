#include<iostream>

using namespace std;

class Converter {
protected:
    double val1, val2;

    double getinit() {
        return val1;
    }

    double getconv() {
        return val2;
    }

public:
    virtual void compute() = 0;
};

class KMtoM : public Converter {
    double temp;
public:
    void compute() {
        cout << "\n=> Kilometer to meter converter";
        cout << "\nEnter the kilometer value: ";
        cin >> val1;
        cout << "\nKilometer value: " << getinit();
        val2 = val1 * 1000;
        cout << "\nMeter value: " << getconv();
    }
};

class CMtoIN : public Converter {
    double temp;
public:
    void compute() {
        cout << "\n=> Centimeter to inch converter";
        cout << "\nEnter the centimeter value: ";
        cin >> val1;
        cout << "\nCentimeter value: " << getinit();
        val2 = val1 / 2.54;
        cout << "\nInch value: " << getconv();
    }
};

class CLtoF : public Converter {
    double temp;
public:
    void compute() {
        cout << "\n=> Celsius to fahrenheit converter";
        cout << "\nEnter the celsius value: ";
        cin >> val1;
        cout << "\nCelsius value: " << getinit();
        val2 = val1 * 1.8 + 32;
        cout << "\nFahrenheit value: " << getconv();
    }
};

int main() {
    int choice;
    Converter *c;
    KMtoM km;
    CMtoIN ci;
    CLtoF cf;
    x:
    cout << "\n==========================MENU==========================\n";
    cout << "\n1.Kilometer to meter\n2.Centimeter to inches\n3.Celsius to fahrenheit";
    cout << "\n\tEnter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            c = &km;
            c->compute();
            break;
        case 2:
            c = &ci;
            c->compute();
            break;
        case 3:
            c = &cf;
            c->compute();
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
