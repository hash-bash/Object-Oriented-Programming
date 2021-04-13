#include <iostream>
#include <set>
#include<iomanip>

using namespace std;

class Person {
public:
    string name, bod;
    long phno;

    Person(string n, string b, long p) : name(n), bod(b), phno(p) {};

    bool operator<(const Person &b) const {
        return name < b.name;
    }
};

int main() {
    int ch;
    char cho;
    string na, b;
    long p;
    set<Person> data;
    do {
        cout << "\n======================MENU======================";
        cout << "\n 1. Insert & sort person";
        cout << "\n 2. Search person by name";
        cout << "\n 3. Search person by date of birth";
        cout << "\n 4. Search person by telephone number";
        cout << "\n 5. Display all persons";
        cout << "\n\tEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter person's: ";
                cout << "\nName: ";
                cin >> na;
                cout << "\nDate of birth (DD/MM/YYYY): ";
                cin >> b;
                cout << "\nPhone number (upto 8 Digits): ";
                cin >> p;
                data.insert(Person(na, b, p));
                break;
            case 2:
                cout << "\nEnter person name for searching: ";
                cin >> na;
                for (std::set<Person>::const_iterator it = data.begin(); it != data.end(); it++) {
                    if (it->name == na)
                        std::cout << it->name << ", " << it->bod << "\t" << it->phno << endl;
                    else
                        continue;
                }
                break;
            case 3:
                cout << "\nEnter person date of birth for searching: ";
                cin >> b;
                for (set<Person>::const_iterator it = data.begin(); it != data.end(); it++) {
                    if (it->bod == b)
                        cout << it->name << ", " << it->bod << "\t" << it->phno << endl;
                    else
                        continue;
                }
                break;
            case 4:
                cout << "\nEnter person phone number for searching: ";
                cin >> p;
                for (set<Person>::const_iterator it = data.begin(); it != data.end(); it++) {
                    if (it->phno == p)
                        cout << it->name << ", " << it->bod << "\t" << it->phno << endl;
                    else
                        continue;
                }
                break;
            case 5:
                cout << "\t" << left << setw(15) << "Name" << left << setw(15) << "Date of Birth" << left << setw(10)
                     << "Phone No" << endl;
                for (set<Person>::const_iterator it = data.begin(); it != data.end(); it++)
                    cout << "\t" << left << setw(15) << it->name << left << setw(15) << it->bod << left << setw(10)
                         << it->phno << endl;
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
