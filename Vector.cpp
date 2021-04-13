#include<Bits/stdc++.h>

using namespace std;

template<class T>
class Vect {
    int size;
    T *v;
public:

    Vect(int size) {
        this->size = size;
        v = new T[this->size];
    }

    void create() {
        cout << "\nEnter " << size << " elements in the vector: ";
        for (int i = 0; i < size; i++)
            cin >> v[i];
    }

    void display() {
        cout << "\nElements in the vector are: \n(";
        for (int i = 0; i < size; i++)
            cout << v[i] << " ";
        cout << ")";
    }

    void modify(int data) {
        if (data > size)
            cout << "\nIndex position can't be greater than the size of vector.";
        cout << "\nEnter new value: ";
        cin >> v[data - 1];
    }

    void multiply(int value) {
        for (int i = 0; i < size; i++)
            v[i] = v[i] * value;
    }
};

int main() {
    char ch;
    int size;
    cout << "\nEnter the size of vector: ";
    cin >> size;
    Vect<int> v(size);
    do {
        cout << "\n==========================MENU==========================";
        cout
                << "\n1. Create the vector\n2. Modify the vector\n3. Multiply the vector elements with a value\n4. Display vector elements";
        cout << "\nEnter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                v.create();
                break;
            case 2:
                int data;
                cout << "\nEnter the index of element you want to modify: ";
                cin >> data;
                v.modify(data);
                break;
            case 3:
                int val;
                cout << "\nEnter scalar value to multiply vector with: ";
                cin >> val;
                v.multiply(val);
                break;
            case 4:
                v.display();
                break;
            case 5:
                exit(0);
        }
        cout << "\nDo you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
