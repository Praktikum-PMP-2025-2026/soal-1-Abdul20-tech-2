/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Abdullah (13224101)
 *   Nama File           : soal2.c
 *   Deskripsi           : 
 * 
 */

 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
  
typedef struct artefak{
    char *nama;
    char *kategori;
    int tahun;
    int nilai;
}artefak;

artefak* masukkanartefak(artefak *data, int *N){

    (*N)++;

    data = (artefak*)realloc(data, (*N) * sizeof(artefak));

    if (data == NULL){
        printf("Gagal dimasukkan pada memori\n");
        exit(1);
    }

    char buffer1[100], buffer2[100];

    scanf(" %[^\n]", buffer1);
    data[*N - 1].nama = (char*)malloc((strlen(buffer1) + 1) * sizeof(char));
    strcpy(data[*N - 1].nama, buffer1);

    scanf(" %[^\n]", buffer2);
    data[*N - 1].kategori = (char*)malloc((strlen(buffer2) + 1) * sizeof(char));
    strcpy(data[*N - 1].kategori, buffer2);

    scanf("%d", &data[*N - 1].tahun);
    scanf("%d", &data[*N - 1].nilai);

    (*N)--;
    
    return data;
}

int compare(artefak a, artefak b){
    if (strcmp(a.kategori, b.kategori)> 0){
        return 1;
    }else if (strcmp(a.kategori, b.kategori)== 0)
    {
        if (a.tahun > b.tahun)
        {
            return 1;
        }else if (a.tahun == b.tahun)
        {
            if (a.nilai < b.nilai)
            {
                return 1;
            }else if (a.nilai == b.nilai)
            {
                if (strcmp(a.nama, b.nama)> 0)
                {
                    return 1;
                }   
            }
        }
    }
    
    
    return 0;
}

void printtotalnilai(artefak *data, int N){
    for (int i = 0; i < N; i++){
        printf("%s %s %d %d\n", data[i].nama, data[i].kategori, data[i].tahun, data[i].nilai);
    }   
}

int main() {
    int N;
    bool isSorted;
    artefak *data = NULL;
    scanf("%d", &N);
    
    int n = sizeof(data) / sizeof(data[0]);
    
    for (int i = 0; i < N; i++){
        data = masukkanartefak(data, &i);
    }

    for (int i = 0; i < N; i++){
        isSorted = true;
        for (int j = 0; j < N-1; j++){
            if (compare(data[j], data[j+1])){
                artefak temp = data[j];
                data[j] = data [j+1];
                data [j+1] = temp;
                isSorted = false;
            }
        }
        if (isSorted == true){
            break;
        }
    }
    
    printtotalnilai(data, N);
    return 0;
}
