#include <iostream>
#include<cstring>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "\nInsufficient number of arguments arguments.";
        return 1;
    }
    char old[50], new1[50];
    strcpy(old, argv[1]);
    strcpy(new1, argv[2]);
    if (rename(old, new1) != 0)
        perror("\nError renaming file.");
    else
        cout << "\nFile renamed successfully.";
    return 0;
}
