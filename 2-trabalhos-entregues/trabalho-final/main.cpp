/* José Clerton Farias Gomes Filho – Matrícula: 397271
Robertson da Silva Nascimento – Matrícula: 391242 */

#include <iostream>
#include <fstream>
#include <chrono>
//#include <windows.h>
#include <string>
#include "ordenacao.h"
using namespace std;

// ----------------------------------------------------------------------

/** 
 * Funcao que gera arquivos binarios, cada um contendo numeros aleatorios
 * Essa funcao recebe um array 'vetor_tam' que contem todos os tamanhos N
 * de vetores aleatorios que serao gerados. O parametro 'num_iteracoes' eh
 * o tamanho do array 'vetor_tam' 
 */
void gera_dados(int num_iteracoes, const int vetor_tam[]) {
	for(int n = 0; n < num_iteracoes; n++) {
		// para cada tamanho n, sao gerados 5 vetores de tamanho n aleatorios
		for(int semente = 0; semente < 5; semente++) {	
			std::string nome_arquivo = "dados/random"+std::to_string(n)+"_"+std::to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); // gera semente
			int r;
			int tamanho_vetor = vetor_tam[n];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
				r = rand(); // gera numero aleatorio
				fout.write((char*)&r, sizeof(r));
			}
			fout.close();
		}
	}
}

// ------------------------------------------------------------------

/*
 * Recebe um vetor de inteiros A[0..n-1] como argumento e o preenche
 * com os n inteiros contidos no arquivo binario de mesmo nome que a 
 * string nomeArquivo
 */
void ler_dados(int n, int A[], const char *nomeArquivo) {	
	ifstream fin(nomeArquivo, ios::binary); // abre arquivo para leitura
	for (int i = 0; i < n; i++) 
	{
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor
	}
	fin.close(); // fecha o arquivo de leitura
}

void printVetor(int tam, int vet[]){
	for(int i=0; i < tam; i++)
		cout << vet[i] << " ";
	cout << endl;
}

