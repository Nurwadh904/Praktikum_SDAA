#include <iostream>
#include <string>

using namespace std;

struct InfoBuah {
    string namaBuah; 
    int stokBuah; 
    double hargaBuah; 
};

void tambahBuahBaru(InfoBuah* daftarBuah, int* jumlahBuahSaatIni) {
    cout << "\n--- Masukkan Buah Baru ---" << endl;
    cout << "Nama buah: ";
    cin >> daftarBuah[*jumlahBuahSaatIni].namaBuah;
    cout << "Stok buah: ";
    cin >> daftarBuah[*jumlahBuahSaatIni].stokBuah;
    cout << "Harga per buah: ";
    cin >> daftarBuah[*jumlahBuahSaatIni].hargaBuah;

    (*jumlahBuahSaatIni)++;
    cout << "Buah baru berhasil ditambahkan!" << endl;
}

void lihatSemuaBuah(InfoBuah* daftarBuah, int jumlahBuah) {
    if (jumlahBuah == 0) {
        cout << "\nTidak ada buah dalam daftar saat ini.\n";
        return;
    }

    cout << "\n--- Daftar Buah di Toko ---" << endl;
    for (int i = 0; i < jumlahBuah; i++) {
        cout << "Buah " << i + 1 << ": " << daftarBuah[i].namaBuah 
             << " | Stok: " << daftarBuah[i].stokBuah 
             << " | Harga: Rp" << daftarBuah[i].hargaBuah << endl;
    }
}

void ubahDataBuah(InfoBuah* daftarBuah, int jumlahBuah) {
    lihatSemuaBuah(daftarBuah, jumlahBuah);

    if (jumlahBuah == 0) return;

    int indexBuah;
    cout << "\nPilih nomor buah yang ingin diubah: ";
    cin >> indexBuah;

    if (indexBuah < 1 || indexBuah > jumlahBuah) {
        cout << "Nomor buah tidak ditemukan!" << endl;
        return;
    }

    indexBuah--;

    cout << "Masukkan nama baru: ";
    cin >> daftarBuah[indexBuah].namaBuah;
    cout << "Masukkan stok baru: ";
    cin >> daftarBuah[indexBuah].stokBuah;
    cout << "Masukkan harga baru: ";
    cin >> daftarBuah[indexBuah].hargaBuah;

    cout << "Data buah berhasil diubah!" << endl;
}

void hapusBuahDariToko(InfoBuah* daftarBuah, int* jumlahBuahSaatIni) {
    lihatSemuaBuah(daftarBuah, *jumlahBuahSaatIni);

    if (*jumlahBuahSaatIni == 0) return;

    int indexBuah;
    cout << "\nPilih nomor buah yang ingin dihapus: ";
    cin >> indexBuah;

    if (indexBuah < 1 || indexBuah > *jumlahBuahSaatIni) {
        cout << "Nomor buah tidak ditemukan!" << endl;
        return;
    }

    indexBuah--;

    for (int i = indexBuah; i < (*jumlahBuahSaatIni) - 1; i++) {
        daftarBuah[i] = daftarBuah[i + 1];
    }

    (*jumlahBuahSaatIni)--;
    cout << "Buah berhasil dihapus dari daftar!" << endl;
}

int main() {
    const int kapasitasToko = 100; 
    InfoBuah daftarBuah[kapasitasToko]; 
    int jumlahBuah = 0; 

    int pilihan;

    do {
        cout << "\n=== Toko Buah Sederhana ===" << endl;
        cout << "1. Tambah Buah" << endl;
        cout << "2. Lihat Semua Buah" << endl;
        cout << "3. Ubah Data Buah" << endl;
        cout << "4. Hapus Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuahBaru(daftarBuah, &jumlahBuah);
                break;
            case 2:
                lihatSemuaBuah(daftarBuah, jumlahBuah);
                break;
            case 3:
                ubahDataBuah(daftarBuah, jumlahBuah);
                break;
            case 4:
                hapusBuahDariToko(daftarBuah, &jumlahBuah);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 5);

    return 0;
}
