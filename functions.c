#include "headers.h"

void inicializar(ARV **arvBin)
{
    *arvBin = (ARV *)malloc(sizeof(ARV));

    if (*arvBin != NULL)
        (*arvBin)->raiz = NULL;
    else
        printf("\nErro no sistema (falha na alocação da árvore binária).\n");
}

void leituraDados(NO **elem)
{
    leituraDadosPessoais(elem);
    leituraDadosEndereco(elem);
    leituraDadosContato(elem);
    (*elem)->dir = (*elem)->esq = NULL;
}

void leituraDadosPessoais(NO **elemPes)
{
    printf("\nInforme os seus dados pessoais.\n");
    printf("\nNOME: ");
    fgets((*elemPes)->dados.nome, 100, stdin);
    strcpy((*elemPes)->dados.nome, formataString((*elemPes)->dados.nome));
    printf("\nCPF (apenas números): ");
    scanf("%lu", &(*elemPes)->dados.cpf);
    strcpy((*elemPes)->dados.cpf_str, formataCpf((*elemPes)->dados.cpf));
    getchar();
    printf("\nSEXO (masculino, feminino ou outro): ");
    fgets((*elemPes)->dados.sexo, 11, stdin);
    strcpy((*elemPes)->dados.sexo, formataString((*elemPes)->dados.sexo));
    printf("\nDATA DE NASCIMENTO (apenas números):");
    printf("\nDIA: ");
    scanf("%hu", &(*elemPes)->dados.dia);
    getchar();
    printf("\nMÊS: ");
    scanf("%hu", &(*elemPes)->dados.mes);
    getchar();
    printf("\nANO: ");
    scanf("%hd", &(*elemPes)->dados.ano);
    getchar();
    printf("\nNATURALIDADE: ");
    fgets((*elemPes)->dados.naturalidade, 50, stdin);
    strcpy((*elemPes)->dados.naturalidade, formataString((*elemPes)->dados.naturalidade));
    printf("\nNOME DO PAI: ");
    fgets((*elemPes)->dados.nome_pai, 100, stdin);
    strcpy((*elemPes)->dados.nome_pai, formataString((*elemPes)->dados.nome_pai));
    printf("\nNOME DA MÃE: ");
    fgets((*elemPes)->dados.nome_mae, 100, stdin);
    strcpy((*elemPes)->dados.nome_mae, formataString((*elemPes)->dados.nome_mae));
}

void leituraDadosEndereco(NO **elemEnd)
{
    printf("\nInforme o seu endereço.\n");
    printf("\nLOGRADOURO: ");
    fgets((*elemEnd)->dados.endereco.logradouro, 50, stdin);
    strcpy((*elemEnd)->dados.endereco.logradouro, formataString((*elemEnd)->dados.endereco.logradouro));
    printf("\nNÚMERO: ");
    scanf("%lu", &(*elemEnd)->dados.endereco.numero);
    getchar();
    printf("\nCOMPLEMENTO: ");
    fgets((*elemEnd)->dados.endereco.complemento, 50, stdin);
    strcpy((*elemEnd)->dados.endereco.complemento, formataString((*elemEnd)->dados.endereco.complemento));
    printf("\nBAIRRO: ");
    fgets((*elemEnd)->dados.endereco.bairro, 50, stdin);
    strcpy((*elemEnd)->dados.endereco.bairro, formataString((*elemEnd)->dados.endereco.bairro));
    printf("\nCIDADE: ");
    fgets((*elemEnd)->dados.endereco.cidade, 50, stdin);
    strcpy((*elemEnd)->dados.endereco.cidade, formataString((*elemEnd)->dados.endereco.cidade));
    printf("\nCEP (apenas números): ");
    scanf("%lu", &(*elemEnd)->dados.endereco.cep_num);
    getchar();
    strcpy((*elemEnd)->dados.endereco.cep_str, formataCep((*elemEnd)->dados.endereco.cep_num));
    printf("\nESTADO: ");
    fgets((*elemEnd)->dados.endereco.estado, 50, stdin);
    strcpy((*elemEnd)->dados.endereco.estado, formataString((*elemEnd)->dados.endereco.estado));
    printf("\nPAÍS: ");
    fgets((*elemEnd)->dados.endereco.pais, 50, stdin);
    strcpy((*elemEnd)->dados.endereco.pais, formataString((*elemEnd)->dados.endereco.pais));
}

