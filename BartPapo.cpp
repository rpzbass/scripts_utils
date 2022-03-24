#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>


using namespace std;


  struct Mensagem{
	
	char texto[500];
	string data;
	string destinario;
	string remetente;
	
};

  struct  Pessoa{
 	
 	char Nome[50];
 	char Idade[2];
 	char Sexo[1];
    Mensagem msg;
 		 	
 };
 

 struct login{
	
	char usuario[100];
	char senha[100];
	Pessoa P;
}; 



void telainicial(){

printf("\n");
system("color 0A");
printf("8''''8   8''''8 8''8  ''8'' 8''''8 8''''8 8''''8 8''''8 \n");
printf("8    8   8    8 8   8   8   8    8 8    8 8    8 8    8 \n");
printf("8eeee8ee 8eeee8 8eee8e  8e  8eeee8 8eeee8 8eeee8 8    8 \n");
printf("88     8 88   8 88   8  88  88     88   8 88     8    8 \n");
printf("88     8 88   8 88   8  88  88     88   8 88     8    8 \n");
printf("88eeeee8 88   8 88   8  88  88     88   8 88     8eeee8 \n");


printf("      / / / / / / /     \n");
printf("     /        	 /  \n");
printf("    /            /	   \n");
printf("  _/            /   \n");
printf(" (.-,--.       /			\n");		
printf(" /o/  o \     /		Bart Papo v1.0  by :: Ronaldo UTP 2019  \n");	
printf(" \ \    /   _/	 		            		\n");
printf(" (__`--'    _)		\n");
printf("  /         \		\n");
printf(" (_____,'    \         [1] - Entrar \n");
printf("   \_       _\	      [2] - Cadastrar \n");
printf("     `._..-'		\n");


printf("\n");

	
}





void telahome(string nome){
		
	cout << "--------------------------------------------------------------------\n";
	cout << " Bem vindo !!! "<< nome  << "  ao BartPapo v1.0                     \n";                                          
	cout << "\n--------------------------------------------------------------------\n";

	
}
void telaopcoes(){
	
	cout << "[1] Contatos |  [2] Alt Pefil | [3] Excluir | [4] Sair";
	cout << "\n--------------------------------------------------------------------\n\n";
	
}

void tela_cadastrar(){
	
	printf("------------------------------------------\n");
	printf("|           CADASTRO DE USUARIO           |\n");
    printf("------------------------------------------\n");
	
	
}
void tela_perfil(){
	printf("------------------------------------------\n");
	printf("|           PERFIL DO USUARIO          |\n");
    printf("------------------------------------------\n");
	
	
}



void telabatepapo(){
	
	cout << "--------------------------------------------------------------------\n";
	cout << "                           BartPapo v1.0                            \n";                                          
	cout << "\n--------------------------------------------------------------------\n\n";
	
}

void rodape(){
	
	cout << "-------------------------------------------------------------------\n";
	cout << "|  [1] Selecionar contato |  [2] Alterar Perfil  |  [3] Sair       \n";     					
	cout << "-------------------------------------------------------------------\n";

}



int  autentica(string user,string pw){

	
	ifstream novoarq;
	novoarq.open("User.txt");

	if (novoarq.fail()){
		
		cout << "Erro 404";
		exit(1);  
	}
	
	
	char *Ssenha;
	string senha;
	string nome;
	char aux[100];
	int cont = 0;

	while(!novoarq.eof()){	
  	   
	   novoarq >> aux;
	   
	   
	    char *str = strtok(aux,",");
    	char *col1 = strtok(NULL,",");
		char *col2 = strtok(NULL,",");
		char *col3 = strtok(NULL,",");
		char *col4 = strtok(NULL,",");
	    senha = col4; 
        nome = strtok(aux,",");  
	    
		if(nome == user && senha == pw){
							
				return true;
			    cont++;
		}else if(user == " " && pw == " "){
			
			cout << "USUARIO NAO EXISTE";
			
		}
		
	}
		
	
	if(cont == 0){
			
			return false;
	}

	novoarq.close();
	
}


void visualiza_contatos(void){
	
	string nome;
	char aux[100];
	ifstream novoarq;
	novoarq.open("User.txt");

	if (novoarq.fail()){
		
		cout << "Arquivo nao encontrado\n";
		exit(1);  
	}
	while(!novoarq.eof()){	
  	   
	   novoarq >> aux;
	   
       nome = strtok(aux,",");  
	   
	   cout <<"|  "<< nome ;
	   cout << "    \n"; 
    }

}



