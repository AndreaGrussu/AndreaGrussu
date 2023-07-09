#include <stdio.h>
#include <stdlib.h>

typedef struct elem_lista{
	int valore;
	struct elem_lista *succ;
}elem_lista_t;

void metti_in_coda(elem_lista_t **uscita,
		   elem_lista_t **ingresso,
		   int valore)
{
	elem_lista_t *nuovo;

	nuovo = (elem_lista_t*) malloc (sizeof(elem_lista_t));
	nuovo->valore = valore;
	nuovo->succ = NULL;
	if(*ingresso != NULL)
		(*ingresso)->succ = nuovo;
	else
		*uscita = nuovo;
	*ingresso = nuovo;

}

elem_lista_t *togli_da_coda(elem_lista_t **uscita,
				elem_lista_t **ingresso)
{
	elem_lista_t *elem;

	elem = *uscita;
	if(*uscita != NULL)
	{
		*uscita = (*uscita)->succ;
		if(*uscita == NULL)
			*ingresso = NULL;
	}
	return(elem);

}

int main(void)
{
	int n_coda,
	    n_rimuovi_coda,
	    max;
	int x,i;
	int valore_random;
	elem_lista_t *uscita = NULL;
	elem_lista_t *ingresso = NULL;
	srand(time(NULL));
	
	printf("\nquanti elementi vuoi inserire nella coda: ");
	scanf("%d",&n_coda);
	for(i = 0; (i <n_coda); i++)
	{
		valore_random = rand() % 100;
		printf("%d° elemento inserito: %d\n",i+1, valore_random);

		metti_in_coda(&uscita,&ingresso,valore_random);
	}

	elem_lista_t *current = uscita;
	while(current != NULL)
	{
		printf("valore inseriti nella coda: ");

		printf("%d\n", current->valore);
		current = current->succ;
	}

	printf("\nquanti elementi vuoi togliere dalla coda: ");
	scanf("%d",&n_rimuovi_coda);
	for(x = 0; (x < n_rimuovi_coda); x++)
	{
		elem_lista_t *removed = togli_da_coda(&uscita,&ingresso);
		free(removed);
	}	


	current = uscita;
	while(current != NULL)
	{
		printf("valore rimanenti nella coda: ");

		printf("%d\n", current->valore);
		current = current->succ;
	}
	
	current = uscita;
	printf("inserisci il valore da cui trovare quelli maggiori:");
	scanf("%d",&max);
	while(current != NULL)
	{
		if(current->valore > max)
		{
			printf("valore maggiori di %d: ",max);
			printf("%d\n",current->valore);
		}
		current = current->succ;
			
	}
	
	






































	return 0;
}
