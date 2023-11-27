#!/bin/bash
#SBATCH --job-name=cuda_example       # Nombre del trabajo
#SBATCH --output=cuda_example.out     # Nombre del archivo de salida
#SBATCH --error=cuda_example.err      # Nombre del archivo de errores
#SBATCH --partition=gpu                # Partición en la que deseas ejecutar tu trabajo
#SBATCH --gres=gpu:1                   # Número de GPUs que necesitas
#SBATCH --nodes=1                      # Número de nodos
#SBATCH --ntasks-per-node=1            # Número de tareas por nodo
#SBATCH --cpus-per-task=1              # Número de hilos por tarea
#SBATCH --time=00:10:00                # Tiempo máximo de ejecución (HH:MM:SS)

# Cargar el entorno de CUDA
module load devtools/cuda/8.0

# Navegar al directorio de trabajo
cd /home/class/2023_2/rtautimae/cuda

# Compilar el programa CUDA
make

# Ejecutar el programa
./simpleMultiGPU