void leituraDadosContato(NO **elemCon)
{
    printf("\nInforme os seus dados de contato.\n");
    printf("\nEMAIL: ");
    scanf("%s", (*elemCon)->dados.contato.email);
    printf("\nTELEFONE (apenas números): ");
    printf("\nDDD: ");
    scanf("%hu", &(*elemCon)->dados.contato.ddd);
    getchar();
    printf("\nNÚMERO: ");
    scanf("%lu", &(*elemCon)->dados.contato.numero);
    getchar();
    strcpy((*elemCon)->dados.contato.telefone_str, formataTelefone((*elemCon)->dados.contato.ddd, (*elemCon)->dados.contato.numero));
}

void novoCadastro(NO **raiz)
{
    NO *elemento = (NO *)malloc(sizeof(NO));

    if (elemento != NULL)
    {
        leituraDados(&elemento);
        inserir(raiz, elemento);
        printf("\nCadastro realizado com sucesso!\n");
        pausaJanela();
    }
    else
        printf("\nErro no sistema (falha na alocação do elemento).\n");
}

void inserir(NO **arvBin, NO *novo)
{
    if ((*arvBin) == NULL)
        (*arvBin) = novo;
    else if (novo->dados.cpf > (*arvBin)->dados.cpf)
        inserir(&(*arvBin)->dir, novo);
    else
        inserir(&(*arvBin)->esq, novo);
}

void listagem(NO *elem)
{
    if (elem == NULL)
        return;
    listagem(elem->esq);
    mostraDados(elem);
    listagem(elem->dir);
}

void mostraDados(NO *elem)
{
    printf("\nDados pessoais\n");
    printf("\nNOME: %s\n", elem->dados.nome);
    printf("CPF: %s\n", elem->dados.cpf_str);
    printf("SEXO: %s\n", elem->dados.sexo);
    printf("DATA DE NASCIMENTO: ");
    printf("%hu/", elem->dados.dia);
    (elem->dados.mes < 10
         ? printf("0%hu/", elem->dados.mes)
         : printf("%hu/", elem->dados.mes));
    printf("%hd\n", elem->dados.ano);
    printf("NATURALIDADE: %s\n", elem->dados.naturalidade);
    printf("NOME DO PAI: %s\n", elem->dados.nome_pai);
    printf("NOME DA MÃE: %s\n", elem->dados.nome_mae);
    printf("\nEndereço\n");
    printf("\nLOGRADOURO: %s\n", elem->dados.endereco.logradouro);
    printf("NÚMERO: %lu\n", elem->dados.endereco.numero);
    printf("COMPLEMENTO: %s\n", elem->dados.endereco.complemento);
    printf("BAIRRO: %s\n", elem->dados.endereco.bairro);
    printf("CIDADE: %s\n", elem->dados.endereco.cidade);
    printf("CEP: %s\n", elem->dados.endereco.cep_str);
    printf("ESTADO: %s\n", elem->dados.endereco.estado);
    printf("PAÍS: %s\n", elem->dados.endereco.pais);
    printf("\nContato\n");
    printf("\nEMAIL: %s\n", elem->dados.contato.email);
    printf("TELEFONE: %s\n", elem->dados.contato.telefone_str);
    printf("\n****************************************************\n");
}

char *formataString(char *str)
{
    unsigned short int i = 1;

    str[0] = toupper(str[0]);
    str[strlen(str) - 1] = '\0';

    while (str[i] != '\0')
    {
        if (str[i - 1] == ' ')
            str[i] = toupper(str[i]);
        else
            str[i] = tolower(str[i]);
        i++;
    }
    return str;
}

char *formataCpf(long unsigned int num_cpf)
{
    char *str_cpf = (char *)malloc(15 * sizeof(char));
    strcpy(str_cpf, "000.000.000-00");
    unsigned short int i = 13;

    while (num_cpf > 0)
    {
        if (str_cpf[i] != '.' && str_cpf[i] != '-')
        {
            str_cpf[i] = CONV(num_cpf % 10);
            num_cpf /= 10;
            i--;
        }
        else
        {
            i--;
            continue;
        }
    }
    return str_cpf;
}

