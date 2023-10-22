/*faca uma classe denominada pessoa com os seguintes dados membros:Nome, Rg e CPF.
A classe devera conter os seguintes metodos : construtor/destrutor , set_dados , print_dados 
e metodos para retornar o rg e cpf individual. faça uma funçao principal que utilize a classe
Pessoa com todos os seus metodos para cadastrar a quantidade que o usuario quiser. fazer
consulta por rg e fazer uma consulta por cpf.
utilize Vector para armazenar os dado s */


#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Pessoa
{
	private:
		string nome,rg,cpf;
	public:
		Pessoa()
		{
			
		}
		~Pessoa()
		{
		}
		void set_dados()
		{
			cout<<"digite seu nome ?";
			getline(cin,nome);
			cout<<"digite seu rg ?";
			getline(cin,rg);
			cout <<"digite seu cpf ?";
			getline(cin,cpf);
			cin.ignore();
		}
		void print_dados()
		{
			cout << nome << "   " << rg << "   "<< cpf << "   ";
		}
		string ret_rg()
		{
			return rg;
		}
		string ret_cpf()
		{
			return cpf;
		}
};
int main()
{
		
	vector<Pessoa> v1;
	Pessoa x;
	char d;
	string crg,ccpf;
	do{
		x.set_dados();
		v1.push_back(x);
		cout << "deseja outro cadastro ?";
		cin >> d;
		cin.ignore();
	}while(d=='s' || d=='S');
	for(int a=0; a<v1.size(); a++){
		x=v1.at(a);
		x.print_dados();
	}
	cout << "digite o cpf a ser consultado ?";
	getline(cin,ccpf);
	for(int b=0; b<v1.size();b++){
		x=v1.at(b);
		if(x.ret_cpf()==ccpf)
			x.print_dados();
		}
	cout<<"digite o rg a ser consultado ?";
	getline(cin,crg);
	for(int c=0; c<=v1.size();c++){
		x=v1.at(c);
		if(x.ret_rg()==crg)
			x.print_dados();
		}
	cout << "\n\n";
	return 0;
}
