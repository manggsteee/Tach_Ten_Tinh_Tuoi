#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tinh_tuoi(char* dob) {
    int cnt = 0, day, month, year;
    char* token = strtok(dob, "/");
    while (token != NULL) {
        if(cnt == 0) {
            day = atoi(token);
        }else if(cnt == 1) {
            month = atoi(token);
        }else if(cnt == 2) {
            year = atoi(token);
        }
        token = strtok(NULL, "/");
        cnt++;
    }
    if(month > 11 || month == 11 && day > 30) {
        return 2023 - year;
    }
    free(token);
    return 2024 - year;
}

int main(void) {
    char name[50];
    int cnt = 0;
    printf("Nhap Ho va Ten - Ngay Sinh: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';
    char** tok = malloc(10 * sizeof(char*));
    char* token = strtok(name, " ");
    while (token != NULL) {
        tok[cnt] = malloc((strlen(token)+1) * sizeof(char));
        for(int i = 0; i < strlen(token); i++) {
            tok[cnt][i] = token[i];
        }
        tok[cnt][strlen(token)] = '\0';
        cnt ++;
        token = strtok(NULL, " ");
    }
    printf("Ho: %s\n",tok[0]);
    printf("Ten: %s\n",tok[cnt - 3]);
    printf("Tuoi: %d",tinh_tuoi(tok[cnt - 1]));
    for (int i = 0; i < cnt; i++) {
        free(tok[i]);
    }
    free(tok);
    return 0;
}
