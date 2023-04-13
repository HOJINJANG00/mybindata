#include <iostream>
#include <fstream>
using namespace std;
void multi5(int, float*, float*);
void square(float, float*, float*);
int main() {
    int n = 1234;
    float number5[] = { 1000,2000,3000,4000,5000 }, result5[5];
    float ss[] = { -0.5 ,0 , 0.5 }, sss[3];
    ofstream myfile("mybin2.dat", ios::binary | ios::out);
    multi5(5, number5, result5);
    square(3, ss, sss);
    myfile.write((char*)&n, sizeof(int));
    myfile.write((char*)result5, sizeof(float) * 5);
    myfile.write((char*)sss, sizeof(float) * 3);
    myfile.close();
}

void multi5(int a, float* b, float* c) {
    for (int i = 0; i < a; i++) {
        c[i] = b[i] * 5;
    }
}
void square(float a, float* b, float* c) {
    for (int i = 0; i < a; i++) {
        c[i] = b[i] * b[i];
    }
}