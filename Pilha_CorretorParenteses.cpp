#include <iostream>
#include <string>

typedef int Dado;

using namespace std;

class noh {
	friend class Pilha;

	private:
		Dado dado;
		noh* prox;
	
	public:
		noh(const Dado& d);
};

noh::noh(const Dado& d){
	dado = d;
	prox = NULL;
}


class Pilha {
	private:
		noh* topo;
		int tamanho;
		
	public:
		Pilha();
		~Pilha();
		void empilha(const Dado& d);
		Dado desempilha();
		bool vazia();
};

Pilha::Pilha() {
	tamanho = 0;
	topo = NULL;
}

Pilha::~Pilha() {
	while (tamanho > 0) {
		desempilha();
	}
}

void Pilha::empilha(const Dado& d) {
	noh* novo = new noh(d);
	novo->prox = topo;
	topo = novo;
	tamanho++;
}


Dado Pilha::desempilha(){
	
	Dado temp = topo->dado;
	noh* aux = topo;
	topo = topo->prox;
	delete aux;
	tamanho--;
	return temp;
}

bool Pilha::vazia(){
	if(topo == 0){
		return true;
	}
	else{
		return false;
	}

}

int main() {
	Pilha p1;
	string palavra;

	getline(cin,palavra);

	int tam = palavra.size();
	
		for (int i = 0; i < tam; i++) {
			if (palavra[i] == '(') {
				p1.empilha(i);
			}
		
			if (palavra[i] == ')') {
				if (not p1.vazia()) {
					p1.desempilha();
				}				
				
				else{
					cout << i << endl;
					return 0;
				}
			}	
		}

		   if (not p1.vazia()) {
			  cout << p1.desempilha() << endl;
		   } 	   
		  
		   else {
			  cout << "correto" << endl;
		   }
	
		return 0;
}
