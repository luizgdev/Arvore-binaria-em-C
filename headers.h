#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Macros
#define CONV(num) ((char)((num) + (48))) // Converte um algarismo INT para CHAR

// Structs
typedef struct dadosContato
{
    char email[100];
    short unsigned int ddd;
    long unsigned int numero;
    char telefone_str[15];
} CON;

typedef struct dadosEndereco
{
    char logradouro[50];
    long unsigned int numero;
    char complemento[50];
    char bairro[50];
    char cidade[50];
    long unsigned int cep_num;
    char cep_str[11];
    char estado[50];
    char pais[50];
} END;

typedef struct dadosPessoais
{
    char nome[100];
    long unsigned int cpf;
    char cpf_str[15];
    char sexo[11];
    short unsigned int dia, mes;
    short int ano;
    char naturalidade[50];
    char nome_pai[100];
    char nome_mae[100];
    END endereco;
    CON contato;
} PES;

typedef struct no
{
    struct no *dir;
    PES dados;
    struct no *esq;
} NO;

typedef struct arvore
{
    NO *raiz;
} ARV;

// Funções
void inicializar(ARV **); // Inicializa a árvore.

void leituraDados(NO **);         // Organiza a leitura de dados.
void leituraDadosPessoais(NO **); // Lê os dados pessoais.
void leituraDadosEndereco(NO **); // Lê os dados de endereço.
void leituraDadosContato(NO **);  // Lê os dados de contato.

void novoCadastro(NO **);  // Cadastra um elemento na árvore.
void inserir(NO **, NO *); // Insere o elemento na árvore.
void listagem(NO *);       // Lista todos os elementos da árvore.
void mostraDados(NO *);    // Imprime os dados da árvore.

char *formataString(char *);                                  // Formata o texto de tudo que não é cpf, cep ou telefone.
char *formataCpf(long unsigned int);                          // Formata o texto do cpf.
char *formataCep(long unsigned int);                          // Formata o texto do cep.
char *formataTelefone(short unsigned int, long unsigned int); // Formata o texto do telefone

void exclusaoElemento(NO **);                        // Organiza a exclusão de um elemnto.
long unsigned int excluir(NO **, long unsigned int); // Exclui um elemnto.

long unsigned int tamanhoARVore(NO *);          // Conta quantos elementos a árvore tem.
void mostraTamanhoARVore(NO *);                 // Mostra o tamanho da árvore.
short unsigned int grau(NO *);                  // Diz o grau de um elemnto.
NO *menor(NO *);                                // Busca o menor elemento mais próximo do elemento atual.
void pesquisaElemento(NO *, long unsigned int); // Busca um elemento na árvore.

void limpaJanela(); // Limpa a janela em linux ou windows.
void pausaJanela(); // Para a janela em linux ou windows.

#endif // HEADERS_H_INCLUDED
