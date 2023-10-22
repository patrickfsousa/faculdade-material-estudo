#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class Carro
{
      private:
              string modelo;
              int ano;
              float valor;
      public:
             Carro()
             {
                    
                    ano=0;
                    valor=0;
             }
             ~Carro()
             {
             }
             void set_dados()
             {
                  cout <<"\nDigite o modelo: ";
                  getline(cin,modelo);
                                
                  cout <<"\nDigite o ano: ";
                  cin >> ano;
                  cout <<"\nDigite o valor: ";
                  cin>> valor;                 
                            
             }
             void print_dados()
             {
                  cout<< "\n Modelo: " << modelo;
                  cout << "\n Ano: " << ano;
                  cout << "\n Valor: " << valor;
             }
             string ret_modelo()
             {
                    return modelo;
             }
             int ret_ano()
             {
                 return ano;
             }
             float ret_valor()
             {
                   return valor;
             }
};
int main()
{
    Carro Loja[05];
    string modelo;
    char d;
    float vi,vf;
    int op;
     do{
        system("cls");
        cout << "\n------------------------------------------------------------";
        cout << "\n     Programa do Bom ";
        cout << "\n------------------------------------------------------------";
        cout << "\n\n\n\t\t<1> Cadastro  ";
        cout << "\n\t\t<2> Listagem Geral ";
        cout << "\n\t\t<3> Consulta por Modelo ";
        cout << "\n\t\t<4> Consulta por Valor  ";
        cout << "\n------------------------------------------------------------";
        cout << "\n\n\nDigite sua opcao- ";
        cin  >> op;
        switch(op){
            case 1:
                 system("cls");
                 for(int a=0;a<5; a++)
                    Loja[a].set_dados();
             break;
             case 2:
                  system("cls");
                  for(int g=0;g<5; g++)
                    Loja[g].print_dados();
             break;
                  
             case 3:
                  system("cls");
                  cout << "\nDigite o modelo a consultar ";
                  getline(cin,modelo);
                    for(int c=0; c<5; c++)
                      if(modelo==Loja[c].ret_modelo())
                          Loja[c].print_dados();
             break;
             default:
                  system("cls");
                  do{
                      cout << "\nDigite o valor ";
                      cin>> vi;
                      cout << "\nDigite o valor final ";
                      cin >> vf;
                        for(int f=0; f<5; f++)
                            if(vi=Loja[f].ret_valor() && vf>=Loja[f].ret_valor())
                              Loja[f].print_dados();
                   cout << "\n Deseja consultar outro? ";
                  cin >> d;
                  cin.ignore();
                  }while(d=='s' || d=='S');
                  break;
             }
            
             cout << "\n Deseja voltar ao menu principal ?  ";
                  cin >> d;
                  cin.ignore();
                  }while(d=='s' || d=='S');
                                   
    system("pause>>null");
    return 0;
}              
