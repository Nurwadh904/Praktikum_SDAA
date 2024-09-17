#include <iostream>
using namespace std;

int hitungNilaiPascal(int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    } else {
        return hitungNilaiPascal(baris - 1, kolom - 1) + hitungNilaiPascal(baris - 1, kolom);
    }
}

void tampilkanSegitigaPascal(int jumlahBaris) {
    for (int i = 0; i < jumlahBaris; i++) {
        for (int j = 0; j <= i; j++) {
            int hasil = hitungNilaiPascal(i, j);
            cout << hasil << " ";
        }
        cout << endl;
    }
}

int main() {
    int jumlahBaris = 3;
    
    cout << "Segitiga Pascal dengan " << jumlahBaris << " baris:" << endl;
    tampilkanSegitigaPascal(jumlahBaris);
    cout << "Proses selesai." << endl;

    return 0;
}
