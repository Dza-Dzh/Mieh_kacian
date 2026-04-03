#include <iostream>
#include <string>

using namespace std;

string jenisKendaraan[2] = {"motor", "mobil"};

struct waktu{
    int jam;
    int menit;
};

struct dataKendaraan{
    string platNomor;
    string jenis;
    int idParkir;
    waktu masuk;
    dataKendaraan* next;
};

int generateID() {
    static int IDselanjutnya = 1;
    return IDselanjutnya++;
}

int cariIndex(dataKendaraan parkir[], int jumlah, string plat){
    for(int i=0;i<jumlah;i++){
        if(parkir[i].platNomor == plat)
            return i;
    }
    return -1;
}

int hitungDurasiJam(waktu masuk, int jamKeluar, int menitKeluar){
    int totalMasuk = masuk.jam * 60 + masuk.menit;
    int totalKeluar = jamKeluar * 60 + menitKeluar;

    if(totalKeluar < totalMasuk){
        totalKeluar += 24 * 60;
    }
    int selisihMenit = totalKeluar - totalMasuk;

    int durasiJam = (selisihMenit + 59) / 60;

    if(durasiJam <= 0)
        durasiJam = 1;

    return durasiJam;
}

dataKendaraan *head = NULL;

void tambahKendaraan(){
    dataKendaraan *node = new dataKendaraan();

    cout << "=== INPUT KENDARAAN MASUK ===" << endl;
    cout << "Masukkan plat nomor kendaraan (Contoh: AB 1234 XYZ): ";
    cin.ignore();
    getline(cin, node->platNomor);

    cout << "Pilih jenis kendaraan : " << endl;
    int pilihanJenis;
    cout << "1. Motor" << endl;
    cout << "2. Mobil" << endl;
    cout << "Pilih jenis kendaraan (1-2): ";
    cin >> pilihanJenis;

    if (pilihanJenis == 1 or pilihanJenis == 2){
        node->jenis = jenisKendaraan[pilihanJenis - 1];
    }
    else{
        cout << "Input tidak valid" << endl;
        return;
    }

    cout << "Masukkan waktu jam masuk (0-23): ";
    int inputJam;
    cin >> inputJam;

    if(cin.fail() || inputJam < 0 || inputJam > 23) {
        cout << "Jam tidak valid! Coba lagi." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    node->masuk.jam = inputJam;

    cout << "Masukkan waktu menit masuk (0-59): ";
    int inputMenit;
    cin >> inputMenit;

    if(cin.fail() || inputMenit < 0 || inputMenit > 59) {
        cout << "Menit tidak valid! Coba lagi." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    };

    node->masuk.menit = inputMenit;

   
    

    node->idParkir = generateID();
    node->next = NULL;

    if (head == NULL){
        head = node;
    }
    else {
        dataKendaraan *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
    }
    cout << "Data Kendaraan berhasil ditambahkan\n";
} 

void daftarKendaraan() {
    cout << "\n=== DAFTAR KENDARAAN TERPARKIR ===\n";
    if (head == NULL) {
        cout << "Parkiran kosong.\n";
        return;
    }

    dataKendaraan* temp = head;
    int nomor = 1;
    while (temp != NULL) {
        string jamStr, menitStr;

        if (temp->masuk.jam < 10){
            jamStr = "0" + to_string(temp->masuk.jam);
        }
        else{
            jamStr = to_string(temp->masuk.jam);
        }

        if (temp->masuk.menit < 10){
            menitStr = "0" + to_string(temp->masuk.menit);
        }
        else{
            menitStr = to_string(temp->masuk.menit);
        }

        cout << nomor << ". Plat: " << temp->platNomor;
        cout << " | Jenis: " << temp->jenis;
        cout << " | Masuk: " << jamStr << ":" << menitStr;
        cout << " | ID Parkir: " << temp->idParkir << endl;
        temp = temp->next;
        nomor++;
    }
}

void ubahKendaraan() {
    cout << "\n=== UBAH DATA KENDARAAN ===\n";
    if (head == NULL) {
        cout << "Parkiran kosong.\n";
        return;
    }

    int cariID;
    cout << "Masukkan ID parkir yang datanya ingin diubah: ";
    cin >> cariID;

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
            } else {
                cout << ">> Pilihan tidak valid, perubahan dibatalkan.\n";
            }

            ketemu = true;
            break;
        }
        temp = temp->next;
    }

    if (!ketemu) cout << ">> ID parkir " << cariID << " tidak ditemukan.\n";
}

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
            cin.ignore(10000, '\n');
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
    else if (pilihan == 0){
        break;
    }
}
}