#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct de materias
typedef struct {
    int codigo;
    char nome[30];
    int quantidade;
	int numero;
	float preco;
}material;

//Declaração de todas as funcoes
void cadastrarNovamente();
void cadastro(int *j,material *P);
void mostraTodos(int *j,material *P);
void mostra1(int codigoMaterial,int *j,material *P);
void deletar(int codigoMaterial, int *j,material *P);
void alterar(int opc, int cod, int *j,material *P);
void alterarStr(int cod,int *j,material *P);
void menu();
void menuMostraTodos(int *j,material *P);
void menuMostra1(int *j,material *P);
void menuDeletar(int *j,material *P);
void menuAlterar(int *j,material *P);
void produtos(int *j,material *P);
void alterapreco(int *j,material *P);


//Inicio das funcoes.
//Função para cadastrar materias no vetor
void cadastro(int *j,material *P){
    while(*j < 10){
		printf("\n------------------------------------------------\n");
		printf("|              CADASTRO DE MATERIAL             |\n");
		printf("------------------------------------------------");
		printf("\nDigite o codigo do material: ");
    	scanf("%d", &P[*j].codigo);
    	printf("Digite o nome do material: ");
    	scanf("%s", P[*j].nome);
    	printf("Digite a quantidade: ");
    	scanf("%d", &P[*j].quantidade);
		printf("Digite o preço: ");
    	scanf("%f", &P[*j].preco);
		printf("------------------------------------------------\n");
		P[*j].numero = *j;
		*j= (*j) + 1;
    	printf("VOCÊ DESEJA CADASTRAR OUTRO PRODUTO?(1 = SIM, 2 = NÃO) ");
        int d;
        scanf("%d", &d);
        	if(d == 2){
            	break;
        	}
        	else if(d == 1){
            	continue;
        	}
    }
    printf("\n********************CADASTRADOS COM SUCESSO :D!!!!************************\n");
}

//Função mostraTodos
//Essa função lista todos materias cadastrados com codigo, nome, quantidade e o preço
void mostraTodos(int *j,material *P){
	int k = *j;
			printf("\n------------------------------------------------\n");
			printf("|               LISTA DE MATERIAS              |\n");
			printf("------------------------------------------------");
	for(int i= 0; i< k; i++){
			if(i == k -1){
			printf("\n------------------------------------------------\n");
			printf("Posição - %d\n", P[i].numero+1);
			printf("\nCodigo: %d\n", P[i].codigo);
    		printf("Nome do material: %s\n", P[i].nome);
    		printf("Quantidade: %d\n", P[i].quantidade);
			printf("Preço: R$%.2f\n", P[i].preco);
    		printf("------------------------------------------------\n");
		}
		else{
			printf("\n------------------------------------------------\n");
			printf("Posição - %d\n", P[i].numero+1);
			printf("\nCodigo: %d\n", P[i].codigo);
    		printf("Nome do material: %s\n", P[i].nome);
    		printf("Quantidade: %d\n", P[i].quantidade);
			printf("Preço: R$%.2f\n", P[i].preco);
		}
		}
		
}

//Função mostra1
//Função que mostra um material.
void mostra1(int codigoMaterial,int *j,material *P){

		printf("\n------------------------------------------------\n");
		printf("|                  MATERIAL                    |\n");
		printf("------------------------------------------------");
	for (int i = 0;i < *j; i++){
		if(codigoMaterial == P[i].codigo){
			printf("\n************************************************");
			printf("\nPosição - %d\n", P[i].numero+1);
			printf("\nCodigo: %d\n", P[i].codigo);
    		printf("Nome do material: %s\n", P[i].nome);
    		printf("Quantidade: %d\n", P[i].quantidade);
			printf("Preço: R$%.2f\n", P[i].preco);
			printf("************************************************\n");
			break;
		}
	}
}

//Função deletar
//Função que deleta um material do vetor 
void deletar(int codigoMaterial, int *j,material *P){

	for (int i = 0;i < *j; i++){//andar em todos os usuários cadastrados
		if(codigoMaterial == P[i].codigo){//encontrou onde eu devo reescrever(excluir) o dado do material
			for(int k = i; k < (*j)-1; k++){//reescreve todos daquela posição para anterior para arrumar o vetor
			P[k].codigo = P[k+1].codigo;
			strcpy(P[k].nome, P[k+1].nome);//copia a string P[k+1].nome para P[k].nome
			P[k].quantidade = P[k+1].quantidade;
			P[k].preco = P[k+1].preco;
			
			}
			break;//para o código porque ja exclui o elemento correto
		}
	}
	(*j)--;
	printf("\nMaterial deletado com sucesso! :D\n");
}

