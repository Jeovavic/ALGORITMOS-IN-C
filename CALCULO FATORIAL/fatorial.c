#include <stdio.h>

int main(void){
    int fatorial(int x);
    int num1, resultado;
    printf("Informe o numero : ");
    scanf("%d", &num1);
    resultado = fatorial(num1);
    printf("O fatorial eh : %d\n", resultado);

    system("pause");
    return 0;
}

int fatorial(int x){
    int resultado;
    if(x == 0){
        resultado = 1;
    }
    else{
        resultado = x * fatorial(x - 1);
    }
    return resultado;

}