#include <iostream>
#include <list>

using namespace std;

int main() {
    int arr[] = {5, 6, 3, 2, 7};
    list<int> l, l1(arr, arr + sizeof(arr) / sizeof(int));
    list<int>::iterator it;
    int choice, item;
    while (1) {
        cout << "\n===================MENU===================\n";
        cout << "1.Insert element at the front" << endl;
        cout << "2.Insert element at the end" << endl;
        cout << "3.Delete element at the front" << endl;
        cout << "4.Delete element at the end" << endl;
        cout << "5.Front element of the list" << endl;
        cout << "6.Last element of the list" << endl;
        cout << "7.Size of the list" << endl;
        cout << "8.Resize list" << endl;
        cout << "9.Remove elements with specific values" << endl;
        cout << "10.Remove duplicate values" << endl;
        cout << "11.Reverse the order of elements" << endl;
        cout << "12.Sort forward list" << endl;
        cout << "13.Merge sorted lists" << endl;
        cout << "14.Display forward list" << endl;
        cout << "15.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nEnter value to be inserted at the front: ";
                cin >> item;
                l.push_front(item);
                break;
            case 2:
                cout << "\nEnter value to be inserted at the end: ";
                cin >> item;
                l.push_back(item);
                break;
            case 3:
                item = l.front();
                l.pop_front();
                cout << "\nElement " << item << " deleted";
                break;
            case 4:
                item = l.back();
                l.pop_back();
                cout << "\nElement " << item << " deleted";
                break;
            case 5:
                cout << "\nFront element of the list: " << l.front();
                break;
            case 6:
                cout << "\nLast element of the list: " << l.back();
                break;
            case 7:
                cout << "\nSize of the list: " << l.size();
                break;
            case 8:
                cout << "\nEnter new size of the list: ";
                cin >> item;
                if (item <= l.size())
                    l.resize(item);
                else
                    l.resize(item, 0);
                break;
            case 9:
                cout << "\nEnter element to be deleted: ";
                cin >> item;
                l.remove(item);
                break;
            case 10:
                l.unique();
                cout << "\nDuplicate items deleted";
                break;
            case 11:
                l.reverse();
                cout << "\nList reversed";
                break;
            case 12:
                l.sort();
                cout << "\nList sorted";
                break;
            case 13:
                l1.sort();
                l.sort();
                l.merge(l1);
                cout << "\nLists merged after sorting";
                break;
            case 14:
                cout << "\nElements of the list: ";
                for (it = l.begin(); it != l.end(); it++)
                    cout << *it << "  ";
                cout << endl;
                break;
            case 15:
                exit(1);
            default:
                cout << "\nWrong choice.";
        }
    }
}
