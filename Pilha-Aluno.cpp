//faça uma classe denominada Aluno com os seguintes dados membros: Nome , idade, altura.
//A classe deverão conter os seguintes metodos : construtor/destrutor . um metodo para solicitar todos os dados e um pra imprimir.
//Faça uma função principal que utilize a classe aluno para fazer o seguinte , Cadastrar a qtd de alunos que o usuario desejar , fazer uma consulta por nome.
//utilize pilhas.
//Metodo para retornar o nome.


#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Aluno {
      
      private:
              string nome;
              int idade;
              float altura;
              
      public:
             Aluno(){
                     
                     idade = 0;
                     altura = 0;
                     }
             ~Aluno(){
                      }
             void set_dados(){
                  cout<< "\n Digite o nome do Aluno ";
                  getline(cin,nome);
                  cout << "\nDigite a idade ";
                  cin >> idade;
                  cout << "\nDigite a altura ";
                  cin >> altura;
                  cin.ignore();
                  }
             void print_dados(){
                  cout << nome << " idade " << idade << " altura " << altura;
                  }
             int ret_idade(){
                 return idade;
                 }
             string ret_nome(){
                    return nome;
                    }
                  };
      int main (){
          int op, ini, fim;
          stack <Aluno> escola,copia;
          Aluno temp;
          char d;
          string nomec;
          do{
               cout << "============================================= \n ";
               cout << "             Programa do Bom \n";
               cout << "==============================================\n ";
               cout << "\n\n\n\n\n\t <1> Cadastro de alunos ";
               cout << "\n\t<2> Consulta Geral ";
               cout << "\n\t <3> Consulta por faixa etaria ";
               cout << "\n\t <4> Consulta por nome ";
               cout << "\n\n\n\n ";
               cout << "===============================================\n ";
               cout << "Digite sua opcao -> ";
               cin >> op;
               cin.ignore();
               switch(op){
                          case 1:
                               do{
                                   cout << "================================\n ";
                                   cout << "           Programa Bom       \n ";
                                   cout << "================================\n ";
                                   temp.set_dados();
                                   escola.push(temp);
                                   cout << "\n Deseja cadastrar outro -> ";
                                   cin >> d;
                                   cin.ignore();
                                   }while(d=='s' || d=='S');
                                   break;
                          case 2:
                               cout << "=======================================\n ";
                               cout << "          Programa Do Bom           \n ";
                               cout << "=======================================\n ";
                               copia=escola;
                               while(!copia.empty()){
                                                     temp=copia.top();
                                                     temp.print_dados();
                                                     copia.pop();
                                                     }
                               break;
                          case 3:
                               do{
                                     cout << "=========================================\n ";
                                     cout << "           Programa Do Bom            \n ";
                                     cout << "=========================================\n ";
                                     cout << "\n Digite a idade inicial -> ";
                                     cin >> ini;
                                     cout << "\nDigite a idade final -> ";
                                     cin >> fim;
                                     copia=escola;
                                     while(!copia.empty()){
                                                           temp=copia.top();
                                                           if(temp.ret_idade() >=ini && temp.ret_idade() <=fim)
                                                                               temp.print_dados();
                                                           copia.pop();
                                                           }
                                                           cout << "\n Deseja consultar outro -> ";
                                                           cin >> d;
                                                           cin.ignore();
                                                           }while(d=='s' || d=='S');
                                                           break;
                          case 4:
                               do{
                                  cout << "==================================\n ";
                                  cout << "         Programa Do Bom           \n";
                                  cout << "==================================\n ";
                                  cout << "\n Digite o nome a consultar -> ";
                                  getline(cin,nomec);
                                  copia=escola;
                                  while(!copia.empty()){
                                                        temp=copia.top();
                                                        if(temp.ret_nome() == nomec)
                                                                           temp.print_dados();
                                                        copia.pop();
                                                        }
                                  cout << "\nDeseja consultar outro -> ";
                                  cin >> d;
                                  cin.ignore();
                                  }while(d=='s' || d=='S');
                                  break;
                                  default:
                                          cout << "\nOp��o invalida !!! ";
                                  break;
                                  }
                               cout << "\nDeseja voltar para o menu principal -> ";
                               cin >> d;
                               cin.ignore();
                               }while(d=='s' || d=='S');
                               cout << "\nObrigado ";
                               system("pause>>null");
                               return 0;                              
                               }
                               
               
