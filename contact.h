#ifndef __contact 
#define __contact 
typedef struct {
	char name[14];
	char phone[14];
	char email[30];
}contact_t;

typedef struct liste_T{
	contact_t * contact ;
	struct liste_T * suive;
	struct liste_T * prec;
	int nbr;
}liste_t;
 typedef struct {
 	liste_t *table[26];
 	int nbrg;
 }rep_t;
liste_t*  creercontact(contact_t*);
rep_t * ajoutercontact(rep_t* ,contact_t*);
rep_t* supprimercontact(rep_t *,contact_t* );
contact_t* cherchername(rep_t * , char * );

#endif 