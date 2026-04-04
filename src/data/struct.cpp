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
    int biaya;
    dataKendaraan* next;
};


struct dataRiwayat{
    string platNomor;
    string jenis;
    int idParkir;
    waktu masuk;
    waktu keluar;
    int biaya;
};


dataRiwayat riwayat[100];
int jumlahRiwayat = 0;


dataKendaraan *head = NULL;

