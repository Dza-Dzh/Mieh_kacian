#include <iostream>
#include <string>


using namespace std;


void ubahKendaraan() {
    cout << "\n=== UBAH DATA KENDARAAN ===\n";
    if (head == NULL) {
        cout << "Parkiran kosong.\n";
        cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
        return;
    }

    int cariID;
    cout << "Masukkan ID parkir yang datanya ingin diubah: ";
    cin >> cariID;

    if(cin.fail() || cariID <= 0) {
        cout << "ID tidak valid! Coba lagi." << endl;
        cin.clear();
        cin.ignore(9999, '\n');
        return;
    }

    dataKendaraan* temp = head;
    bool ketemu = false;

    while (temp != NULL) {
        if (temp->idParkir == cariID) {
            cout << "Data ditemukan!" << endl;

            string platNomorBaru;
            cout << "Masukkan plat nomor baru: ";   
            cin.ignore();
            getline(cin, platNomorBaru);
            temp->platNomor = platNomorBaru;

            int pilihanJenis;
            cout << "Ubah Jenis Kendaraan (1: Motor, 2: Mobil): "; cin >> pilihanJenis;
            if (pilihanJenis == 1 || pilihanJenis == 2) {
                temp->jenis = jenisKendaraan[pilihanJenis - 1];
                cout << ">> Data berhasil diperbarui!\n";
            } else if(cin.fail() || pilihanJenis < 1 || pilihanJenis > 2) {
                 cout << "Pilihan tidak valid, perubahan dibatalkan.\n";
                 cin.clear();
                 cin.ignore(9999, '\n');
                 return;
            }

            ketemu = true;
            break;
        }
        temp = temp->next;
    }

    if (!ketemu) cout << ">> ID parkir " << cariID << " tidak ditemukan.\n";
}