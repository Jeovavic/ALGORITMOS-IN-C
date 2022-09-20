#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 100

typedef struct registro{
    int tipo;
    char tituloObra[80];
    int edicaoObra;
    char nomeAutor[30];
    char editoraObra[50];
    char isbn[30];
    int quantidadeExemplares;
    int anoObra;
    int caixaObra;
} obra;

int i = 0;
void cabecalhoMapa(obra obras[]);
void cadastrarObra(obra obras[]);
void listarLivros(obra obras[]);
void listarRevistas(obra obras[]);
void listarObrasCaixa(obra obras[]);
int ler_arquivo(obra obras[]);

int main(){
    setlocale(LC_ALL,"");
    obra obras[MAX];  
    int op;
    char resp;
    do{
        system("cls");
        cabecalhoMapa(obras);
        printf(" 1 - Cadastrar obras ");
        printf("\n 2 - Listar todos os livros ");
        printf("\n 3 - Listar todas as revistas ");
        printf("\n 4 - Listar obras por caixa ");
        printf("\n 0 - sair ");
        printf("\n Escolha a opção desejada : ");
        scanf("%d", &op);
        switch(op){
            case 1:
                resp = 's';
				while((resp == 's')||(resp == 'S')){
                    system("cls");
                    cabecalhoMapa(obras);
					i++;
                    cadastrarObra(obras);
                    printf("deseja cadastrar uma nova obra ? [s] ou [n]");
                    fflush(stdin);
                    scanf("%c", &resp);
                    system("cls");
                }
            break;
            case 2:
                system("cls");
                cabecalhoMapa(obras);
				listarLivros(obras);
                system("pause");
            break;
            case 3:
                system("cls");
                cabecalhoMapa(obras);
				listarRevistas(obras);
                system("pause");
            break;
            case 4:
                system("cls");
                cabecalhoMapa(obras);
				listarObrasCaixa(obras);
                system("pause");
            break;
        }
    }while(op != 0);
    printf("\n-------- Saindo do sistema! --------\n\n");
    system ("pause");
    return 0;
}
void cadastrarObra(obra obras[]){
    FILE * arq;
	arq = fopen("RA200233625.txt", "a+");
	if(arq != NULL){
    printf("Tipo de obra : Livro[1] Revista[2] : ");
    fflush(stdin);
    scanf("%d", &obras[i].tipo);
    printf("Informe o título da obra : ");
    fflush(stdin);
    gets(obras[i].tituloObra);
    printf("Informe o nome do autor da obra : ");
    fflush(stdin);
    gets(obras[i].nomeAutor);
    printf("Informe a editora : ");
    fflush(stdin);
    gets(obras[i].editoraObra);
    printf("Informe a edição da obra : ");   
    fflush(stdin);
    scanf("%d", &obras[i].edicaoObra);
    printf("Informe o isbn : ");
    fflush(stdin);
    gets(obras[i].isbn);
    printf("Informe a quantidade de exemplares : ");
    fflush(stdin);
    scanf("%d", &obras[i].quantidadeExemplares);
    printf("Informe o ano : ");
    fflush(stdin);
    scanf("%d", &obras[i].anoObra);
    printf("Informe a caixa armazenada : ");
    fflush(stdin);
    scanf("%d", &obras[i].caixaObra);
    
    fwrite(&obras[i], sizeof(obra), 1, arq);
	fclose(arq); // aborta o programa 
    }
    else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}
