#include <stdio.h>
#include <time.h>
#include "main.h"

int escolha;
char nome1[50];
char nome2[50];

void menu() {

    printf("**********************\n");
    printf("*****  CesuGame  *****\n");
    printf("**********************\n\n");

    printf("Qual jogo deseja jogar?\n");
    printf("1: Pergunta e resposta \n");
    printf("2: Cobra na caixa \n");
    printf("3: Sair \n");
    scanf("%d", &escolha);
}
int main() {
    menu();

    switch (escolha) {
        case 1:
            perg();
            break;
        case 2:
            introducao();
            break;
        case 3:
            exit(1);
        default:
            printf("Escolha invalida!\n");
            main();
            break;
    }
}
void perg() {
    int resposta;
    int acertos = 0;
    int respostascorretas[5] = {2,3,2,3,4};
    printf("Serao feitas 5 perguntas e voce tera que escolher a alternativa correta, deseja continuar?\n");
    printf("1: Sim\n");
    printf("2: Voltar ao menu principal\n");
    scanf("%d", & escolha);
    if (escolha == 1) {
        printf("Quando terminou a segunda guerra mundial? \n");
        printf("1: 1943\n2: 1945\n3: 1947\n4: 1949\n");
        scanf("%d", & resposta);
        for (int i = 0; i < respostascorretas; i++) {
            if (resposta < 1 || resposta > 4) {
                printf("Resposta incorreta, escolha apenas uma das 4 opcoes\n");
            } else if (resposta == respostascorretas[0]) {
                printf("Resposta correta!\n");
                acertos++;
                break;
            } else {
                printf("Resposta incorreta, a resposta era 1945\n");
                break;
            }
        }
        printf("Qual o maior oceano do mundo?\n");
        printf("1: Oceano atlantico\n2: Oceano indico\n3: Oceano pacifico\n4: Oceano articon\n");
        scanf("%d", & resposta);
        for (int i = 0; i < respostascorretas; i++) {
            if (resposta < 1 || resposta > 4) {
                printf("Resposta incorreta, escolha apenas uma das 4 opcoes\n");
            } else if (resposta == respostascorretas[1]) {
                printf("Resposta correta!\n");
                acertos++;
                break;
            } else {
                printf("Resposta incorreta, a resposta era oceano pacifico\n");
                break;
            }
        }
        printf("Quem inventou a teoria da relatividade?\n");
        printf("1: Nikola Tesla\n2: Albert Einstein\n3: Isaac Newton\n4: Galileu Galilei\n");
        scanf("%d", & resposta);
        for (int i = 0; i < respostascorretas; i++) {
            if (resposta < 1 || resposta > 4) {
                printf("Resposta incorreta, escolha apenas uma das 4 opcoes\n");
            } else if (resposta == respostascorretas[2]) {
                printf("Resposta correta!\n");
                acertos++;
                break;
            } else {
                printf("Resposta incorreta, a resposta era Albert Eisntein\n");
                break;
            }
        }
        printf("Quem e o maior artilheiro de copas do mundo de futebol?\n");
        printf("1: Pele\n2: Ronaldo\n3: Klose\n4: Zidane\n");
        scanf("%d", & resposta);
        for (int i = 0; i < respostascorretas; i++) {
            if (resposta < 1 || resposta > 4) {
                printf("Resposta incorreta, escolha apenas uma das 4 opcoes\n");
            } else if (resposta == respostascorretas[3]) {
                printf("Resposta correta!\n");
                acertos++;
                break;
            } else {
                printf("Resposta incorreta, a resposta era Klose\n");
                break;
            }
        } 
        printf("De que banda e a musica Yellow Submarine?\n");
        printf("1: The Rolling Stones\n2: System Of Down\n3: AC/DC\n4: The Beatles\n");
        scanf("%d", & resposta);
        for (int i = 0; i < respostascorretas; i++) {
            if (resposta < 1 || resposta > 4) {
                printf("Resposta incorreta, escolha apenas uma das 4 opcoes\n");
            } else if (resposta == respostascorretas[4]) {
                printf("Resposta correta!\n");
                acertos++;
                break;
            } else {
                printf("Resposta incorreta, a resposta era the beatles\n");
                break;
            }
        }
        printf("Voce acertou %d de 5\n", acertos);
        printf("Deseja jogar novamente?\n");
        printf("1: Sim\n");
        printf("2: Voltar ao menu\n");
        scanf("%d", & escolha);
        if (escolha == 1) {
            perg();
        } else if (escolha == 2) {
            main();
        } else {
            printf("Escolha invalida, voltando ao menu\n");
            main();
        }

    } else if (escolha == 2) {
        main();
    } else {
        printf("Escolha invalida, voltando ao menu\n");
        main();
    }
}
void introducao() {
    printf("Voce tera que acertar em qual das 5 caixas esta o botao, mas tome cuidado em uma delas se encontra uma cobra mortal, o jogador que encontrar o botao primeiro e o vencedor! Deseja iniciar o jogo?\n");
    printf("1: Sim\n");
    printf("2: Voltar ao menu\n");
    scanf("%d", & escolha);
    if(escolha == 1) {
    printf("Jogador 1, qual seu nick?\n");
    scanf("%s", & nome1);
    printf("Jogador 2, qual seu nick?\n");
    scanf("%s", & nome2);
    cobra();
    } else if (escolha == 2) {
        main();
    } else {
        printf("Escolha invalida, voltando ao menu\n");
    }

}
void cobra() {
    int segundos = time(0);
    srand(segundos);
    int botaoaleat = rand() % 5;
    int cobraaleat = rand() % 5;
    while (cobraaleat == botaoaleat) {
        cobraaleat = rand() % 5;
    }
    int jogada = 0;
    int caixas_abertas[6];
    int fim = 0;
    for (int i = 0; i < 6; i++) {
    caixas_abertas[i] = 0;
    }

    if (escolha == 1) {
        int jogadoratual = rand() % 2 + 1;
        if (jogadoratual == 1) {
            printf("%s comeca o jogo!\n", nome1);
        } else {
            printf("%s comeca o jogo!\n", nome2);
        }
        while (fim == 0) {
            if (jogadoratual == 1) {
                printf("%s, escolha uma caixa de 1 a 5\n", nome1);
                scanf("%d", &jogada);

                if (jogada < 1 || jogada > 5) {
                    printf("Escolha invalida! Tente novamente.\n");
                    continue;
                }
                if (jogada == botaoaleat) {
                    printf("Parabens, %s voce encontrou o botao e venceu o jogo!\n", nome1);
                    fim++;
                } else if (jogada == cobraaleat) {
                    printf("Voce escolheu a caixa com a cobra e perdeu o jogo :(\n");
                    fim++;
                } else {
                    if (caixas_abertas[jogada] != jogada) {
                        printf("Caixa vazia!\n");
                        caixas_abertas[jogada] = jogada;
                    } else if (caixas_abertas[jogada] == jogada) {
                        printf("Essa caixa ja foi aberta\n");
                        continue;
                    }
                    jogadoratual = 2;

                }
            } else {
                printf("%s, escolha uma caixa de 1 a 5\n", nome2);
                scanf("%d", & jogada);

                if (jogada < 1 || jogada > 5) {
                    printf("Escolha invalida! Tente novamente.\n");
                    continue;
                }
                if (jogada == botaoaleat) {
                    printf("Parabens, %s voce encontrou o botao e venceu o jogo!\n", nome2);
                    fim++;
                } else if (jogada == cobraaleat) {
                    printf("Voce escolheu a caixa com a cobra e perdeu o jogo :(\n");
                    fim++;
                } else {
                    if (caixas_abertas[jogada] != jogada) {
                        caixas_abertas[jogada] = jogada;
                        printf("Caixa vazia!\n");
                    } else if (caixas_abertas[jogada] == jogada) {
                        printf("Essa caixa ja foi aberta\n");
                        continue;
                    }
                    jogadoratual = 1;
                }
            }
        }
        printf("Deseja jogar novamente!\n");
        printf("1: Sim\n");
        printf("2: Voltar ao menu\n");
        scanf("%d", & escolha);
        if (escolha == 1) {
            cobra();
        } else if (escolha == 2) {
            main();
        } else {
            printf("Escolha invalida, voltando ao menu\n");
            main();
        }
    }
}