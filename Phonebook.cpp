#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>

using namespace std;

class Dict {
    char name[20], ph[15];
public:
    void getdata() {
        cout << "\nEnter the phone details:";
        cout << "\nName: ";
        cin >> name;
        cout << "\nphone Number: ";
        cin >> ph;
    }

    void putdata() {
        cout << "\n" << left << setw(20) << name;
        cout << left << setw(15) << ph;
    }

    char *getName() {
        return name;
    }

    char *gettel() {
        return ph;
    }

    void update(char *nam, char *ph) {
        strcpy(name, nam);
        strcpy(ph, ph);
    }
};

int main() {
    char ph[15], name[20], ch;
    int cho, flag = 0, cnt = 0;
    fstream f;
    Dict t;
    f.open("ph.txt", ios::out | ios::in | ios::binary);
    do {
        cout << "\n=====================MENU=====================";
        cout << "\n 1. Create record";
        cout << "\n 2. Display all records";
        cout << "\n 3. Search by name";
        cout << "\n 4. Search by phone number";
        cout << "\n 5. Update phone number";
        cout << "\n 6. Exit";
        cout << "\nEnter your choice: ";
        cin >> cho;
        switch (cho) {
            case 1:
                t.getdata();
                f.write((char *) &t, sizeof(t));
                break;
            case 2:
                cout << "\nAll phone records are:";
                cout << "\n  Name \t\tTelephoneNumber";
                f.seekg(0, ios::beg);
                for (f.read((char *) &t, sizeof(t)); !f.eof(); f.read((char *) &t, sizeof(t)))
                    t.putdata();
                f.clear();
                break;
            case 3:
                cout << "\nEnter name for searching: ";
                cin >> name;
                f.seekg(0, ios::beg);
                for (f.read((char *) &t, sizeof(t)); !f.eof(); f.read((char *) &t, sizeof(t))) {
                    if (strcmp(name, t.getName()) == 0) {
                        cout << "\nAll phone records are:";
                        cout << "\n  Name \t\tTelephoneNumber";
                        t.putdata();
                        flag = 1;
                    }
                }
                f.clear();
                if (flag == 0)
                    cout << "\nRecord not found.";
                break;
            case 4:
                cout << "\nEnter telephone number for searching: ";
                cin >> ph;
                f.seekg(0, ios::beg);
                flag = 0;
                for (f.read((char *) &t, sizeof(t)); !f.eof(); f.read((char *) &t, sizeof(t))) {
                    if (strcmp(ph, t.gettel()) == 0) {
                        cout << "\nAll phone records are:";
                        cout << "\n  Name \t\tTelephoneNumber";
                        t.putdata();
                        flag = 1;
                    }
                }
                f.clear();
                if (flag == 0)
                    cout << "\nRecord not found.";
                break;
            case 5:
                cout << "\nEnter name for updating: ";
                cin >> name;
                flag = 0;
                f.seekg(0, ios::beg);
                for (f.read((char *) &t, sizeof(t)); !f.eof(); f.read((char *) &t, sizeof(t))) {
                    cnt++;
                    if (strcmp(name, t.getName()) == 0) {
                        flag = 1;
                        break;
                    }
                }
                f.clear();
                if (flag == 0)
                    cout << "\nRecord not found.";
                else {
                    int loc = (cnt - 1) * sizeof(t);
                    if (f.eof())
                        f.clear();
                    cout << "\nEnter new phone number: ";
                    cin >> ph;
                    f.seekp(loc);
                    t.update(name, ph);
                    f.flush();
                    f.write((char *) &t, sizeof(t));
                }
                break;
            case 6:
                return 0;
            default:
                cout << "\nEnter valid choice.";
                break;
        }
        cout << "\nDo you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}
