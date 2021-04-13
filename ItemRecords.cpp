#include <iostream>
#include <set>
#include<iomanip>

using namespace std;

class Item {
public:
    string iname;
    int icode, qty;
    float icost;

    Item(int i, string n, int q, float ic) : iname(n), icode(i), qty(q), icost(ic) {};

    bool operator<(const Item &b) const {
        return icode < b.icode;
    }
};

int main() {
    int ch;
    char cho;
    string ina;
    int code, qt;
    float cost;
    set<Item> data;
    do {
        cout << "\n======================MENU======================";
        cout << "\n 1. Insert & sort item";
        cout << "\n 2. Search person by item name";
        cout << "\n 3. Search person by item code";
        cout << "\n 4. Search person by item cost";
        cout << "\n 5. Display all items";
        cout << "\n\tEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter item's:";
                cout << "\nCode: ";
                cin >> code;
                cout << "\nName: ";
                cin >> ina;
                cout << "\nQuantity: ";
                cin >> qt;
                cout << "\nCost: ";
                cin >> cost;
                data.insert(Item(code, ina, qt, cost));
                break;
            case 2:
                cout << "\nEnter item name for searching: ";
                cin >> ina;
                for (std::set<Item>::const_iterator it = data.begin(); it != data.end(); it++) {
                    if (it->iname == ina)
                        std::cout << it->icode << ", " << it->iname << ", " << it->qty << "\t" << it->icost << endl;
                    else
                        continue;
                }
                break;
            case 3:
                cout << "\nEnter item code for searching: ";
                cin >> code;
                for (std::set<Item>::const_iterator it = data.begin(); it != data.end(); it++) {
                    if (it->icode == code)
                        std::cout << it->icode << ", " << it->iname << ", " << it->qty << "\t" << it->icost << endl;
                    else
                        continue;
                }
                break;
            case 4:
                cout << "\nEnter item code for searching: ";
                cin >> cost;
                for (std::set<Item>::const_iterator it = data.begin(); it != data.end(); it++) {
                    if (it->icost == cost)
                        std::cout << it->icode << ", " << it->iname << ", " << it->qty << "\t" << it->icost << endl;
                    else
                        continue;
                }
                break;
            case 5:
                cout << "\nList of items:\n";
                cout << "\t" << left << setw(5) << "CODE" << left << setw(15) << "NAME" << left << setw(10)
                     << "QUANTITY" << left << setw(10) << "COST" << endl;
                for (std::set<Item>::const_iterator it = data.begin(); it != data.end(); it++)
                    cout << "\t" << left << setw(5) << it->icode << left << setw(15) << it->iname << left << setw(10)
                         << it->qty << left << setw(10) << it->icost << endl;
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
