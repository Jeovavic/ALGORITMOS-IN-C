#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int num1, num2, total, op;
    float a, b, c, delta, xi, xii;
    do{
        system("cls");
        printf(" 1 - Somaç");
        printf("\n 2 - Subtracao ");
        printf("\n 3 - Multiplicacao ");
        printf("\n 4 - Divisao ");
        printf("\n 5 - equacao de 2 grau");
        printf("\n 6 - SAIR ");
        printf("\n____________________________\n");
        printf("\nDigite o numero da sua operacao : ");
        scanf("%d", &op);
        switch(op){
            case 1:
                system("cls");
                printf("Informe o numero 1 : ");
                scanf("%d", &num1);
                printf("\nInforme o numero 2 :");
                scanf("%d", &num2);
                total = num1 + num2;
                printf("\nA soma dos numero e : %d\n", total);
                system("pause");
            break;
            case 2:
                printf("Informe o numero 1 : ");
                scanf("%d", &num1);
                printf("\nInforme o numero 2 :");
                scanf("%d", &num2);
                total = num1 - num2;
                printf("\nA subtracao dos numero e : %d\n", total);
                system("pause");
            break;
            case 3:
                system("cls");
                printf("Informe o numero 1 : ");
                scanf("%d", &num1);
                printf("\nInforme o numero 2 :");
                scanf("%d", &num2);
                total = num1 * num2;
                printf("\nA multiplicacao dos numero e : %d\n", total);
                system("pause");
            break;
            case 4:
                system("cls");
                printf("Informe o numero 1 : ");
                scanf("%d", &num1);
                printf("\nInforme o numero 2 :");
                scanf("%d", &num2);
                total = num1 / num2;
                printf("\nA divisao dos numero e : %d\n", total);
                system("pause");
            break;
            case 5:
                system("cls");
                printf("Informe o coeficiente a : ");
	            scanf("%f", &a);
	            printf("Informe o coeficiente b : ");
	            scanf("%f", &b);
	            printf("Informe o coeficiente c : ");
	            scanf("%f", &c);
	            delta = pow(b, 2) - (4*a*c);
	            if (delta > 0){
		            xi  = (-b + sqrt(delta))/(2*a);
		            xii = (-b - sqrt(delta))/(2*a);
		            printf("\n Raiz 1 = %.2f ", xi);
		            printf("\n Raiz 2 = %.2f \n", xii);
                }
		        else if(delta == 0){
			        xi = (-b + sqrt(delta))/(2*a);
			       printf("\n Raizes iguais = %.2f \n", xi);
                }
		        else {
                printf("\n A equacao nao possui raizes reais\n");
                }
                system("pause");
            break;
        }
       
    
    }while(op != 6);
    printf("\nFim de execucao");
    system("pause");
    return 0;
}