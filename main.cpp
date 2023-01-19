#include "BinaryHeap.h"
#include <math.h>
#include <string>
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;

class CustomData
{
public:

    int f1;
    char f2;
};


string writeData(CustomData d)
{
    string out;

    out.append("ID: ");
    out.append(to_string(d.f1));

    out.append(" || CHARACTER: ");
    out.append(to_string(d.f2));

    return out;
}


int compreFun(CustomData d1, CustomData d2)
{
    return d1.f1 - d2.f1;
}


CustomData createRandomData()
{
    CustomData d;

    d.f1 = 0 + rand() % ((1000 + 1) - 0);
    d.f2 = 97 + rand() % ((122 + 1) - 97);

    return d;
}


int main() {

    srand(time(NULL));

    BinaryHeap<CustomData> *bh = new BinaryHeap<CustomData>();

    bh->data_cmp = &compreFun;
    bh->treeToString = &writeData;

    const int MAX_ORDER = 1;

    for (int o = 1; o <= MAX_ORDER; o++) {
        cout << "Rzad wielkosci: " << o << endl;

        const int n = pow(10, o);

        clock_t t1 = clock();
        double max_time_per_element = 0.0;

        for (int i = 0; i < n; i++) {
            bh->addAtEnd(createRandomData());
            //  bh->toStringHeap();

        }

        clock_t t2 = clock();


        clock_t t3 = clock();
        for (int i = 0; i < n; i++) {
            cout << writeData(bh->deleteFirst()) << endl;
            //bh->deleteFirst()

        }
        clock_t t4 = clock();

        double time_delete = (t4 - t2) / double(CLOCKS_PER_SEC * 1000);

        double time = (t2 - t1) / double(CLOCKS_PER_SEC * 1000);

        cout << "czas dodania: " << time << endl;
        cout << "czas usuniecia: " << time_delete << endl;

        const int m = pow(10, 4);
        t1 = clock();


        cout << endl;
    }

    bh->clearNode();
    delete bh;

    return 0;
}