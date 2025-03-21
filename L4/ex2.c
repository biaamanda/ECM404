/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler n valores inteiros e os insira em um 
 * array. A leitura deve ser feita de acordo com o programa feito no ex1. 
 * Após a leitura, desenvolva a função calcula_media e calcula_dvp 
 * para calcular a média e o desvio padrão dos valores informados. 
 * O programa principal deve receber os valores lidos pelo array e retornar a 
 * média e o desvio padrão no seguinte formato: MÉDIA +- DVP
 *
 * Exemplos:
 *    Digite os valores para o array: 1 2 3 4 5 6 7 -100
 *    4.00 +- 2.0
 *
 *    Digite os valores para o array: 1 1 1 1 1 1 1 1 1 1 1 -100
 *    1.00 +- 0.0
 *
 *    Digite os valores para o array: 10 20 1 40 50 90 100 -100
 *    44.43 +- 35.6
 *
 */

 #include <stdio.h>
 #include <math.h> 
 
 #define MAX_SIZE 100 
 
 /* Protótipos */
 float calcula_media(int array[], int tam_array);
 float calcula_dvp(int array[], int tam_array);
 void exibe_array(int array[], int tam_array);
 
 int main (int argc, char *argv[]) {
     int array[MAX_SIZE];
     int n, i = 0;
 
     printf("Digite os valores para o array: ");
 
     // Leitura dos valores inteiros e armazenamento no array
     while (scanf("%d", &n) && n != -100 && i < MAX_SIZE) {
         array[i++] = n;
     }
 
 
     // Cálculo da média e do desvio padrão
     float media = calcula_media(array, i);
     printf("%.2f +- ", media);
 
     float dvp = calcula_dvp(array, i);
     printf("%.1f", dvp);
 
     return 0;
 }
 
 float calcula_media(int array[], int tam_array) {
     float somanotas = 0, media;
     for (int i = 0; i < tam_array; i++) {
         somanotas += array[i];
     }
     media = somanotas / tam_array;
     return media;
 }
 
 float calcula_dvp(int array[], int tam_array) {
     float somanotas = 0, media, dvp = 0;
     media = calcula_media(array, tam_array);
 
     for (int i = 0; i < tam_array; i++) {
         dvp += pow(array[i] - media, 2);
     }
 
     dvp = sqrt(dvp / tam_array);
     return dvp;
 }
 