#include <bits/stdc++.h>

using namespace std;

class MyString {
public:
    MyString(string s) {
        str = s;
    }

    char& operator[](int index) {
        return str[index];
    }
private:
    string str;
};


int main() {
    MyString str("ABCD");
    cout << str[1] << endl;
    return 0;

}
