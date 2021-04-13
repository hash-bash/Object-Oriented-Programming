#include<bits/stdc++.h>

using namespace std;

class UserEx {
public:
    int age;
    float sal;
    string place;

    UserEx(int age) {
        age = age;
    }

    UserEx(float sal) {
        sal = sal;
    }

    UserEx(string place) {
        place = place;
    }

    void dis1() {
        cout << "\nAge is " << age;
    }

    void dis2() {
        cout << "\nSalary is " << sal;
    }

    void dis3() {
        cout << "\nPlace is " << place;
    }

};

int main() {
    int age;
    float sal;
    string place;

    cout << "\nEnter the age, salary and place: ";

    try {
        cout << "\nEnter the age: ";
        cin >> age;
        if (age < 18 || age > 55)
            throw UserEx(age);
        else
            cout << "\nAge is: " << age;
    }
    catch (UserEx e) {
        cout << "\nAge is invalid.";
        e.dis1();
    }

    try {
        cout << "\nEnter the salary: ";
        cin >> sal;
        if (sal < 50000 || sal > 150000)
            throw UserEx(sal);
        else
            cout << "\nSalary is: " << sal;
    }
    catch (UserEx e) {
        cout << "\nSalary is invalid.";
        e.dis2();
    }

    try {
        cout << "\nEnter the place of working: ";
        cin >> place;
        if (place != "Pune" || place != "Mumbai" || place != "Bangalore" || place != "Chennai")
            throw UserEx(sal);
        else
            cout << "\nPlace is: " << place;
    }
    catch (UserEx e) {
        cout << "\nPlace is invalid.";
        e.dis3();
    }
    return 0;
}
