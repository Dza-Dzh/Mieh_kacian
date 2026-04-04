#include <iostream>
#include <string>
#include "data/struct.cpp"
#include "utils/utils.cpp"
#include "functions/tambahkendaraan.cpp"
#include "functions/daftarkendaraan.cpp"
#include "functions/ubahkendaraan.cpp"
#include "functions/kendaraankeluar.cpp"
#include "functions/statistikparkir.cpp"
#include "functions/riwayatkendaraan.cpp"
#include "functions/carikendaraan.cpp"
using namespace std;

int main() {
    int jumlah = 0;
    int pilihan;
    

while (true)
{
    cout << "\n==== Sistem Parkir Kendaraan ====\n";
    cout << "1. Tambah kendaraan masuk\n";
    cout << "2. Tampilkan kendaraan\n";
    cout << "3. Ubah data kendaraan\n";
    cout << "4. Kendaraan keluar\n";
    cout << "5. Cari kendaraan\n";
    cout << "6. Statistik parkir\n";
    cout << "7. Riwayat parkir\n";
    cout << "0. Keluar\n";

    while(true) {
        cout << "Pilih opsi nomor (0-7): ";
        cin >> pilihan;
        if(cin.fail() || pilihan < 0 || pilihan > 7) {
            cout << "Pilihan tidak valid! Coba lagi." << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        } else {
            break;
        }
    }
    if(pilihan == 1){
        tambahKendaraan();
    }
    else if(pilihan == 2){
        daftarKendaraan();
    }
    else if(pilihan == 3){
        ubahKendaraan();
    }
    else if(pilihan == 4){
       kendaraanKeluar();
    }
    else if(pilihan == 5){
        cariKendaraan();
    }
    else if(pilihan == 6){
        statistikParkir();
    }
    else if(pilihan == 7){
        riwayatKendaraan();
    }
    else if (pilihan == 0){
        break;
    }
}
}