int ler_arquivo(obra obras[]){
    FILE * arq = fopen("RA200233625.txt", "r");
	if(arq != NULL)
	{
		int indice = 0;
		while(1)
		{
			obra p;
			size_t r = fread(&p, sizeof(obra), 1, arq);
			if(r < 1)
				break;
			else{
				obras[indice++] = p;
            }
        }
		fclose(arq); // fecha o arquivo
		return indice;
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}
void listarLivros(obra obras[]){
    FILE *arq; 	
	arq = fopen ("RA200233625.txt", "r");

	fread(obras, sizeof (int), 20, arq); 	

	int len_vet = ler_arquivo(obras);	

	int j;
    printf("\n>>>> Lista de Livros <<<<\n");
    printf("\n__________________________________________________________________________________________________________________\n");
	
    for(j = 0; j < len_vet; j++){
    if(obras[j].tipo == 1){
    printf("\n título da obra : %s", obras[j].tituloObra);
    printf("\t\t edição da obra : %d", obras[j].edicaoObra);
    printf("\n nome do autor : %s", obras[j].nomeAutor);
    printf("\t\t editora da obra : %s", obras[j].editoraObra);
    printf("\n isbn : %s", obras[j].isbn);
    printf("\t\t\t quantidade de exemplares : %d", obras[j].quantidadeExemplares);
    printf("\n ano : %d", obras[j].anoObra);
    printf("\t\t\t caixa armazenada : %d", obras[j].caixaObra);
    printf("\n__________________________________________________________________________________________________________________\n");
    }
    }
    fclose(arq);
}
void listarRevistas(obra obras[]){
    FILE *arq; 	
	arq = fopen ("RA200233625.txt", "r");

	fread(obras, sizeof (int), 20, arq); 	

	int len_vet = ler_arquivo(obras);	

	int j;
    printf("\n>>>> Lista de Revistas <<<<\n");
    printf("\n__________________________________________________________________________________________________________________\n");
	for(j = 0; j < len_vet; j++){
    if(obras[j].tipo == 2){
    printf("\n título da obra : %s", obras[j].tituloObra);
    printf("\t\t edição da obra : %d", obras[j].edicaoObra);
    printf("\n nome do autor : %s", obras[j].nomeAutor);
    printf("\t\t editora da obra : %s", obras[j].editoraObra);
    printf("\n isbn : %s", obras[j].isbn);
    printf("\t\t\t quantidade de exemplares : %d", obras[j].quantidadeExemplares);
    printf("\n ano : %d", obras[j].anoObra);
    printf("\t\t\t caixa armazenada : %d", obras[j].caixaObra);
    printf("\n__________________________________________________________________________________________________________________\n");
    }
    }
    fclose(arq);
}
void listarObrasCaixa(obra obras[]){   
    FILE *arq; 	
	arq = fopen ("RA200233625.txt", "r");

	fread(obras, sizeof (int), 20, arq); 	

	int len_vet = ler_arquivo(obras);	
    int opCaixa;
	int j;
    printf("Informe a caixa desejada : ");
    scanf("%d", &opCaixa);
    if(opCaixa == 1){
            printf("\n>>>> Obras Armazenadas por caixa <<<<\n");
            printf("\n__________________________________________________________________________________________________________________\n\n\n");
    
            printf("\n\n************************************************ CAIXA : 1 ************************************************ \n\n\n");
            printf("\n__________________________________________________________________________________________________________________\n");
            for(j = 0; j < len_vet; j++){
                if(obras[j].caixaObra == 1){
                    if(obras[j].tipo == 1){
                        printf("Tipo de obra : Livro");
                    }
                    else if(obras[j].tipo == 2){
                        printf("Tipo de obra : Revista");
                    }
            printf("\nTítulo da obra : %s", obras[j].tituloObra);
            printf("\t\tEdição da obra : %d", obras[j].edicaoObra);
            printf("\t\tNome do autor : %s", obras[j].nomeAutor);
            printf("\nEditora da obra : %s", obras[j].editoraObra);                
            printf("\t\tIsbn : %s", obras[j].isbn);
            printf("\t\t\tQuantidade de exemplares : %d", obras[j].quantidadeExemplares);
            printf("\nAno : %d", obras[j].anoObra);
            printf("\t\t\tcaixa armazenada : %d", obras[j].caixaObra);
            printf("\n__________________________________________________________________________________________________________________\n");
                }
            }
        }
    if(opCaixa == 2){
            printf("\n>>>> Obras Armazenadas por caixa <<<<\n");
            printf("\n__________________________________________________________________________________________________________________\n\n\n");
    
            printf("\n\n************************************************ CAIXA : 2 ************************************************ \n\n\n");
            printf("\n__________________________________________________________________________________________________________________\n");
            for(j = 0; j < len_vet; j++){
                if(obras[j].caixaObra == 2){
                    if(obras[j].tipo == 1){
                        printf("Tipo de obra : Livro");
                    }
                    else if(obras[j].tipo == 2){
                        printf("Tipo de obra : Revista");
                    }
            printf("\nTítulo da obra : %s", obras[j].tituloObra);
            printf("\t\tEdição da obra : %d", obras[j].edicaoObra);
            printf("\t\tNome do autor : %s", obras[j].nomeAutor);
            printf("\nEditora da obra : %s", obras[j].editoraObra);                
            printf("\t\tIsbn : %s", obras[j].isbn);
            printf("\t\t\tQuantidade de exemplares : %d", obras[j].quantidadeExemplares);
            printf("\nAno : %d", obras[j].anoObra);
            printf("\t\t\tcaixa armazenada : %d", obras[j].caixaObra);
            printf("\n__________________________________________________________________________________________________________________\n");
                }
            }
        }
    if(opCaixa == 3){
            printf("\n>>>> Obras Armazenadas por caixa <<<<\n");
            printf("\n__________________________________________________________________________________________________________________\n\n\n");
    
            printf("\n\n************************************************ CAIXA : 3 ************************************************ \n\n\n");
            printf("\n__________________________________________________________________________________________________________________\n");
            for(j = 0; j < len_vet; j++){
                if(obras[j].caixaObra == 3){
                    if(obras[j].tipo == 1){
                        printf("Tipo de obra : Livro");
                    }
                    else if(obras[j].tipo == 2){
                        printf("Tipo de obra : Revista");
                    }
            printf("\nTítulo da obra : %s", obras[j].tituloObra);
            printf("\t\tEdição da obra : %d", obras[j].edicaoObra);
            printf("\t\tNome do autor : %s", obras[j].nomeAutor);
            printf("\nEditora da obra : %s", obras[j].editoraObra);                
            printf("\t\t\tIsbn : %s", obras[j].isbn);
            printf("\t\t\tQuantidade de exemplares : %d", obras[j].quantidadeExemplares);
            printf("\nAno : %d", obras[j].anoObra);
            printf("\t\t\t\tcaixa armazenada : %d", obras[j].caixaObra);
            printf("\n__________________________________________________________________________________________________________________\n");
                }
            }
        }
    if(opCaixa > 3){
            printf("\n>>>> Obras Armazenadas por caixa <<<<\n");
            printf("\n__________________________________________________________________________________________________________________\n\n\n");
    
            printf("\n\n*************************************** Obras armazenadas em outras caixas ************************************* \n\n\n");
            printf("\n__________________________________________________________________________________________________________________\n");
            for(j = 0; j < len_vet; j++){
                if(obras[j].caixaObra > 3){
                printf("O livro esta na caixa : %d\n", obras[j].caixaObra);   
                    if(obras[j].tipo == 1){
                        printf("Tipo de obra : Livro");
                    }
                    else if(obras[j].tipo == 2){
                        printf("Tipo de obra : Revista");
                    }
            printf("\nTítulo da obra : %s", obras[j].tituloObra);
            printf("\t\tEdição da obra : %d", obras[j].edicaoObra);
            printf("\t\tNome do autor : %s", obras[j].nomeAutor);
            printf("\nEditora da obra : %s", obras[j].editoraObra);                
            printf("\t\t\tIsbn : %s", obras[j].isbn);
            printf("\t\t\tQuantidade de exemplares : %d", obras[j].quantidadeExemplares);
            printf("\nAno : %d", obras[j].anoObra);
            printf("\t\t\t\tcaixa armazenada : %d", obras[j].caixaObra);
            printf("\n__________________________________________________________________________________________________________________\n");
                }
            }
        }
    fclose(arq);
    
}
void cabecalhoMapa(obra obras[]){
    printf(">>>>>>| JEOVÁ VICTOR           |<<<<<<<<<");
    printf("\n>>>>>>| RA:20023362-5          |<<<<<<<<<");
    printf("\n>>>>> | ENGENHARIA DE SOFTWARE |<<<<<<\n");
    printf("\n____________________________________________________\n");
}
