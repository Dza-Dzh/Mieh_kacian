#include <iostream>
#include <string>

using namespace std;


void kendaraanKeluar(){
    dataKendaraan *temp = head;
    dataKendaraan *prev = NULL;
    cout << "\n=== CHECK OUT PARKIR ===\n";
    if (head == NULL) {
        cout << "Parkiran kosong" << endl;
        return;
    };

    string plat;
    cout << "Masukkan plat nomor: ";
    cin >> plat;
    if (temp ->platNomor != plat) {
            cout << "Data tidak ditemukan!" << endl;
            return;
    }
    else if (temp->platNomor == plat){
     while (temp != NULL && temp->platNomor != plat) {
        prev = temp;
        temp = temp->next;
    }
    

    int jamKeluar, menitKeluar;
    cout << "Jam keluar   : "; cin >> jamKeluar;
    cout << "Menit keluar : "; cin >> menitKeluar;

    int durasi = hitungDurasiJam(temp->masuk, jamKeluar, menitKeluar);

    int tarif = (temp->jenis == "motor") ? 2000 : 5000;
    int totalBayar = durasi * tarif;

    cout << "\n========== STRUK PARKIR ==========\n";
    cout << "ID Parkir : " << temp->idParkir << endl;
    cout << "Plat      : " << temp->platNomor << endl;
    cout << "Jenis     : " << temp->jenis << endl;
    cout << "Durasi    : " << durasi << " jam\n";
    cout << "Bayar     : Rp " << totalBayar << endl;
    cout << "==================================\n";

    if (prev == NULL) {
        head = temp->next;
    }
    else{
        prev->next = temp->next;
    }

    delete temp;
    cout << "Kendaraan berhasil keluar!\n";
}
}