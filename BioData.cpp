#include<iostream>
#include<ios>
#include<limits>

using namespace std;

class BioData {
private:
    string name, address, gender;
    long phone;
public:
    BioData() {
        name = "";
        address = "";
        gender = "";
        phone = -1;
    }

    void getData() {
        cout << "\nEnter your name: ";
        cin >> name;
        cout << "\nEnter gender: ";
        cin >> gender;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter address: ";
        getline(cin, address);
        cout << "\nEnter phone number: ";
        cin >> phone;
    }

    void putData() {
        cout << "\nPERSONAL DETAILS:- \n";
        cout << "\nNAME: " << name;
        cout << "\nGENDER: " << gender;
        cout << "\nADDRESS: " << address;
        cout << "\nCONTACT: " << phone;
    }
};

class ProfClass {
private:
    string os, pl;
    string classname;
public:
    ProfClass() {
        os = "";
        pl = "";
        classname = "";
    }

    void getData() {
        cout << "\nEnter name of the course: ";
        cin >> classname;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter which operating system do you know?: ";
        getline(cin, os);
        cout << "\nEnter which programming language do you know?: ";
        getline(cin, pl);
    }

    void putData() {
        cout << "\nPROFESSIONAL DETAILS:- \n ";
        cout << "\nCOURSE: " << classname;
        cout << "\nOS KNOWN: " << os;
        cout << "\nPROGRAMMING LANGUAGES: " << pl;
    }
};

class AcadClass {
private:
    float ten, twe, fe;
public:
    AcadClass() {
        ten = -1;
        twe = -1;
        fe = -1;
    }

    void getData() {
        cout << "\nEnter 10th class percentage: ";
        cin >> ten;
        cout << "\nEnter 12th class percentage: ";
        cin >> twe;
        cout << "\nEnter first year  percentage: ";
        cin >> fe;
    }

    void putData() {
        cout << "\nACADEMIC DETAILS:- \n";
        cout << "\n10th MARKS: " << ten;
        cout << "\n12th MARKS: " << twe;
        cout << "\nFE MARKS: " << fe;
    }
};

class Resume : public BioData, public ProfClass, public AcadClass {
private:
    string title;
public:
    Resume() : BioData(), ProfClass(), AcadClass() {
        title = "";
    }

    void getData() {
        BioData::getData();
        ProfClass::getData();
        AcadClass::getData();
        cout << "\nEnter the title for your Resume: ";
        cin >> title;
    }

    void putData() {
        cout << "\n=============================" << title << "=============================\n";
        BioData::putData();
        ProfClass::putData();
        AcadClass::putData();
    }
};

int main() {
    Resume r1;
    r1.getData();
    r1.putData();
    return 0;
}
