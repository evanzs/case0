#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100
#include <locale.h>

faltas ()
{
	
	 int horas_dadas,creditos,faltas;
	 int total_faltas,pode_faltar;
	printf ("\nHoras de aulas dadas: ");
	scanf  ("%d",&horas_dadas);
	
	printf ("\nQuantos creditos: ");
	scanf  ("%d",&creditos);
	
	printf ("\nQuantas horas voce faltou: ");
	scanf  ("%d",&faltas);
	
	
	//creditos e o numero de aulas por semana, sendo assim 
	//calculei o numero de aulas em 15 semana  para chegar
	// no valor total de horas/semestre
	
	// calcula o total de faltas que alguem pode ter
	total_faltas = (creditos*15)*(0.3);
	printf ("%d\n",total_faltas);
	
	pode_faltar  = (total_faltas - faltas);
	printf ("%d\n",pode_faltar);
	// ve se o numero de horas falta nao e menor que o numero que pode faltar
	// Se sim, printa o numero de aulas que ainda restas
	// Senao, printa o numero real que pode faltar
	
	if (((creditos*15) - horas_dadas)<= pode_faltar)
	{
		 printf("Voce ainda pode faltar %d",(creditos*15) - horas_dadas);
	}
	   
	else
	{
		if (pode_faltar <= 0)
			pode_faltar = 0;
		
		printf("Voce ainda pode faltar %d",pode_faltar);
	}
	    
	    
}


float notas ()
{
	
		//Pesos das notas
		float pprovas,ptrabalhos;
		
		//quantidade dos trabalhos q provas
	
		int qprovas,qtrabalhos;
		
		//soma das notas e media delas 
		float tprova    = 0;
		float ttrabalho = 0;
		
		//Notas
		float nprovas,ntrabalhos;
		
		//variavel auxiliar
		int i=1;
	
	
	
	
		//Nota como nao ha restricao para o valor menor e maior dos pesos e notas,
		//o codigo aceita qualquer valor como valido
	
		printf ("\nValor das provas na media final: ");
		scanf ("%f",&pprovas);
		
		
		printf ("\nValor dos trabalhos na media final: ");
		scanf ("%f",&ptrabalhos);	
		
		
		
		printf ("\nQuantidade de provas sem sub: ");
		scanf ("%d",&qprovas);		
		
		
		printf ("\nQuantidade de trabalhos sem os extras: ");
		scanf ("%d",&qtrabalhos);
		
		
		//registra as notas das provas e soma
		do
		{
			printf ("\nNota da prova %d: ",i);
			scanf ("%f",&nprovas);
			
						
			i++;
			
			// ja soma todas as provas
			tprova = nprovas+tprova;
			
		}while (i <= qprovas );
		
		//zera variavel contadora
		i=1;
		
		printf ("\n");
		//registra e soma as notas dos trabalhos
		do
		{
			printf ("\nNota dos Trabalhos %d: ",i);
			scanf ("%f",&nprovas);
			i++;
			
			// ja soma todas as provas
			ttrabalho= nprovas+ttrabalho;
			
		}while (i <= qtrabalhos);
		
		
		// calcula a media dos trabalhos e das provas
		ttrabalho = (ttrabalho/qtrabalhos)*ptrabalhos;
		tprova   = (tprova/qprovas)*pprovas;
		
		return ( (tprova+ttrabalho));
}



float bitcoins ()
{
	
	int linha,coluna;
	
	float tabela[MAX][MAX];
	
	int l,c;
	
	float maior_valor = 0;
	float menor_valor = 9999999;
	int compra=1;
	
	
    float primeira_compra = 0;
    float ultima_compra   = 0;
	printf ("\nDigite da dimensão da tabela\n");
	printf ("Quantas linhas(sites): ");
	scanf ("%d",&l);
	printf ("Quantas colunas (tempos): ");
	scanf ("%d",&c);
	
	
	for (coluna=0;coluna<c;coluna++)//anda pelas linhas/sites
	{
		printf ("\n\nTempo: %d\n",coluna+1);
		for (linha=0;linha<l;linha++)//anda pelas colunas/tempos		
		{
						
			printf ("\nValor do Bitcoin no site %d: ",linha);
			scanf ("%f",&tabela[linha][coluna]);	
		}			
		
	}
	
	system ("cls");
	
	for (linha=0;linha<c;linha++)//anda pelas linhas/sites
	{	
		printf ("\t\t\t");
		for (coluna=0;coluna<c;coluna++)//anda pelas colunas/tempos		
		{
						
			printf("%.4f\t\t",tabela[linha][coluna]);	
		}			
		printf ("\n");
	}
	
	for (coluna=0;coluna<c;coluna++)//anda pelas linhas/sites
	{
		for (linha=0;linha<l;linha++)//anda pelas colunas/tempos		
		{
			
			 if (maior_valor < tabela[linha][coluna])
			 	maior_valor = tabela [linha][coluna];
			
			if (menor_valor > tabela [linha][coluna])
				menor_valor = tabela [linha][coluna];
			 					
		}
		printf ("\n\nInstante %d\n",coluna+1);
		if (coluna == 0)
		{
			
			printf ("Compre  do site com valor %.4f\n",menor_valor);
			primeira_compra = menor_valor;
		}
						
		else
		{
			//como ja foi comprado, só vende
			if ( coluna+1 == c)
			{
				printf ("Venda para o Site pelo valor de %.4f\n",maior_valor);
				ultima_compra = maior_valor;
				
			}
			else
			{
				printf ("enda para o Site pelo valor de %.4f\n",maior_valor);
				printf ("nCompre no Site pelo valor de %.4f\n",menor_valor);
			}
			
		}
	}
	
	return (ultima_compra-primeira_compra);
}

int main ()
{
	 setlocale(LC_ALL, "Portuguese");
	int op;

	do
	{
	
		 system ("cls");	
		 printf ("\t\t\tMENU\n\n");
		 
		 
		 printf ("\t\t1. Calculo de Fatas\n");
		 printf ("\t\t2. Calculo de Notas\n");
		 printf ("\t\t3. Calculo de Bitcoins\n");
		 printf ("\t\t0. Sair\n");
			
		
		
		do
		{
			printf ("\nEntre com a opção: ");
			scanf ("%d",&op);
			if (op == 0 )
				exit(0);
			if ((op >3 || op < 0))	
				printf ("opçao invalida\n");
		}while (op >3 || op < 0);
		
		
		
			if ( op == 1)
				faltas();
				
			if (op == 2)
				printf ("\nSua nota final: %.2f:",notas());
			
			if (op == 3)
				printf ("Diferença do instante um para o estante 3: %.2f",bitcoins());
				
				
	getch();		
				
	}while (op != 0);
}
