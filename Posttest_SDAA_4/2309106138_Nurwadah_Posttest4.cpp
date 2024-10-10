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
    cout << "Buah baru berhasil ditambahkan ke Daftar Buah!" << endl;
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

void hapusBuahDariDaftar(NodeBuah** head) {
    if (*head == nullptr) {
        cout << "\nDaftar buah kosong, tidak ada buah yang dapat dihapus.\n";
        return;
    }

    string namaBuah;
    cout << "\n--- Hapus Buah dari Daftar ---" << endl;
    cout << "Masukkan nama buah yang ingin dihapus: ";
    cin >> namaBuah;

    NodeBuah* temp = *head;
    NodeBuah* prev = nullptr;

    // Mencari buah yang akan dihapus
    while (temp != nullptr && temp->namaBuah != namaBuah) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Buah dengan nama " << namaBuah << " tidak ditemukan di daftar.\n";
        return;
    }

    // Jika buah berada di node pertama
    if (prev == nullptr) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Buah " << namaBuah << " berhasil dihapus dari daftar!\n";
}

void tambahBuahKeTempat1(NodeBuah** top) {
    tambahBuahBaru(top);
    cout << "Buah berhasil ditambahkan ke Tempat Penyimpanan 1!" << endl;
}

void hapusBuahDariTempat1(NodeBuah** top) {
    if (*top == nullptr) {
        cout << "Tempat Penyimpanan 1 kosong, tidak ada buah untuk dihapus!" << endl;
        return;
    }
    NodeBuah* temp = *top;
    *top = (*top)->next;
    delete temp;
    cout << "Buah paling atas berhasil dihapus dari Tempat Penyimpanan 1!" << endl;
}

void lihatTempatPenyimpanan1(NodeBuah* top) {
    if (top == nullptr) {
        cout << "\nTempat Penyimpanan 1 kosong, tidak ada buah untuk ditampilkan.\n";
        return;
    }

    cout << "\n--- Isi Tempat Penyimpanan 1 ---" << endl;
    int i = 1;
    NodeBuah* temp = top;
    while (temp != nullptr) {
        cout << "Buah " << i << ": " << temp->namaBuah
             << " | Stok: " << temp->stokBuah
             << " | Harga: Rp" << temp->hargaBuah << endl;
        temp = temp->next;
        i++;
    }
}

void tambahBuahKeTempat2(NodeBuah** front, NodeBuah** rear) {
    NodeBuah* buahBaru = new NodeBuah();
    cout << "\n--- Masukkan Buah ke Tempat Penyimpanan 2 ---" << endl;
    cout << "Nama buah: ";
    cin >> buahBaru->namaBuah;
    cout << "Stok buah: ";
    cin >> buahBaru->stokBuah;
    cout << "Harga per buah: ";
    cin >> buahBaru->hargaBuah;
    buahBaru->next = nullptr;

    if (*rear == nullptr) {
        *front = *rear = buahBaru;
    } else {
        (*rear)->next = buahBaru;
        *rear = buahBaru;
    }
    cout << "Buah berhasil ditambahkan ke Tempat Penyimpanan 2!" << endl;
}

void hapusBuahDariTempat2(NodeBuah** front) {
    if (*front == nullptr) {
        cout << "Tempat Penyimpanan 2 kosong, tidak ada buah untuk dihapus!" << endl;
        return;
    }
    NodeBuah* temp = *front;
    *front = (*front)->next;
    delete temp;
    cout << "Buah pertama berhasil dihapus dari Tempat Penyimpanan 2!" << endl;
}

void lihatTempatPenyimpanan2(NodeBuah* front) {
    if (front == nullptr) {
        cout << "\nTempat Penyimpanan 2 kosong, tidak ada buah untuk ditampilkan.\n";
        return;
    }

    cout << "\n--- Isi Tempat Penyimpanan 2 ---" << endl;
    int i = 1;
    NodeBuah* temp = front;
    while (temp != nullptr) {
        cout << "Buah " << i << ": " << temp->namaBuah
             << " | Stok: " << temp->stokBuah
             << " | Harga: Rp" << temp->hargaBuah << endl;
        temp = temp->next;
        i++;
    }
}

int main() {
    NodeBuah* head = nullptr;
    NodeBuah* tempatPenyimpanan1 = nullptr;
    NodeBuah* tempatPenyimpanan2Depan = nullptr;
    NodeBuah* tempatPenyimpanan2Belakang = nullptr;

    int pilihan;

    do {
        cout << "\n=== Toko Buah Sederhana ===" << endl;
        cout << "1. Tambah Buah ke Daftar Buah" << endl;
        cout << "2. Lihat Semua Buah di Daftar Buah" << endl;
        cout << "3. Hapus Buah dari Daftar Buah" << endl;
        cout << "4. Tambah Buah ke Tempat Penyimpanan 1" << endl;
        cout << "5. Hapus Buah dari Tempat Penyimpanan 1" << endl;
        cout << "6. Lihat Isi Tempat Penyimpanan 1" << endl;
        cout << "7. Tambah Buah ke Tempat Penyimpanan 2" << endl;
        cout << "8. Hapus Buah dari Tempat Penyimpanan 2" << endl;
        cout << "9. Lihat Isi Tempat Penyimpanan 2" << endl;
        cout << "10. Keluar" << endl;
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
                hapusBuahDariDaftar(&head);
                break;
            case 4:
                tambahBuahKeTempat1(&tempatPenyimpanan1);
                break;
            case 5:
                hapusBuahDariTempat1(&tempatPenyimpanan1);
                break;
            case 6:
                lihatTempatPenyimpanan1(tempatPenyimpanan1);
                break;
            case 7:
                tambahBuahKeTempat2(&tempatPenyimpanan2Depan, &tempatPenyimpanan2Belakang);
                break;
            case 8:
                hapusBuahDariTempat2(&tempatPenyimpanan2Depan);
                break;
            case 9:
                lihatTempatPenyimpanan2(tempatPenyimpanan2Depan);
                break;
            case 10:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 10);

    return 0;
}
