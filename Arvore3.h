#ifndef BILBIOTECAARVORE_H_INCLUDED
#define BILBIOTECAARVORE_H_INCLUDED

#include <iostream>
#include <clocale>

using namespace std;

//CRIA UM NOVO TIPO DE DADO TPESSOA COM NOME, IDADE, SEXO
struct TPessoa{
    string nome;
    int idade;
    string sexo; //(M/F)
};

//CRIA UM TIPO DE DADO QUE SER� OS NOHS DE NOSSA �RVORE! ESSE NOH RECEBE DOIS PONTEIROS DIR,ESQ
//DENTRO DESSES NOHS PODEREMOS GUARDAR O TPESSOA
struct TNoh{
    TPessoa pessoa;
    TNoh *esq,*dir;
};

//CRIA UM TIPO DE DADO CHAMADO TARVORE QUE ARMAZENA NOSSA RAIZ
struct TArvore{
    TNoh *raiz;
    string nome;
    int contador;
};
//OPERA��ES B�SICAS DA �RVORE

//PARA INICIAR A �RVORE SE FAZ A RAIZ VALER NULL = NADA, TAMB�M ESSA �RVORE RECEBERA UM NOME
void iniciarArvore(TArvore &a){
    a.raiz = NULL;
    a.nome = "";
    a.contador=0;
}

//VERIFICA SE A �RVORE EST� VAZIA, SE A RAIZ == NULL A �RVORE ESTAR� VAZIA
bool estaVazia(TArvore a){
    return a.raiz == NULL;
}

void inserir(TPessoa i, TNoh *&n, TArvore &a){

     if (n == NULL){
        n = new TNoh;
        n->pessoa = i;
        n->esq = NULL;
        n->dir = NULL;
        if (a.raiz == NULL){//ESSA PARTE S� SERVE PRA PRIMEIRA INSER��O
            a.raiz = n;
        };
        a.contador++;
    }
    else{
        if (i.idade < n->pessoa.idade){//SE O VALOR FOR MENOR QUE A RAIZ VAI PRA ESQUERDA DA �RVORE
            inserir(i,n->esq,a);
        }
            else{
            if (i.idade > n->pessoa.idade){//SE O VALOR FOR MAIOR QUE A RAIZ VAI PRA DIREITA DA �RVORE
                inserir(i,n->dir,a);
                }
                else{
                cout << "Valor j� existe na �rvore!";
                }
            }
        }
}

//ESSA FUN��O MOSTRA NOSSAS PESSOAS EM ORDEM CRESCENTE DE IDADE
void percorrerINOrdem(TNoh *&a){
    if(a!=NULL){
        percorrerINOrdem(a->esq);
        cout << a->pessoa.nome << ", ";
        cout << a->pessoa.idade << ", ";
        cout << a->pessoa.sexo << "//";
        percorrerINOrdem(a->dir);
    }
}

//ESSA FUN��O MOSTRA A PRIMIERA PESSOA INSERIDA NA �RVORE COMO SENDO A PRIMIERA A SER MOSTRADA
void percorrerPREOrdem(TNoh *&a){
    if(a!=NULL){
        cout << a->pessoa.nome << ", ";
        cout << a->pessoa.idade << ", ";
        cout << a->pessoa.sexo << "// ";
        percorrerPREOrdem(a->esq);
        percorrerPREOrdem(a->dir);
    }
}

//ESSA FUN��O MOSTRA A PRIMEIRA PESSOA INSERIDA NA �RVORE COMO A �LTIMA A SER MOSTRADA
void percorrerPOSOrdem(TNoh *&a){
    if(a!=NULL){
        percorrerPOSOrdem(a->esq);
        percorrerPOSOrdem(a->dir);
        cout << a->pessoa.nome << ", ";
        cout << a->pessoa.idade << ", ";
        cout << a->pessoa.sexo << "// ";
    }
}

//ESSA FUN��O FAZ O CADATRAMENTO DAS PESSOAS CHAMANDO A FUN��O INSERIR DENTRO DELA MESMA
void cadastrarItens(TArvore &a){
TPessoa x;
string opcao;

    cout << endl << "---   CADASTRANDO �RVORE   ----" << endl;
    cout << "Qual o nome da �rvore: ";
    cin >> a.nome;
    do{
        cout << "Informe o nome da pessoa: ";
        cin >> x.nome;
        cout << "Informe a idade da pessoa: ";
        cin >> x.idade;
        cout << "Informe o sexo da pessoa: ";
        cin >> x.sexo;
        inserir(x,a.raiz,a);
        cout << "Continuar inserindo? s/n: ";
        cin >> opcao;
    }while(opcao!="n");
    cout << endl << "-----------------------------" << endl;
}

