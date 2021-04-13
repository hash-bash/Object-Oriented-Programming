#include<iostream>

using namespace std;

template<class T>
T selection() {
    T a[10];
    T temp;

    cout << "\nSorting for 10 elements: \n";
    for (int i = 0; i < 10; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "\nUnsorted array: \n";
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";

    cout << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "\nSorted Array: \n";
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}

int main() {
    selection<int>();
}
