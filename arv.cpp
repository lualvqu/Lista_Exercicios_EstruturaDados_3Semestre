#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
	int info;
	struct arv *esq;
	struct arv *dir;
}Arv;

Arv *abb_cria(){
	return NULL;
}

int abb_vazia(Arv *a){
	return (a==NULL);
}

Arv *abb_insere(Arv *a, int v){
	if (a==NULL){
        a=(Arv*) malloc(sizeof(Arv));
		a->info=v;
		a->esq=a->dir=NULL;
     } 
     else 
	      if (v< a->info)
                   a->esq=abb_insere(a->esq,v);
          else    
                   a->dir=abb_insere(a->dir,v);
     return a;

}
Arv* abb_busca(Arv *r, int v){
    if (r==NULL) return NULL;
    if (r->info > v) 
                return abb_busca(r->esq,v);
    if (r->info < v)
                 return abb_busca(r->dir,v);
    return r; 	
}
// percurso em ordem  esq – raiz - dir
void abb_mostraEmOrdem(Arv *a){
    if (a!=NULL){
       abb_mostraEmOrdem(a->esq);
       printf("%d\t", a->info);
	   abb_mostraEmOrdem(a->dir); 	
	} 
}
//percurso em preordem  raiz – esq - dir
void abb_mostraPreOrdem(Arv *a){
    if (a!=NULL){
        printf("%d\t", a->info); 
       abb_mostraPreOrdem(a->esq);
       abb_mostraPreOrdem(a->dir); 	
	} 
}
//percurso em posordem  esq - dir - raiz
void abb_mostraPosOrdem(Arv *a){
    if (a!=NULL){
       abb_mostraPosOrdem(a->esq);
       abb_mostraPosOrdem(a->dir); 
	   printf("%d\t", a->info); 
	} 
}
Arv* abb_retira(Arv *r, int v) {
     if (r==NULL) return NULL;
     if(r->info > v) r->esq = abb_retira(r->esq, v);
     else if (r->info < v) r->dir = abb_retira(r->dir, v);
          else {      //achou o elemento 
                if ( r->esq ==NULL && r->dir ==NULL) { // no sem filhos
                     free(r);
                     r=NULL;   } 
                else  if (r->esq ==NULL) { //filho a direita            
                          Arv *t = r;
                          r=r->dir;
                          free(t);      }
                      else if( r->dir ==NULL) { //filho a esquerda
                                 Arv *t=r;
                                 r=r->esq;
                                 free(t);     }
                               else { //tem 2 filhos     
                                      Arv *f=r->esq;
                                      while (f->dir != NULL)f=f->dir;
                                      r->info =f->info;
                                      f->info=v;
                                      r->esq=abb_retira(r->esq,v);    }
                    }
                    return r;                           
}

//altura da arvore
int max2 (int a, int b)
{
       return (a>b)?a:b;
}       

int abb_altura(Arv *a)
{
       if (abb_vazia(a))
           return -1;
       return 1+ max2(abb_altura(a->esq),abb_altura(a->dir));   
}              

int somaNos(Arv *Tree){
	if (abb_vazia(Tree))
           return 0;
       return Tree->info + somaNos(Tree->esq) + somaNos(Tree->dir); 
}

void menu(){
	system("cls");
	printf("Escolha uma opcao: \n\n");
	printf("1- inserir\n");
	printf("2- remover\n");
	printf("3- mostrar\n");
	printf("4- procurar\n");
	printf("5- altura\n");
	printf("6- soma nos\n");
	printf("9- fim\n");
	printf("==> ");
}

int main(){
	Arv *a, *t;
	a=abb_cria();//inicializa a arvore
	int item, opmenu;
	do{
		menu();
		scanf("%d",&opmenu);
		switch(opmenu){
			case 1: //inserir
			   printf("Digite o valor a ser inserido: ");
			   scanf("%d",&item);
			   a=abb_insere(a,item);
			   break;
		    case 3: //mostrar
		       if(abb_vazia(a)){
		       	  printf("Arvore vazia!\n");
			   }
			    else{
			    	printf("Em Ordem\n");
			    	abb_mostraEmOrdem(a);
			    	printf("\n\nPre Ordem\n");
			    	abb_mostraPreOrdem(a);
			    	printf("\n\nPos Ordem\n");
			    	abb_mostraPosOrdem(a);
				}
				break;
			case 5: //altura da arvore
				printf("Altura da arvore: %d\n",abb_altura(a));
				break;
			case 6: //soma nos
				printf("Soma dos nos da arvore: %d\n",somaNos(a));
				break;
			
		}
		printf("\n\n");
		system("pause");
	}while(opmenu!=9);
}
