#include <iostream>
#include <map>
#include <vector>
#include <initializer_list>
#include <cmath>
#include <memory>

using namespace std;

const int values[] = { 1,2,3,4,5 };
const int val_size = sizeof(values) / sizeof(int);

class Foo {
    std::vector<int> mElements;
public:
    Foo(std::initializer_list<int> list) : mElements(list) {}
};

struct Person {
    int age;
    float weight;
};

void show_output(int** pp)
{
    printf("%p : %p : %d\n", (void*)pp, (void*)*pp, **pp);
}

int main() {
    int x = -10;
    int y = 15;
    cout << x << " " << y << std::endl;

    // print integer ratios of y:x till x < y
    // invalid ratios should print 0
    while (x < y) {
        if (x != 0) {
            cout << "ratio: " << (y / x) << endl;
        } else {
            cout << "ratio: 0" << endl; // Prevent division by zero
        }
        x++;
        y--;
    }

    int i = 1, j = 1; // don't change values
    if ((i = !3) & (j = 1)) {
        cout << "j is 1 and i is not 3\n";
    } else {
        cout << "either j is NOT 1, or i is set to 3\n";
    }

    typedef map<int, double> valmap;
    valmap m;

    for (int i = 0; i < val_size; i++) {
        m.insert(make_pair(values[i], pow(values[i], 0.5)));
    }

    m.insert(make_pair(1, 2.0));

    int n = 1;
    int* p = &n;
    show_output(&p);

    // Initialize a person using a unique_ptr
    auto ptr = std::unique_ptr<Person>(new Person());
    ptr->age = 10;
    ptr->weight = 55.5;

    // Initialize Foo with 5 integers
    Foo foo({1, 2, 3, 4, 5});

    return 0;
}