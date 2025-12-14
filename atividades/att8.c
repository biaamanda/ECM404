#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "sqlite3.h"

void formatarData(int year, int month, int day, char variable[]) {
    sprintf(variable, "%i-%02i-%02i", year, month, day);

}
void diplayMenu() {
    printf("Informe a opcao desejada:\n1 - Consultar preciptacao media no periodo\n2 - Consultar os dias com a temperatura maxima no periodo\n3 - Consultar os dias com a temperatura minima no periodo\n4 - Consultar a temperatura media no perido\n0 - Sair do sistema\n");
}
int main() {
    setlocale(LC_CTYPE, "Portuguese");
    char initPeriod[20];
    char endPeriod[20];

    int initPeriodYear;
    int initPeriodMonth;
    int initPeriodDay;

    int endPeriodYear;
    int endPeriodMonth;
    int endPeriodDay;

    int programOption = 5;

    char query[500];
    
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    
    int dbConnection;
    dbConnection = sqlite3_open("Tempo.db", &db);
    if (dbConnection != SQLITE_OK) {
        printf("Erro ao conectar com o banco\n");
        exit(-1);
    }
    while(programOption != 0) {
        printf("Por favor, digite o ANO do periodo incial:\n");
        scanf("%i", &initPeriodYear);
        printf("Agora, digite o MES do periodo inicial:\n");
        scanf("%i", &initPeriodMonth);
        printf("Agora, digite o DIA do periodo inicial:\n");
        scanf("%i", &initPeriodDay);
        formatarData(initPeriodYear, initPeriodMonth, initPeriodDay, initPeriod);
        printf("\nVamos agora fazer o mesmo para o periodo final!\n\n");
        printf("Por favor, digite o ANO do per odo final:\n");
        scanf("%i", &endPeriodYear);
        printf("Agora, digite o MES do periodo final:\n");
        scanf("%i", &endPeriodMonth);
        printf("Agora, digite o DIA do periodo final:\n");
        scanf("%i", &endPeriodDay);
        formatarData(endPeriodYear, endPeriodMonth, endPeriodDay, endPeriod);
        printf("\n\nEscolha uma opcao de consulta abaixo:\n\n");
        diplayMenu();
        scanf("%i", &programOption);
        switch(programOption) {
            case 1:
            // Precipita o Media
            sprintf(query, "SELECT AVG(precipitacao) FROM Medicoes WHERE data BETWEEN '%s' AND '%s'", initPeriod, endPeriod);
            sqlite3_prepare(db, query, -1, &stmt, NULL);
            if(sqlite3_step(stmt) == SQLITE_ROW) {
                printf("Precipita o M dia = %s\n\n" ,sqlite3_column_text(stmt,0));
            }
            break;
            case 2:
            // Temperatura Maxima
            sprintf(query, "SELECT data, tmax from Medicoes WHERE tmax = (SELECT MAX(tmax) FROM Medicoes WHERE data BETWEEN '%s' AND '%s') AND data BETWEEN '%s' AND '%s';", initPeriod, endPeriod, initPeriod, endPeriod);
            sqlite3_prepare(db, query, -1, &stmt, NULL);
            while(sqlite3_step(stmt) != SQLITE_DONE) {
                for(int i=0; i<sqlite3_column_count(stmt); i++) {
                    printf("Data: %s", sqlite3_column_text(stmt, i));
                    printf(" ");
                    i++;
                    printf("Temperatura M xima: %.2f\n", sqlite3_column_double(stmt, i));
                }
            }
            printf("\n");
            break;
            case 3:
            // Temperatura Minima
            sprintf(query, "SELECT data, tmin from Medicoes WHERE tmin = (SELECT MIN(tmin) FROM Medicoes WHERE data BETWEEN '%s' AND '%s') AND data BETWEEN '%s' AND '%s';", initPeriod, endPeriod, initPeriod, endPeriod);
            sqlite3_prepare(db, query, -1, &stmt, NULL);
            while(sqlite3_step(stmt) != SQLITE_DONE) {
                for(int i=0; i<sqlite3_column_count(stmt); i++) {
                    printf("Data: %s", sqlite3_column_text(stmt, i));
                    printf(" ");
                    i++;
                    printf("Temperatura M nima: %.2f\n", sqlite3_column_double(stmt, i));
                }
            }
            printf("\n");
            break;
            case 4:
            // Temperatura Media
            sprintf(query, "SELECT ((AVG(tmax) + AVG(tmin)) / 2) FROM Medicoes WHERE data BETWEEN '%s' AND '%s';", initPeriod, endPeriod);
            sqlite3_prepare(db, query, -1, &stmt, NULL);
            if(sqlite3_step(stmt) == SQLITE_ROW){
                printf("Temperatura M dia = %s\n\n" ,sqlite3_column_text(stmt,0));
            }
            break;
        }
    }
    sqlite3_close(db);
    return 0;
}