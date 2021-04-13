#include<bits/stdc++.h>

using namespace std;

int count(string n, char ch) {
    fstream file;
    file.open(n.c_str(), ios::in);
    if (!file) {
        cout << "\nError reading file.";
        return 1;
    }
    int counter = 0;
    char data[80];
    cout << "\nContents of file are: ";
    while (file) {
        file.getline(data, 80);
        cout << data << endl;
        if (data[0] == ch)
            counter++;
    }
    return counter;
}

int counttotal(string n, char ch) {
    ifstream fin;
    fin.open(n.c_str());
    int ct = 0;
    while (!fin.eof()) {
        fin >> ch;
        ct++;
    }
    return ct;
}

int main() {
    string name;
    cout << "\nEnter the name of the file you want read: ";
    cin >> name;
    char ch;
    cout << "\nEnter the character to check the first character with: ";
    cin >> ch;
    int c = count(name, ch);
    cout << "\nThe number of line starting with " << ch << " is " << c;
    int d = counttotal(name, ch);
    cout << "\nThe total number of characters in file are: " << d;

    return 0;
}