//FUN��O QUE MOSTRA AS PESSOAS INSERIDAS EM (IN,PRE,POS) ORDEM
void mostrarArvore(TArvore a){
    cout << "---   MOSTRANDO  PESSOAS NA NOSSA �RVORE   ----" << endl;
    cout << "   �rvore : " << a.nome << endl;
    cout << "   IN Ordem: ";
    percorrerINOrdem(a.raiz);
    cout << endl ;
    cout << "   PRE Ordem: ";
    percorrerPREOrdem(a.raiz);
    cout << endl ;
    cout << "   POS Ordem: ";
    percorrerPOSOrdem(a.raiz);
    cout << endl << "-----------------------------" << endl;
}

//PESQUISA UMA IDADE DIGITADA PELO USU�RIO
void pesquisar(TPessoa i, TNoh *&n, TArvore a){
    if (n == NULL){
        cout << "\nRegistro n�o localizado na �rvore" << endl;
    }
    else {
        if (i.idade < n->pessoa.idade){
            pesquisar(i, n->esq, a);// SE A IDADE PROCURADA FOR MENOR QUE A RAIZ A RAIZ APONTA PARA ESQUERDA
        }
        else {
            if (i.idade > n->pessoa.idade){
                pesquisar(i, n->dir, a);
            }
            else{
                // aqui vc faz o que precisar!!!
                cout << "\nAchei a pessoa com idade procurada: " << n->pessoa.nome << endl;
            }
        }
    }

}
//FUN��O QUE MOSTRA A PESSOA MAIS VELHA
TNoh *pesquisaMaisVelho(TNoh *&noh){
    if(noh == NULL){
        cout << "\nN�o h�" << endl;
    }else{
        if(noh->dir == NULL){

            return noh;

        }else{
            pesquisaMaisVelho(noh->dir);
        }
    }
}

//FUN��O QUE MOSTRA A PESSOA MAIS NOVA
TNoh *pesquisaMaisNovo(TNoh *&noh){
    if(noh == NULL){
        cout << "\nN�o h�" << endl;
    }else{
        if(noh->esq == NULL){

            return noh;

        }else{
            pesquisaMaisNovo(noh->esq);
        }
    }
}



void pegarAnterior(TNoh *q, TNoh *&r){

    if (r->dir != NULL){
        pegarAnterior(q, r->dir);
    }
    else{
        q->pessoa = r->pessoa;
        q = r;
        r = r->esq;
        delete q;
    }
}

//RETIRA UM N� � FAZ O MAIOR ELEMENTO APONTADO PELO O N� IR PARA O LUGAR DELE
void retirar(TPessoa i, TNoh *&p){
TNoh *aux;

    if (p == NULL){
        cout << "\nRegistro n�o encontrado" << endl;
    }
    else{
        if (i.idade < p->pessoa.idade){
            retirar(i, p->esq);
        }
        else{
            if (i.idade > p->pessoa.idade){
                retirar(i, p->dir);
            }
            else{
                if (p->dir == NULL){
                    aux = p;
                    //exemplo de "debug manual" para ajudar a entender o c�digo
                    //cout << "Passada Dir: " << aux->item.valor << endl;
                    p = p->esq;
                    delete aux;
                }
                else{
                    if (p->esq != NULL){
                        pegarAnterior(p, p->esq);
                    }
                    else{
                        aux = p;
                        p = p->dir;
                        delete aux;

                    }
                }
            }
        }
    }
}

//DEMAIS APLICA��ES

double somarDesc(double &soma, TNoh *&n){
    if(n!=NULL){
        somarDesc(soma,n->esq);
        somarDesc(soma,n->dir);
        soma += n->pessoa.idade;
    }
    return soma;
}

//FUN��O QUE CONTA O N�MERO DE NOHS NA �RVORE
int contaNos(TNoh *n){
    if (n == NULL){
        return 0;
    }
    else{
        return contaNos(n->esq) + contaNos(n->dir) + 1;
    }

}

double media(TNoh *&n){
    double s;
    int c;
    s = somarDesc(s, n);
    c = contaNos(n);
    return s/c;
}

//FUN��O QUE RETORNA A ALTURA DE N�S DA �RVORE
int alturaNoh(TNoh *n){
    int u, v;
    if (n == NULL){
        return -1;
    }
    else{
        u = alturaNoh(n->esq);
        v = alturaNoh(n->dir);
        if (u>v){
            return u+1;
        }
        else{
            return v+1;
        }
    }
}

#endif // BILBIOTECAARVORE_H_INCLUDED
