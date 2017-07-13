//Estruturas de Dados I
//hash table com chainning (listas encadeadas)

#include <stdio.h>
#include <stdlib.h>




//estrutura dos nodos da lista
typedef struct nodo{
    int key;
    struct nodo * next;
} nodo;

//cabeça para a lista
typedef struct head{
    nodo * first, * last;
} head;


//estrutura da tabela hash
typedef struct hashTable{
    head ** table;
    int size;
} hash;


//inicia a cabeça
head * head_start(){
    head * new = malloc(sizeof(head));
    
    new->first = new->last = NULL;

    return new;
}

//insere a chave no final da lista apontada pela cabeça h
void insert_nodo( head * h, int key){
    nodo * new = malloc(sizeof(nodo));
    
    new->key = key;
    new->next = NULL;

    //se h->first não é nulo
    if(h->first)
        h->last->next = new;
    else 
        h->first = new;

    h->last = new;     
}

//inicia a hash
hash * hash_start(int v){
    hash * new_hash = malloc(sizeof(hash));
    int i;

    new_hash->size = v;    
    new_hash->table = malloc(v*sizeof(head)); //inicia vetor de ponteiros para a cabeça
    
    //inicia a cabeça de todas as listas da tabela
    for (i = 0; i < v; i++)
        new_hash->table[i] = head_start();
    
    return new_hash; 
}

nodo * search_list(head * h, int key){
    nodo * aux = h->first;
    
    while(aux){
        if(aux->key == key)break;
        aux = aux->next;    
    }

    return aux;
}


//função de hash
int hash_func(int key, int hash_size){
    return key % hash_size;
}


void insert_hash(hash * h, int key){
    //insere a chave na posição mapeada pela função de hash
    insert_nodo(h->table[hash_func(key, h->size)], key); 
}

void hash_search(hash * h, int key){
    //busca o nodo que possui chave na posição mapeada pela função de hash
    nodo * s = search_list(h->table[hash_func(key, h->size)] ,key);
    
    if(s) printf("Key: %d", key);
    else printf ("There's no key=%d\n", key);

}


void print_hash(hash * h){
	int i;
	nodo * aux;


	for ( i = 0; i < h->size; i++){
		aux = h->table[i]->first;
		printf("%d ->", i);
		while(aux){
			printf("%d ", aux->key);
			aux=aux->next;
		}
		printf("\n");
	}

}

int main ( void ){

    hash * h = hash_start(8);   //inicia uma tabela de hash com tamanho 47

    insert_hash(h,10);
    insert_hash(h,150);
    insert_hash(h,101);
    insert_hash(h,15340);
    insert_hash(h,140);
    insert_hash(h,17560);
    insert_hash(h,1340);
    insert_hash(h,180);
    

    hash_search(h,1530);
    hash_search(h,1510);
    hash_search(h,180);
    hash_search(h,150);

	print_hash(h);


    return 0;
}














