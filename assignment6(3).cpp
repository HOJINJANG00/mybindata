#include <iostream>
#include <fstream>
using namespace std;
void multi5(char*,float*, float*);
void square(char*,float*, float*);
int main() {
    float number5[] = { 1000,2000,3000,4000,5000 }, result5[9];
    float ss[] = { -0.5,0,0.5 };
    float* n; n = (float*)result5; *n = 1234;
    
    multi5((char*) "mybin3.dat",number5, result5);
    square((char*) "mybin3.dat",ss, result5);
}

void multi5(char* fn,float* b, float* c) {
    for (int i = 0; i < 5; i++) {
        c[i+1] = b[i] * 5;
    }
}
void square(char* fn,float* b, float* c) {
    ofstream myfile(fn, ios::binary | ios::out);
    for (int i = 0; i < 3; i++) {
        c[i+6] = b[i] * b[i];
    }
    myfile.write((char*)c, sizeof(float)*9);
    myfile.close();
}