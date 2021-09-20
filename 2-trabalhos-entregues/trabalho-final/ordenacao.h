/* José Clerton Farias Gomes Filho – Matrícula: 397271
Robertson da Silva Nascimento – Matrícula: 391242 */
#ifndef ORDENACAO_H
#define ORDENACAO_H

// Algoritmo BubbleSort
// Ordena um vetor A[0..n-1]
void BubbleSort(int n, int A[]);

// Algoritmo CockTailSort
// Esta funcao ordena um vetor A[0..n-1]  
void CocktailSort(int n, int A[]);

// Ordena o vetor A[0..n-1] utilizando o algoritmo SelectionSort.
void SelectionSort(int n, int A[]);

// Ordena o vetor A[] utilizando o algoritmo SelectionSort de maneira recursiva.
void SelectionSortRecursiv(int n, int A[], int ind);

// Ordena o vetor A[] utilizando o algoritmo InsertionSort.
void InsertionSort(int n, int A[]);

// Ordena o vetor A[] utilizando o algortimo InsertionSort de maneira recursiva.
void InsertionSortRecursiv(int n, int A[]);

// Ordena o vetor A[] utilizando o algoritmo MergeSort recursivamente.
void MergeSortRecursiv(int A[], int p, int r);

// Odena o vetor A[] utilizando o algoritmo MergeSort iterativamente.
void MergeSort(int n, int A[]);

// Ordena o vetor A[] utilizando o algoritmo QuickSort recursivamente.
void QuickSortRecursiv(int A[] ,int p, int r);

// Ordena o vetor A[] utilizando a versão iterativa do algoritmo QuickSort.
void QuickSort(int A[], int e, int d);

#endif