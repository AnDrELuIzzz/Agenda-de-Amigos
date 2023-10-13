
#include "conection.h"
#include <stdio.h>
MYSQL *connect_to_mysql(const char *host, const char *user, const char *password, const char *dbname, unsigned int port)
{
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL)
    {
        fprintf(stderr, "mysql_init failed\n");
        return NULL;
    }

    if (mysql_real_connect(conn, host, user, password, dbname, port, NULL, 0) == NULL)
    {
        fprintf(stderr, "mysql_real_connect failed. Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    return conn;
}

void close_mysql_connection(MYSQL *conn)
{
    mysql_close(conn);
}

void inserir_contato(MYSQL *conn, const char *nome, const char *telefone, const char *email)
{
    char query[200];
    sprintf(query, "INSERT INTO contatos (nome, telefone, email) VALUES ('%s', '%s', '%s')", nome, telefone, email);

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "Erro ao inserir contato: %s\n", mysql_error(conn));
    }
    else
    {
        printf("Contato inserido com sucesso.\n");
    }
}

void buscar_contato(MYSQL *conn, const char *procurado)
{
    char query[200];
    sprintf(query, "SELECT * FROM contatos WHERE nome LIKE '%%%s%%'", procurado);

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "Erro ao buscar contato: %s\n", mysql_error(conn));
        return;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL)
    {
        fprintf(stderr, "Erro ao obter resultado da consulta: %s\n", mysql_error(conn));
        return;
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

void excluir_contato(MYSQL *conn, const char *procurado)
{
    char query[200];
    sprintf(query, "DELETE FROM contatos WHERE nome LIKE '%%%s%%'", procurado);

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "Erro ao excluir contato: %s\n", mysql_error(conn));
    }
    else
    {
        printf("Contato(s) excluído(s) com sucesso.\n");
    }
}

void atualizar_contato(MYSQL *conn, const char *nome_antigo, const char *novo_nome, const char *novo_telefone, const char *novo_email)
{
    char query[200];
    sprintf(query, "UPDATE contatos SET nome = '%s', telefone = '%s', email = '%s' WHERE nome LIKE '%%%s%%'",
            novo_nome, novo_telefone, novo_email, nome_antigo);

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "Erro ao atualizar contato: %s\n", mysql_error(conn));
    }
    else
    {
        printf("Contato atualizado com sucesso.\n");
    }
}