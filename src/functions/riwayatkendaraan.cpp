#include <iostream>
#include <string>

using namespace std;



void riwayatKendaraan(){
    cout << "\n====== RIWAYAT KENDARAAN =======\n";

    if(jumlahRiwayat == 0){
        cout << "Belum ada data\n";
        cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
        return;
    }

    for(int i = 0; i < jumlahRiwayat; i++){
        cout << i+1 << ". Plat   : " << riwayat[i].platNomor << endl;
        cout << "   Jenis  : " << riwayat[i].jenis << endl;
        cout << "   ID     : " << riwayat[i].idParkir << endl;

        cout << "   Masuk  : ";
        if(riwayat[i].masuk.jam < 10) cout << "0";
        cout << riwayat[i].masuk.jam << ":";

        if(riwayat[i].masuk.menit < 10) cout << "0";
        cout << riwayat[i].masuk.menit << endl;

        cout << "   Keluar : ";
        if(riwayat[i].keluar.jam < 10) cout << "0";
        cout << riwayat[i].keluar.jam << ":";

        if(riwayat[i].keluar.menit < 10) cout << "0";
        cout << riwayat[i].keluar.menit << endl;

        cout << "==========================\n";
    }
    cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
}