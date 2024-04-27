
#include <iostream>
#include <unordered_set>

using namespace std;

int removeDuplicates(char chars[], int size) {
    unordered_set<char> seen;
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (seen.insert(chars[i]).second) {
            chars[index++] = chars[i];
        }
    }

    return index; 
}

int main() {
    char chars[100];
    int size = 0;
    char input;
    cout << "Enter characters (type '.' to stop): ";

    while (cin >> input && input != '.') {
        if (size < 100) {
            chars[size++] = input;
        } else {
            cout << "Array is full." << endl;
            break;
        }
    }

    int newSize = removeDuplicates(chars, size);

    cout << "Array without duplicates: ";
    for (int i = 0; i < newSize; ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}



