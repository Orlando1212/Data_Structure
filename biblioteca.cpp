
#include <iostream>
#include <string>

using namespace std;

struct livro {
    string nomeDoProduto;
    int quantidadeEmEmprestimo;
    int quantidadeDeExemplares;
    livro();
};

livro::livro() {
    nomeDoProduto.clear();
    quantidadeEmEmprestimo = 0;
    quantidadeDeExemplares = 0;
}

class biblioteca {
    private:
        // *** AVISO: Não altere os atributos privados da classe ***
        livro* listaDeLivros;
        int quantidadeDeItens;
        int capacidadeMaxima;
    public:
        biblioteca(int capacidade);
        ~biblioteca();
        void inserirNovolivro(const livro& umlivro);
        bool buscarlivro(const string& nome, livro& umlivro);
        void redimensionarCapacidade();
        friend void verificarDisponibilidadeLivros(biblioteca umbiblioteca, int quantidade);
};

biblioteca::biblioteca(int capacidade) {
    quantidadeDeItens = 0;
    capacidadeMaxima = capacidade;
    listaDeLivros = new livro[capacidadeMaxima];
}

biblioteca::~biblioteca() {
    delete [] listaDeLivros;
}

void biblioteca::inserirNovolivro(const livro& umlivro) {
    if (quantidadeDeItens == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDeLivros[quantidadeDeItens] = umlivro;
    quantidadeDeItens++;
}

bool biblioteca::buscarlivro(const string& nome, livro& umlivro) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDeItens and
           listaDeLivros[posicaoAtual].nomeDoProduto != nome)
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de produtos, é porque não encontrou
    if (posicaoAtual < quantidadeDeItens) {
        umlivro = listaDeLivros[posicaoAtual];
        return true;
    }

    return false;
}

void biblioteca::redimensionarCapacidade() {
		
	int tamNovo = 2*capacidadeMaxima;
	livro* livros2;
		
	livros2 = new livro[tamNovo];
		
		for(int i=0;i<capacidadeMaxima;i++){
				
			livros2[i] = listaDeLivros[i];
		}

        delete[] listaDeLivros;
        capacidadeMaxima*= 2;
        listaDeLivros = new livro[tamNovo];
        
        for(int i = 0 ;i<capacidadeMaxima;i++){

            listaDeLivros[i] = livros2[i];
        }
        
        delete [] livros2;
}

void verificarDisponibilidadeLivros(biblioteca umbiblioteca, int quantidade) {
    // *** AVISO: Não altere esta função ***
    for (int i = 0; i < umbiblioteca.quantidadeDeItens; i++) {
        if ((umbiblioteca.listaDeLivros[i].quantidadeDeExemplares - umbiblioteca.listaDeLivros[i].quantidadeEmEmprestimo) > quantidade)
            cout << umbiblioteca.listaDeLivros[i].nomeDoProduto << endl;
    }
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() ***
    int capacidadeInicial;

    cout << "biblioteca - Aplicativo para Empréstimos de Livros\n"
         << "Entre com capacidade máxima inicial: ";
    cin >> capacidadeInicial;

    biblioteca meubiblioteca(capacidadeInicial);

    cout << "biblioteca - Escolha a Opção:\n"
         << "i - inserir novo livro\n"
         << "b - buscar por um dado livro a partir do nome\n"
         << "v - verificar livros com disponibilidade de empréstimo\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    livro umlivro;
    string nome;
    int quantidade;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' :
                cout << "Entre com dados do livro (nome, quantidade em empréstimos, quantidade de exemplares):" << endl;
                cin >> umlivro.nomeDoProduto
                    >> umlivro.quantidadeEmEmprestimo
                    >> umlivro.quantidadeDeExemplares;
                meubiblioteca.inserirNovolivro(umlivro);
                break;

            case 'b' :
                cout << "Entre com nome do livro para busca: ";
                cin >> nome;

                if (meubiblioteca.buscarlivro(nome, umlivro))
                    cout << umlivro.nomeDoProduto << " "
                         << umlivro.quantidadeEmEmprestimo << " "
                         << umlivro.quantidadeDeExemplares << endl << endl;
                else
                    cout << "livro não encontrado!" << endl << endl;
                break;

            case 'v' :
                cout<< "informe a quantidade de exemplares desejadas:";
                cin>>quantidade;
                verificarDisponibilidadeLivros(meubiblioteca,quantidade);
                break;

            case 's' : // não faz nada, espera retorno ao while para sair
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;

        }
        cout << "biblioteca - Escolha a Opção:\n"
            << "i - inserir novo livro\n"
            << "b - buscar por um dado livro a partir do nome\n"
            << "v - verificar livros com disponibilidade de empréstimo\n"
            << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}
