Trabajo en parerjas:
###Integrantes:
Rubi Tatiana Utima Echeverry - 2190032
Andres Felipe Valenzuela - 2190035

#Guía de Ejecución del Programa de Resolución de la Ecuación del Calor con MPI


La siguiente guía proporciona instrucciones detalladas para ejecutar un programa en C que resuelve la Ecuación del Calor en un dominio 2D utilizando el modelo de programación paralela MPI (Message Passing Interface). Esta simulación se utiliza para modelar la distribución de temperatura en una placa 2D a lo largo del tiempo.

## Contenido de los Códigos
Dentro del repositorio podemos encontrar varios documentos que hacen parte de la solucion, a continuacion se explica el contenido de cada uno:

####Codigo principal
- `main.c`: Este archivo contiene el programa principal que configura y controla la ejecución.
  desempeña un papel fundamental en el control y la ejecución de la simulación del solucionador de la ecuación de calor en un dominio bidimensional. Comienza por definir variables cruciales, como la constante de difusión, los campos que almacenan la temperatura actual y previa, los pasos de tiempo, los intervalos para generar salidas, así como información relacionada con la paralelización mediante MPI.


- `core.c`: Este archivo implementa la lógica principal para resolver la Ecuación del Calor.
- `heat.h`: Este es el archivo de cabecera que define estructuras y prototipos de funciones.
- `io.c`: Este archivo contiene funciones para leer y escribir datos.
- `pngwriter.c` y `pngwriter.h`: Proporcionan funciones para escribir resultados en archivos PNG.
- `setup.c`: Contiene funciones para la inicialización del programa.
- `utilities.c`: Funciones utilitarias para la gestión de campos de temperatura y matrices.
