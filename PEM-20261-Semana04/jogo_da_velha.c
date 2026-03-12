#include <stdio.h>

char tabuleiro[3][3];
char jogador = 'X';

void inicializar() {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

void mostrar() {
    printf("\n");
    for(int i=0;i<3;i++){
        printf(" %c | %c | %c ", tabuleiro[i][0],tabuleiro[i][1],tabuleiro[i][2]);
        if(i<2) printf("\n---+---+---\n");
    }
    printf("\n\n");
}

void trocar() {
    if(jogador=='X')
        jogador='O';
    else
        jogador='X';
}

int verificar() {

    for(int i=0;i<3;i++){
        if(tabuleiro[i][0]==jogador && tabuleiro[i][1]==jogador && tabuleiro[i][2]==jogador)
            return 1;
    }

    for(int i=0;i<3;i++){
        if(tabuleiro[0][i]==jogador && tabuleiro[1][i]==jogador && tabuleiro[2][i]==jogador)
            return 1;
    }

    if(tabuleiro[0][0]==jogador && tabuleiro[1][1]==jogador && tabuleiro[2][2]==jogador)
        return 1;

    if(tabuleiro[0][2]==jogador && tabuleiro[1][1]==jogador && tabuleiro[2][0]==jogador)
        return 1;

    return 0;
}

int cheio() {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(tabuleiro[i][j]==' ')
                return 0;
        }
    }
    return 1;
}

int main() {

    int linha,coluna;
    inicializar();

    while(1){

        mostrar();

        printf("Jogador %c\n", jogador);
        printf("Linha (0-2): ");
        scanf("%d",&linha);

        printf("Coluna (0-2): ");
        scanf("%d",&coluna);

        if(tabuleiro[linha][coluna]!=' '){
            printf("Posicao ocupada!\n");
            continue;
        }

        tabuleiro[linha][coluna]=jogador;

        if(verificar()){
            mostrar();
            printf("O jogador %c venceu!\n", jogador);
            break;
        }

        if(cheio()){
            mostrar();
            printf("Empate!\n");
            break;
        }

        trocar();
    }

    return 0;
}