int  QtdeCadastrados(){
	
	
	ifstream novoarq;
	novoarq.open("User.txt");

	if (novoarq.fail()){
		
		cout << "Erro 404";
		exit(1);  
	}
	
	
	
	char aux[100];
	int cont=0;
    
	while(!novoarq.eof()){	
  	   
	   novoarq >> aux;  
	
	    cont++;
	}
	
	return cont;	
}

/*void consultar(){

    int i = 0;
    int numPalavras = 0;
    login L[50];
    char line[50];
    char palavras[i];
    FILE *arq;
    arq = fopen("palavras.txt", "r");

    

    while(fgets(line, sizeof line, arq) != NULL)
    {
        //Adiciona cada palavra no vetor
        
        strcpy(palavras[i],line[i]);
		i++;
        //Conta a quantidade de palavras
        numPalavras++;
    }

    int j;

    for (j = 0; j < numPalavras; j++)
        printf("\n%s", palavras[i]); //Exibi as palavras que estao no vetor.

    printf("\n\n");

    fclose(arq);

	
}
*/
void deletar(string nomedel){
	
	string line;
	string lin;
	char aux[200];
	ifstream ler;
	ler.open("User.txt");
	ifstream ler2;
	ler2.open("User.txt");
	ofstream escrever;
	escrever.open("Temp2.txt");
	
	fflush(stdin);
	
	if(ler.fail()){
		
		cout << "Arquivo n encontrado";
		
	}
	
	
	
	while(!ler.eof()){
		
		
			ler >> aux;
			ler2 >> lin;
		
			line = strtok(aux,",");
			if(line != nomedel){
			
			//cout << lin <<"\n";
			  escrever << lin << "\n";
				
			
			}
		
		}
	
			
		ler.close();
		ler2.close();
		
		remove("User.txt");
		
		escrever.close();
	
	    rename("Temp2.txt","User.txt");
		
	
}

void cria_arq_msg(char *nome){
	
	
	
	char ext[30] = ".txt";
	char cat[100];
    
    
	sprintf(cat,"%s%s",nome,ext);
	ofstream escreve;
	escreve.open(cat);
    
}

int busca_cont(string localiza){
	
	string nome;
	char aux[100];
	ifstream novoarq;
	novoarq.open("User.txt");

	if (novoarq.fail()){
		
		cout << "Arquivo nao encontrado\n";
		exit(1);  
	}
	while(!novoarq.eof()){	
  	   
	   novoarq >> aux;
	
	   nome = strtok(aux,",");
	   if(nome == localiza){
	   	
		   
		   
		
		   return false;
	   }
	   
	}
	
	
}



char a[5];

char validaSenha(void){
char x[5];
	
	
	cout << "SENHA  4 DIGITOS:";
	for(int i = 0; i < 4;i++){
        a[i] = _getch(); _putch('*'); 
		if(a[i] == 4)break;
	};
		cout << "\nREPITA A SENHA: ";
	for(int i = 0; i < 4;i++){
         x[i] = _getch(); _putch('*');
		if(x[i] == 4)break;
	};
   
   
   if(strcmp(a,x)== 0){
   	
    printf("\n\n##CADASTRADO COM SUCESSO##\n");
   	
   }else{
   	
   	printf("\nSENHAS INCORRETAS !!!");
   	
   	validaSenha();
   	
   } 
	
}







int cadastrar(void){
	
	int cont;
	
    cont = QtdeCadastrados();
	login L[cont];	
	FILE *arq;
	arq = fopen("User.txt","a+");
	
	if(cont > 0)
	fputs("\n",arq);
	tela_cadastrar();
	cout << "NOME :";
	cin >> L[cont].P.Nome;
	fputs(L[cont].P.Nome,arq);
	fputs(",",arq);
	
	cout << "IDADE :";
	cin >> L[cont].P.Idade;
	fputs(L[cont].P.Idade,arq);
	fputs(",",arq);
	
	cout << "SEXO M OU F :";
	cin >> L[cont].P.Sexo;
	fputs(L[cont].P.Sexo,arq);
	fputs(",",arq);
	
	cout << "USUARIO :";
	cin >> L[cont].usuario;
	fputs(L[cont].usuario,arq);
	fputs(",",arq);
	
	validaSenha();
	fputs(a,arq);	
	fclose(arq);
	
	
}


