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

void push(NodeBuah** top) {
    tambahBuahBaru(top);
    cout << "Buah berhasil ditambahkan ke stack!" << endl;
}

void pop(NodeBuah** top) {
    if (*top == nullptr) {
        cout << "Stack kosong, tidak ada buah untuk dihapus!" << endl;
        return;
    }
    NodeBuah* temp = *top;
    *top = (*top)->next;
    delete temp;
    cout << "Buah paling atas berhasil dihapus dari stack!" << endl;
}

void lihatStack(NodeBuah* top) {
    if (top == nullptr) {
        cout << "\nStack kosong, tidak ada buah untuk ditampilkan.\n";
        return;
    }

    cout << "\n--- Isi Stack ---" << endl;
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

void enqueue(NodeBuah** front, NodeBuah** rear) {
    NodeBuah* buahBaru = new NodeBuah();
    cout << "\n--- Masukkan Buah ke Queue ---" << endl;
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
    cout << "Buah berhasil ditambahkan ke queue!" << endl;
}

void dequeue(NodeBuah** front) {
    if (*front == nullptr) {
        cout << "Queue kosong, tidak ada buah untuk dihapus!" << endl;
        return;
    }
    NodeBuah* temp = *front;
    *front = (*front)->next;
    delete temp;
    cout << "Buah pertama berhasil dihapus dari queue!" << endl;
}

void lihatQueue(NodeBuah* front) {
    if (front == nullptr) {
        cout << "\nQueue kosong, tidak ada buah untuk ditampilkan.\n";
        return;
    }

    cout << "\n--- Isi Queue ---" << endl;
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
    NodeBuah* stackTop = nullptr;
    NodeBuah* queueFront = nullptr;
    NodeBuah* queueRear = nullptr;

    int pilihan;

    do {
        cout << "\n=== Toko Buah Sederhana ===" << endl;
        cout << "1. Tambah Buah ke Linked List" << endl;
        cout << "2. Lihat Semua Buah di Linked List" << endl;
        cout << "3. Tambah Buah ke Stack" << endl;
        cout << "4. Hapus Buah dari Stack (Pop)" << endl;
        cout << "5. Lihat Isi Stack" << endl;
        cout << "6. Tambah Buah ke Queue" << endl;
        cout << "7. Hapus Buah dari Queue (Dequeue)" << endl;
        cout << "8. Lihat Isi Queue" << endl;
        cout << "9. Keluar" << endl;
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
                push(&stackTop);
                break;
            case 4:
                pop(&stackTop);
                break;
            case 5:
                lihatStack(stackTop);
                break;
            case 6:
                enqueue(&queueFront, &queueRear);
                break;
            case 7:
                dequeue(&queueFront);
                break;
            case 8:
                lihatQueue(queueFront);
                break;
            case 9:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 9);

    return 0;
}