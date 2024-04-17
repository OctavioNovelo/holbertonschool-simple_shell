#!/bin/bash

# Define la carpeta donde se encuentran tus archivos .c y .h
DIRECTORY="./"

# Busca archivos .c y .h y aplica betty a cada uno
find "$DIRECTORY" -type f \( -name "*.c" -o -name "*.h" \) -exec betty {} \;
