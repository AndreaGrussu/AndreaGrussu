#include <stdio.h>
#include <stdlib.h>



typedef struct elem_lista
{
	int	valore;
	struct elem_lista *succ;
}elem_lista_t;

void metti_su_pila(elem_lista_t **cima, int valore)
{
	elem_lista_t *nuovo;

	nuovo = (elem_lista_t *) malloc (sizeof(elem_lista_t));
	nuovo->valore  = valore;
	nuovo->succ = *cima;
	*cima = nuovo;
}

elem_lista_t *togli_da_pila(elem_lista_t **cima)
{
	elem_lista_t *elem;

	elem = *cima;
	if(*cima !=NULL)
		*cima  = (*cima)->succ;
	return elem;
}
int main(void)
{
	int n_pila,
	    n_rimuovi_pila;
	int max;
	int i,x;
	int valore_random;
	elem_lista_t *cima = NULL;
	srand(time(NULL));

	printf("quanti elementi vuoi inserire nella pila: ");
	scanf("%d",&n_pila);
	for(i = 0; (i <n_pila); i++)
	{
		valore_random = rand() % 100;
		printf("%d° elemento inserito: %d\n",i+1, valore_random);

		metti_su_pila(&cima,valore_random);
	}
		
	printf("valore inseriti nella pila: ");
	elem_lista_t *current = cima;
	while(current != NULL)
	{
		printf("%d\n", current->valore);
		current = current->succ;
	}
	
	printf("quanti elementi vuoi togliere dalla pila: ");
	scanf("%d",&n_rimuovi_pila);
	for(x = 0; (x < n_rimuovi_pila); x++)
	{
		elem_lista_t *removed = togli_da_pila(&cima);
		free(removed);
	}	
	
	printf("valore rimanenti nella pila: ");
	current = cima;
	while(current != NULL)
	{
		printf("%d\n", current->valore);
		current = current->succ;
	}

	current = cima;
	printf("inserisci il valore da cui trovare quelli maggiori:");
	scanf("%d",&max);
	printf("valori maggiori di %d: ", max);
	while (current != NULL)
	{
		if(current->valore > max)
			printf("%d\n",current->valore);
		current = current->succ;
	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

