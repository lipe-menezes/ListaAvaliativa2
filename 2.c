#include <stdio.h>

double calcularForcaPonderada(int forcaGoleiro, int forcaLaterais[], int forcaZagueiros[], int forcaVolantes[], int forcaMeias[], int forcaAtacantes[]) {
    double forcaTotal = (8 * forcaGoleiro + 10 * (forcaLaterais[0]) +
                        5 * (forcaZagueiros[0] ) +
                        8 * (forcaVolantes[0] ) +
                        11 * (forcaMeias[0] ) +
                        12 * (forcaAtacantes[0] )) / 100.0;
    return forcaTotal;
}

int main() {
    char nomeTime[2][31];
    int forcaGoleiro[2];
    int forcaLaterais[2][2];
    int forcaZagueiros[2][2];
    int forcaVolantes[2][2];
    int forcaMeias[2][2];
    int forcaAtacantes[2][2];

    int i, j;
        forcaGoleiro[0] = 0;
        forcaLaterais[0][0] = forcaLaterais[1][0] = 0;
        forcaZagueiros[0][0] = forcaZagueiros[1][0] = 0;
        forcaVolantes[0][0] = forcaVolantes[1][0] = 0;
        forcaMeias[0][0] = forcaMeias[1][0] = 0;
        forcaAtacantes[0][0] = forcaAtacantes[1][0] = 0;
        
    for (i = 0; i < 2; i++) {
        //printf("Nome do time %d: ", i + 1);
        scanf(" %30[^\n]", nomeTime[i]);



        //printf("Jogadores do time %d:\n", i + 1);
        for (j = 0; j < 11; j++) {
            char nomeJogador[31];
            char posicao;
            int forca;

            //printf("Nome, Posicao, Forca (separados por virgula): ");
            scanf(" %30[^;];%c;%d", nomeJogador, &posicao, &forca);

            switch (posicao) {
                case 'G':
                    forcaGoleiro[i] = forca;
                    break;
                case 'L':
                    forcaLaterais[i][0] += forca;
                    break;
                case 'Z':
                    forcaZagueiros[i][0] += forca;
                    break;
                case 'V':
                    forcaVolantes[i][0] += forca;
   
                    break;
                case 'M':
                    forcaMeias[i][0] += forca;
 
                    break;
                case 'A':
                    forcaAtacantes[i][0] += forca;

                    break;
                default:
                    printf("Posicao invalida. Use G, L, Z, V, M ou A.\n");
                    j--;
                    break;
            }
        }
    }

    double forcaTime1 = calcularForcaPonderada(forcaGoleiro[0], forcaLaterais[0], forcaZagueiros[0], forcaVolantes[0], forcaMeias[0], forcaAtacantes[0]);
    double forcaTime2 = calcularForcaPonderada(forcaGoleiro[1], forcaLaterais[1], forcaZagueiros[1], forcaVolantes[1], forcaMeias[1], forcaAtacantes[1]);

    printf("Forca do %s: %.2lf\n", nomeTime[0], forcaTime1);
    printf("Forca do %s: %.2lf\n", nomeTime[1], forcaTime2);

    if (forcaTime1 > forcaTime2) {
        printf("%s eh o time mais forte.\n", nomeTime[0]);
    } else if (forcaTime2 > forcaTime1) {
        printf("%s eh o time mais forte.\n", nomeTime[1]);
    } else {
        printf("Os times tem a mesma forca.\n");
    }

    return 0;
}
