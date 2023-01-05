#include "functions.c"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ARV *arvore;
    short unsigned int escolha;
    long unsigned int cpf_busca;

    inicializar(&arvore);

    printf("\t\t\t\t\t\t##########################################\n");
    printf("\t\t\t\t\t\t# Seja bem-vindo ao sistema de cadastro! #\n");
    printf("\t\t\t\t\t\t##########################################\n\n");
    printf("\n*Para uma boa experiência siga as instruções abaixo.*\n\n");

    do
    {
        mostraTamanhoArvore(arvore->raiz);

        printf("\nInforme o que você deseja fazer\n\n");
        printf("0 - Sair.\n");
        printf("1 - Cadastrar um elemento.\n");
        printf("2 - Excluir um elemento.\n");
        printf("3 - Listar todos os elementos.\n");
        printf("4 - Procurar um elemento.\n\n");
        printf("Escolha: ");
        scanf("%hu", &escolha);
        getchar();

        switch (escolha)
        {
        case 0:
            limpaJanela();
            printf("\nObrigado por utilizar o sistema de cadastro!\n");
            break;
        case 1:
            limpaJanela();
            printf("\nVocê escolheu cadastrar um elemento!\n");
            printf("\nPara evitar erros siga as instruções de cadastro!\n");
            novoCadastro(&arvore->raiz);
            limpaJanela();
            break;
        case 2:
            limpaJanela();
            exclusaoElemento(&arvore->raiz);
            pausaJanela();
            limpaJanela();
            break;
        case 3:
            limpaJanela();
            if (arvore->raiz != NULL)
            {
                printf("\nVocê escolheu listar os elementos!\n");
                listagem(arvore->raiz);
                printf("\nA listagem terminou!\n");
            }
            else
                printf("\nNão existem elementos para serem listados.\n");
            pausaJanela();
            limpaJanela();
            break;
        case 4:
            limpaJanela();
            printf("Informe qual CPF você deseja procurar (apenas números): ");
            scanf("%lu", &cpf_busca);
            limpaJanela();
            pesquisaElemento(arvore->raiz, cpf_busca);
            pausaJanela();
            limpaJanela();
            break;
        default:
            limpaJanela();
            printf("Opção inválida.\n");
            pausaJanela();
            break;
        }
    } while (escolha != 0);

    return 0;
}