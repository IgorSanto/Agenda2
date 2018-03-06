#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//TAD - Tipo Abstrato de Dados
typedef struct 
{
	char nome[40];
	char email[40];
	char telefone[12];
}Agenda;

int menu(){
	int op;
	do{
		printf("\tMenu\n");
		printf("1. Adicionar funcionário.\n");
		printf("2. Consultar funcionário.\n");
		printf("3. Excluír funcionário.\n");
		printf("4. Pesquisa.\n");
		printf("5. Sair.\n");
		printf("Opção: ");
		scanf("%i",&op);
		if((op < 1)|| (op > 5 )){
			printf("Opção inválida...\n");	
			system ("pause");	
		}system ("cls");
		return op;
    }while(op!=5);
}
	

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int i = 1, c = 0, x = 0, z = 0;
	char nome2[40];
	Agenda *p = (Agenda*) calloc(i, sizeof(Agenda));

	
	int m;

	do
	{
			m = menu();
		switch(m)
		{
			case 1:
				printf("\t Adicionar funcioário\n");
				printf("Nome do funcionário : \n");
				scanf(" %[^\n]s", p[i-1].nome);
				
				printf("Telefone do funcionário: \n");
				scanf("%s",& p[i-1].telefone);
				
				printf("Email do funcionário: \n");
				scanf("%s",& p[i-1].email);
				printf("Seu número de registro é : %i\n",i);
				i++;
				p = (Agenda*) realloc(p, i * sizeof(Agenda));
				system("pause");
				system("cls");
				break;
			
			case 2:
				printf("Digite o numero de registro: ");
				scanf("%i",&c);
				
				if(c <= i){
					printf("Nome: %s\n", p[c-1].nome);
					printf("Telefone: %s\n", p[c-1].telefone);
					printf("Email: %s\n", p[c-1].email);
				}
				system("pause");
				system("cls");
				
				break;
			case 3:
				printf("\t Excluir funcionário\n");
			
				
			printf("Numero de Registro - ");
				scanf("%i",&c);
				if(c <= i)
				{
					printf("Nome - %s\n",p[c-1].nome);
					printf("E-mail - %s\n",p[c-1].email);
					printf("Tel - %s\n",p[c-1].telefone);
					printf("CADASTRO EXCLUIDO!\n");
					for(z = 0; z <= i; z++)
					{
						if((c - 1) != z)
						{
							strcpy(p[x].nome,p[z].nome);
							strcpy(p[x].email,p[z].email);
							strcpy(p[x].telefone,p[z].telefone);
							x++; 
						}
					}
					p = (Agenda*) realloc(p, x * sizeof(Agenda));
					i--;	
				}else
					printf("REGISTRO NÂO EXISTENTE!\n"); 
				break;
			case 4:
				printf("\tPesquisa\n");
			printf("Nome - ");
				scanf(" %[^\n]s",nome2);
				for(z = 0; z <= i; z++)
				{
					x = stricmp(nome2,p[z].nome);
					if(x == 0)
					{
						printf("NUMERO DE REGISTRO %i\n",(z+1));
						printf("Nome - %s\n",p[z].nome);
						printf("E-mail - %s\n",p[z].email);
						printf("Tel - %s\n",p[z].telefone);
					}
				}
				break;
			default:
				system("cls");
			}	
	}while(m != 5);
	return 0;
}
