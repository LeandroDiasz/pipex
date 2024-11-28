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
```
Para executar o programa:
```bash
./pipex infile "comando1" "comando2" outfile
```
Por exemplo:
```bash
./pipex input.txt "cat" "wc -l" output.txt
```
Isso replicará o comportamento do comando shell:
```bash
< input.txt cat | wc -l > output.txt
```
## 📖 Conceitos Envolvidos
- Manipulação de arquivos com open e close.
- Redirecionamento de entrada e saída com dup2.
- Comunicação entre processos com pipe.
- Criação de processos filhos com fork.
- Execução de comandos com execve.
## 🎯 Resultado
Ao finalizar este projeto, você terá uma compreensão mais sólida de como funciona a comunicação entre processos e o redirecionamento de entrada/saída no Unix, fundamentos essenciais para os próximos desafios na 42.
