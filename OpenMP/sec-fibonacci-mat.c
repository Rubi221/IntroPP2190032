#include <stdio.h>
#include <math.h>

double numeroAureo = (1.0 + sqrt(5.0)) / 2.0;

double fibonacci(long numero){
return (pow(numeroAureo, numero) - pow(1 - numeroAureo, numero)) / sqrt(5.0);
}

int main(){
long numero;
printf("Ingresar un numero: ");
scanf("%ld", &numero);
printf("El numero %ld de la sucesion de Fibonacci es %.0f\n", numero, fibonacci(numero));
return 0;
}
