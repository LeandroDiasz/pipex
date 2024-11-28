# Pipex

## 📜 Descrição
O projeto **Pipex** simula o funcionamento do comando `|` (pipe) no shell. Ele é um exercício fundamental para aprender sobre processos, redirecionamento de entrada e saída, e manipulação de arquivos em sistemas Unix.

## 🚀 Objetivo
Implementar um programa em C que replique o comportamento do pipe, permitindo a comunicação entre diferentes comandos. Além disso, reforça os conceitos de chamadas de sistema como `fork`, `execve`, `dup2`, e `pipe`.

## 📂 Estrutura do Projeto
- **pipex.c**: Arquivo principal do projeto, responsável por gerenciar o fluxo do programa.
- **utils.c**: Funções auxiliares para manipulação de strings e caminhos.
- **Makefile**: Automação de compilação do programa.

## 🛠️ Execução
Para compilar o projeto:
```bash
make
