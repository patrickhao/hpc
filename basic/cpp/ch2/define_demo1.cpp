#include <iostream>

using namespace std;

int main() {
    int apple_count {15}; // braced initializer (recommend)
    int lemon_count(4); // functional notation
    int tomato_count = 12; // assignment natation

    int total_fruit {apple_count + lemon_count + tomato_count};

    cout << total_fruit << endl;

    return 0;
}