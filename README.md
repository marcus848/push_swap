# push_swap

## Objetivo do Projeto

O **push_swap** é um projeto da 42 School que consiste em ordenar uma sequência de números inteiros utilizando apenas um conjunto limitado de operações nas pilhas A e B. O desafio está em produzir a sequência de instruções mais curta possível. Este repositório recebeu nota máxima e implementa todas as funcionalidades básicas e bônus.

## Estrutura de Dados

As pilhas são implementadas através de uma **lista duplamente encadeada circular**. Cada nó é representado pela estrutura `t_stack` com ponteiros `next` e `prev`, permitindo rotações em ambas as direções:

```c
typedef struct s_stack
{
        long                    nbr;
        struct s_stack  *next;
        struct s_stack  *prev;
}       t_stack;
```

A função `add_node` insere novos elementos preservando o formato circular da lista.

## Operações Implementadas

Todas as operações exigidas pelo projeto estão presentes:

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

Os protótipos encontram-se em `include/push_swap.h` e as implementações estão nos arquivos `moves_simple.c`, `moves_rotate.c` e `moves_specials.c`.

## Algoritmo: Método Turk

A ordenação principal utiliza o **Método Turk**, uma estratégia que empurra elementos de A para B calculando o movimento mais barato em cada passo. O fluxo básico pode ser observado em `src/turkish.c`:

```c
start_turkish(turk);
while ((*turk)->stats.a.size > 3)
{
        vars = find_cheap_to_b(turk);
        moves = get_moves(&vars, (*turk)->stats.a.size, (*turk)->stats.b.size);
        execute_moves(turk, &moves, pb);
}
sort_three_numbers((*turk));
...
while ((*turk)->stats.a.size < (*turk)->size)
{
        vars = find_right_position_a(turk);
        ...
        moves = get_moves(&vars, (*turk)->stats.a.size, (*turk)->stats.b.size);
        execute_moves(turk, &moves, pa);
}
last_rotate(turk);
```

O processo se divide em três etapas principais:

1. **Preparação** - Duas chamadas a `pb` movem números para a pilha B, iniciando o algoritmo.
2. **Distribuição** - Enquanto A possui mais de três elementos, o programa identifica o melhor candidato a ser enviado para B.
3. **Inserção** - Após ordenar A com três elementos, cada valor de B é recolocado na posição correta de A.

Essas operações de rotação e inserção são calculadas levando em conta a posição atual dos elementos e qual combinação de `ra`, `rb`, `rr`, `rra` ou `rrb` resulta no menor número de movimentos.

## Compilação

Para compilar o programa principal:

```bash
make
```

O executável resultante é `push_swap`.

Para compilar também o checker (bônus):

```bash
make bonus
```

## Uso

Execute o programa passando os números a serem ordenados:

```bash
./push_swap 3 2 1
```

Também é possível fornecer os valores entre aspas:

```bash
./push_swap "3 2 1 4"
```

O programa escreverá na saída padrão a sequência de operações para ordenar a pilha.

## Checker Bônus

O executável `checker` recebe os mesmos argumentos e espera, pela entrada padrão, uma lista de movimentos para validar. Caso a sequência esteja correta, imprime `OK`; caso contrário, `KO`:

```bash
./push_swap 2 1 3 | ./checker 2 1 3
```

O código da ferramenta está em `apps/checker.c`.

## Exemplos de Uso

```bash
$ ./push_swap 2 1 3
sa

$ ./push_swap "4 1 3 2" | ./checker "4 1 3 2"
OK
```

## Observações

A implementação procura minimizar ao máximo o número de instruções, além de utilizar apenas bibliotecas permitidas pela 42. A estrutura em lista circular agiliza as rotações sem custos extras de alocação ou cópia de dados.

