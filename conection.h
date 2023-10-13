#include <mysql/mysql.h>
MYSQL *connect_to_mysql(const char *host, const char *user, const char *password, const char *dbname, unsigned int port);
void close_mysql_connection(MYSQL *conn);
void inserir_contato(MYSQL *conn, const char *nome, const char *telefone, const char *email);
void buscar_contato(MYSQL *conn, const char *procurado);
void excluir_contato(MYSQL *conn, const char *procurado);
void atualizar_contato(MYSQL *conn, const char *nome_antigo, const char *novo_nome, const char *novo_telefone, const char *novo_email);
