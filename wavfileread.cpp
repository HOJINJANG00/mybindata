#include <iostream>
#include <fstream>
using namespace std;
int main() {
    char header[44];
    unsigned int* ChunkID, * ChunkSize, * Format, * Subchunk1ID, * Subchunk1Size, * SampleRate, * ByteRate, * Subchunk2ID, * Subchunk2Size;
    unsigned short* AudioFormat, * Numchannels, * BlockAlign, * BitsPerSample;

    ifstream myfile;
    myfile.open("Beatles-LetItBe-wav_30s.wav", ios::binary | ios::in);
    if (!myfile) {
        cout << "cant read Beatles-LetItBe-wav_30s.wav\n" << endl;
        return 666;
    }
    myfile.read(header, sizeof(header));
    myfile.close();

    ChunkID = (unsigned int*)(header);
    ChunkSize = (unsigned int*)(header + 4);
    Format = (unsigned int*)(header + 8);
    Subchunk1ID = (unsigned int*)(header + 12);
    Subchunk1Size = (unsigned int*)(header + 16);
    AudioFormat = (unsigned short*)(header + 20);
    Numchannels = (unsigned short*)(header + 22);
    SampleRate = (unsigned int*)(header + 24);
    ByteRate = (unsigned int*)(header + 28);
    BlockAlign = (unsigned short*)(header + 32);
    BitsPerSample = (unsigned short*)(header + 34);
    Subchunk2ID = (unsigned int*)(header + 36);
    Subchunk2Size = (unsigned int*)(header + 40);

    cout << "ChunkID " << *ChunkID << endl;
    cout << "ChunkSize " << *ChunkSize << endl;
    cout << "Format " << *Format << endl;
    cout << "Subchunk1ID " << *Subchunk1ID << endl;
    cout << "Subchunk1Size " << *Subchunk1Size << endl;
    cout << "AudioFormat " << *AudioFormat << endl;
    cout << "Numchannels " << *Numchannels << endl;
    cout << "SampleRate " << *SampleRate << endl;
    cout << "ByteRate " << *ByteRate << endl;
    cout << "BlockAlign " << *BlockAlign << endl;
    cout << "BitsPerSample " << *BitsPerSample << endl;
    cout << "Subchunk2ID " << *Subchunk2ID << endl;
    cout << "Subchunk2Size " << *Subchunk2Size << endl;
}