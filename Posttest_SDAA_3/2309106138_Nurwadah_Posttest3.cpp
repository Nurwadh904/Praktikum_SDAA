#include <iostream>
#include <string>

using namespace std;

struct NodeBuah {
    string namaBuah; 
    int stokBuah; 
    double hargaBuah; 
    NodeBuah* next;
};

void tambahBuahBaru(NodeBuah** head) {
    NodeBuah* buahBaru = new NodeBuah();
    cout << "\n--- Masukkan Buah Baru ---" << endl;
    cout << "Nama buah: ";
    cin >> buahBaru->namaBuah;
    cout << "Stok buah: ";
    cin >> buahBaru->stokBuah;
    cout << "Harga per buah: ";
    cin >> buahBaru->hargaBuah;
    buahBaru->next = nullptr;

    if (*head == nullptr) {
        *head = buahBaru; 
    } else {
        NodeBuah* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = buahBaru;
    }
    cout << "Buah baru berhasil ditambahkan!" << endl;
}

void lihatSemuaBuah(NodeBuah* head) {
    if (head == nullptr) {
        cout << "\nTidak ada buah dalam daftar saat ini.\n";
        return;
    }

    cout << "\n--- Daftar Buah di Toko ---" << endl;
    int i = 1;
    NodeBuah* temp = head;
    while (temp != nullptr) {
        cout << "Buah " << i << ": " << temp->namaBuah 
             << " | Stok: " << temp->stokBuah 
             << " | Harga: Rp" << temp->hargaBuah << endl;
        temp = temp->next;
        i++;
    }
}

void ubahDataBuah(NodeBuah* head) {
    lihatSemuaBuah(head);

    if (head == nullptr) return;

    int indexBuah;
    cout << "\nPilih nomor buah yang ingin diubah: ";
    cin >> indexBuah;

    NodeBuah* temp = head;
    for (int i = 1; i < indexBuah; i++) {
        if (temp == nullptr) {
            cout << "Nomor buah tidak ditemukan!" << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp != nullptr) {
        cout << "Masukkan nama baru: ";
        cin >> temp->namaBuah;
        cout << "Masukkan stok baru: ";
        cin >> temp->stokBuah;
        cout << "Masukkan harga baru: ";
        cin >> temp->hargaBuah;

        cout << "Data buah berhasil diubah!" << endl;
    } else {
        cout << "Nomor buah tidak ditemukan!" << endl;
    }
}

void hapusBuahDariToko(NodeBuah** head) {
    lihatSemuaBuah(*head);

    if (*head == nullptr) return;

    int indexBuah;
    cout << "\nPilih nomor buah yang ingin dihapus: ";
    cin >> indexBuah;

    NodeBuah* temp = *head;
    NodeBuah* prev = nullptr;

    if (indexBuah == 1) {
        *head = temp->next; 
        delete temp;
        cout << "Buah berhasil dihapus dari daftar!" << endl;
        return;
    }

    for (int i = 1; temp != nullptr && i < indexBuah; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Nomor buah tidak ditemukan!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Buah berhasil dihapus dari daftar!" << endl;
}

int main() {
    NodeBuah* head = nullptr; 

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
                tambahBuahBaru(&head);
                break;
            case 2:
                lihatSemuaBuah(head);
                break;
            case 3:
                ubahDataBuah(head);
                break;
            case 4:
                hapusBuahDariToko(&head);
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