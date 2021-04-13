#include <iostream>
#include <set>
#include<iomanip>

using namespace std;

class Bus1 {
public:
    string name;
    int seat, dist, bill;

    Bus1(string n, int b, int p, int g) : name(n), dist(b), seat(p), bill(g) {};

    bool operator<(const Bus1 &b) const {
        return name < b.name;
    }
};

int main() {
    int ch;
    char cho;
    string na, y;
    int b, p, g, flag = 0, x;
    set<Bus1> data;
    do {
        cout << "\n=====================PUNE-MUMBAI BUS=====================";
        cout << "\n 1. Entry & sort passengers";
        cout << "\n 2. Display bill of all passengers";
        cout << "\n 3. Display all passengers";
        cout << "\n 4. Search by seat number";
        cout << "\n 5. Search by passenger name";
        cout << "\n\tEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter passenger details:";
                cout << "\nName: ";
                cin >> na;
                cout << "\nDistance traveling (Kms): ";
                cin >> b;
                cout << "\nSeat number: ";
                cin >> p;
                if (b <= 99)
                    g = b * 2;
                if (b > 100 && b < 199)
                    g = b * 3;
                if (b >= 200 && b <= 299)
                    g = b * 4;
                if (b >= 300 && b < 399)
                    g = b * 5;
                data.insert(Bus1(na, b, p, g));
                break;
            case 2:
                cout << "\nYou will be charged according to the table given to you, per kilometer.\n";
                cout << "\t" << left << setw(15) << "Name" << left << setw(15) << "Seat Number" << left << setw(15)
                     << "Net Pay" << endl;
                for (set<Bus1>::const_iterator it = data.begin(); it != data.end(); it++)
                    cout << "\t" << left << setw(15) << it->name << left << setw(15) << it->seat << left << setw(15)
                         << it->bill << endl;
                break;
            case 3:
                cout << "\t" << left << setw(15) << "Name" << left << setw(15) << "Distance" << left << setw(10)
                     << "Seat Number" << endl;
                for (set<Bus1>::const_iterator it = data.begin(); it != data.end(); it++)
                    cout << "\t" << left << setw(15) << it->name << left << setw(15) << it->dist << left << setw(10)
                         << it->seat << endl;
                break;
            case 4:
                cout << "\nEnter seat number for searching: ";
                cin >> x;
                for (set<Bus1>::const_iterator it = data.begin(); it != data.end(); it++)
                    if (it->seat == x) {
                        flag = 1;
                        cout << "\t" << left << setw(15) << it->name << left << setw(15) << it->dist << left << setw(10)
                             << it->seat << endl;
                    }
                if (flag == 0)
                    cout << "\nRecord not found.";
                break;
            case 5:
                cout << "\nEnter same for searching: ";
                cin >> y;
                for (set<Bus1>::const_iterator it = data.begin(); it != data.end(); it++)
                    if (it->name == y) {
                        flag = 1;
                        cout << "\t" << left << setw(15) << it->name << left << setw(15) << it->dist << left << setw(10)
                             << it->seat << endl;
                    }
                if (flag == 0)
                    cout << "\nRecord not found.";
                break;

            default:
                cout << "\nWrong choice.";
                break;
        }
        cout << "\nDo you want to continue? (y/n): ";
        cin >> cho;
    } while (cho == 'y' || cho == 'Y');
    return 0;
}
