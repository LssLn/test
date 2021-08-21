#define _CRT_SECURE_NO_WARNINGS
#define N 23
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s1 {
	char nome[100]; //nome prodotto
	int numero;  // quantita
	int reparto; // in base a cui carico nell'array di liste, fino a N
} elemento;

typedef struct s2 {
	elemento info;
	struct s2* next;
} nodo, * lista;

//Se inserisco nel DB un oggetto gi� presente per cambiarlo di reparto
//lista RicercaOggetto(lista l, char* nome) {
//
//	while (l != NULL) {
//		if (strcmp(strcmp(nome, l->info.nome) == 0))
//			return (l);
//		l = l->next;
//	}
//	return(l);
//}


void InserisciTestaLista(lista* l, elemento e) {
	lista aux;

	if ((aux = (lista)malloc(sizeof(nodo))) == NULL) {
		printf("Errore: impossibile allocare memoria");
		exit(1);
	}
	aux->info = e;
	aux->next = *l;
	*l = aux;
}

void inserisci(lista v[], elemento e) {

	InserisciTestaLista(&v[e.reparto], e);

}

int carica(char* file, lista *l) {
	FILE* f;
	elemento e;
	f = fopen(file, "r");
	if (f == NULL) {
		return 0;
	}
	int cont = 0;
	while (fscanf(f, "%s %d %d", e.nome, &e.numero, &e.reparto) == 3) {
		inserisci(l, e);
	}
}

void index() {
	//printf("\033[1; 31m"); //RED
	printf("\033[1;33m"); //YELLOW 
	printf("\n*************************************************************************"); 
	printf("\n* REPARTO 0  >> FRUTTA E ORTAGGI                                         ");
	printf("\n* REPARTO 1  >> SALUMI E PROSCIUTTI                                      ");
	printf("\n* REPARTO 2  >> FORMAGGI MOZZARELLE E YOGURT                             ");
	printf("\n* REPARTO 3  >> ALCOLICI                                                 ");
	printf("\n* REPARTO 4  >> STUZZICHERIA SNACK E PRODOTTI FORNO                      ");
	printf("\n* REPARTO 5  >> BEVANDE 												   ");
	printf("\n* REPARTO 6  >> BISCOTTI BRIOCHE SUCCHI								   ");
	printf("\n* REPARTO 7  >> DROGHERIA (LATTE ZUCCHERO NUTELLA)					   ");
	printf("\n* REPARTO 8  >> PREP (UOVA FARINA SALE OLIO ACETO) E LEGUMI			   ");
	printf("\n* REPARTO 9  >> SOTTOLIO												   ");
	printf("\n* REPARTO 10 >> SALSE E CONDIMENTI									   ");
	printf("\n* REPARTO 11 >> SURGELATI VERDURE										   ");
	printf("\n* REPARTO 12 >> DROGHERIA 2 (BUSTINE DOLCI, CIOCC,FRUTTE SCIROPP)        ");
	printf("\n* REPARTO 13 >> RISO E PASTA											   ");
	printf("\n* REPARTO 14 >> CUCINA (TOVAGL POSATE BICCHIERI FAZZOL)				   ");
	printf("\n* REPARTO 15 >> DETERSIVI PER CASA E BUSTE							   ");
	printf("\n* REPARTO 16 >> GASTRONOMIA MACELLERIA								   ");
	printf("\n* REPARTO 17 >> SPEZIE												   ");
	printf("\n* REPARTO 18 >> ACQUA E UTILITA' (STAGNOLA C.FORNO)					   ");
	printf("\n* REPARTO 19 >> DETERSIVI BUCATO										   ");
	printf("\n* REPARTO 20 >> SURGELATI PATATINE SOFF PESCE						       ");
	printf("\n* REPARTO 21 >> CEREALI												   ");
	printf("\n* REPARTO 22 >> IGIENE												   ");
	printf("\n*************************************************************************");	 
}

int stampa(lista l) {
	int cont = 0;
	while (l != NULL) {
		printf("\033[1;36m"); //CYAN
		printf("\n\t	>>  %s  x %d", l->info.nome, l->info.numero);
		cont++;
		l = l->next;
	}
	return cont;
}


int menu() {
	int x;
	printf("\033[0m"); // RESET COLOR
	printf("\n\n	1)Stampa\n	Esci\n\n");
	scanf("%d", &x);
	return x;
}


int main() {
	lista v[N]; //definire quanti reparti si hanno (riga 2)
	elemento e;
	int scelta;

	for (int i = 0; i < N; i++)
		v[i] = NULL;

	char nome_file[30] = "spesa.txt";

	carica(nome_file, v);

	index();
	

	do {
		scelta = menu();
		switch (scelta) {
		case 1:
			for (int i = 0; i < N; i++) {
				if (v[i] != NULL) {
					printf("\033[1;32m"); //GREEN
					printf("\n		_________________________");
					printf("\n		[	REPARTO : %d	]", i);
					stampa(v[i]);
				}
			}
			break;
		}
	} while (scelta != 0);
	return 0;
}


