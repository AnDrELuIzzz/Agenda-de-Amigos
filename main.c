
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "variaveis.h"
#include "conection.c"
#include <mysql/mysql.h>

struct ficha
{
    char nome[40];
    char telefone[20];
    char email[30];
};

typedef struct ficha FICHA;



int main()
{
    MYSQL *conn = connect_to_mysql(HOST, USER, SENHA, BD, PORT);
    if (conn == NULL)
    {
        fprintf(stderr, "Erro ao conectar ao banco de dados.\n");
        return EXIT_FAILURE;
    }

    FICHA agenda[100];
    int fichas_existentes = 0;
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

        if (opcao[0] == '1')
        { // inserir
            printf("\nEntre com um nome:");
            gets(agenda[fichas_existentes].nome);
            printf("\nEntre com um telefone:");
            gets(agenda[fichas_existentes].telefone);
            printf("\nEntre com um e-mail:");
            gets(agenda[fichas_existentes].email);
            inserir_contato(conn, agenda[fichas_existentes].nome, agenda[fichas_existentes].telefone, agenda[fichas_existentes].email);
            fichas_existentes++;
        }
        else if (opcao[0] == '2')
        { // procurar
            char procurado[40];
            printf("\nEntre com o nome procurado:");
            gets(procurado);
            buscar_contato(conn, procurado);
        }
        else if (opcao[0] == '3')
        {                             // listar tudo
            buscar_contato(conn, ""); // Retorna todos os contatos
        }
        else if (opcao[0] == '4')
        { // excluir
            char procurado[40];
            printf("\nEntre com o nome que sera excluído:");
            gets(procurado);
            excluir_contato(conn, procurado);
        }
        else if (opcao[0] == '5')
        {
            // Alterar
            char procurado[40];
            printf("\nEntre com o nome da pessoa que terá dados alterados:");
            gets(procurado);

            // Buscar o contato
            buscar_contato(conn, procurado);

            // Encontrar o índice do contato a ser atualizado
            int i;
            for (i = 0; i < fichas_existentes; i++)
            {
                if (strcmp(agenda[i].nome, procurado) == 0)
                {
                    break; // Encontrou o contato
                }
            }

            if (i < fichas_existentes) // Verifica se encontrou o contato
            {
                char novo_nome[40], novo_telefone[20], novo_email[30];

                printf("Nome atual: %s\n", agenda[i].nome);
                printf("Novo nome (ou pressione ENTER para manter o atual): ");
                gets(novo_nome);

                printf("Telefone atual: %s\n", agenda[i].telefone);
                printf("Novo telefone (ou pressione ENTER para manter o atual): ");
                gets(novo_telefone);

                printf("Email atual: %s\n", agenda[i].email);
                printf("Novo email (ou pressione ENTER para manter o atual): ");
                gets(novo_email);

                atualizar_contato(conn, agenda[i].nome, novo_nome[0] ? novo_nome : agenda[i].nome, novo_telefone[0] ? novo_telefone : agenda[i].telefone, novo_email[0] ? novo_email : agenda[i].email);
            }
            else
            {
                printf("\n\nNome não encontrado\n");
            }
        }
    }

    close_mysql_connection(conn);
    return 0;
}