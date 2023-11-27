# simpleMultiGPU - Simple Multi-GPU


## Integrantes:
Rubi Tatiana Utima Echeverry - 2190032


Santiago Bolaños - 

## Descripcion

Esta aplicación demuestra cómo utilizar la nueva API CUDA 4.0 para la gestión del contexto CUDA y el acceso multiproceso para ejecutar kernels CUDA en varias GPU.

## Arquitecturas SM compatibles

[SM 5.0 ](https://developer.nvidia.com/cuda-gpus)  [SM 5.2 ](https://developer.nvidia.com/cuda-gpus)  [SM 5.3 ](https://developer.nvidia.com/cuda-gpus)  [SM 6.0 ](https://developer.nvidia.com/cuda-gpus)  [SM 6.1 ](https://developer.nvidia.com/cuda-gpus)  [SM 7.0 ](https://developer.nvidia.com/cuda-gpus)  [SM 7.2 ](https://developer.nvidia.com/cuda-gpus)  [SM 7.5 ](https://developer.nvidia.com/cuda-gpus)  [SM 8.0 ](https://developer.nvidia.com/cuda-gpus)  [SM 8.6 ](https://developer.nvidia.com/cuda-gpus)  [SM 8.7 ](https://developer.nvidia.com/cuda-gpus)  [SM 8.9 ](https://developer.nvidia.com/cuda-gpus)  [SM 9.0 ](https://developer.nvidia.com/cuda-gpus)


## Arquitectura de CPU compatible

x86_64, ppc64le, armv7l

## Prerequisitos

Descargue e instale el [CUDA Toolkit 12.3](https://developer.nvidia.com/cuda-downloads) para su plataforma correspondiente.

## Construir y ejecutar

### Windows
Los ejemplos de Windows se crean utilizando el IDE de Visual Studio. Los archivos de solución (.sln) se proporcionan para cada versión compatible de Visual Studio, con el formato:
```
*_vs<versión>.sln - para Visual Studio <versión>
```
Cada muestra individual tiene su propio conjunto de archivos de solución en su directorio:

Para crear/examinar todas las muestras a la vez, se deben utilizar los archivos de solución completos. Para crear/examinar una sola muestra, se deben utilizar los archivos de solución de muestra individuales.


### Ejecucion Pasiva
Para ejecutar el programa en modo pasivo utilizando sbatch, sigue estos pasos:

#### Creación de un Archivo de Script de Trabajo

Crea un archivo de script de trabajo, por ejemplo, run_cuda.sh, utilizando un editor de texto. Agrega el siguiente contenido al archivo:

```bash
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
```
### Ejecucion en PC Local con 1 GPU

![1gpu](https://github.com/Rubi221/IntroPP2190032/assets/98795896/c2c720b8-146d-498f-9457-a4ce68f88ec8)


### Ejecucion en GUANE-1 con 8 GPU's
![Captura de pantalla 2023-11-27 072752](https://github.com/Rubi221/IntroPP2190032/assets/98795896/c0b4a600-817c-4152-8f06-8e1a6a2d195e)


