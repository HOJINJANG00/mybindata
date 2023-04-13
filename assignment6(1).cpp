#include <iostream>
#include <fstream>
using namespace std;
int multi5(int);
float square(float);

int multi5(int n) {
    return n * 5;
}

float square(float n) {
    return float(n * n);
}

int main() {
    int i = 1234;
    float i5[5];
    float ii[3];

    ofstream myfile("mybin1.dat", ios::binary | ios::out);

    myfile.write((char*)&i, sizeof(i));

    for (int i = 1000; i <= 5000; i = i + 1000) {
        int point = i / 1000 - 1;
        i5[point] = multi5(i);
    }

    myfile.write((char*)i5, sizeof(i5));

    for (float i = -0.5; i <= 0.5; i = i + 0.5) {
        int point = i * 2 + 1;
        ii[point] = square(i);
    }

    myfile.write((char*)ii, sizeof(ii));

    myfile.close();
}