int main() {
	
	int opc;
	char user[30];
	char pw[4];
	char ext[30] = ".txt";
	char contato[30];
   
	while(opc!= 5){
	system("cls");
	telainicial();
	cout << "--> ";	
	fflush(stdin);
	cin >> opc;
	switch(opc){
				
				case 1:
			
				 	fflush(stdin);		
					cout << "USUARIO: ";
					cin >> user;
				 	cout << "SENHA: ";
			     	for(int i = 0; i < 4;i++){
        		 	pw[i] = _getch(); _putch('*'); 
				 	if(pw[i] == 4)break;
					};
				 
				 
					 if(autentica(user,pw)){
				     
						
						system("cls");
						int op = 0;
												
						while(op != 4){
						system("cls");
						telahome(user);
						telaopcoes();	
							cout << "informe uma opcao: \n";
							cin >> op;
					
					
					
							if(op == 1){
						
					
					
							visualiza_contatos();
					
					
							cout << "\nInforme um nome :";
							cin >> contato;
					
							if(!busca_cont(contato)){
						
							char cat[30];
							char continu;
							sprintf(cat,"%s%s",user,ext);
							ifstream read;
							read.open(cat);
							system("cls");
							telabatepapo();
						
						
						
							if(read.fail()){
					
							cria_arq_msg(user);
						}
							    string log;
								ifstream novoarq3;
								novoarq3.open(cat);
								
								while(!novoarq3.eof()){	
  	   
  	   							getline(novoarq3,log);
	  						    cout << log <<"\n\n";
						}
	
						
							ofstream file;
							file.open(cat);
						
							
							Pessoa p;
							int i;
							for (i=2; i>=0 ;i--){
						
					    	cout << user <<" : ";
					    	fflush(stdin);
							gets(p.msg.texto);
							cout <<"\n\n";	
							file << user << ":";
					    	file << p.msg.texto <<". \n\n" ;
					    	
					   
					    	if(i == 0){
					    		cout << "Deseja continuar? S/N\n";
					    		fflush(stdin);
					    		cin >> continu;
					    		if(continu == 'S' || continu == 's'){
					    			i = 3;		
							}else{
								read.close();
								file.close();		
							    string swap;
								char conc[50];
								ifstream ler;
							    ler.open(cat);
							    sprintf(conc,"%s%s",contato,ext);
								ofstream write;
				                write.open(conc,ios::in| ios::out | ios::app); //ios app faz o append
				                
								while(!ler.eof()){	
  	   
  	   							getline(ler,swap);
	  						    //cout << swap;
	  						    write << swap;
	  						    write << "\n";
	   
								}
								 
							 	cout << "Saindo da conversa...";
							 	Sleep(2000);
							 	system("cls");
							 	
								}
					    	
							}
					    
						}	
						
					
					}else{
					
						cout << "\n\n>>>>>>ERROR...CONTATO NAO CADASTRADO!!!<<<<<<<\n\n";
					}
				
				}else if(op == 3){
					
					deletar(user);	
					cout <<"Deletando perfil..\n";
					Sleep(2000);
					cout <<"Perfil Deletado";
					exit(1);
					
				}else if(op == 2){
					system("cls");
					tela_perfil();
					cout <<"\n";
					char p;
					cout << "Deseja alterar o perfil? S/N\n";
					cin >> p;
					if(p == 'S' || p == 's'){
					deletar(user);
					cadastrar();	
					}
			
				}
			
		     
			
			
			}	
			  	 	
				 
			   		 }else{
						
				 	    system("cls");
						cout << "\n\nUSUARIO OU SENHA INCORRETOS !!!\n\n";
				    	Sleep(1000);
				    	system("cls");
					}
	 	       	 
			break;	
			
			case 2:
				system("cls");
				cadastrar();
				Sleep(2000);
                system("cls");			    
			break;
	
	}
	
}
	
	/*
	
	 int opc;
	 	
	 while(opc != 5){
	 	
		
		 
		 cin >> opc;
		 	
	 	 if(opc == 1){
	 	 	
	 	 	string usuario;
	 	 	string senha;
	 	 	cout << "Usuario: ";
	 	 	cin >> usuario;
	 		cout << "Senha: ";
	 		cin >> senha;
	 		
			if(autentica(usuario,senha)){
				
				cout << "Acesso permitido\n\n";
				system("cls");
				telahome();
				
													
			}else{
				
				cout << "Usuario ou senha incorretos!!!\n\n";
			}
	 		
	 		
			system("pause");
			system("cls"); 	
	 	
		  }else if(opc == 2){
		  	//fflush(stdin);
		  	//system("cls");
			  
		  	cadastrar();
		  	
		  }
						 	
	 }	
		
	*/
	
	return 0;
}
