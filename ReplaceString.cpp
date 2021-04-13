#include <iostream>
#include <fstream>
#include<cstring>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cout << "\nInsufficient number of arguments.";
        return 1;

    }

    string input, output;
    fstream fin;
    fin.open(argv[1], ios::in);
    cout << "\nFind String " << argv[2] << " and replace with " << argv[3];

    if (!fin) {
        cout << "\nCan't open the file.";
        return 1;
    }

    while (fin) {
        getline(fin, input);
        cout << input;
        cout << endl;
    }

    fin.close();
    fin.open(argv[1], ios::in);
    output = "";
    if (!fin) {
        cout << "\nCan't open the file.";
        return 1;
    }

    while (fin) {
        getline(fin, input);
        int a = (int) input.find(argv[2], 0);
        while (a != string::npos) {
            input.replace(a, strlen(argv[2]), argv[3]);
            a = (int) input.find(argv[2], (a + 1));
        }
        output = output + input + "\n";
    }
    fin.close();
    fin.open(argv[1], ios::out);

    if (!fin) {
        cout << "\nCan't open the file.";
        return 1;

    }

    fin << output;
    cout << "\nData replaced.";
    fin.close();

}
