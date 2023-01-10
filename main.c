#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

struct ficha
{
    char nome[40];
    char telefone[20];
    char email[30];
};

typedef struct ficha FICHA;

int procurarRec(char procurado[], FICHA vetor[], int inicio, int num_fichas)
{
    if (inicio >= num_fichas)
        return -1; // nao achei... Base
    if (strstr(vetor[inicio].nome, procurado) != NULL)
        return inicio;
    return procurarRec(procurado, vetor, inicio + 1, num_fichas);
}

int procurar(char procurado[], FICHA vetor[], int num_fichas)
{
    int i;
    char resposta[10];
    for (i = 0; i < num_fichas; i++)
    {
        if (strstr(vetor[i].nome, procurado) != NULL)
        {
            printf("Nome: %s, telefone: %s -> é este? (S/N)\n", vetor[i].nome, vetor[i].telefone);
            gets(resposta);
            if (resposta[0] == 's' || resposta[0] == 'S')
                return i;
        }
    }
    return -1; // índice inexistente == elemento não encontrado
}

int main()
{
    FICHA agenda[100];
    int fichas_existentes = 0, proxima = 0;
    char opcao[10] = "0";
    setlocale(LC_ALL, "Portuguese");

    while (opcao[0] != '6')
    {
        printf("\nEntre com a opção desejada:\n");
        printf("\n1) Inserir ficha:");
        printf("\n2) Procurar por nome:");
        printf("\n3) Listar toda a base:");
        printf("\n4) Excluir por nome:");
        printf("\n5) Alterar");
        printf("\n6) Sair\n\n");
        gets(opcao);

        if (opcao[0] == '1') // inserir
        {
            printf("\nEntre com um nome:");
            gets(agenda[proxima].nome);
            printf("\nEntre com um telefone:");
            gets(agenda[proxima].telefone);
            printf("\nEntre com um e-mail:");
            gets(agenda[proxima].email);
            fichas_existentes++;
            proxima++;
        }
        if (opcao[0] == '2') // procurar
        {
            char procurado[40];
            printf("\nEntre com o nome procurado:");
            gets(procurado);

            int i = procurar(procurado, agenda, fichas_existentes);
            if (i != -1) // encontrei
                printf("\n\nO telefone de %s é %s e o e-mail é %s\n", agenda[i].nome, agenda[i].telefone, agenda[i].email);
            else
                printf("\n\nNome não encontrado\n");
        }
        if (opcao[0] == '3') // listar tudo
        {
            printf("\n\n");
            int i;
            for (i = 0; i < fichas_existentes; i++)
            {
                printf("O telefone de %s é %s e o e-mail é %s\n", agenda[i].nome, agenda[i].telefone, agenda[i].email);
            }
            if (fichas_existentes == 0)
                printf("A base de dados está vazia!\n");
        }
        if (opcao[0] == '4') // excluir
        {
            char procurado[40];
            printf("\nEntre com o nome que sera excluído:");
            gets(procurado);

            int i = procurar(procurado, agenda, fichas_existentes);
            if (i != -1) // encontrei
            {
                printf("\n\nO telefone de %s é %s e o e-mail é %s. Esta ficha será removida\n", agenda[i].nome, agenda[i].telefone, agenda[i].email);
                agenda[i] = agenda[fichas_existentes - 1];
                fichas_existentes--;
                proxima--;
            }
            else
                printf("\n\nNome não encontrado\n");
        }
        if (opcao[0] == '5') // alterar
        {
            char procurado[40];
            printf("\nEntre com o nome da pessoa que terá dados alterados:");
            gets(procurado);

            int i = procurar(procurado, agenda, fichas_existentes);
            if (i != -1) // encontrei
            {
                char aux[50];
                printf("Nome: %s, telefone: %s, e-mail: %s\n", agenda[i].nome, agenda[i].telefone, agenda[i].email);
                printf("\nEntre com o nome (ENTER para manter o atual): ");
                gets(aux);
                if (aux[0] != '\0')
                    strcpy(agenda[i].nome, aux);
                printf("\nEntre com um telefone (ENTER para manter o atual): ");
                gets(aux);
                if (aux[0] != '\0')
                    strcpy(agenda[i].telefone, aux);
                printf("\nEntre com um e-mail (ENTER para manter o atual): ");
                gets(aux);
                if (aux[0] != '\0')
                    strcpy(agenda[i].email, aux);
            }
            else
                printf("\n\nNome não encontrado\n");
        }
    }
    return 0;
}
