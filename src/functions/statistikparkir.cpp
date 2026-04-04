#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void statistikParkir() {
    cout << "\n========== Statistik Parkir ==========\n";

    int totalParkirAktif = 0;
    int motorAktif = 0;
    int mobilAktif = 0;
    dataKendaraan* temp = head;

    while (temp != NULL) {
        totalParkirAktif++;
        if (temp->jenis == "motor") motorAktif++;
        else mobilAktif++;
        temp = temp->next;
    }


    int totalKeluar = 0;
    int motorKeluar = 0;
    int mobilKeluar = 0;
    int totalPendapatan = 0;

    for (int i = 0; i < jumlahRiwayat; i++) {
        totalKeluar++;
        totalPendapatan += riwayat[i].biaya;
        if (riwayat[i].jenis == "motor") {
            motorKeluar++;
        } else {
            mobilKeluar++;
        }
    }

    int totalMasuk = totalParkirAktif + totalKeluar;
    int totalMotor = motorAktif + motorKeluar;
    int totalMobil = mobilAktif + mobilKeluar;

    
    cout << "Kendaraan Masuk:" << endl;
    cout << "Total Masuk : " << totalMasuk << " kendaraan" << endl;
    cout << "Motor Masuk : " << totalMotor << " unit" << endl;
    cout << "Mobil Masuk : " << totalMobil << " unit" << endl;
    
    cout << "\nKendaraan Terparkir Saat Ini:" << endl;
    cout << "Total Terparkir : " << totalParkirAktif << " kendaraan" << endl;
    cout << "Motor Terparkir : " << motorAktif << " unit" << endl;
    cout << "Mobil Terparkir : " << mobilAktif << " unit" << endl;
    
    cout << "\nKendaraan Keluar:" << endl;
    cout << "Total Keluar : " << totalKeluar << " kendaraan" << endl;
    cout << "Motor Keluar : " << motorKeluar << " unit" << endl;
    cout << "Mobil Keluar : " << mobilKeluar << " unit" << endl;
    
    cout << "\nPendapatan:" << endl;
    cout << "Total Pendapatan : Rp" << totalPendapatan << endl;
   
    
   cout << "==================\n";
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}