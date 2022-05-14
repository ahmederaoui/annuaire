#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

liste_t*  creercontact(contact_t *contact){
	liste_t * nouveau;
	nouveau=(liste_t*)malloc(sizeof(liste_t));
	nouveau->contact=contact ;
	nouveau->suive=NULL;
	nouveau->prec=NULL;
	return nouveau ; 
}
int estvide(liste_t *liste){
	if (liste == NULL)
		return 0 ;
	else 
		return 1;
}

rep_t * ajoutercontact(rep_t* rep,contact_t *contact ){
	int index ;
	liste_t *tp,*temp ;
	char c;
	c= tolower(contact->name[0]);
	index = atoi (c) - 97;
	liste_t * nouveau = creercontact(contact);
	int v = estvide(rep->table[index]);
	if( v== 0){
		rep->table[index]=nouveau ;
		rep->table[index]->nbr+=1;
		rep->nbrg+=1;
		return rep ;
	}
	else{
		
		tp = rep->table[index];
		if(strcmp(contact->name,tp->contact->name)<= 0) {
			nouveau->suive=tp;
			nouveau->prec=NULL;
			rep->table[index]= nouveau;
			rep->table[index]->nbr+=1;
			rep->nbrg+=1;
			free(tp);
			return rep ;

		}
		
		while (tp != NULL)
		{
			if(strcmp(contact->name,tp->contact->name)<= 0){
				nouveau->suive=tp;
				nouveau->prec=tp->prec;
				tp->prec=nouveau;
				rep->table[index]->nbr+=1;
		        rep->nbrg+=1;
				free(tp);
				free(temp);
				return rep ;
			}
			temp=tp;
			tp=tp->suive;
		}
		temp->suive=nouveau;
		nouveau->prec=temp;
		rep->table[index]->nbr+=1;
		rep->nbrg+=1;
		free(tp);
		free(temp);
		return rep;

		

	}
	return rep ;
}

rep_t* supprimercontact(rep_t *rep,contact_t* contact){
	int index ;
	liste_t *tp ;
	char c;
	c= tolower(contact->name[0]);
	index = atoi (c) - 97;
	tp= rep->table[index];
	
	while(tp!=NULL){
		if(strcmp(tp->contact->name,contact->name)==0){
			tp->prec->suive=tp->suive;
			tp->suive->prec=tp->prec;
			tp->prec=NULL;
			tp->suive = NULL;
			rep->table[index]->nbr-=1;
		    rep->nbrg-=1;
			free(tp);
			return rep ; 			
		}
		tp=tp->suive;

	}
}
contact_t* cherchername(rep_t * rep, char *name ){
	int index ;
	liste_t *tp ;
	char c;
	c= tolower(name[0]);
	index = atoi (c) - 97;
	int v = estvide(rep->table[index]);
	if( v==0){
		printf("le nom n'existe pas\n");
		return ;
	}
	tp= rep->table[index];
	while (tp)
	{
		if (strcmp(tp->contact->name,name)==0){
			printf("le nom est %s \n",tp->contact->name);
			printf("l'email est %s\n",tp->contact->email);
			printf("le numero de telephone est %s\n",tp->contact->phone);
			return tp->contact ;
			free(tp);
		}
		tp=tp->suive;
	}
	printf("le nom n'existe pas\n");
	free(tp);
	return ;
	

}

void afficherrep(rep_t *rep){
	int i ;
	char c ;
	liste_t * tp;
	for(i=0, c='a';i<26,c='z';i++){
		int j=1;
		printf("les contacts commencées par %c >>\n ",c);
		tp =rep->table[i];
		while(tp=!NULL){
			printf("  le contact numero %d  : \n",j);
			printf("        - le nom est %s .\n", rep->table[i]->contact->name);
			printf("        - le telephone est %s .\n", rep->table[i]->contact->phone);
			printf("        - l'email' est %s .\n", rep->table[i]->contact->email);
			tp=tp->suive;
			j++;
		}
	}
}