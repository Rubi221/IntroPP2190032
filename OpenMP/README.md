### Taller1 OpenMP
## Cod:2190032 - Problema A - Suma de elementos de la serie de Fibonacci.
Dentro de la carpeta se encuentran los archivos .c y los ejecutables .exe.
Aquellos archivos que empiezan por "sec" son aquellos donde esta una solucion secuencial, y aquellos que inician en "omp" son aquellos que contienen la solucuion paralelizada.

Haciendo un pequeño analisis de las soluciones, se pudo notar que haciendo uso de la formula matematica de la sucesion de Fibonacci, la diferencia entre los tiempos de respuesta entre la solucion secuencial y la paralelizada no difieren por mucho en su rango.
Como se puede ver a continuacion, los tiempos de respuesta con numeros bajos, en este caso 15, son:

Secuencial: 2.198 seg
![Captura de pantalla 2023-09-21 023528](https://github.com/Rubi221/IntroPP2190032/assets/98795896/2f5cc123-6fc2-4bcb-9515-fa2154009cf4)

Paralelizada: 1.528 seg
![Captura de pantalla 2023-09-21 025143](https://github.com/Rubi221/IntroPP2190032/assets/98795896/5bce80ea-1d62-41ee-8543-14cefd110a84)


Ahora, los tiempos de respuesta con numeros mas altos, en este caso 1000, son:


Secuencial: 3.954 seg
.![Captura de pantalla 2023-09-21 023414](https://github.com/Rubi221/IntroPP2190032/assets/98795896/aeb9fa48-6c51-4aaf-b192-a5679643aacf)

Paralelizada: 3.055 seg
![Captura de pantalla 2023-09-21 023434](https://github.com/Rubi221/IntroPP2190032/assets/98795896/5fbe5a7c-f78a-41bd-bedd-b82b7a33bc11)


Probando repetidas veces se puede notar que los tiempos de respuesta siguen variando, sin embargo se puede afirmar que en la mayoria de los casos la solucion paralelizada tiene tiempos menores, aunque no es una diferencia muy considerable la que se muestra en esta implementacion.
