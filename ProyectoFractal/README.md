# Proyecto Final ICP - Fractal Mandelbrot con OpenMP
Este proyecto genera una imagen del conjunto fractal de Mandelbrot en formato PPM (Portable Pixel Map) utilizando OpenMP para la paralelización y optimización del proceso.

## Integrantes:
- Rubi Tatiana Utima Echeverry - 2190032
- Andres Felipe Valenzuela Pardo - 2190035
- David Alexander Vasquez Vivas - 2190053

### Cálculo del Conjunto de Mandelbrot

El código se encarga de iterar sobre cada píxel en una matriz bidimensional que representa la imagen. Para cada píxel, se realiza la iteración de la fórmula de Mandelbrot: \(Z_{n+1} = Z_n^2 + C\), donde \(Z_n\) es un número complejo y \(C\) es la coordenada compleja correspondiente al píxel.

La iteración continúa hasta que \(Z_n\) excede un límite predefinido o se alcanza el número máximo de iteraciones (cant_max). La cantidad de iteraciones necesarias para escapar del límite determina el color del píxel en la imagen generada.

### Secuencial

En la versión secuencial del código, se utilizan dos bucles anidados para recorrer todos los píxeles de la imagen. Para cada píxel, se calcula la coordenada compleja correspondiente, y se itera la fórmula de Mandelbrot hasta que se cumplan las condiciones de escape.

El resultado de la iteración determina el color del píxel en la imagen. Los valores de color se almacenan en matrices separadas para los componentes rojo, verde y azul.

### Paralelo con OpenMP

La versión paralela utiliza OpenMP para distribuir el cálculo de los píxeles entre múltiples hilos. Se emplean directivas de OpenMP para paralelizar el bucle exterior, lo que permite que cada hilo trabaje en diferentes filas de la matriz de píxeles de manera concurrente.

La paralezacion del ciclo for se realiza mediante las siguientes directivas

```bash
# pragma omp parallel \
  shared ( b, cant, cant_max, g, r, x_max, x_min, y_max, y_min ) \
  private ( i, j, k, x, x1, x2, y, y1, y2 )
{
# pragma omp for
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      // ... (resto del código)
    }
  }
}
```


1. **#pragma omp parallel:** Esta es la directiva principal de OpenMP que indica que el bloque de código siguiente debe ejecutarse en paralelo. Cada hilo que se inicie ejecutará el mismo bloque de código.

2. **shared(b, cant, cant_max, g, r, x_max, x_min, y_max, y_min):** Esta parte especifica las variables que se comparten entre todos los hilos. En este caso, las matrices b, cant, g, y r, así como las variables x_max, x_min, y_max, y y_min, se comparten entre los hilos. Esto significa que cada hilo tendrá acceso a estas variables.

3. **private(i, j, k, x, x1, x2, y, y1, y2):** Esta parte especifica las variables que son privadas para cada hilo. Cada hilo tendrá su propia copia independiente de estas variables. En este caso, las variables de bucle (i, j, k) y las variables de cálculo (x, x1, x2, y, y1, y2) son privadas.

En resumen, este bloque de código paraleliza el algoritmo utilizando OpenMP. Todos los hilos comparten algunas variables (aquellas necesarias para la operación global, como las matrices de resultado y algunos parámetros), mientras que otras variables son privadas para cada hilo (variables de bucle y cálculo). Esto asegura que cada hilo realice su trabajo de manera independiente sin interferir con los demás hilos.


### Observaciones Importantes

- El código utiliza funciones auxiliares como crear_matriz y eliminar_matriz para gestionar la memoria de matrices dinámicas.
- La función min se utiliza para determinar el valor mínimo entre dos enteros.
- Los parámetros del fractal, como la resolución de la imagen y el rango de coordenadas complejas, pueden ajustarse según sea necesario.

Este código genera visualizaciones del conjunto fractal de Mandelbrot, que es conocido por su belleza visual y estructuras geométricas fascinantes. La paralelización con OpenMP ayuda a mejorar el rendimiento, especialmente en conjuntos de datos más grandes, distribuyendo la carga de trabajo entre varios hilos de manera eficiente.

### Almacenamiento en Imagen PPM

El código genera dos archivos de imagen PPM que visualizan el conjunto fractal de Mandelbrot. Uno de los archivos se crea utilizando la versión secuencial del código (fractal_secuencial.ppm), y el otro se genera mediante la versión paralela utilizando OpenMP (fractal_paralelo.ppm). Ambos archivos contienen información en formato PPM, que es un formato de imagen simple. 

### Resultados

Se realizaron 3 ejecuciones del codigo variando en cada una de ellas el tamaño de la imagen (Cantidad de pixeles)

#### Ejecucion 1 - 500x500 px
   
![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/d522a4cd-6314-409b-9bbd-6e9908688102)
##### Secuencial:
![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/3ca2d573-37bd-4195-bd54-2b8f3ccf0220)
##### Paralela:
![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/2fdb59d2-408f-4081-94d7-b252e3d4995b)

#### Ejecucion 2 - 2000 x 2000 px
 ![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/8c41127f-7e92-47f4-983b-31f299f21f75)

##### Secuencial:
![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/e1845d97-1ff1-4594-8d4a-5bb741180de0)

##### Paralela:
![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/37e840d9-c5a5-426e-9dec-15fdb77d0aad)

#### Ejecucion 3 - 4360 x 4360 px
![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/fac76e69-8e35-47de-9604-c2349dba3c93)

##### Secuencial:
![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/319fb723-9328-48b5-a1ae-6092f0044bd6)

##### Paralela:
![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/c897106d-202c-45bb-968f-13063ede1dad)

![imagen](https://github.com/Rubi221/IntroPP2190032/assets/98795896/c7ac09ab-b26c-402c-b38c-ad64531c96d1)

### Interpretación de los Resultados

#### Coloración de los Píxeles:
La coloración de los píxeles se basa en la cantidad de iteraciones necesarias para que la fórmula de Mandelbrot escape o alcance el límite predeterminado (cant_max).

#### Efecto Visual:
El conjunto fractal de Mandelbrot es conocido por su complejidad y detalle visual infinito. La visualización revela estructuras fractales complejas, como espirales, bifurcaciones y patrones autosemejantes.

### Consideraciones

#### Tiempo de Ejecución:
El tiempo de ejecución se imprime en la consola al final de cada ejecución, permitiendo comparar el rendimiento entre las versiones secuencial y paralela.

#### Ajuste de Parámetros:
Los parámetros del fractal, como la resolución de la imagen, el rango de coordenadas y la cantidad máxima de iteraciones, pueden ajustarse en el código para explorar diferentes visualizaciones.

