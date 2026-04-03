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

    int selisihMenit = totalKeluar - totalMasuk;
    int durasiJam = selisihMenit / 60;

    if(selisihMenit % 60 != 0)
        durasiJam++;

    if(durasiJam <= 0)
        durasiJam = 1;

    return durasiJam;
}

dataKendaraan *head = NULL;

void tambahKendaraan(){
    dataKendaraan *node = new dataKendaraan();

    cout << "=== INPUT KENDARAAN MASUK ===" << endl;
    cout << "Masukkan plat nomor kendaraan (Contoh: ABC 1234 XYZ): ";
    cin >> node->platNomor;

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
    }

    cout << "Masukkan waktu jam masuk (0-23): ";
    int inputJam;
    cin >> inputJam;

    if(inputJam >= 0 && inputJam <= 23){
        node->masuk.jam = inputJam;
    } else {
        cout << "Jam tidak valid! Coba lagi." << endl;
        return;
    }

    cout << "Masukkan waktu menit masuk (0-59): ";
    int inputMenit;
    cin >> inputMenit;

    if(inputMenit >= 0 && inputMenit <= 59){
        node->masuk.menit = inputMenit;
    } else {
        cout << "Menit tidak valid! Coba lagi." << endl;
        return;
    };

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


void kendaraanKeluar(dataKendaraan parkir[], int &jumlah){
    cout << "\n=== CHECK OUT PARKIR ===\n";
    string plat;
    cout << "Masukkan plat nomor: ";
    cin >> plat;

    int index = cariIndex(parkir, jumlah, plat);

    if(index == -1){
        cout << "Kendaraan tidak ditemukan!\n";
        return;
    }

    int jamKeluar, menitKeluar;
    cout << "Jam keluar   : "; cin >> jamKeluar;
    cout << "Menit keluar : "; cin >> menitKeluar;

    int durasi = hitungDurasiJam(parkir[index].masuk, jamKeluar, menitKeluar);

    int tarif = (parkir[index].jenis == "motor") ? 2000 : 5000;
    int totalBayar = durasi * tarif;

    cout << "\n========== STRUK PARKIR ==========\n";
    cout << "ID Parkir : " << parkir[index].idParkir << endl;
    cout << "Plat      : " << parkir[index].platNomor << endl;
    cout << "Jenis     : " << parkir[index].jenis << endl;
    cout << "Durasi    : " << durasi << " jam\n";
    cout << "Bayar     : Rp " << totalBayar << endl;
    cout << "==================================\n";

    for(int i=index;i<jumlah-1;i++)
        parkir[i] = parkir[i+1];

    jumlah--;

    cout << "Kendaraan berhasil keluar!\n";
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
        tambahKendaraan();
    }
    else if(pilihan == 2){
        daftarKendaraan();
    }
    else if(pilihan == 4){
        kendaraanKeluar(parkir, jumlah);
    }
    else if (pilihan == 0){
        break;
    }
}
}