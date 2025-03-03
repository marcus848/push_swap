#!/bin/bash

# Inicializa variáveis para armazenar os melhores e piores resultados
best=9999999
worst=0
num_tests=1000

echo "Testando push_swap $num_tests vezes com 500 números aleatórios..."

for ((i = 1; i <= num_tests; i++)); do
    ARG=$(seq -10000 10000 | shuf -n 500)  # Gera uma sequência aleatória de 500 números
    INSTRUCTIONS=$(./push_swap $ARG | wc -l)  # Conta o número de instruções

    # Atualiza os melhores e piores resultados
    if [ "$INSTRUCTIONS" -lt "$best" ]; then
        best=$INSTRUCTIONS
    fi

    if [ "$INSTRUCTIONS" -gt "$worst" ]; then
        worst=$INSTRUCTIONS
    fi

    echo "Teste $i: $INSTRUCTIONS instruções"
done

# Exibe os resultados finais
echo "--------------------------------------"
echo "Melhor resultado: $best instruções"
echo "Pior resultado: $worst instruções"

