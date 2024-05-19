#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");

    struct registro {
        char nome[15];
        int idade, id;
    };

    int k = 0, i = -1, j = 0, opcao = 0, altera = 0, nomid = 0;
    int pesquisa = 0, pidade = 0, inci = 0, incn = 0;
    char pnome[15];
    struct registro cadastro[8];

    while (opcao != 5) {
        printf("\n ============ Menu ============ ");
        printf("\n 1-Cadastrar");
        printf("\n 2-Alterar");
        printf("\n 3-Pesquisar");
        printf("\n 4-Relatório");
        printf("\n 5-Sair");
        printf("\n");

        do {
            printf("\nDigite a opção desejada: ");
            scanf("%d", &opcao);

            if (opcao < 1 || opcao > 5) {
                printf("\nOpção inválida. Por favor, escolha outra opção.\n");
            } else {
                k = 1;
            }
        } while (k != 1);

        k = 0;

        switch (opcao) {
            case 1:
                if (i < 7) {
                    i++;
                    setbuf(stdin, NULL);
                    printf("\nNome: ");
                    scanf("%14s", cadastro[i].nome); // 14 para deixar espaço para o terminador nulo
                    printf("\nIdade: ");
                    scanf("%d", &cadastro[i].idade);
                    cadastro[i].id = i + 1;
                } else {
                    printf("\nCadastro cheio.\n");
                }
                break;
            case 2:
                if (i >= 0) {
                    printf("\nDADOS");
                    printf("\nID | NOME | IDADE");

                    for (j = 0; j <= i; j++) {
                        printf("\n %d | %s | %d", cadastro[j].id,
                                                   cadastro[j].nome,
                                                   cadastro[j].idade);
                    }
                    printf("\nEm qual ID está o dado que deseja alterar? ");
                    scanf("%d", &altera);
                    altera = altera - 1;
                    if (altera >= 0 && altera <= i) {
                        printf("\nO que você deseja alterar?\nDigite 1 para nome ou 2 para idade: ");
                        scanf("%d", &nomid);
                        if (nomid == 1) {
                            setbuf(stdin, NULL);
                            printf("\nDigite o novo nome: ");
                            scanf("%14s", cadastro[altera].nome);
                        } else if (nomid == 2) {
                            printf("\nDigite a nova idade: ");
                            scanf("%d", &cadastro[altera].idade);
                        } else {
                            printf("\nOpção inválida");
                        }
                    } else {
                        printf("\nID inválido");
                    }
                } else {
                    printf("\nNenhum cadastro disponível para alterar.\n");
                }
                break;

            case 3:
                printf("\nO que você deseja pesquisar?\nDigite 1 para nome ou 2 para idade: ");
                scanf("%d", &pesquisa);

                if (pesquisa == 1) {
                    printf("\nDigite o nome que deseja pesquisar: ");
                    scanf("%14s", pnome);
                    incn = 0;  // Reiniciar o contador
                    for (j = 0; j <= i; j++) {
                        if (strcasecmp(cadastro[j].nome, pnome) == 0) {
                            incn++;
                        }
                    }
                    if (incn == 0) {
                        printf("\n %s não consta no cadastro.", pnome);
                    } else {
                        if (incn == 1){
                            printf("\n %s aparece %d vez no cadastro.", pnome, incn);
                        }else{
                            printf("\n %s aparece %d vezes no cadastro.", pnome, incn);
                        }
                    }
                } else if (pesquisa == 2) {
                    printf("\nDigite a idade que deseja pesquisar: ");
                    scanf("%d", &pidade);
                    inci = 0;  // Reiniciar o contador
                    for (j = 0; j <= i; j++) {
                        if (cadastro[j].idade == pidade) {
                            inci++;
                        }
                    }
                    if (inci == 0) {
                        printf("\n %d não consta no cadastro.", pidade);
                    } else {
                        if (inci == 1){
                            printf("\n %d aparece %d vez no cadastro.", pidade, inci);
                        }else{
                            printf("\n %d aparece %d vezes no cadastro.", pidade, inci);
                        }
                    }
                } else {
                    printf("\nOpção inválida.");
                }
                break;
            case 4:
                if (i >= 0) {
                    printf("\nRELATÓRIO");
                    printf("\nID | NOME | IDADE");

                    for (j = 0; j <= i; j++) {
                        printf("\n %d | %s | %d", cadastro[j].id,
                                                  cadastro[j].nome,
                                                  cadastro[j].idade);
                    }
                } else {
                    printf("\nNenhum cadastro disponível.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                break;
        }
    }
}