// ----------------------------------------------------------------------------
// Funcao Principal
int main(){ 
	//SetConsoleOutputCP(CP_UTF8);
	// Os tamanhos dos vetores a serem testados estao
	// guardados neste vetor 'tam'
	const int tam[] = {500, 1000, 2000, 3000, 4000, 5000, 6000, 7000,8000, 9000, 10000, 11000, 12000, 
	13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000};
	
	int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'
	
	// Etapa 1: Gerar arquivos contendo numeros aleatorios
	gera_dados(TOTAL_N, tam);
	int opcao = 0;
	while(opcao != 11){
		string menu = "Infome qual algoritmo de ordenação deseja executar:\n";
		menu += " 1  | SelectionSort iterativo.\n";
		menu += " 2  | SelectionSort recursivo.\n";
		menu += " 3  | InsertionSort iterativo.\n";
		menu += " 4  | InsertionSort recursivo.\n";
		menu += " 5  | MergeSort recursivo.\n";
		menu += " 6  | MergeSort iterativo.\n";
		menu += " 7  | QuickSort recursivo.\n";
		menu += " 8  | QuickSort iterativo.\n";
		menu += " 9  | CocktailSort iterativo.\n";
		menu += " 10 | BubbleSort iterativo.\n";
		menu += " 11 | Fechar programa.\n";
		cout << menu;
		
		cin >> opcao;

		switch(opcao){
			case 1:{
				// ------------------------------------------------------------
				// Execução do SelectionSort
				// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
				// um vetor de inteiros com os dados lidos.
				std::ofstream ofs2("resultados/resultadoSelection.txt", std::ofstream::out ); // abre arquivo de resultados do SelectionSort
				for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
			
					long double duracao_media_selection = 0.0;
					int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
					int vetor[tamanho_vetor]; // cria vetor a ser ordenado
					
					// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
					// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
					// Chamar o SelectionSort para ordena-los e, entao, calcular o tempo medio de 
					// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
					for(int semente = 0; semente < 5; semente++){	
						string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
					
						ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
						
						// SelectionSorte ---------------------------------------------------------
						// obtendo o tempo inicial
						auto ini2 = std::chrono::high_resolution_clock::now();
					
						
						SelectionSort(tamanho_vetor, vetor); // ordena o vetor usando o SelectionSort
						
						
						auto fim2 = std::chrono::high_resolution_clock::now(); // obtendo o tempo final
					
						// obtendo a duracao total da ordenacao
						auto duracao_selection = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
						
						duracao_media_selection += duracao_selection;			
					}	
					
					duracao_media_selection = duracao_media_selection / 5.0;
					cout << "[Selection] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_selection << " microssegundos" << endl;
					ofs2 << tamanho_vetor << " " << duracao_media_selection << "\n"; // grava no arquivo de resultados do selection
				}
				ofs2.close(); // fecha arquivo de resultados do Selection Sort
				// ------------------------------------------------------------
				cout << "Os dados mostradas foram salvos em resultados/resultadoSelection.txt" << endl;
				break;
			}
			case 2:{
				// ------------------------------------------------------------
				// Execução do SelectionSort Recursivamente
				// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
				// um vetor de inteiros com os dados lidos.
				std::ofstream ofs2("resultados/resultadoSelectionRecursiv.txt", std::ofstream::out); // abre arquivo de resultados do SelectionSortRecursiv
				
				for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
					
					long double duracao_media_Selection = 0.0;
					int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
					int vetor[tamanho_vetor]; // cria vetor a ser ordenado
					
					// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
					// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
					// Chamar o Selectionsort para ordena-los e, entao, calcular o tempo medio de 
					// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
					for(int semente = 0; semente < 5; semente++){	
						string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
					
						ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
						
						// SelectionSort ---------------------------------------------------------
						// obtendo o tempo inicial
						auto ini2 = std::chrono::high_resolution_clock::now();

						
						SelectionSortRecursiv(tamanho_vetor, vetor, 0); // ordena o vetor usando o SelectionSortRecursiv
						

						// obtendo o tempo final
						auto fim2 = std::chrono::high_resolution_clock::now();
					
						// obtendo a duracao total da ordenacao
						auto duracao_Selection = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
						
						duracao_media_Selection += duracao_Selection;			
					}	
					
					duracao_media_Selection = duracao_media_Selection / 5.0;
					cout << "[SelectionRecursiv] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_Selection << " microssegundos" << endl;
					ofs2 << tamanho_vetor << " " << duracao_media_Selection << "\n"; // grava no arquivo de resultados do Selection Recursiv
				}
				
				ofs2.close(); // fecha arquivo de resultados do SelectionSortRecursiv 
				// ------------------------------------------------------------
				cout << "Os dados mostradas foram salvos em resultados/resultadoSelectionRecursiv.txt" << endl;
				break;
			}
			case 3:{
				// ------------------------------------------------------------
				// Execução do InsertionSort
				// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
				// um vetor de inteiros com os dados lidos.
				std::ofstream ofs2("resultados/resultadoInsertion.txt", std::ofstream::out ); // abre arquivo de resultados do Insertionsort

				for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
					
					long double duracao_media_Insertion = 0.0;
					int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
					int vetor[tamanho_vetor]; // cria vetor a ser ordenado
					
					// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
					// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
					// Chamar o Insertionsort para ordena-los e, entao, calcular o tempo medio de 
					// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
					for(int semente = 0; semente < 5; semente++){	
						string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
					
						ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
						
						// InsertionSort ---------------------------------------------------------
						// obtendo o tempo inicial
						auto ini2 = std::chrono::high_resolution_clock::now();
					
						
						InsertionSort(tamanho_vetor, vetor); // ordena o vetor usando o InsertionSort
						

						// obtendo o tempo final
						auto fim2 = std::chrono::high_resolution_clock::now();
					
						// obtendo a duracao total da ordenacao
						auto duracao_Insertion = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
						
						duracao_media_Insertion += duracao_Insertion;			
					}	
					
					duracao_media_Insertion = duracao_media_Insertion / 5.0;
					cout << "[Insertion] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_Insertion << " microssegundos" << endl;
					ofs2 << tamanho_vetor << " " << duracao_media_Insertion << "\n"; // grava no arquivo de resultados do Insertion
				}

				ofs2.close(); // fecha arquivo de resultados do Insertion Sort
				// ------------------------------------------------------------
				cout << "Os dados mostradas foram salvos em resultados/resultadoInsertion.txt" << endl;
				break;
			}
			case 4:{
				// ------------------------------------------------------------
				// Execução do InsertionSort Recursivamente
				// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
				// um vetor de inteiros com os dados lidos.
				std::ofstream ofs2("resultados/resultadoInsertionRecursiv.txt", std::ofstream::out ); // abre arquivo de resultados do InsertionSortRecursiv

				for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
					
					long double duracao_media_Insertion = 0.0;
					int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
					int vetor[tamanho_vetor]; // cria vetor a ser ordenado
					
					// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
					// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
					// Chamar o Insertionsort para ordena-los e, entao, calcular o tempo medio de 
					// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
					for(int semente = 0; semente < 5; semente++){	
						string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
					
						ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
						
						// InsertionSort ---------------------------------------------------------
						// obtendo o tempo inicial
						auto ini2 = std::chrono::high_resolution_clock::now();
					
						
						InsertionSortRecursiv(tamanho_vetor, vetor); // ordena o vetor usando o InsertionSortRecursiv
						

						// obtendo o tempo final
						auto fim2 = std::chrono::high_resolution_clock::now();
					
						// obtendo a duracao total da ordenacao
						auto duracao_Insertion = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
						
						duracao_media_Insertion += duracao_Insertion;			
					}	
					
					duracao_media_Insertion = duracao_media_Insertion / 5.0;
					cout << "[InsertionRecursiv] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_Insertion << " microssegundos" << endl;
					ofs2 << tamanho_vetor << " " << duracao_media_Insertion << "\n"; // grava no arquivo de resultados do Insertion Recursiv
				}

				ofs2.close(); // fecha arquivo de resultados do Insertion Sort Recursiv
				// ------------------------------------------------------------
				cout << "Os dados mostradas foram salvos em resultados/resultadoInsertionRecursiv.txt" << endl;
				break;
			}
			case 5:{
				// ------------------------------------------------------------
				// Execução do MergeSort Resursiv
				// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
				// um vetor de inteiros com os dados lidos.
				std::ofstream ofs2("resultados/resultadoMergeResursiv.txt", std::ofstream::out ); // abre arquivo de resultados do Mergesort Resursiv

				for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
					
					long double duracao_media_Merge = 0.0;
					int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
					int vetor[tamanho_vetor]; // cria vetor a ser ordenado
					
					// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
					// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
					// Chamar o Mergesort para ordena-los e, entao, calcular o tempo medio de 
					// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
					for(int semente = 0; semente < 5; semente++){	
						string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
					
						ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
						
						// MergeSort ---------------------------------------------------------
						// obtendo o tempo inicial
						auto ini2 = std::chrono::high_resolution_clock::now();
					
						
						MergeSortRecursiv(vetor, 0, tamanho_vetor-1); // ordena o vetor usando o MergeSortRecursiv
						

						// obtendo o tempo final
						auto fim2 = std::chrono::high_resolution_clock::now();
					
						// obtendo a duracao total da ordenacao
						auto duracao_Merge = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
						
						duracao_media_Merge += duracao_Merge;			
					}	
					
					duracao_media_Merge = duracao_media_Merge / 5.0;
					cout << "[MergeRecursiv] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_Merge << " microssegundos" << endl;
					ofs2 << tamanho_vetor << " " << duracao_media_Merge << "\n"; // grava no arquivo de resultados do MergeSortRecursiv
				}

				ofs2.close(); // fecha arquivo de resultados do Merge Sort Recursiv
				// ------------------------------------------------------------
				cout << "Os dados mostradas foram salvos em resultados/resultadoMergeRecursiv.txt" << endl;
				break;
			}
			case 6:{
				// ------------------------------------------------------------
				// Execução do MergeSort
				// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
				// um vetor de inteiros com os dados lidos.
				std::ofstream ofs2("resultados/resultadoMerge.txt", std::ofstream::out ); // abre arquivo de resultados do Mergesort

				for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
					
					long double duracao_media_Merge = 0.0;
					int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
					int vetor[tamanho_vetor]; // cria vetor a ser ordenado
					
					// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
					// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
					// Chamar o Mergesort para ordena-los e, entao, calcular o tempo medio de 
					// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
					for(int semente = 0; semente < 5; semente++){	
						string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
					
						ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
						
						// MergeSort ---------------------------------------------------------
						// obtendo o tempo inicial
						auto ini2 = std::chrono::high_resolution_clock::now();
					
						
						MergeSort(tamanho_vetor, vetor); // ordena o vetor usando o MergeSort
						

						// obtendo o tempo final
						auto fim2 = std::chrono::high_resolution_clock::now();
					
						// obtendo a duracao total da ordenacao
						auto duracao_Merge = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
						
						duracao_media_Merge += duracao_Merge;			
					}	
					
					duracao_media_Merge = duracao_media_Merge / 5.0;
					cout << "[Merge] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_Merge << " microssegundos" << endl;
					ofs2 << tamanho_vetor << " " << duracao_media_Merge << "\n"; // grava no arquivo de resultados do Merge
				}

				ofs2.close(); // fecha arquivo de resultados do Merge Sort
				// ------------------------------------------------------------
				cout << "Os dados mostradas foram salvos em resultados/resultadoMerge.txt" << endl;
				break;
			}
			case 7:{
				// ------------------------------------------------------------
				// Execução do QuickSortRecursiv
				// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
				// um vetor de inteiros com os dados lidos.
				std::ofstream ofs2("resultados/resultadoQuickRecursiv.txt", std::ofstream::out ); // abre arquivo de resultados do QuicksortRecursiv

				for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
					
					long double duracao_media_Quick = 0.0;
					int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
					int vetor[tamanho_vetor]; // cria vetor a ser ordenado
					
					// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
					// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
					// Chamar o Quicksort para ordena-los e, entao, calcular o tempo medio de 
					// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
					for(int semente = 0; semente < 5; semente++){	
						string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
					
						ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
						
						// QuickSortRecursiv ---------------------------------------------------------
						// obtendo o tempo inicial
						auto ini2 = std::chrono::high_resolution_clock::now();
					
						
						QuickSortRecursiv(vetor, 0, tamanho_vetor-1); // ordena o vetor usando o QuickSortRecursiv
						

						// obtendo o tempo final
						auto fim2 = std::chrono::high_resolution_clock::now();
					
						// obtendo a duracao total da ordenacao
						auto duracao_Quick = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
						
						duracao_media_Quick += duracao_Quick;			
					}	
					
					duracao_media_Quick = duracao_media_Quick / 5.0;
					cout << "[QuickRecursiv] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_Quick << " microssegundos" << endl;
					ofs2 << tamanho_vetor << " " << duracao_media_Quick << "\n"; // grava no arquivo de resultados do Quick
				}

				ofs2.close(); // fecha arquivo de resultados do Quick Sort Recursivo
				// ------------------------------------------------------------
				cout << "Os dados mostradas foram salvos em resultados/resultadoQuickRecursiv.txt" << endl;
				break;
			}
			case 8:{
				// ------------------------------------------------------------
				// Execução do QuickSort
				// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
				// um vetor de inteiros com os dados lidos.
				std::ofstream ofs2("resultados/resultadoQuick.txt", std::ofstream::out ); // abre arquivo de resultados do QuickSort
				for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
			
					long double duracao_media_Quick = 0.0;
					int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
					int vetor[tamanho_vetor]; // cria vetor a ser ordenado
					
					// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
					// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
					// Chamar o QuickSort para ordena-los e, entao, calcular o tempo medio de 
					// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
					for(int semente = 0; semente < 5; semente++){	
						string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
					
						ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
						
						// QuickSorte ---------------------------------------------------------
						// obtendo o tempo inicial
						auto ini2 = std::chrono::high_resolution_clock::now();
					
						
						QuickSort(vetor, 0, tamanho_vetor-1); // ordena o vetor usando o QuickSort
						
						
						auto fim2 = std::chrono::high_resolution_clock::now(); // obtendo o tempo final
					
						// obtendo a duracao total da ordenacao
						auto duracao_Quick = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
						
						duracao_media_Quick += duracao_Quick;			
					}	
					
					duracao_media_Quick = duracao_media_Quick / 5.0;
					cout << "[Quick] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_Quick << " microssegundos" << endl;
					ofs2 << tamanho_vetor << " " << duracao_media_Quick << "\n"; // grava no arquivo de resultados do Quick
				}
				ofs2.close(); // fecha arquivo de resultados do Quick Sort
				// ------------------------------------------------------------
				cout << "Os dados mostradas foram salvos em resultados/resultadoQuick.txt" << endl;
				break;
			}
			case 9:{
				// ------------------------------------------------------------
				// Execucao do CocktailSort
				// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
				// um vetor de inteiros com os dados lidos.
				std::ofstream ofs("resultados/resultadoCocktail.txt", std::ofstream::out ); // abre arquivo de resultados do cocktail
				
				for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
					
					long double duracao_media_cocktail = 0.0;
					int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
					int vetor[tamanho_vetor]; // cria vetor a ser ordenado
					
					// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
					// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
					// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
					// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
					for(int semente = 0; semente < 5; semente++) {	
						string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
					
						ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
						
						// CocktailSort ------------------------------------------------------
						// obtendo o tempo inicial
						auto ini = std::chrono::high_resolution_clock::now();
					
						CocktailSort(tamanho_vetor, vetor); // ordena o vetor usando o CocktailSort
					
						// obtendo o tempo final
						auto fim = std::chrono::high_resolution_clock::now();
					
						// obtendo a duração total da ordenação
						auto duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
						
						duracao_media_cocktail += duracao_cocktail;
						
					}
					
					duracao_media_cocktail = duracao_media_cocktail / 5.0;
					cout << "[Cocktail] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_cocktail << " microssegundos" << endl;
					ofs << tamanho_vetor << " " << duracao_media_cocktail << "\n"; // grava no arquivo de resultados do cocktail
				}
				
				ofs.close(); // fecha arquivo de resultados do CockTail Sort
				// ------------------------------------------------------------
				cout << "Os dados mostradas foram salvos em resultados/resultadoCocktail.txt" << endl;
				break;
			}
			case 10:{
				// ------------------------------------------------------------
				// Execução do BubbleSort
				// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
				// um vetor de inteiros com os dados lidos.
				std::ofstream ofs2("resultados/resultadoBubble.txt", std::ofstream::out ); // abre arquivo de resultados do bubblesort
				
				for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
					
					long double duracao_media_bubble = 0.0;
					int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
					int vetor[tamanho_vetor]; // cria vetor a ser ordenado
					
					// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
					// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
					// Chamar o bubblesort para ordena-los e, entao, calcular o tempo medio de 
					// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
					for(int semente = 0; semente < 5; semente++){	
						string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
					
						ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
						
						// BubbleSort ---------------------------------------------------------
						// obtendo o tempo inicial
						auto ini2 = std::chrono::high_resolution_clock::now();
					
						BubbleSort(tamanho_vetor, vetor); // ordena o vetor usando o BubbleSort
					
						// obtendo o tempo final
						auto fim2 = std::chrono::high_resolution_clock::now();
					
						// obtendo a duracao total da ordenacao
						auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
						
						duracao_media_bubble += duracao_bubble;			
					}	
					
					duracao_media_bubble = duracao_media_bubble / 5.0;
					cout << "[Bubble] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
					ofs2 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
				}
				
				ofs2.close(); // fecha arquivo de resultados do Bubble Sort
				// ------------------------------------------------------------
				cout << "Os dados mostradas foram salvos em resultados/resultadoBubble.txt" << endl;
				break;
			}
			case 11:
				break;
			default:{
				cout << "Opção inválida." << endl;
				break;
			}
		}
	}
	return 0;
}
