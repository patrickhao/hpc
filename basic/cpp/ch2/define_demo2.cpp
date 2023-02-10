#include <iostream>

using namespace std;

int main() {
    /*
    As long as the target type can represent the given values without loss of information,
    thereis no need to issue a warining.
    */
    int a {1.2}; // at least a compiler warning, often an error

    int b {0};

    int c {}; // an empty braced initializer is always assumed to contain the number zero

    int d {11'222}; // use the single quote character, ', to make numeric literals more readable.

    unsigned long e {99UL}; // 99ul or 99LU would be OK too

    return 0;
}