#include <stdio.h>
#include "pilha.h"

void retiraImpares(tp_pilha *p){
	tp_pilha novaPilha;
	inicializaPilha(&novaPilha);
	int i = 0;
	while(i < p->topo){
		if(p->item[i] % 2 == 0){
			push(&novaPilha, p->item[i]);
		} 
		i++;
	}
	*p = novaPilha;
}

int pilhasIdenticas(tp_pilha *p1, tp_pilha *p2) {
    if (p1->topo != p2->topo) {
        return 0;
    }

    for (int i = 0; i <= p1->topo; i++) {
        if (p1->item[i] != p2->item[i]) {
            return 0;
        }
    }

    return 1;
}

void empilhaSobre(tp_pilha *p1, tp_pilha *p2) {
    tp_pilha pilhaAux;
    inicializaPilha(&pilhaAux);

    while (!pilhaVazia(p2)) {
        push(&pilhaAux, p2->item[p2->topo]);
        p2->topo--;
    }

    while (!pilhaVazia(&pilhaAux)) {
        push(p1, pilhaAux.item[pilhaAux.topo]);
        pilhaAux.topo--;
    }
}

int main(void){
	
//	  1º Atividade
//    tp_pilha minhaPilha;
//    inicializaPilha(&minhaPilha);
//    
//    push(&minhaPilha, 1);
//    push(&minhaPilha, 2);
//    push(&minhaPilha, 3);
//    push(&minhaPilha, 4);
//    push(&minhaPilha, 5);
//    
//    printf("Pilha original: ");
//    imprimePilha(minhaPilha);
//    
//    retiraImpares(&minhaPilha);
//    
//    imprimePilha(minhaPilha);
    
    
    //2º Atividade
//    tp_pilha pilha1, pilha2;
//
//    inicializaPilha(&pilha1);
//    inicializaPilha(&pilha2);

//    push(&pilha1, 1);
//    push(&pilha1, 2);
//    push(&pilha1, 3);
//    
//    push(&pilha2, 1);
//    push(&pilha2, 2);
//    push(&pilha2, 5);
//    
//    if (pilhasIdenticas(&pilha1, &pilha2)) {
//        printf("As pilhas sao identicas.\n");
//    } else {
//        printf("As pilhas nao sao idênticas.\n");
//    }

//	3º Atividade

	tp_pilha pilha1, pilha2;

    inicializaPilha(&pilha1);
    inicializaPilha(&pilha2);
    
    push(&pilha1, 1);
    push(&pilha1, 2);
    push(&pilha1, 3);
    
    push(&pilha2, 4);
    push(&pilha2, 5);
    push(&pilha2, 6);
    
    empilhaSobre(&pilha1, &pilha2);
    
    printf("Pilha apos empilhar pilha2 sobre pilha1: ");
    imprimePilha(pilha1);
    
    return 0;
}
