#include <clocale>
#include "Arvore3.h"

int main(){
    setlocale(LC_ALL,"Portuguese");

    TArvore arvore1;
    TPessoa chave;
    TPessoa i;
    iniciarArvore(arvore1);

    bool flag = true;
    int opcao;

    do{
        cout << "\n==============================================================" << endl;
        cout << "===============ABAIXO=SE=ENCONTRA=NOSSO=MENU==================" << endl;
        cout << "====SELECIONE=UM=N�MERO=QUE=QUEIRA=PARA=INICIAR=O=PROCESSO====" << endl;
        cout << "==============================================================\n" << endl;
        cout << "   1 - Cadastrar pessoas" << endl;
        cout << "   2 - Mostrar a quantidade de pessoas cadastradas" << endl;
        cout << "   3 - Mostrar a m�dia das idades" << endl;
        cout << "   4 - Verificar se a �rvore est� vazia" << endl;
        cout << "   5 - Deseja mostrar as pessoas cadastradas " << endl;
        cout << "   6 - Ver a altura da �rvore " << endl;
        cout << "   7 - Ver o nivel da �rvore " << endl;
        cout << "   8 - Deseja pesquisar por uma pessoa " << endl;
        cout << "   9 - Deseja retirar algu�m da �rvore " << endl;
        cout << "   10 - Mostrar Pessoa mais velha "<<endl;
        cout << "   11 - Mostrar Pessoa mais nova "<<endl;
        cout << "   Digite qualquer outra op��o para sair" << endl;
        cout << "Op��o: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                cadastrarItens(arvore1);
                break;
            case 2:
                cout << "\nEst�o cadastradas " << contaNos(arvore1.raiz) << " pessoas at� o momento!" << endl;
                break;
            case 3:

                cout << "\nA media das idades � " << media(arvore1.raiz) << " para as pessoas at� o momento" << endl;
                break;
            case 4:
                if(estaVazia(arvore1)){
                    cout << "\n�rvore de pessoas vazia! " << endl;
                }else{
                    cout << "\n�rvore de pessoas cheia! " << endl;
                }
                break;
            case 5:
                mostrarArvore(arvore1);
                break;
            case 6:
                cout << "\nAltura: " << alturaNoh(arvore1.raiz) << endl;
                break;
            case 7:
                cout << "\nN�vel: " << alturaNoh(arvore1.raiz) << endl;
                break;
            case 8:
                    cout << "\nDigite a idade da pessoa � pesquisar: ";
                    cin >> chave.idade;
                    pesquisar(chave, arvore1.raiz, arvore1);
                    i = chave;
                break;
            case 9:
                    cout << "\nDigite a idade da pessoa para ser retirada: ";
                    cin >> chave.idade;
                    i = chave;
                    retirar(i,arvore1.raiz);
                break;
            case 10:
                TNoh *aux;
                aux = pesquisaMaisVelho(arvore1.raiz);
                cout << "Nome: " << aux->pessoa.nome << " � a pessoa mais velha! " << endl;
                break;
            case 11:
                TNoh *aux2;
                aux2 = pesquisaMaisNovo(arvore1.raiz);
                cout << "Nome: " << aux2->pessoa.nome << " � a pessoa mais nova! " << endl;
            default:
                cout << "At� a pr�xima!!" << endl;
                flag = false;
                true;
        }

    }while(flag == true);
}
