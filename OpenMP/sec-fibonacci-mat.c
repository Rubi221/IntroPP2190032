#include <stdio.h>
#include <math.h>

double numeroAureo = (1.0 + sqrt(5.0)) / 2.0;

double fibonacci(long numero){
return (pow(numeroAureo, numero) - pow(1 - numeroAureo, numero)) / sqrt(5.0);
}

int main(){
long numero;
printf("Ingresa el indice par a encontrar: ");
scanf("%ld", &numero);

if(numero%2 == 1){
    printf("El numero ingresado debe ser par");
    return 0;
}
else{
    printf("El numero %ld de la sucesion de Fibonacci es %.0f\n", numero, fibonacci(numero));
    return 0;
}
}
