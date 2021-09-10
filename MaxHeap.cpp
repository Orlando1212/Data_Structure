#include <iostream>
#include <string>
using namespace std;

typedef int dado;

class MaxHeap{

    private:
        dado* heap;
        int capacidade;
        int tamanho;
        inline int pai (int i){return (i-1)/2;};
        inline int esquerdo(int i){return 2*i+1;};
        inline int direito(int i){return 2*i+2;};
        void arruma();
        void corrigeDescendo(int i);
        void corrigeSubindo(int i);
    
    public:
        MaxHeap(int cap);
        MaxHeap(dado vet[] ,int tam);
        ~MaxHeap();
        dado RetiraRaiz();
        dado EspiaRaiz();
        void insere (dado d);
        void imprime();


};


MaxHeap::MaxHeap(int cap) {
    capacidade = cap;
    heap = new dado[cap];
    tamanho = 0;
}

MaxHeap::MaxHeap(dado vet[] , int tam){
    capacidade = tam;
    heap = new dado[capacidade];
        
        for(int i = 0; i<tam;i++){
            heap[i] = vet[i];
        }
        tamanho = tam;
        arruma();
}

MaxHeap::~MaxHeap(){
    delete[] heap;
}

void MaxHeap::arruma(){
    for(int i=(tamanho/2-1);i>=0;i--){
        corrigeDescendo(i);
    }

}

void MaxHeap::corrigeDescendo(int i){

    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = i;

        if((esq < tamanho) and (heap[esq] > heap[maior])){   // ((esq<tamanho) and (heap[esq]>heap[i])
            maior = esq;
        }

        // caso eu nao coloca maior = i, eu crio o else para maior receber i 
       // else{
       //     maior = i;
       // } 

        if((dir < tamanho) and (heap[dir] > heap[maior])){
            maior = dir;
        }

       // else{
        //    maior = i;
        // }

        if(maior!= i){
            swap(heap[i], heap[maior]);
            corrigeDescendo(maior);
        }

}
void MaxHeap::corrigeSubindo(int i){

    int p = pai(i);
        
        if(heap[i] > heap[p]){
            swap(heap[i], heap[p]);
            corrigeSubindo(p);
        }
}

void MaxHeap::imprime(){
    for(int i = 0 ; i < tamanho;i++){
        cout<<heap[i]<< " ";
    }
        cout<<endl;
}

dado MaxHeap::EspiaRaiz(){
    return  heap[0];
}

dado MaxHeap::RetiraRaiz(){
    
    if(tamanho == 0){
        cerr<<"Erro ao retirar a raiz"<<endl;
    }

    dado aux = heap[0];
    swap(heap[0], heap[tamanho -1]);
    tamanho--;
    corrigeDescendo(0);
    return aux;
}

void MaxHeap::insere(dado d){
    
    if(tamanho == capacidade){
        cerr<<"Erro ao inserir"<<endl;
    }

    heap[tamanho] = d;
    corrigeSubindo(tamanho);
    tamanho++;
}

int main(){
    int tam = 13;
    dado vet[] = {50,2,90,20,230,43,8,34,66,100,110,3,13};

    MaxHeap *h = new MaxHeap(vet,tam);
    
        for(int i =0; i<tam; i++){
            cout<<h->RetiraRaiz()<<" :";
            h->imprime();
        }

        cout<<endl;

        for(int i = 0; i< tam ; i++){
            h->insere(vet[i]); 
        }

        cout<<endl;

        for(int i = 0 ;i < tam ; i++){
            cout<<h->RetiraRaiz()<< " ";
        }

        cout<<endl;

        delete h;

        return 0;

}
