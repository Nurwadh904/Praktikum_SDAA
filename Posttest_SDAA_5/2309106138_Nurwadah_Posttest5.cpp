#include <iostream>
#include <string>

using namespace std;

struct NodeBuah {
    string namaBuah;
    int stokBuah;
    double hargaBuah;
    NodeBuah* next;
};

NodeBuah* head = nullptr;  
NodeBuah* tempatPenyimpanan1 = nullptr;  
NodeBuah* tempatPenyimpanan2Depan = nullptr; 
NodeBuah* tempatPenyimpanan2Belakang = nullptr;  

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

    while (temp != nullptr && temp->namaBuah != namaBuah) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Buah dengan nama " << namaBuah << " tidak ditemukan di daftar.\n";
        return;
    }

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

// Fungsi untuk menggabungkan dua sublist dalam Merge Sort berdasarkan namaBuah (Ascending)
NodeBuah* gabung(NodeBuah* kiri, NodeBuah* kanan) {
    if (!kiri)
        return kanan;
    if (!kanan)
        return kiri;

    if (kiri->namaBuah < kanan->namaBuah) {
        kiri->next = gabung(kiri->next, kanan);
        return kiri;
    } else {
        kanan->next = gabung(kiri, kanan->next);
        return kanan;
    }
}

// Fungsi untuk memecah list menjadi dua bagian
void bagi(NodeBuah* head, NodeBuah** kiri, NodeBuah** kanan) {
    NodeBuah* cepat;
    NodeBuah* lambat;
    lambat = head;
    cepat = head->next;

    while (cepat != nullptr) {
        cepat = cepat->next;
        if (cepat != nullptr) {
            lambat = lambat->next;
            cepat = cepat->next;
        }
    }

    *kiri = head;
    *kanan = lambat->next;
    lambat->next = nullptr;
}

// Fungsi utama untuk melakukan Merge Sort berdasarkan namaBuah (Ascending)
void mergeSort(NodeBuah** headRef) {
    NodeBuah* head = *headRef;
    NodeBuah* kiri;
    NodeBuah* kanan;

    if ((head == nullptr) || (head->next == nullptr)) {
        return;
    }

    bagi(head, &kiri, &kanan);

    mergeSort(&kiri);
    mergeSort(&kanan);

    *headRef = gabung(kiri, kanan);
}

// Fungsi untuk mengambil tail (elemen terakhir) dari linked list
NodeBuah* ambilTail(NodeBuah* head) {
    while (head != nullptr && head->next != nullptr)
        head = head->next;
    return head;
}

// Fungsi untuk partisi dalam Quick Sort berdasarkan stokBuah (Descending)
NodeBuah* partisi(NodeBuah* head, NodeBuah* tail, NodeBuah** baruHead, NodeBuah** baruTail) {
    NodeBuah* pivot = tail;
    NodeBuah* prev = nullptr;
    NodeBuah* cur = head;
    NodeBuah* akhir = pivot;

    while (cur != pivot) {
        if (cur->stokBuah > pivot->stokBuah) { 
            if ((*baruHead) == nullptr) {
                (*baruHead) = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev != nullptr) {
                prev->next = cur->next;
            }
            NodeBuah* tmp = cur->next;
            cur->next = nullptr;
            akhir->next = cur;
            akhir = cur;
            cur = tmp;
        }
    }

    if ((*baruHead) == nullptr) {
        (*baruHead) = pivot;
    }

    (*baruTail) = akhir;

    return pivot;
}

// Fungsi Quick Sort rekursif berdasarkan stokBuah (Descending)
NodeBuah* quickSortRekursif(NodeBuah* head, NodeBuah* tail) {
    if (!head || head == tail) {
        return head;
    }

    NodeBuah* baruHead = nullptr;
    NodeBuah* baruTail = nullptr;

    NodeBuah* pivot = partisi(head, tail, &baruHead, &baruTail);

    if (baruHead != pivot) {
        NodeBuah* temp = baruHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr;

        baruHead = quickSortRekursif(baruHead, temp);

        temp = ambilTail(baruHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRekursif(pivot->next, baruTail);

    return baruHead;
}

// Fungsi utama untuk melakukan Quick Sort berdasarkan stokBuah (Descending)
void quickSort(NodeBuah** headRef) {
    *headRef = quickSortRekursif(*headRef, ambilTail(*headRef));
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu Aplikasi Buah\n";
        cout << "1. Tambah Buah Baru\n";
        cout << "2. Lihat Semua Buah\n";
        cout << "3. Hapus Buah dari Daftar\n";
        cout << "4. Tambah Buah ke Tempat Penyimpanan 1\n";
        cout << "5. Lihat Tempat Penyimpanan 1\n";
        cout << "6. Hapus Buah dari Tempat Penyimpanan 1\n";
        cout << "7. Tambah Buah ke Tempat Penyimpanan 2\n";
        cout << "8. Lihat Tempat Penyimpanan 2\n";
        cout << "9. Hapus Buah dari Tempat Penyimpanan 2\n";
        cout << "10. Urutkan Buah dengan Merge Sort (Nama Buah Ascending)\n";
        cout << "11. Urutkan Buah dengan Quick Sort (Stok Descending)\n";
        cout << "12. Keluar\n";
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
                lihatTempatPenyimpanan1(tempatPenyimpanan1);
                break;
            case 6:
                hapusBuahDariTempat1(&tempatPenyimpanan1);
                break;
            case 7:
                tambahBuahKeTempat2(&tempatPenyimpanan2Depan, &tempatPenyimpanan2Belakang);
                break;
            case 8:
                lihatTempatPenyimpanan2(tempatPenyimpanan2Depan);
                break;
            case 9:
                hapusBuahDariTempat2(&tempatPenyimpanan2Depan);
                break;
            case 10:
                mergeSort(&head);
                cout << "Buah berhasil diurutkan berdasarkan Nama Buah secara Ascending!\n";
                lihatSemuaBuah(head);
                break;
            case 11:
                quickSort(&head);
                cout << "Buah berhasil diurutkan berdasarkan Stok Buah secara Descending!\n";
                lihatSemuaBuah(head);
                break;
            case 12:
                cout << "Keluar dari aplikasi. Terima kasih!\n";
                break;
            default:
                cout << "Opsi tidak valid, silakan coba lagi.\n";
                break;
        }

    } while (pilihan != 12);

    return 0;
}