#include <iostream>
#include <fstream>
using namespace std;
int main() {
    char header[44];
    short data[1000];
    unsigned int* SampleRate;

    ifstream myfile;
    myfile.open("Beatles-LetItBe-wav_30s.wav", ios::binary | ios::in);
    if (!myfile) {
        cout << "cant read Beatles-LetItBe-wav_30s.wav\n" << endl;
        return 666;
    }
    myfile.read(header, sizeof(header));

    SampleRate = (unsigned int*)(header + 24);

    myfile.seekg(SampleRate[0] * 10);
    myfile.read((char*)data, 1000);
    myfile.close();

    ofstream aaa("data.txt");
    float dt = 1. / SampleRate[0];
    for (int i = 0; i < 500; i++) {
        aaa << i * dt << " " << data[i * 2] << " " << data[i * 2 + 1] << endl;
    }
}