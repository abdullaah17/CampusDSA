#include <iostream>
using namespace std;

int main() {
    char name[] = "Hamid";
    char *p;
    p = name; /* for string, this stores pointer to its first character */

    while (*p != '\0') {
        cout << *p;
        p++;
    }

    return 0;
}