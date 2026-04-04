#include <iostream>
#include <string>

using namespace std;


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