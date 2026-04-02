#include <iostream>
#include <string>

using namespace std;

string jenisKendaraan[2] = {"mobil, motor"};
dataKendaraan* head = NULL;


struct waktu{
    int jam;
    int menit;
};

struct dataKendaraan{
    string platNomor;
    string jenisKendaraan;
    int idParkir;
    waktu masuk;
    dataKendaraan* next;
};



int main() {
};