#include <iostream>
#include <string>

using namespace std;

struct atleta{
    string nacionalidade;
    int altura;
    float peso;
    string nome;
    string Dn;
    string nomeEsporte;
    string nomeAtivade;
    int dia;
    string hora;
    atleta();
};

atleta::atleta(){
	 nacionalidade.clear();
	 nome.clear();
	 Dn.clear();
	 nomeEsporte.clear();
	 nomeAtivade.clear();
	 hora.clear();
	 altura = 0;
	 peso = 0;
	 dia = 0;
}

struct patrocinador{
    string nomeP;
    string setor;
    string paisS;
    float valorI;
    string inicioC;
    string prazo;     // numero seguido de 'mes ou 'ano'
    patrocinador();
};

patrocinador::patrocinador(){
	nomeP.clear();
	setor.clear();
	paisS.clear();
	inicioC.clear();
	prazo.clear();
	valorI = 0;
}

class Dados{

    private:
        atleta* inscrito;
        patrocinador* patrocinando;
        int totalAtletas, totalPatrocinadores;

    public:

        Dados(int qtdAtletas, int qtdPatrocinadores); //construtor
        ~Dados(); //destrutor
        void CadastraAtleta(); //cadastra atletas
        void CadastraPatrocinador(); //cadastra patrocinadores
        void Busca_Esporte(string busca,int posicao); //faz a busca para achar o esporte

};

Dados::Dados(int qtdAtletas , int qtdPatrocinadores){
    totalAtletas = qtdAtletas;
    totalPatrocinadores = qtdPatrocinadores;
    
     inscrito = new atleta [totalAtletas];
     patrocinando = new patrocinador[totalPatrocinadores];
}

Dados::~Dados(){

    delete[] inscrito;
    delete[] patrocinando;

    totalAtletas = 0;
    totalPatrocinadores = 0;
}

void Dados::CadastraAtleta(){

        for(int i=0; i<totalAtletas;i++){
            cout<<"Nacionalidade, Altura, Peso , Nome , DataNascimento, NomeEsporte, NomeAtividade, Dia, Hora \n";
            cin>>inscrito[i].nacionalidade>>inscrito[i].altura>>inscrito[i].peso>>inscrito[i].nome
            >>inscrito[i].Dn>>inscrito[i].nomeEsporte>>inscrito[i].nomeAtivade>>inscrito[i].dia>>
            inscrito[i].hora;
        
			cout<<endl;
        }
        

}

void Dados::CadastraPatrocinador(){

        for(int i=0; i<totalPatrocinadores;i++){
            cout<<"Nome, Setor, PaisSede, ValorInvestido , InicioContrato, Prazo \n";
            cin>>patrocinando[i].nomeP>>patrocinando[i].setor>>patrocinando[i].paisS>>patrocinando[i].valorI
            >>patrocinando[i].inicioC>>patrocinando[i].prazo;
        }
}


void Dados::Busca_Esporte(string busca, int posicao){

     bool achou = false;
        
		for(int i=0;i<totalAtletas;i++){

               if(busca==inscrito[i].nomeEsporte){   // esporte encontrado, printa os dados do atleta ou atletlas inscritos .
                   posicao= i;
                   achou=true;

					cout<<inscrito[posicao].nacionalidade<<" "
					<<inscrito[posicao].nome<<" "
					<<inscrito[posicao].altura<<"cm"<<" "
					<<inscrito[posicao].peso<<" "
					<<inscrito[posicao].Dn<<" "
					<<inscrito[posicao].nomeAtivade<<" "
					<<inscrito[posicao].dia<<" "
					<<inscrito[posicao].hora<<endl;
				}
		}
						
				
				if(achou == false){
					cout<<"Nao encontrou o esporte";
				
				}
					
			
				if(totalPatrocinadores >0){
		
					for(int j=0;j<totalPatrocinadores;j++){    // patrocinador é geral 
						cout<<patrocinando[j].nomeP<<" "
						<<patrocinando[j].setor<<" "
						<<patrocinando[j].paisS<<" "
						<<patrocinando[j].valorI<<" "
						<<patrocinando[j].inicioC<<" "
						<<patrocinando[j].prazo<<endl;
					}
				}
				
				else{
					cout<<"Nenhum Patrocinador registrado";
				}
}

int main(){

     int qtdAtletas;
     int qtdPatrocinadores;
     string busca;
     int posicao =-1;

		cout<<"Quantidade de atletas"<<endl;
        cin>>qtdAtletas;
       
			if(qtdAtletas < 0){
					cerr<<"Informacao Invalida \n";
					exit(EXIT_FAILURE);
			}
			
			else{
					
				while(qtdAtletas == 0){
					cout<<"Nao digitou o requisito minimo. Digite novamente \n";
					cin>>qtdAtletas;
				}
				if(qtdAtletas < 0){
					cerr<<"Informacao Invalida \n";
					exit(EXIT_FAILURE);
				}	
			}
			
		cout<<"Digite a quantidade de Patrocinadores \n";
		cin>>qtdPatrocinadores;
			
			if(qtdPatrocinadores < 0){
					cerr<<"Informacao Invalida \n";
					exit(EXIT_FAILURE);
			}
					

		Dados* Pesquisa = new Dados(qtdAtletas,qtdPatrocinadores);
 
            //chamada dos metodos
         Pesquisa->CadastraAtleta();

         Pesquisa->CadastraPatrocinador();

		 cout<<"Digite o Esporte"<<endl;
		 cin>>busca;
		 
		 cout<<endl;


         Pesquisa->Busca_Esporte(busca,posicao);
            
         Pesquisa->~Dados();
            
          return 0;
}

