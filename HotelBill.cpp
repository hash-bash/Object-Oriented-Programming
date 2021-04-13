#include <iostream>
#include <set>
#include<iomanip>

using namespace std;

class Hotel1 {
public:
    string name;
    int tableno, bill;

    Hotel1(string n, int p, int g) : name(n), tableno(p), bill(g) {};

    bool operator<(const Hotel1 &b) const {
        return name < b.name;
    }
};

int main() {
    int ch;
    char cho;
    string na, y;
    int p, g, flag = 0, x, ser, qnt, amt;
    set<Hotel1> data;
    do {
        cout << "\n=====================Hotel Billing System=====================";
        cout << "\n 1. Take the order from customer";
        cout << "\n 2. Display bill of all orders";
        cout << "\n 4. Search by table number";
        cout << "\n 5. Search by customer name";
        cout << "\n\tEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter customer details:";
                cout << "\nName: ";
                cin >> na;
                cout << "\nTable number: ";
                cin >> p;
                cout << "\nPlease order any of the following.\n";
                cout << "\t   " << left << setw(15) << "ITEM" << left << setw(15) << "PRICE RATE" << endl;
                cout << "\t1. " << left << setw(15) << "Pepsi" << left << setw(15) << "15" << endl;
                cout << "\t2. " << left << setw(15) << "Noodles" << left << setw(15) << "20" << endl;
                cout << "\t3. " << left << setw(15) << "Pizza" << left << setw(15) << "58" << endl;
                cout << "\t4. " << left << setw(15) << "Tea" << left << setw(15) << "5" << endl;
                cout << "\t5. " << left << setw(15) << "Coffee" << left << setw(15) << "12" << endl;
            label:
                cout << "\nEnter serial number of food you want to order: ";
                cin >> ser;
                cout << "\nEnter quantity of food you want to order: ";
                cin >> qnt;
                switch (ser) {
                    case 1:
                        amt = (amt + (15 * qnt));
                        break;
                    case 2:
                        amt = (amt + (20 * qnt));
                        break;
                    case 3:
                        amt = (amt + (58 * qnt));
                        break;
                    case 4:
                        amt = (amt + (5 * qnt));
                        break;
                    case 5:
                        amt = (amt + (12 * qnt));
                        break;
                    default:
                        cout << "\nWe don't have that!";
                }
                cout << "\nAnything else do you want to order? (y/n): ";
                cin >> cho;
                if (cho == 'y' || cho == 'Y')
                    goto label;
                g = amt;
                data.insert(Hotel1(na, p, g));
                break;
            case 2:
                cout << "\nYou will be charged according to the table given to you, per kilometer.\n";
                cout << "\t" << left << setw(15) << "Name" << left << setw(15) << "Table Number" << left << setw(15)
                     << "Net Pay" << endl;
                for (set<Hotel1>::const_iterator it = data.begin(); it != data.end(); it++)
                    cout << "\t" << left << setw(15) << it->name << left << setw(15) << it->tableno << left << setw(15)
                         << it->bill << endl;
                break;
            case 3:
                cout << "\nEnter table number for searching: ";
                cin >> x;
                for (set<Hotel1>::const_iterator it = data.begin(); it != data.end(); it++)
                    if (it->tableno == x) {
                        flag = 1;
                        cout << "\t" << left << setw(15) << it->name << left << setw(10) << it->tableno << endl;
                    } else
                        flag = 0;
                if (flag == 0)
                    cout << "\nRecord not Found.";
                break;
            case 4:
                cout << "\nEnter name for searching: ";
                cin >> y;
                for (set<Hotel1>::const_iterator it = data.begin(); it != data.end(); it++)
                    if (it->name == y) {
                        flag = 1;
                        cout << "\t" << left << setw(15) << it->name << left << setw(10) << it->tableno << endl;
                    } else
                        flag = 0;
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
