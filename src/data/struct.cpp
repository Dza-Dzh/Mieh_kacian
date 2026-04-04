#include <iostream>
#include <string>


using namespace std;
string jenisKendaraan[2] = {"motor", "mobil"};

struct waktu{
    int jam;
    int menit;
};

struct dataKendaraan{
    string platNomor;
    string jenis;
    int idParkir;
    waktu masuk;
    dataKendaraan* next;
};

struct dataRiwayat{
    string platNomor;
    string jenis;
    int idParkir;
    waktu masuk;
    waktu keluar;
};