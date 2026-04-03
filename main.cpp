#include <iostream>
#include <string>

using namespace std;

string jenisKendaraan[2] = {"mobil", "motor"};

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

int generateID() {
    static int IDselanjutnya = 1;
    return IDselanjutnya++;
}

void tambahKendaraan(dataKendaraan parkir[], int &jumlah){
    cout << "Masukkan plat nomor kendaraan (Contoh: ABC 1234 XYZ): ";
    cin >> parkir[jumlah].platNomor;

    cout << "Pilih jenis kendaraan : " << endl;
    int pilih;
    cout << "1. Motor" << endl;
    cout << "2. Mobil" << endl;
    cout << "Pilih jenis kendaraan (1-2): ";
    cin >> pilih;

    while(pilih < 1 or pilih > 2){
        cout << "Pilihan tidak valid! Coba lagi." << endl;
        cout << "Pilih jenis kendaraan (1-2): ";
        cin >> pilih;
    }
    parkir[jumlah].jenisKendaraan = jenisKendaraan[pilih - 1];

    parkir[jumlah].idParkir = generateID();
    cout << "ID parkir: " << parkir[jumlah].idParkir << endl;

    cout << "Masukkan waktu jam masuk (0-23): ";
    int pilihanJamParkir;
    cin >> pilihanJamParkir;

    if(pilihanJamParkir >= 0 && pilihanJamParkir <= 23){
        parkir[jumlah].masuk.jam = pilihanJamParkir;
    } else {
        cout << "Jam tidak valid! Coba lagi." << endl;
        return;
    }

    cout << "Masukkan waktu menit masuk (0-59): ";
    int pilihanMenitParkir;
    cin >> pilihanMenitParkir;

    if(pilihanMenitParkir >= 0 && pilihanMenitParkir <= 59){
        parkir[jumlah].masuk.menit = pilihanMenitParkir;
    } else {
        cout << "Menit tidak valid! Coba lagi." << endl;
        return;
    }

    jumlah++;

    cout << "Data Kendaraan berhasil ditambahkan\n";
}

int main() {
    dataKendaraan parkir[100];
    int jumlah = 0;
    int pilihan;
while (true)
{
    cout << "\n==== Sistem Parkir Kendaraan ====\n";
    cout << "1. Tambah kendaraan masuk\n";
    cout << "2. Tampilkan kendaraan\n";
    cout << "3. Ubah data kendaraan\n";
    cout << "4. Kendaraan keluar\n";
    cout << "0. Keluar\n";
    cout << "Pilih opsi nomor (0-4): ";

    cin >> pilihan;

    if(pilihan == 1){
        tambahKendaraan(parkir, jumlah);
    }
    else if (pilihan == 0){
        break;
    }
}
}