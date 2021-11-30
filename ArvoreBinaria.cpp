#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class Info {
    friend class Noh;
    friend class ABB;
   
    public:
        int chave;
        std::string valor;

};


class Noh {
    friend class ABB;
    friend class Info;
    public:
        Noh(Info i);
    private:
        Noh* Esquerdo;
        Noh* Direito;
        Info info;

};

Noh::Noh(Info i){
    Esquerdo = NULL;
    Direito = NULL;
    info = i;

}


class ABB {
	friend class Info;
    public:
        ABB();
       // ~ABB();
        void InsereRecursivo(Info info);
        Noh* InsereRecAux (Noh* atual,Info info);
        Info buscaAux(int chave);
		Info busca(Info info);
        void RemoveTodos(Noh* atual);
        //void Destrutor(){ RemoveTodos(Raiz);};

    private:
    Noh* Raiz;
};

 ABB::ABB(){
    Raiz = NULL;
}

// ABB::~ABB(){
  // Destrutor();
//}

void  ABB::InsereRecursivo(Info info){
	Noh* atual = Raiz;

	InsereRecAux(atual,info);
}

Noh* ABB::InsereRecAux (Noh* atual, Info info){
	if(atual == NULL){
		Noh* novo = new Noh(info);

		return novo;
	} else {
		if (info.chave < atual->info.chave){
			atual->Esquerdo = InsereRecAux(atual->Esquerdo, info);

		} else {
			atual->Direito = InsereRecAux(atual-> Direito,info);
		}
	}
	    return atual;

}

Info ABB::buscaAux(int chave){

        Noh* atual = Raiz;
        Info info;

        if(atual != NULL){
                
                info.chave = atual->info.chave;
				info.valor = atual->info.valor;

		while(atual!=NULL){

            if(atual->info.chave == chave){ 

				return info;
			}
			
			else if(atual->info.chave > chave){
				
				atual = atual->Esquerdo;
				info.chave = atual->info.chave;
				info.valor = atual->info.valor;

			}
			else{
				atual = atual->Direito;
				info.chave = atual->info.chave;
				info.valor = atual->info.valor;
			}
		}
    }
       return info;
}


Info ABB::busca(Info info){

	Info busca = buscaAux(info.chave);

    if(busca.chave != -1){    
    return busca;
    }

    else{
       throw runtime_error("erro");
    }

}

/*void ABB::RemoveTodos(Noh* atual){
	
	while(atual!=NULL){
		RemoveTodos(atual->Esquerdo);
		RemoveTodos(atual->Direito);
		delete atual;
	}
}
	
*/
int main() {
    ABB arvore;
    Info info;
    char operacao;
    do {
        cin >> operacao;
        switch (operacao) {
            case 'i': // Inserir
                cin >> info.chave >> info.valor;
                arvore.InsereRecursivo(info);
                break;
            case 'b': // Buscar
                try {
                    cin >> info.chave; // ler a chave
                   info = arvore.busca(info);
                    cout << info.valor<< endl;
                }
                catch (runtime_error& e) {
                    cout << "INEXISTENTE" << endl;
                }
                break;
            case 'e': // Escrever tudo
                break;
            case 'f': // Finalizar execução
                break;
            default:
                cerr << "Comando invalido!\n";
        }
    } while (operacao != 'f');
    return 0;
}
