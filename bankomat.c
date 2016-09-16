#include <stdio.h>
#include <stdbool.h>

//zapros na terminal ili bankomat
//bankomat
	//zapros nomera scheta
	//proverka scheta
	//balans
	//sniatie
//terminal
	//zapros nomera scheta
	//proverka scheta
	//balans
	//popolnenie


char Bankomat_or_terminal()
{
    char vibor = '0';
    printf("\nchem hotite vjspolzovatsa?\n\nBANKOMAT    1.\nTERMINAL    2.\nEXIT        3.\n\nVvedite vash vibor: ");
    while (vibor<'1' || vibor>'3')
    {
       	scanf(" %c", &vibor);
       	if (vibor <'1' || vibor > '3')
       		printf("\nNepravlnij vvod, vvedite 1, 2 ili 3: ");
    }
    return vibor;
}

void Balance(int schet, int* scheta)
{
	printf("Vash balance   %i$\n", scheta[schet]);
}

void Popolnenie(int schet, int* scheta)
{
	int cashin;
	printf("\nNa skol'ko jelaete popolnit'?   ");
	scanf(" %i", &cashin);
	if (cashin<1)
	{
		printf("Nevozmojno\n");
	}
	else
	{
		scheta[schet]+=cashin;
		printf("\nVash schet popolnen na %i$\n", cashin);
	}
}

void Vidacha(int schet, int* scheta)
{
	int vidacha;
	printf("\nSkol'ko jelaete snat'?   ");
	scanf(" %i", &vidacha);
	if (vidacha > scheta[schet])
	{
		printf("nedostatochno sredstv, popolnite schet v terminale\n");
	}
	else if(vidacha <1)
	{
		printf("Nevozmojno\n");
	}
	else
	{
		printf("s vashego scheta spisano %i$,zaberite vashi den'gi\n   %i$", vidacha, vidacha);
		scheta[schet]-=vidacha;
	}
}

bool Proverka_scheta(int size, int schet)
{
	if (schet > 0 && schet < size)
	{
		return true;
	}
	printf("\nnepravil'nij nomer scheta, pjprobyjte esche");
	return false;
}

void Terminal ( int size, int* scheta)
{
    int schet = 0;
    printf("\nVvedite nomer scheta: ");
    scanf(" %i", &schet);
    if (Proverka_scheta ( size, schet ))
    {
        char vibor = '0';
        printf("\nPosmotret balans    1\nPopolnit' schet     2\n");
        while (vibor<'1' || vibor>'2')
        {
       	    scanf(" %c", &vibor);
       	    if (vibor !='1' && vibor != '2')
       	    {
       	    	printf("\nNepravlnij vvod, vvedite 1 ili 2: ");
       	    }
        }
        if (vibor == '1')
        {
        	Balance (schet, scheta);        
        }
        else
        {
            Popolnenie (schet, scheta);
        }
        
    }
}

void Bankomat ( int size, int* scheta)
{
    int schet = 0;
    printf("\nVvedite nomer scheta: ");
    scanf(" %i", &schet);
    if (Proverka_scheta ( size, schet ))
    {
        char vibor = '0';
        printf("\nPosmotret balance    1\nVidacha nalichnih   2\n");
        while (vibor<'1' || vibor>'2')
        {
       	    scanf(" %c", &vibor);
       	    if (vibor !='1' && vibor != '2')
       	    	printf("\nNepravlnij vvod, vvedite 1 ili 2: ");
        }
        if (vibor == '1')
        {
        	Balance (schet, scheta);        
        }
        else
        {
            Vidacha (schet, scheta);
        }
        
    }
}


int main()
{
	const int size = 100;
	int scheta[size];
	for (int i=0; i<size; i++)
		scheta[i] = 0;
		
	char b_or_t = '1';
	
	while (b_or_t == '1' || b_or_t == '2')
	{
		char b_or_t = Bankomat_or_terminal();
		if( b_or_t == '1')
		{
			Bankomat (size, scheta);
		}
		else if(b_or_t == '2')
		{
			Terminal (size, scheta);
		}
		else
		{
			break;
		}
				
	}
}
