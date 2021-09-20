//Robertson Nascimento - 391242
//Clerton Filho - 397271
#ifndef LIST_H
#define LIST_H

struct Node;
static int cont_list = 0;

class List{
    private:
        Node *head;
        int id_list; 
    public:
        /* Construtor da classe. Deve iniciar todos os atributos da classe com valores
        válidos. */
        List();

        /* Destrutor da classe. Libera memória previamente alocada. */
        ~List(); 

        //Insere um inteiro key ao final da lista.
        void push_back(int key); 

        //Remove elemento do final da lista e retorna seu valor.
        int pop_back(); 

        //Insere um novo nó com valor key após o k-ésimo nó da lista.
        void insertAfter(int key, int k); 

        //Remove da lista o nó apontado pelo ponteiro p.
        void removeNode(Node *p); 

        //Remove da lista a primeira ocorrência do inteiro key
        void remove(int key);

        //Remove da lista todas as ocorrências do inteiro key.
        void removeAll(int key); 

        /* Remove o k-ésimo nó da lista encadeada e retorna o seu valor. Caso o k-ésimo nó não exista, 
        o programa retorna o valor especial INT MIN definido no cabeçalho climits. */
        int removeNodeAt(int k); 

        //Imprime os elementos da lista.
        void print(); 

        //Imprime os elementos da lista em ordem reversa.
        void printReverse(); 

        //Retorna true se a lista estiver vazia e false caso contrário.
        bool empty(); 
        
        //Retorna o número de nós da lista.
        int size(); 

        //Remove todos os elementos da lista e deixa apenas o nó cabeça.
        void clear(); 

        /* Concatena a lista atual com a lista lst passada por
        parâmetro. Após essa operação ser executada, lst será uma lista vazia, ou seja, o
        único nó de lst será o nó cabeça. */
        void concat(List *lst); 

        //Retorna um ponteiro para uma cópia desta lista.
        List *copy(); 

        /* Copia os elementos do array arr para a
        lista. O array arr tem n elementos. Todos os elementos anteriores da lista são
        mantidos e os elementos do array arr devem ser adicionados ap´os os elementos
        originais. */
        void copyArray(int n, int arr[]); 

        /* Determina se a lista passada por parâmetro é igual à
        lista em questão. Duas listas são iguais se elas possuem o mesmo tamanho e o valor
        do k-ésimo elemento da primeira lista é igual ao k-ésimo elemento da segunda lista. */
        bool equal(List *lst);

        /* Recebe como parâmetro um valor inteiro n e divide a
        lista em duas, de forma à segunda lista começar no primeiro nó logo após a primeira
        ocorrência de n na lista original. A função deve retornar um ponteiro para a segunda
        subdivisão da lista original, enquanto a cabeça da lista original deve continuar
        apontando para o primeiro elemento da primeira lista, caso ele não tenha sido o
        primeiro a ter valor n. */
        List* separate(int n); 

        /* Recebe uma List como parâmetro e constrói
        uma nova lista com a intercalação dos nós da lista original com os nós da lista
        passada por parâmetro. Ao final desta operação, list2 deve ficar vazia. */
        List * merge_lists(List *list2);  

        //Retorna o id da lista em questão.
        int getId();

        //Retorna a quantidade de listas ativas.
        static int getContList();

        //Seta o valor do contator de listas.
        static void setContList(int i);

        //Retorna o ponteiro que aponta para posição pos. Retorna nulo se a posição não existir na lista.
        Node * ponteiroPos(int pos);
};

#endif