char *formataCep(long unsigned int num_cep)
{
    char *str_cep = (char *)malloc(10 * sizeof(char));
    strcpy(str_cep, "00000-000");
    short unsigned int i = 8;

    while (num_cep > 0)
    {
        if (str_cep[i] != '-')
        {
            str_cep[i] = CONV(num_cep % 10);
            num_cep /= 10;
            i--;
        }
        else
        {
            i--;
            continue;
        }
    }
    return str_cep;
}

char *formataTelefone(short unsigned int tel_ddd, long unsigned int tel_num)
{
    char *str_tel = (char *)malloc(15 * sizeof(char));

    strcpy(str_tel, "(00)00000-0000");
    str_tel[1] = CONV(tel_ddd / 10);
    str_tel[2] = CONV(tel_ddd % 10);

    short unsigned int i = 13;

    while (tel_num > 0)
    {
        if (str_tel[i] == '(' || str_tel[i] == ')' || str_tel[i] == '-')
        {
            i--;
            continue;
        }
        else
        {
            str_tel[i] = CONV(tel_num % 10);
            tel_num /= 10;
            i--;
        }
    }
    return str_tel;
}

void exclusaoElemento(NO **raiz)
{
    long unsigned int dado;

    if (raiz != NULL)
    {
        printf("Informe qual elemento você deseja excluir.\n");
        printf("CPF (apenas números): ");
        scanf("%lu", &dado);
        getchar();
        dado = excluir(raiz, dado);
        (dado == 0
             ? printf("\nCPF não encontrado.\n")
             : printf("\nO CPF %s foi excluido.\n", formataCpf(dado)));
    }
    else
        printf("\nNão existem elementos para serem excluidos.\n");
}

long unsigned int excluir(NO **arvBin, long unsigned int num_cpf)
{
    NO *tmp;
    long unsigned int cpf_aux;

    if (*arvBin == NULL)
        return 0;
    if ((*arvBin)->dados.cpf == num_cpf)
    {
        if (grau(*arvBin) == 0) // sem filhos
        {
            cpf_aux = (*arvBin)->dados.cpf;
            free(*arvBin);
            *arvBin = NULL;
        }
        else if (grau(*arvBin) == 1) // 1 filho
        {
            cpf_aux = (*arvBin)->dados.cpf;
            tmp = *arvBin;
            if ((*arvBin)->esq != NULL)
                *arvBin = (*arvBin)->esq;
            else
                *arvBin = (*arvBin)->dir;
            free(tmp);
        }
        else // 2 filhos
        {
            cpf_aux = (*arvBin)->dados.cpf;
            tmp = menor((*arvBin)->esq);
            (*arvBin)->dados = tmp->dados;
            excluir(&((*arvBin)->esq), tmp->dados.cpf);
        }

        return cpf_aux;
    }
    if (num_cpf < (*arvBin)->dados.cpf)
        return excluir(&((*arvBin)->esq), num_cpf);
    return excluir(&((*arvBin)->dir), num_cpf);
}

long unsigned int tamanhoArvore(NO *elem)
{
    return (elem == NULL ? 0 : 1 + tamanhoArvore(elem->esq) + tamanhoArvore(elem->dir));
}

void mostraTamanhoArvore(NO *raiz)
{
    long unsigned int tam = tamanhoArvore(raiz);
    
    if (tam == 0)
        printf("*Nenhum elemento cadastrado.*\n");
    else if (tam == 1)
        printf("*1 elemento cadastrado.*\n");
    else
        printf("*%lu elementos cadastrados.*\n", tam);
}

short unsigned int grau(NO *elem)
{
    if ((elem->esq == NULL) && (elem->dir == NULL))
        return 0;
    if ((elem->esq != NULL) && (elem->dir != NULL))
        return 2;
    return 1;
}

NO *menor(NO *elem)
{
    if ((elem == NULL) || (elem->dir == NULL))
        return elem;
    menor(elem->dir);
}

void pesquisaElemento(NO *elem, long unsigned int cpf_busca)
{
    if (elem == NULL)
        printf("CPF não encontrado.\n");
    else if (elem->dados.cpf == cpf_busca)
        mostraDados(elem);
    else if (elem->dados.cpf > cpf_busca)
        pesquisaElemento(elem->esq, cpf_busca);
    else
        pesquisaElemento(elem->dir, cpf_busca);
}

void limpaJanela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausaJanela()
{
#ifdef _WIN32
    system("pause");
#else
    system("read -p 'Aperte Enter Para Continuar...' var");
#endif
}