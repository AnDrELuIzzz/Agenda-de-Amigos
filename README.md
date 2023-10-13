# Agenda de Contatos

Este é um programa simples em C para gerenciar uma agenda de contatos utilizando um banco de dados MySQL.

## Funcionalidades

O programa oferece as seguintes funcionalidades:

1. **Inserir Contato**: Permite inserir informações de um novo contato na agenda.
2. **Procurar por Nome**: Busca por contatos na agenda com base no nome.
3. **Listar Toda a Base**: Exibe todos os contatos existentes na agenda.
4. **Excluir por Nome**: Permite excluir um ou mais contatos da agenda com base no nome.
5. **Alterar Contato**: Possibilita alterar as informações de um contato na agenda.

## Pré-requisitos

- Compilador C (gcc)
- Biblioteca MySQL (libmysqlclient-dev)
- MySQL Server instalado e em execução

## Compilação

Para compilar o programa, utilize o seguinte comando:

gcc -o agenda main.c -lmysqlclien

## Execução

Após a compilação, execute o programa com o seguinte comando:

./main


## Como Usar

1. Ao executar o programa, você será apresentado a um menu com opções numeradas.
2. Escolha a opção desejada digitando o número correspondente e pressionando Enter.
3. Siga as instruções para executar a funcionalidade selecionada.

## Observações

- O programa utiliza uma tabela chamada `contatos` no banco de dados MySQL para armazenar as informações dos contatos.
- Certifique-se de configurar as variáveis de conexão no arquivo `variaveis.h` antes de compilar o programa.

## Planos Futuros

- **Sistema de Autenticação**: Pretendo implementar um sistema de autenticação para garantir o acesso seguro ao programa.
- **Interface Gráfica com Glade e GTK**: Está nos planos criar uma interface gráfica para tornar a interação com o programa mais amigável usando Glade e GTK.

---