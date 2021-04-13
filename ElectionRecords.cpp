#include <iostream>
#include <set>
#include<iomanip>

using namespace std;

class Election {
public:
    string vname, vote;
    int vid, age;

    Election(string vname1, string vote1, int vid1, int age1) {
        vname = vname1;
        vid = vid1;
        vote = vote1;
        age = age1;
    }

    bool operator<(const Election &b) const {
        return vid < b.vid;
    }
};

int main() {
    int ch;
    char cho;
    int sena, bjp, con, mns, rw, vid, age;
    string vname, vote;
    set<Election> data;
    do {
        cout << "\n======================MENU======================";
        cout << "\n 1. Insert & sort vote";
        cout << "\n 2. Display voter list";
        cout << "\n 3. Display result";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter voter ID: ";
                cin >> vid;
                cout << "\nEnter voter name: ";
                cin >> vname;
                cout << "\nEnter voter age: ";
                cin >> age;
                if (age >= 18) {
                    cout << "\nYou can vote for any of the party listed below:" << endl;
                    cout
                            << "\n1.ShivSena (Sena)\n2.Bharatiya Janta Party (BJP)\n3.Congress (CON)\n4.Maharashtra Navnirman Sena (MNS)\n5.Rashtrawadi (RW)"
                            << endl << "\tVote: ";
                    cin >> vote;
                    data.insert(Election(vname, vote, vid, age));
                } else
                    cout << "\nYou are not eligible person to vote.";
                break;
            case 2:
                cout << "\nList of voters who have done voting:\n";
                cout << "\t" << left << setw(7) << "ID" << left << setw(15) << "NAME" << left << setw(5) << "AGE"
                     << endl;
                for (set<Election>::const_iterator it = data.begin(); it != data.end(); it++)
                    cout << "\t" << left << setw(7) << it->vid << left << setw(15) << it->vname << left << setw(5)
                         << it->age << endl;
                break;
            case 3:
                cout << "\n\t\t--- Results for the election 2019 ---" << endl;
                sena = bjp = con = mns = rw = 0;
                for (std::set<Election>::const_iterator it = data.begin(); it != data.end(); it++) {
                    if (it->vote == "Sena")
                        sena++;
                    else if (it->vote == "BJP")
                        bjp++;
                    else if (it->vote == "CON")
                        con++;
                    else if (it->vote == "MNS")
                        mns++;
                    else if (it->vote == "RW")
                        rw++;
                }
                cout << "\n--------------------------------------------------------------------" << endl;
                cout << "\t" << left << setw(10) << "SENA" << left << setw(10) << "BJP" << left << setw(10)
                     << "CONGRESS" << left << setw(10) << "MNS" << left << setw(12) << "RASHTRAWADI" << endl;
                cout << "\n--------------------------------------------------------------------" << endl;
                cout << "\t" << left << setw(10) << sena << left << setw(10) << bjp << left << setw(10) << con << left
                     << setw(10) << mns << left << setw(10) << rw << endl;
                cout << "\n--------------------------------------------------------------------" << endl;
                if (sena > bjp && sena > con && sena > mns && sena > rw)
                    printf("\nSHIVSENA PARTY WON THE ELECTION.");
                else if (con > bjp && con > mns && con > sena && con > rw)
                    printf("\nCONGRESS PARTY WON THE ELECTION.");
                else if (mns > bjp && mns > con && mns > sena && mns > rw)
                    printf("\nMAHARASHTRA NAVNIRMAN SENA PARTY WON THE ELECTION.");
                else if (bjp > sena && bjp > con && bjp > mns && bjp > rw)
                    printf("\nBJP PARTY WON THE ELECTION.");
                else
                    printf("\nRASHTRAWADI PARTY WON THE ELECTION.");
                cout << "\n--------------------------------------------------------------------" << endl;
                break;
            default:
                cout << "\nWrong choice.";
                break;
        }
        cout << "\n\tDo you want to continue? (y/n): ";
        cin >> cho;
    } while (cho == 'y' || cho == 'Y');
    return 0;
}
