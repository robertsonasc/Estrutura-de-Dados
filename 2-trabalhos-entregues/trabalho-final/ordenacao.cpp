/* José Clerton Farias Gomes Filho – Matrícula: 397271
Robertson da Silva Nascimento – Matrícula: 391242 */
#include <iostream>
#include "ordenacao.h"
using namespace std;

void BubbleSort(int n, int A[]) {   
    for (int i = 0; i < n-1; i++)      
		for (int j = 0; j < n-i-1; j++)  
			if (A[j] > A[j+1])  
				swap(A[j], A[j+1]);  
}

void CocktailSort(int n, int A[]) { 
    bool trocou = true; 
    int inicio = 0; 
    int fim = n-1; 
  
    while (trocou) {  
        trocou = false; 
  
        // varre o vetor da esquerda para a direita, 
        // assim como o bubblesort 
        for (int i = inicio; i < fim; i++) 
            if (A[i] > A[i+1]) { 
                swap(A[i], A[i + 1]); 
                trocou = true; 
            } 
  
        // se nenhuma troca ocorreu, entao o vetor
        // ja esta ordenado 
        if (!trocou) 
			break;
		else
			// caso contrario, a variavel 'trocou' 
			// volta a ser 'false' para que a 
			// proxima iteração do loop while ocorra  
			trocou = false; 
  
        // como o elemento na posicao 'fim' e todos os 
        // elementos apos ele (se existirem) ja estao
        // ordenados, decrementamos 'fim'  
        fim--; 
  
        // varremos o vetor agora da direita para a esquerda, 
        // fazendo a mesma comparacao que no estagio anterior 
        for (int i = fim-1; i >= inicio; i--) 
            if (A[i] > A[i+1]) { 
                swap(A[i],A[i+1]); 
                trocou = true; 
            } 
  
        // incrementamos a variavel inicio', pois no 
        // ultimo loop 'for' o proximo menor elemento 
        // foi colocado no seu devido lugar 
        inicio++; 
    } 
}

void SelectionSort(int n, int A[]){
    for(int i = 0; i < n-1; i++) {
        int min = i ;
        for(int j = i+1; j < n; j++)
            if(A[j] < A[min])
                min = j;

        swap(A[i], A[min]);
    }
}

//Utilizada na função SelectionSortRecursiv, no intervalo de A[ind] até A[fim], retorna o indice do menor valor. 
int ind_min(int ind, int A[], int fim){ 
    if (ind == fim) 
        return ind; 
  
    int aux = ind_min(ind+1, A, fim); 
  
    if(A[ind] < A[aux])
        return ind;
    return aux;
}
void SelectionSortRecursiv(int n, int A[], int ind){
    if (ind == n) 
       return;
    int aux = ind_min(ind, A, n-1);

    if(aux != ind)
        swap(A[aux], A[ind]);

    SelectionSortRecursiv(n, A, ind+1);
}

void InsertionSort(int n, int A[]){
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = A [j];
        i = j-1;
        while (i >= 0 && A[i] > key){
            A[i +1] = A [i];
            i--;
        }
        A[i+1] = key;
    }
}

void InsertionSortRecursiv(int n, int A[]){
    if (n <= 1) return;

    InsertionSortRecursiv(n-1, A); 
    int aux = n-2; 
    int ultim = A[n-1]; 
    while(aux >= 0 && A[aux] > ultim){ 
        A[aux+1] = A[aux]; 
        aux--; 
    } 
    A[aux+1] = ultim; 
}

void Intercala(int A[], int p, int q, int r){
    int i, j, k;
    int *W = new int [r - p+1]; // Vetor auxiliar
    i = p;
    j = q+1;
    k = 0;
    // Intercala A[p..q] e A[q +1.. r]
    while(i <= q && j <= r) {
        if(A[i] <= A[j])
            W[k++] = A [i++];
        else
            W[k++] = A [j++];
    }
    while(i <= q) W[k++] = A[i++];
    while(j <= r) W[k++] = A[j++];
    // Copia vetor ordenado W para o vetor A
    for(i = p; i <= r; i++)
        A[i] = W[i-p];
    delete[] W;
}
void MergeSortRecursiv(int A[], int p, int r){
    if (p < r) {
        int q = (p + r) / 2; // Dividir
        // Conquistar
        MergeSortRecursiv(A, p, q);
        MergeSortRecursiv(A, q + 1, r);
        // Combinar
        Intercala(A, p, q, r);
    }
}

//Utilizada na função MergeSort, compara dois inteiros e retorna o menor deles
int min(int x, int y){
    if(x < y) 
        return x;
    else 
        return y;
}
void merge(int A[], int e, int m, int d){ 
    int i, j, k; 
    int n1 = m - e + 1; 
    int n2 =  d - m; 
  
    int E[n1], D[n2]; 
  
    for (i = 0; i < n1; i++) 
        E[i] = A[e+i]; 
    for (j = 0; j < n2; j++) 
        D[j] = A[m+1+j]; 

    i = 0; j = 0; k = e; 
    while(i < n1 && j < n2){ 
        if(E[i] <= D[j]){ 
            A[k] = E[i]; 
            i++; 
        } 
        else{ 
            A[k] = D[j]; 
            j++; 
        } 
        k++; 
    } 
    while(i < n1){ 
        A[k] = E[i]; 
        i++; 
        k++; 
    } 
    while(j < n2){ 
        A[k] = D[j]; 
        j++; 
        k++; 
    } 
}
void MergeSort(int n, int A[]){
	int tamanho_atual;  
	int esquerda; 

	for(tamanho_atual=1; tamanho_atual<=n-1; tamanho_atual = 2*tamanho_atual){ 
		for(esquerda=0; esquerda<n-1; esquerda += 2*tamanho_atual){  
			int meio = min(esquerda + tamanho_atual - 1, n-1); 
			int direita = min(esquerda + 2*tamanho_atual - 1, n-1); 
			merge(A, esquerda, meio, direita); 
		} 
	} 
} 

/* Recebe um vetor A[p..r] com p <= r.
2 * Rearranja os elementos do vetor e devolve
3 * j em p..r tal que A[p..j -1] <= A[j] < A[j +1.. r
].
4 */
int separa(int A[], int p, int r){
    int c = A[r];
    int j = p;
    for(int k = p; k < r; k++){
        if(A[k] <= c){
            swap(A[k], A[j]);
            j++;
        }
    }
    A[r] = A[j];
    A[j] = c;
    return j;
}
void QuickSortRecursiv(int A[], int p, int r){
    if(p < r){
        int i = separa(A, p, r);
        QuickSortRecursiv(A, p, i -1);
        QuickSortRecursiv(A, i+1, r);
    }
}

void QuickSort(int A[], int e, int d){ 
    int pilha[d - e + 1];    
    int top = -1; 
  
    pilha[++top] = e; 
    pilha[++top] = d; 
  
    while(top >= 0){ 
        d = pilha[top--]; 
        e = pilha[top--]; 

        int p = separa(A, e, d); 
        if (p - 1 > e) { 
            pilha[++top] = e; 
            pilha[++top] = p - 1; 
        } 
        if (p + 1 < d) { 
            pilha[++top] = p + 1; 
            pilha[++top] = d; 
        } 
    } 
} 