#include <iostream>
#include <string>

using namespace std;

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
