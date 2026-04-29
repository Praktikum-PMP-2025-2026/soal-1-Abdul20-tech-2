/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Abdullah (13224101)
 *   Nama File           : soal2.c
 *   Deskripsi           : Program yang menerima input struct tipe data artefak berdasarkan nama, kategori, tahun, dan nilai.
 *                         Kemudian mengurutkan data tersebut dengan prioritas alfabet kategori naik, tahun naik, nilai turun, alfabet nama naik
 * 
 */

 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  
typedef struct artefak{
    char *nama;
    char *kategori;
    int tahun;
    int nilai;
}artefak;

artefak* masukkanartefak(artefak *data, int *N){
    
    printf("\ndata ke %d", *N);

    (*N)++;
    
    printf("\ndata ke %d", *N);

    data = (artefak*)realloc(data, (*N) * sizeof(artefak));

    if (data == NULL){
        printf("Gagal dimasukkan pada memori\n");
        exit(1);
    }

    char buffer1[100], buffer2[100];

    printf("\nNama: ");
    scanf(" %[^\n]", buffer1);
    data[*N - 1].nama = (char*)malloc((strlen(buffer1) + 1) * sizeof(char));
    strcpy(data[*N - 1].nama, buffer1);

    printf("Kategori: ");
    scanf(" %[^\n]", buffer2);
    data[*N - 1].kategori = (char*)malloc((strlen(buffer2) + 1) * sizeof(char));
    strcpy(data[*N - 1].kategori, buffer2);

    printf("Tahun: ");
    scanf("%d", &data[*N - 1].tahun);
    printf("Nilai: ");
    scanf("%d", &data[*N - 1].nilai);

    (*N)--;

    printf("\ndata ke %d", *N);
    
    return data;
}

void printtotalnilai(artefak *data, int N){
    printf("\nUrutan: ");
    for (int i = 0; i < N; i++){
        printf("\nNama: %s \nKategori: %s \nTahun: %d\nNilai: %d\n", data[i].nama, data[i].kategori, data[i].tahun, data[i].nilai);
    }   
}

int main() {
    int N;
    artefak *data = NULL;
    scanf("%d", &N);
    printf("nilai N: %d", N);

    
    
    for (int i = 0; i < N; i++){
        printf("\nmasuk for %d\n", i);
        data = masukkanartefak(data, &i);
    }

    printtotalnilai(data, N);
    return 0;
}
