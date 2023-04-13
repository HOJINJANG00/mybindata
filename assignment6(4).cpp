#include <iostream>
#include <fstream>
using namespace std;
void multi5(float*, float*);
void square(float*, float*);
void All(float*, float*, float*);
int a = 1234;

int main() {
    float number5[] = { 1000,2000,3000,4000,5000 }, result[8];
    float ss[] = { -0.5,0,0.5 };
    All(number5, ss, result);
}

void multi5(float* a1, float* b) {
    for (int i = 0; i < 5; i++) {
        b[i] = a1[i] * 5;
    }
}
void square(float* a2, float* b) {
    for (int i = 0; i < 3; i++) {
        b[i + 5] = a2[i] * a2[i];
    }
}

void All(float* a1, float* a2, float* b) {
    multi5(a1, b);
    square(a2, b);
    ofstream myfile("mybin4.dat", ios::binary | ios::out);
    myfile.write((char*)&a, sizeof(int));
    myfile.write((char*)b, sizeof(float) * 8);
    myfile.close();
}