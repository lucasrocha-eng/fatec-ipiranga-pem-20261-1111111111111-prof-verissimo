
/*FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo 
Objetivo do Programa: Gestão de Carga em Logística
Autor: Lucas Rocha
*/

#include <stdio.h>

// Função para processar a carga
void processarCarga(float *vetor, int tamanho) {

    // inicializa a soma e a media com valor 0
    float soma = 0.0;
    float media = 0.0;

    // Laço usado para somar todos os valores do vetor
    for (int i = 0; i < tamanho; i++) {
        soma += *(vetor + i); 
    }
    // Media é calculada divivindo o valor que somamos pelo tamanho
    media = soma / tamanho;
    // Media então é calculada 

    printf("\nMedia do lote: %.2fkg\n", media);
    // A media de peso da frota é apresentada ao usuario

    float limite = media * 1.10; 
    // Define o limite, localizando pesos que excedem mais de 10% da media

    // Laço que identifica os valores excedentes e então aplica correção de -5%
    for (int i = 0; i < tamanho; i++) {
        if (*(vetor + i) > limite) {

            *(vetor + i) = *(vetor + i) * 0.95;
        }
    }
}

// Função principal
int main() {

    // Cria e inicializa o vetor de pesos e a varivel de tamanho
    float pesos[10] = {50.0, 52.5, 48.0, 95.0, 49.5, 51.0, 88.0, 50.5, 47.5, 53.0};
    int tamanho = 10;

    // Atraves de um laço, exibe os valores atuais antes da calibração
    printf("Pesos antes da calibracao\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Pacote %d: %.2f kg\n", i + 1, pesos[i]);
    }

    // Chama a função que processa a carga, passando como parametro o valor do vetor de pesos e seu tamanho
    processarCarga(pesos, tamanho);

    // Laço para exibir novamente os valores, agora apos a calibração feita depois de termos chamado a funcao
    printf("Pesos depois da calibracao\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Pacote %d: %.2f kg\n", i + 1, pesos[i]);
    }

    return 0;
}