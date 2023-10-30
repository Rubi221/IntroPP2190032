Trabajo en parerjas:
### Integrantes:
Rubi Tatiana Utima Echeverry - 2190032

Andres Felipe Valenzuela - 2190035

# Guía de Ejecución del Programa de Resolución de la Ecuación del Calor con MPI


La siguiente guía proporciona instrucciones detalladas para ejecutar un programa en C que resuelve la Ecuación del Calor en un dominio 2D utilizando el modelo de programación paralela MPI (Message Passing Interface). Esta simulación se utiliza para modelar la distribución de temperatura en una placa 2D a lo largo del tiempo.

## Contenido de los Códigos
Dentro del repositorio podemos encontrar varios documentos que hacen parte de la solucion, a continuacion se explica el contenido de cada uno:

#### Codigo principal
- `main.c`: Este archivo contiene el programa principal que configura y controla la ejecución.
  desempeña un papel fundamental en el control y la ejecución de la simulación del solucionador de la ecuación de calor en un dominio bidimensional. Comienza por definir variables cruciales, como la constante de difusión, los campos que almacenan la temperatura actual y previa, los pasos de tiempo, los intervalos para generar salidas, así como información relacionada con la paralelización mediante MPI.

#### Codigos complementarios
- `core.c`: Este archivo implementa la lógica principal para resolver la Ecuación del Calor.
- `heat.h`: Este es el archivo de cabecera que define estructuras y prototipos de funciones.
- `io.c`: Este archivo contiene funciones para leer y escribir datos.
- `pngwriter.c` y `pngwriter.h`: Proporcionan funciones para escribir resultados en archivos PNG.
- `setup.c`: Contiene funciones para la inicialización del programa.
- `utilities.c`: Funciones utilitarias para la gestión de campos de temperatura y matrices.

## Instrucciones para la compilacion

### Paso 1: Acceso al Entorno MPI

Antes de ejecutar el programa, asegúrate de estar en un entorno que admita MPI. Puedes iniciar un entorno MPI con un comando como el siguiente:

```bash
srun -n 24 --pty /bin/bash
```	

### Paso 2: Carga de Módulos Necesarios

Carga los módulos necesarios para MPI. Por ejemplo, puedes cargar el módulo OpenMPI con el siguiente comando:

```bash
module load devtools/mpi/openmpi/3.1.4
```

### Paso 3: Limpieza

Para compilar el programa, utiliza el archivo Makefile proporcionado. Primero, puedes limpiar los archivos temporales generados previamente:

```bash
make clean
```
### Paso 4: Compilación

Luego, compila el código con el siguiente comando:

```bash
make
```
![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/b440a9ea-071a-43cd-8101-591a062077b9)

## Opciones de ejecucion
### Ejecucion Interactiva
Para poner en marcha el programa interactivamente y personalizar la simulación de la ecuación de calor en 2D, utilizamos el comando mpirun. A continuación, se detallan diversas opciones para ejecutar el programa con distintas condiciones iniciales y parámetros de tiempo. Asegúrate de haber seguido las instrucciones previas para compilar el programa.

#### Valores Predeterminados: Comenzando con la Simulación Básica
Ejecuta el programa con los valores predeterminados mediante el siguiente comando:

```bash
mpirun -np 8 ./heat_mpi
```
Este comando iniciará la simulación con los valores estándar para el campo inicial y los parámetros de tiempo.

#### Campo Inicial desde un Archivo: Importando una Configuración Personalizada

Si deseas utilizar una configuración de campo inicial personalizada, puedes hacerlo a través de un archivo de entrada. Por ejemplo botella.dat, ejecuta de la siguiente manera:

```bash
mpirun -np 8 ./heat_mpi botella.dat
```

#### Campo Inicial desde un Archivo y Pasos de Tiempo: Control Preciso

Para especificar tanto el campo inicial desde un archivo como el número exacto de pasos de tiempo, utiliza el siguiente formato:

```bash
mpirun -np 8 ./heat_mpi botella.dat 1000
```

Con esta instrucción, cargarás el campo inicial desde botella.dat y llevarás a cabo una simulación con precisamente 1000 pasos de tiempo.

#### Dimensiones y Pasos de Tiempo Personalizados: Diseña tu Simulación

Si deseas definir dimensiones personalizadas para el dominio (ancho y alto) y el número de pasos de tiempo, puedes hacerlo de la siguiente manera:

```bash
mpirun -np 8 ./heat_mpi [ANCHO] [ALTO] [PASOS]
```

### Ejecucion Pasiva
Para ejecutar el programa en modo pasivo utilizando sbatch y garantizar que se cargue el módulo MPI recomendado antes de la ejecución, sigue estos pasos:

#### Paso 1: Creación de un Archivo de Script de Trabajo

Crea un archivo de script de trabajo, por ejemplo, run_heat_mpi.sh, utilizando un editor de texto. Agrega el siguiente contenido al archivo:

```bash
#!/bin/bash
#SBATCH --job-name=heat_mpi_job   # Nombre del trabajo
#SBATCH --ntasks=8               # Número total de tareas MPI
#SBATCH --nodes=2                # Número de nodos
#SBATCH --cpus-per-task=1        # Número de hilos de CPU por tarea
#SBATCH --output=heat_mpi_output.txt

# Carga del módulo MPI recomendado
module load devtools/mpi/openmpi/3.1.4

# Ruta al ejecutable y argumentos
EXECUTABLE=./heat_mpi
INPUT_FILE=botella.dat
NUM_STEPS=1000

# Ejecución del programa con MPI
mpirun -np 8 ./heat_mpi
```

Asegúrate de ajustar las rutas y los valores de acuerdo a tus necesidades.
Con esta guía revisada, deberías poder ejecutar el programa de resolución de la Ecuación del Calor con MPI de manera efectiva. 


## Ejecucion y Resultados

#### Pruebas sin mejoras:

#### Pruebas con mejoras:

