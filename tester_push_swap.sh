#!/bin/bash

# Inicializa variáveis para armazenar os melhores e piores resultados
best=9999999
worst=0
num_tests=100
count_above_error=0  # Contador para execuções acima de 5500 movimentos
sum=0  # Para armazenar a soma total das instruções
numbers=500
max_moviments=5500

echo "Testando push_swap $num_tests vezes com $numbers números aleatórios..."

for ((i = 1; i <= num_tests; i++)); do
    ARG=$(seq -10000 10000 | shuf -n $numbers)  # Gera uma sequência aleatória de 100 números
    INSTRUCTIONS=$(./push_swap $ARG | wc -l)  # Conta o número de instruções

    # Se INSTRUCTIONS estiver vazio, pula este teste
    if [[ -z "$INSTRUCTIONS" ]]; then
        echo "Erro no Teste $i: push_swap não retornou saída válida!"
        continue
    fi

    # Atualiza os melhores e piores resultados
    if [ "$INSTRUCTIONS" -lt "$best" ]; then
        best=$INSTRUCTIONS
    fi

    if [ "$INSTRUCTIONS" -gt "$worst" ]; then
        worst=$INSTRUCTIONS
    fi

    # Conta quantas vezes teve mais de 5500 movimentos
    if [ "$INSTRUCTIONS" -gt "$max_moviments" ]; then
        ((count_above_error++))
    fi

    # Soma os movimentos para calcular a média
    sum=$((sum + INSTRUCTIONS))

    echo "Teste $i: $INSTRUCTIONS instruções"
done

# Evita erro de divisão por zero
if [ "$num_tests" -gt 0 ]; then
    media=$(awk "BEGIN {print $sum / $num_tests}")
else
    media=0
fi

# Exibe os resultados finais
echo "--------------------------------------"
echo "Melhor resultado: $best instruções"
echo "Pior resultado: $worst instruções"
echo "Quantidade de testes acima de $max_moviments movimentos: $count_above_error"
echo "Média final: $media instruções"

