#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void tambahData(node **head);
void tranverse(node *head);
int hitungPenjumlahan(node *head);
int hitungJumlah(node *head);
int cariData(node *head, int bil);

int main() {
    node *head = NULL;
    int pilih;

    do {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di akhir\n");
        printf("3. Tambah data di tengah list\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cari data\n");
        printf("8. Cetak isi list\n");
        printf("9. Tampilkan hasil penjumlahan semua data\n");
        printf("10. Tampilkan jumlah data\n");
        printf("MASUKKAN PILIHAN (tekan 0 untuk keluar): ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: tambahAwal(&head); break;
            case 2: tambahAkhir(&head); break;
            case 3: tambahData(&head); break;
            case 4: hapusAwal(&head); break;
            case 5: hapusTengah(&head); break;
            case 6: hapusAkhir(&head); break;
            case 7: {
                int bil;
                printf("\nMasukkan data yang dicari: ");
                scanf("%d", &bil);
                printf("Data %d %s ditemukan.\n", bil, cariData(head, bil) ? "" : "tidak");
                getch();
                break;
            }
            case 8: tranverse(head); getch(); break;
            case 9: {
                int total = hitungPenjumlahan(head);
                printf("\nHasil penjumlahan semua data di circular linked list: %d\n", total);
                getch();
                break;
            }
            case 10: {
                int jumlah = hitungJumlah(head);
                printf("\nJumlah data di circular linked list: %d\n", jumlah);
                getch();
                break;
            }
        }
    } while (pilih != 0);

    return 0;
}

void tambahAwal(node **head) {
    int bil;
    node *pNew = (node *)malloc(sizeof(node));
    if (pNew) {
        printf("Masukkan bilangan: ");
        scanf("%d", &bil);
        pNew->data = bil;

        if (*head == NULL) {
            *head = pNew;
            pNew->next = *head;
        } else {
            node *pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *head;
            *head = pNew;
        }
        printf("Data %d berhasil ditambahkan di awal.\n", bil);
        getch();
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

void tambahAkhir(node **head) {
    int bil;
    node *pNew = (node *)malloc(sizeof(node));
    if (pNew) {
        printf("Masukkan bilangan: ");
        scanf("%d", &bil);
        pNew->data = bil;

        if (*head == NULL) {
            *head = pNew;
            pNew->next = *head;
        } else {
            node *pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *head;
        }
        printf("Data %d berhasil ditambahkan di akhir.\n", bil);
        getch();
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

void hapusAwal(node **head) {
    if (*head) {
        node *temp = *head;
        node *pCur = *head;

        while (pCur->next != *head) {
            pCur = pCur->next;
        }

        if (temp->next == *head) {
            free(temp);
            *head = NULL;
        } else {
            *head = (*head)->next;
            pCur->next = *head;
            printf("Data %d telah terhapus dari awal.\n", temp->data);
            free(temp);
        }
        getch();
    } else {
        printf("List kosong, tidak ada data yang dihapus.\n");
        getch();
    }
}

void hapusTengah(node **head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada data yang dihapus.\n");
        getch();
        return;
    }

    printf("Data dalam list:\n");
    tranverse(*head);
    int pos;
    printf("\nMasukkan data setelah mana yang ingin dihapus: ");
    scanf("%d", &pos);

    node *pCur = *head;
    while (pCur->next != *head && pCur->data != pos) {
        pCur = pCur->next;
    }

    if (pCur->next == *head || pCur == *head) {
        printf("Data tidak ditemukan atau tidak ada data setelahnya.\n");
        getch();
    } else {
        node *temp = pCur->next;
        pCur->next = temp->next;
        printf("Data %d telah terhapus dari tengah.\n", temp->data);
        free(temp);
        getch();
    }
}

void hapusAkhir(node **head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada data yang dihapus.\n");
        getch();
        return;
    }

    if ((*head)->next == *head) {
        printf("Data %d telah terhapus dari akhir.\n", (*head)->data);
        free(*head);
        *head = NULL;
        getch();
        return;
    }

    node *pCur = *head;
    while (pCur->next->next != *head) {
        pCur = pCur->next;
    }

    printf("Data %d telah terhapus dari akhir.\n", pCur->next->data);
    free(pCur->next);
    pCur->next = *head;
    getch();
}

void tambahData(node **head) {
    int pos, bil;
    node *pCur = *head;

    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    scanf("%d", &pos);
    printf("\nBilangan: ");
    scanf("%d", &bil);

    while (pCur->next != *head && pCur->data != pos) {
        pCur = pCur->next;
    }

    node *pNew = (node *)malloc(sizeof(node));
    if (pCur == NULL || pCur->next == *head) {
        printf("\nNode tidak ditemukan\n");
        free(pNew);
        getch();
    } else if (pNew == NULL) {
        printf("\nAlokasi memori gagal\n");
        getch();
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
        printf("Data %d berhasil ditambahkan setelah data %d.\n", bil, pos);
        getch();
    }
}

void tranverse(node *head) {
    if (head == NULL) {
        printf("List kosong\n");
        return;
    }

    node *pWalker = head;
    do {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("(Back to head)\n");
}

int hitungPenjumlahan(node *head) {
    int total = 0;
    if (head == NULL) return total;

    node *pWalker = head;
    do {
        total += pWalker->data;
        pWalker = pWalker->next;
    } while (pWalker != head);
    return total;
}

int hitungJumlah(node *head) {
    int count = 0;
    if (head == NULL) return count;

    node *pWalker = head;
    do {
        count++;
        pWalker = pWalker->next;
    } while (pWalker != head);
    return count;
}

int cariData(node *head, int bil) {
    if (head == NULL) return 0;

    node *pWalker = head;
    do {
        if (pWalker->data == bil) return 1;
        pWalker = pWalker->next;
    } while (pWalker != head);
    return 0;
}
