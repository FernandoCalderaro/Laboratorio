/*2. No dia da estréia do filme “Senhor dos Anéis”, uma grande emissora de TV realizou uma pesquisa logo
  após o encerramento do filme. Cada espectador respondeu a um questionário no qual constava sua idade
  e a sua opinião em relação ao filme: excelente -1; bom-2; regular-3. Criar um algoritmo que receba a
  idade e a opinião de 30 espectadores, calcule e imprima:
  A média das idades das pessoas que responderam regular; a quantidade de pessoas que responderam bom;
  a percentagem de pessoas que responderam excelente entre todos os expectadores analisados.*/
#include<stdio.h>
#include<stdlib.h>
#define TAM 2



struct dados
{
    int idade;
    int opiniao;
};

void ler_dados (struct dados *vetor, FILE *arquivo)
{
	int i;
	
	 for(i = 0; i < TAM; i++)
    {
    	//idades
		printf("\n(Questao 1) - Informe a idade: ");
        scanf("%d", &vetor[i].idade);
        //opinioes
        printf("\n1- Excelente \t2- Bom \t3- Regular\n");
        printf("\n(Questao 2) - O que achou do filme? (1, 2 ou 3): ");
        scanf("%d", &vetor[i].opiniao);
        
        fprintf(arquivo,"IDADE[%d]:%d\t\tOPINIAO[%d]:%d\n", i, vetor[i].idade, i, vetor[i].opiniao);
	}
}

float media_respostas_regular(struct dados *vetor)
{
	int soma=0,i,cont=0;
	float media=0;
	for(i=0;i<TAM;i++)
	{
		if(vetor[i].opiniao==3)
		{
			soma+=vetor[i].idade;
			cont++;
		}
	}
	media=soma/cont;
	return media;
}

int quantidade_bom(struct dados *vetor)
{
	int cont=0,i;
	for(i=0;i<TAM;i++)
	{
		if(vetor[i].opiniao==2)
		{
			cont++;
		}
	}
	
	return cont;
}

float porcentagem_excelente(struct dados *vetor)
{
	int i,cont=0;
	float p;
	for(i=0;i<TAM;i++)
	{
		if(vetor[i].opiniao==1)
		{
			cont++;
		}
	}
	p=(100.0*cont)/30.0;
	return p;	
}

int main()
{
    struct dados *vetor = (struct dados *) malloc(sizeof(struct dados) * TAM);
    
	FILE *arquivo = fopen("opinioes.txt", "w");
	
	ler_dados(vetor, arquivo);
	fprintf(arquivo,"MEDIA DAS IDADES DE QUEM RESPONDEU REGULAR  %.2f\n",media_respostas_regular(vetor));
	fprintf(arquivo,"QUANTIDADE DE QUEM RESPONDEU BOM %d\n",quantidade_bom(vetor));
//    fprintf(arquivo,"porcentagem de quem respondeu excelente  %.2f \n",porcentagem_excelente(vetor));
    fclose(arquivo);
    return 0;
}

