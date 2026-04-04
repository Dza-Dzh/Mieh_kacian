#include <iostream>
#include <string>

using namespace std;

void daftarKendaraan() {
    cout << "\n=== DAFTAR KENDARAAN TERPARKIR ===\n";
    if (head == NULL) {
        cout << "Parkiran kosong.\n";
        cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
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
  cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}