#include <iostream>
#include <string>

using namespace std;

void cariKendaraan(){
    cout << "\n=== CARI KENDARAAN ===\n";

    if(head == NULL){
        cout << "Parkiran kosong.\n";
         cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
        return;
    }

    string plat;
    cout << "Masukkan plat nomor yang dicari: ";
    cin.ignore();
    getline(cin, plat);

    dataKendaraan *temp = head;
    bool ditemukan = false;
    int nomor = 1;

    while(temp != NULL){
        if(temp->platNomor == plat){
            cout << "\n>> Kendaraan ditemukan!\n";
            cout << "Nomor urut : " << nomor << endl;
            cout << "ID Parkir  : " << temp->idParkir << endl;
            cout << "Plat Nomor : " << temp->platNomor << endl;
            cout << "Jenis      : " << temp->jenis << endl;

            cout << "Waktu masuk: ";
            if(temp->masuk.jam < 10) cout << "0";
            cout << temp->masuk.jam << ":";
            if(temp->masuk.menit < 10) cout << "0";
            cout << temp->masuk.menit << endl;
            cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
            ditemukan = true;
            
            break;

        }

        temp = temp->next;
        nomor++;
    }

    if(!ditemukan){
        cout << "Kendaraan dengan plat \"" << plat << "\" tidak ditemukan.\n";
    }

    
}
