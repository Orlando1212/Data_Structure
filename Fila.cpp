#include <iostream>
using namespace std;

typedef string Dado;

class noh{
    friend class Fila;
    
    private:
        Dado mDado;
        noh* prox;

    public:
        noh(const Dado& d);
};

noh::noh(const Dado& d){
    prox = NULL;
    mDado = d;
}


class Fila{

    private:
        noh* inicio;
        noh* fim;
        unsigned tamanho;

    public:
        Fila();
        ~Fila();
        void enfilera(const Dado& d);
        Dado desenfilera();
        bool vazia();
        string Imprime();
};

Fila::Fila(){
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}
Fila::~Fila(){
    while(inicio != NULL){
        desenfilera();
    }
    tamanho = 0;
}

void Fila::enfilera(const Dado& d){
    noh* novo = new noh(d);
    
    if(vazia()){
        inicio = novo;;
        fim = novo;
    }
    else{
        fim->prox = novo;
        fim = novo;
    }
     tamanho++;
}

Dado Fila::desenfilera(){
    if(vazia()){
        return "Esta Vazia";
    }
    
    else{
        Dado temp = inicio->mDado;
        noh* aux = inicio;
        inicio = inicio->prox;
        delete aux;
        tamanho--;

        return temp;
    }
}

string Fila::Imprime(){
    return inicio->mDado;
}


bool Fila::vazia(){
    if(inicio == NULL){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Fila f1;
     string inicio = "1";
    int n;
    string elemento;
        
        cin>>n;


    f1.enfilera(inicio);
    
    cout<<inicio<<" ";
    
    for(int i = 1 ;i < n; i++){
        f1.enfilera(inicio + "0");
        f1.enfilera(inicio + "1");
        f1.enfilera(inicio + "1" + "0");
        f1.enfilera(inicio + "0" + "1");
        f1.enfilera(inicio + "1" + "0");
        elemento = f1.desenfilera();
        cout<<f1.Imprime()<<" ";
    }
}