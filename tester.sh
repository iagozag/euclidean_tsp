#!/bin/bash

# Caminho para o executável do seu programa
EXECUTAVEL="./main"

# Pasta com os arquivos de entrada
INPUT_DIR="examples"

# # Verifica se o programa existe
# if [[ ! -f $EXECUTAVEL ]]; then
#     echo "Erro: o executável '$EXECUTAVEL' não foi encontrado."
#     exit 1
# fi

# Verifica se a pasta de entrada existe
if [[ ! -d $INPUT_DIR ]]; then
    echo "Erro: a pasta '$INPUT_DIR' não foi encontrada."
    exit 1
fi

# Itera sobre os arquivos na pasta e executa o programa
for FILE in "$INPUT_DIR"/*; do
    if [[ -f $FILE ]]; then
        # Extrai apenas o nome do arquivo
        FILE_NAME=$(basename "$FILE")

        echo "Executando o programa para o arquivo: $FILE_NAME"
        $EXECUTAVEL "$FILE_NAME"
        echo "--------------------------------------"
    fi
done
