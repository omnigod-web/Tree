
#include <iostream>
#include <new>
using namespace std;

int main() {
    size_t block = 1024*1024*1024; // 1 GB
    char* ptr = nullptr;
    try {
        while (true) {
            ptr = new char[block];
            cout << "Allocated " << block << " bytes\n";
        }
    } catch (bad_alloc&) {
        cout << "Cannot allocate more memory\n";
    }
}