//Função alterar
//Função que altera o codigo e a quantidade.
void alterar(int opc, int cod, int *j,material *P){
	switch (opc){
	case 1:
		for (int i = 0; i < *j ; i++){
			if(cod == P[i].codigo){
				printf("Digite o novo codigo: ");
				scanf("%d", &P[i].codigo);
				printf("\nCODIGO ALTERADO COM SUCESSO! :D\n");
			}
		}
		break;
	case 2:
		alterarStr(cod,j,P);
		break;
	case 3:
		for (int i = 0; i < *j ; i++){
			if(cod == P[i].codigo){
				printf("Digite uma nova quantidade: ");
				scanf("%d", &P[i].quantidade);
				printf("\nQUANTIDADE ALTERADA COM SUCESSO! :D\n");
			}
		}
		break;
	}
	int d;
	printf("\nVOCE DESEJA FAZER MAIS ALGUMA ALTERACAO? (1 = SIM, 2 = NÃO)\n");
		scanf("%d", &d);
		if(d == 1){
			menuAlterar(j,P);
		}
}

//Função que alteraStr
//Essa função altera o nome do material
void alterarStr(int cod,int *j,material *P){

		for (int i = 0; i < *j ; i++){
			if(cod == P[i].codigo){
				printf("\n--------------------------------------");
				printf("\nDigite o novo nome: ");
				scanf("%s", P[i].nome);
				printf("--------------------------------------\n");
				printf("\nNOME ALTERADO COM SUCESSO! :D\n");
				break;
			}
		}
}

//Função alteraPreco
void alterapreco(int *j,material *P){
	int cod;
	printf("\nPor favor digite o código do produto que deseja alterar o preço: \n");
	scanf("%d", &cod);

	for(int i = 0 ; i <= *j; i++){
		float preco;
		if(cod == P[i].codigo){
			printf("\nPor favor digite agora o preço do material atualizado: \n");
			scanf("%f", &preco);
			P[i].preco = preco;
			break;
		}
	}
	printf("\nDeseja alterar o preço de outro produto? 1(SIM) 2(NÃO): \n");
	scanf("%d", &cod);
	if (cod == 1){
		alterapreco(j,P);
	}
}

//Função produtos
//Essa função retorna se algum material precisa ser reposto
void produtos(int *j,material *P){
    int codigo;
    printf("Inserir o código do produto: ");
    scanf("%d", &codigo);
    int local = 0;
    for(int i = 0; i < *j; i++){
    if(P[i].codigo == codigo){
        local = i;
        break;
    }
    }
    if(P[local].quantidade < 3){
        printf("PRODUTO PRECISA SER REPOSTO\n");
    }
    else{
        printf("PRODUTO NÃO PRECISA SER REPOSTO\n");
    }
}

void menu(){
	int opcao;
	material P[10];
	int j = 0;

	while(1){
		printf("\nBem vindo UFUSTOCK\n");
        printf("\n1- Cadastrar Material");
        printf("\n2- Mostrar Todos Materiais");
        printf("\n3- Mostrar Um Material");
        printf("\n4- Excluir dados do Material");
        printf("\n5- Alterar material");
        printf("\n6- Ver se o produto está com 3 ou menos quantidades para reposição");
        printf("\n7- Alterar o preço");
        printf("\n8- Sair ");
        printf("\nDigite opção: ");
        scanf("%d", &opcao);

		if(opcao == 1) cadastro(&j,P);
		if(opcao == 2) mostraTodos(&j,P);
		if(opcao == 3) menuMostra1(&j,P);
		if(opcao == 4) menuDeletar(&j,P);
		if(opcao == 5) menuAlterar(&j,P);
		if(opcao == 6) produtos(&j,P);
		if(opcao == 7) alterapreco(&j,P);
		if(opcao == 8) return;
	}
}

int main(){
	menu();
}

void menuMostraTodos(int *j,material *P){
	mostraTodos(j,P);
}
void menuMostra1(int *j,material *P){
	int cod;

	printf("\nDigite o codigo do material que voce deseja ver: ");
	scanf("%d", &cod);
	mostra1(cod,j,P);
}

void menuDeletar(int *j,material *P){
	int cod;

	mostraTodos(j,P);
	printf("\nDigite o codigo do material a ser deletado: ");
	scanf("%d", &cod);
	deletar(cod,j,P);
}

void menuAlterar(int *j,material *P){
	int opc, codMaterial;

	mostraTodos(j,P);

	printf("\n------------------------------------------------\n");
	printf("|                  ALTERAR MATERIAL            |\n");
	printf("------------------------------------------------");
	printf("\nDigite o codigo do material a ser alterado: ");
	scanf("%d", &codMaterial);

	printf("\nVocê deseja alterar qual informação?\n");
	printf("\nEscolha uma opção: \n");
    printf("\n1- Alterar Codigo\n");
    printf("2- Alterar nome\n");
    printf("3- Alterar quantidade\n");
	scanf("%d", &opc);

	alterar(opc, codMaterial,j,P);
}