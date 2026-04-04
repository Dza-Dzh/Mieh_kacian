#include <iostream>
#include <string>

using namespace std;

void statistikParkir() {
    cout << "\n=== Statistik Parkir ===\n";

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
    temp = history;

    while (temp != NULL) {
        totalKeluar++;
        totalPendapatan += temp->biaya;
        if (temp->jenis == "motor") motorKeluar++;
        else mobilKeluar++;
        temp = temp->next;
    }

    int totalMasuk = totalParkirAktif + totalKeluar;
    int totalMotor = motorAktif + motorKeluar;
    int totalMobil = mobilAktif + mobilKeluar;

    cout << "Total Kendaraan Masuk   : " << totalMasuk << endl;
    cout << "Total Kendaraan Keluar  : " << totalKeluar << endl;
    cout << "Total Kendaraan Parkir  : " << totalParkirAktif << endl;
    cout << "Total Motor             : " << totalMotor << endl;
    cout << "Total Mobil             : " << totalMobil << endl;
    cout << "Total Pendapatan        : Rp" << totalPendapatan << endl;
    cout << "=============================\n";
    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}