#include <iostream>
#include <string>

using namespace std;

string jenisKendaraan[2] = {"mobil, motor"};
dataKendaraan* head = NULL;


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

dataKendaraan* head = NULL;
dataKendaraan* cariNode(string plat);
int hitungDurasiJam(waktu masuk, int jamKeluar, int menitKeluar);
void hapusKendaraanBaru();

dataKendaraan* cariNode(string plat) {
    dataKendaraan* p = head;
    while (p != NULL) {
        if (p->platNomor == plat)
            return p;
        p = p->next;
    }
    return NULL;
}

int hitungDurasiJam(waktu masuk, int jamKeluar, int menitKeluar) {
    int masukMenit = masuk.jam * 60 + masuk.menit;
    int keluarMenit = jamKeluar * 60 + menitKeluar;

    // jika lewat tengah malam
    if (keluarMenit < masukMenit)
        keluarMenit += 24 * 60;

    int selisih = keluarMenit - masukMenit;

    int jam = selisih / 60;
    if (selisih % 60 != 0) jam++; 
    if (jam == 0) jam = 1;        

    return jam;
}


void hapusKendaraanBaru() {
    cout << "\n=== CHECK OUT PARKIR ===\n";

    if (head == NULL) {
        cout << "Parkiran kosong!\n";
        return;
    }

    string plat;
    cout << "Masukkan plat nomor: ";
    cin >> plat;

    dataKendaraan* target = cariNode(plat);

    if (target == NULL) {
        cout << "Kendaraan tidak ditemukan!\n";
        return;
    }

    int jamKeluar, menitKeluar;
    cout << "Jam keluar   : "; cin >> jamKeluar;
    cout << "Menit keluar : "; cin >> menitKeluar;

    int durasi = hitungDurasiJam(target->masuk, jamKeluar, menitKeluar);

    int tarif = (target->jenisKendaraan == "Motor") ? 2000 : 5000;
    int totalBayar = durasi * tarif;


    cout << "\n========== STRUK PARKIR ==========\n";
    cout << "ID Parkir : " << target->idParkir << endl;
    cout << "Plat      : " << target->platNomor << endl;
    cout << "Jenis     : " << target->jenisKendaraan << endl;
    cout << "Durasi    : " << durasi << " jam\n";
    cout << "Bayar     : Rp " << totalBayar << endl;
    cout << "==================================\n";


    if (target->next != NULL) {
        dataKendaraan* hapus = target->next;
        *target = *hapus;
        delete hapus;
    }
    else {
        if (head == target) {
            delete head;
            head = NULL;
            return;
        }

        dataKendaraan* bantu = head;
        while (bantu->next != target)
            bantu = bantu->next;

        bantu->next = NULL;
        delete target;
    }

    cout << "Kendaraan berhasil keluar!\n";
}

int main() {
};