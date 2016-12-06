/*2. No dia da estréia do filme “Senhor dos Anéis”, uma grande emissora de TV realizou uma pesquisa logo
  após o encerramento do filme. Cada espectador respondeu a um questionário no qual constava sua idade
  e a sua opinião em relação ao filme: excelente -1; bom-2; regular-3. Criar um algoritmo que receba a
  idade e a opinião de 30 espectadores, calcule e imprima:
  A média das idades das pessoas que responderam regular; a quantidade de pessoas que responderam bom;
  a percentagem de pessoas que responderam excelente entre todos os expectadores analisados.*/
#include<stdio.h>
#include<stdlib.h>
#define TAM 3



struct dados
{
    int idade;
    int opiniao;
}espectadores[TAM];




int ler_dados(struct dados espectadores[TAM], FILE *arq)
{
    int i;


    for(i = 0; i < TAM; i++)
    {
        printf("<-------- Espectador %d -------->", i);
        printf("\n(Questao 1) - Informe a idade: ");
        scanf("%d", &espectadores[i].idade);
        fprintf(arq, "escreveu\n", espectadores[i].idade);
        while (espectadores[i].idade <= 0)
        {
            printf("Idade invalida, tente novamente.\n");
            printf("(Questao 1) - Informe a idade: ");
            scanf("%d", &espectadores[i].idade);
        }
        printf("\n1- Excelente \t2- Bom \t3- Regular\n");
        printf("\n(Questao 2) - O que achou do filme? (1, 2 ou 3): ");
        scanf("%d", &espectadores[i].opiniao);
        while (espectadores[i].opiniao > TAM || espectadores[i].opiniao < 1)
        {
            printf("\nOpcao invalida, tente novamente.\n");
            printf("\n(Questao 2) - O que achou do filme? (1, 2 ou 3): ");
            scanf("%d", &espectadores[i].opiniao);
        }
        printf("\n\n\n\n");
        
    }
    media_respostas_regular(espectadores);
}


//funcao que calcula a media das idades de todos que responderam regular
int media_respostas_regular(struct dados espectadores[TAM])
{
    int i, denominador = 0, numerador = 0;
    float media = 0;
    
    for(i = 0; i < TAM; i++)
    {
        if (espectadores[i].opiniao == 3)
        {
            numerador = numerador + espectadores[i].idade;
            denominador = denominador + 1;
        }
    }
    media = (numerador/denominador);
    printf("\n\nMedia de opinioes regulares: %.2f", media);
    
    quantidade_responderam_bom (espectadores);


}


int quantidade_responderam_bom (struct dados espectadores[TAM])
{
    int i, coleta = 0;
    for(i = 0; i < TAM; i++)
    {    
        if (espectadores[i].opiniao == 2)
        {
            coleta = coleta +1;
        }
    }
    printf("\n\nQuantidade de pessoas que avaliaram o filme em bom (2): %d", coleta);


    percentagem_responderam_excelente (espectadores);
}


int percentagem_responderam_excelente (struct dados espectadores[TAM])
{
    int i, cont = 0;
    float percentagem = 0;
    
    for(i = 0; i < TAM; i++)
    {
        if (espectadores[i].opiniao == 1)
        {
            cont = cont + 1;
        }
    }
    percentagem = (100*cont)/3;
    printf("\nA percentagem dos que avaliaram como excelente eh = %.2f", percentagem);
}
int main()
{
    char url[]="char.txt";
    FILE *arq;
    arq = fopen(url, "w");
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");

	ler_dados(espectadores,arq);
	fclose(arq);
    
    return 0;
}

