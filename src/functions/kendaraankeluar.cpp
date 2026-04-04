#include <iostream>
#include <string>

using namespace std;


void kendaraanKeluar(){
    dataKendaraan *temp = head;
    dataKendaraan *prev = NULL;

    cout << "\n=== CHECK OUT PARKIR ===\n";
    if (head == NULL) {
        cout << "Parkiran kosong" << endl;
        cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
        return;
    }

    string plat;
    cout << "Masukkan nomor plat kendaraan:  ";
    cin >> plat;

    while (temp != NULL && temp->platNomor != plat) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    int jamKeluar, menitKeluar;
    cout << "Jam keluar   : "; cin >> jamKeluar;
    if(cin.fail() || jamKeluar < 0 || jamKeluar > 23) {
        cout << "Jam tidak valid! Coba lagi." << endl;
        cin.clear();
        cin.ignore(9999, '\n');
        return;
    }
    cout << "Menit keluar : "; cin >> menitKeluar;
    if(cin.fail() || menitKeluar < 0 || menitKeluar > 59) {
        cout << "Menit tidak valid! Coba lagi." << endl;
        cin.clear();
        cin.ignore(9999, '\n');
        return;
    }
    int durasi = hitungDurasiJam(temp->masuk, jamKeluar, menitKeluar);
    int tarif = (temp->jenis == "motor") ? 2000 : 5000;
    int totalBayar = durasi * tarif;

    riwayat[jumlahRiwayat].platNomor = temp->platNomor;
    riwayat[jumlahRiwayat].jenis = temp->jenis;
    riwayat[jumlahRiwayat].idParkir = temp->idParkir;
    riwayat[jumlahRiwayat].masuk = temp->masuk;
    riwayat[jumlahRiwayat].keluar.jam = jamKeluar;
    riwayat[jumlahRiwayat].keluar.menit = menitKeluar;
    riwayat[jumlahRiwayat].biaya = totalBayar;
    jumlahRiwayat++;


    temp->biaya = totalBayar;

    cout << "\n========== STRUK PARKIR ==========\n";
    cout << "ID Parkir : " << temp->idParkir << endl;
    cout << "Plat      : " << temp->platNomor << endl;
    cout << "Jenis     : " << temp->jenis << endl;
    cout << "Durasi    : " << durasi << " jam\n";
    cout << "Bayar     : Rp " << totalBayar << endl;
    cout << "==================================\n";

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Kendaraan berhasil keluar!\n";
}