//Clerton Filho - 397271
//Robertson Nascimento - 391242

#ifndef CONJUNTO_H
#define CONJUNTO_H

struct Elemento; 
#define capacidade 100

class Conjunto{
    
    private:
      int tamanho = 0;
      Elemento *vetor[capacidade]; // Quer dizer o todo conjunto suportará no máximo 100 elementos.

    public:
      Conjunto();
      ~Conjunto();

      /* Função insere – insere o elemento elem no conjunto A e
      retorna se a execução foi realizada com sucesso(1) ou
      não(0)*/
      bool insere(Elemento x);

      /*  /* Função união – Une os elementos do conjunto A e B em um conjunto C */      
	    static void uniao(Conjunto *A, Conjunto *B, Conjunto *C);

      /* Função Intersecção – Armazena em C os mesmos elementos que estão no conjunto A e
      B*/
      static void interseccao(Conjunto *A, Conjunto *B, Conjunto *C);

      /* Função membro – verifica se o elemento elem está no Conjunto
      A */
      static bool membro(Elemento y, Conjunto *A);

      /* Função diferença – atribui ao conjunto C a diferença entre os
      conjuntos A e B */
      static void diferenca(Conjunto *A, Conjunto *B, Conjunto *C);

      /* Função remove (diferente da de PASCAL) – remove o
      Elementoo elem do Conjunto A, retorna 1 se o Elementoo
      foi retirado e 0 se o Elementoo não está no conjunto */
      static bool remove(Elemento x, Conjunto *A);

      //Função max – retorna o maior elemento do conjunto A
      static int max(Conjunto *A); 

      //Retorna o menor elemento do conjunto.
      static int min(Conjunto *A);

      //Retorna true se os conjuntos recebidos são iguias, e false caso contrário.
      static bool iguais(Conjunto *A, Conjunto *B);

      //Recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A (diferença simétrica) B.
      static void diferencaSimetrica(Conjunto *A, Conjunto *B, Conjunto *C);

      /* Função copia – faz a copia do conjunto A para o B*/
      static void copia(Conjunto *A, Conjunto *B);

      /* Função igual – verifica se o conjunto A é igual a Conjunto B */
      int igual(Conjunto *A, Conjunto *B);

      //Retorna o tamanho da conjunto atual.
      int getTamanho(); 

      //Retorna o elemento que está na posição i do vetor.
      Elemento getElementoVetor(int i);

};
#endif
