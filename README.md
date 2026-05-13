# 📂 Estruturas de Dados em C

Este repositório contém a implementação das principais Estruturas de Dados fundamentais, desenvolvidas de forma modular em linguagem C. O objetivo é servir como uma biblioteca de consulta e portfólio de algoritmos clássicos.

> **Status:** 🚀 Concluído (Lista, Pilha, Fila, BST)

## 🏗️ Estrutura do Projeto

O projeto segue o padrão de **Tipos Abstratos de Dados (TADs)**, garantindo que a implementação interna fique oculta do usuário final através do encapsulamento.

```text
.
├── include/           # Cabeçalhos (.h) - Interfaces
├── src/               # Implementações (.c) - Lógica
├── tests/             # Programas de teste (main.c)
└── .gitignore         # Arquivos ignorados pelo Git
```

## 📊 Tabela de Complexidade (Big O)

| Estrutura | Inserção | Remoção | Busca | Tipo |
| :--- | :---: | :---: | :---: | :--- |
| **Lista Encadeada** | $O(1)$ | $O(n)$ | $O(n)$ | Linear |
| **Pilha (Stack)** | $O(1)$ | $O(1)$ | $O(n)$ | LIFO |
| **Fila (Queue)** | $O(1)$ | $O(1)$ | $O(n)$ | FIFO |
| **Árvore (BST)** | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | Hierárquica |

*Obs: As complexidades para Árvore de Busca Binária referem-se ao caso médio (árvore balanceada). No pior caso, as operações podem chegar a $O(n)$.*

---

## 🛠️ Como Compilar e Rodar

Para compilar o projeto manualmente utilizando o **GCC**, navegue até a raiz do projeto e execute (exemplo para a Pilha):

```bash
gcc src/stack.c tests/main.c -Iinclude -o teste_pilha
./teste_pilha
```
> Nota: A flag -Iinclude é essencial para que o compilador localize os arquivos .h na pasta correta. Lembre-se de comentar os testes das outras estruturas no código do arquivo `main.c` para não quebrar.

## 📝 Estruturas Implementadas

### 1. Lista Encadeada Simples
Estrutura linear composta por nós que apontam para o próximo elemento. É a base fundamental para entender alocação dinâmica e a manipulação de ponteiros em C.

### 2. Pilha (Stack)
Implementada seguindo a política **LIFO** (*Last-In, First-Out*). As operações de inserção (`push`) e remoção (`pop`) são otimizadas para ocorrerem sempre no topo da estrutura, garantindo máxima performance.

### 3. Fila (Queue)
Segue o princípio **FIFO** (*First-In, First-Out*). Esta implementação utiliza ponteiros duplos — início (`head`) e fim (`tail`) — para garantir que tanto a entrada quanto a saída de dados ocorram em tempo constante.

### 4. Árvore Binária de Busca (BST)
Uma estrutura hierárquica onde cada nó possui no máximo dois filhos. Os elementos são organizados de modo que valores menores fiquem à esquerda e maiores à direita, otimizando drasticamente o tempo de busca e permitindo percursos ordenados.

---
## 👨‍💻 Autor

Desenvolvido com ☕ e C por Francisco Irlan de Oliveira Barros.