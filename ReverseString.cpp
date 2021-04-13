#include<iostream>
#include<stack>

using namespace std;

int main() {
    char c;
    stack<char> st;

    cout << "\nEnter the String: ";
    for (c = getchar(); c != ' '; c = getchar())
        st.push(c);

    cout << "\nReverse string is: ";
    for (; !st.empty(); st.pop())
        cout << st.top();

    return 0;
}
