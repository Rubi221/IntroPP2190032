### Taller1 OpenMP
## Cod:2190032 - Problema A - Suma de elementos de la serie de Fibonacci.
Dentro de la carpeta se encuentran los archivos .c y los ejecutables .exe.
Aquellos archivos que empiezan por "sec" son aquellos donde esta una solucion secuencial, y aquellos que inician en "omp" son aquellos que contienen la solucuion paralelizada.

Haciendo un pequeño analisis de las soluciones, se pudo notar que haciendo uso de la formula matematica de la sucesion de Fibonacci, la diferencia entre los tiempos de respuesta entre la solucion secuencial y la paralelizada no difieren por mucho en su rango, sin embargo al aumentar el N termino se puede ver que la diferencia entre estos tiempos aumenta.
Como se puede ver a continuacion, los tiempos de respuesta con numeros bajos, en este caso 16, son:

Secuencial: 2.430 seg
![Captura de pantalla 2023-09-21 032141](https://github.com/Rubi221/IntroPP2190032/assets/98795896/6141546c-31e1-4be5-9477-c7ad7de9ee9c)


Paralelizada: 2.078 seg
![Captura de pantalla 2023-09-21 032223](https://github.com/Rubi221/IntroPP2190032/assets/98795896/b047bb3a-423a-46ef-a077-1d041204be36)



Ahora, los tiempos de respuesta con numeros mas altos, en este caso 1200, son:


Secuencial: 8,285 seg
![Captura de pantalla 2023-09-21 032426](https://github.com/Rubi221/IntroPP2190032/assets/98795896/944d6826-18f7-4db7-a4ef-eb8b8cd9dd07)


Paralelizada: 4.469 seg
![Captura de pantalla 2023-09-21 032446](https://github.com/Rubi221/IntroPP2190032/assets/98795896/83970aca-a184-4f09-b8b9-b60ed0336c9f)


Probando repetidas veces se puede notar que los tiempos de respuesta siguen variando, sin embargo se puede afirmar que en la mayoria de los casos la solucion paralelizada tiene tiempos menores, aunque no es una diferencia muy considerable la que se muestra en esta implementacion.
