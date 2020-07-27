#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<locale.h>

using namespace std;

struct cadastroAcad
{
    int ra;
    string nome,telefone,cpf,rg,curso;
};
struct no
{
    cadastroAcad academico;
    no *prox;
};
no criaNo(int ra)
{
    no novo;
    novo.prox=NULL;

    cout<<"Academico: ";
    getline(cin,novo.academico.nome);
    cin.sync();

    cout<<"curso de graduacao: ";
    getline(cin,novo.academico.curso);
    cin.sync();

    cout<<"CPF: ";
    getline(cin,novo.academico.cpf);
    cin.sync();

    cout<<"RG: ";
    getline(cin,novo.academico.rg);
    cin.sync();

    cout<<"TELEFONE: ";
    getline(cin,novo.academico.telefone);
    cin.sync();

    novo.academico.ra=ra;
    ra++;

    return novo;
}
void listarAcad(no *ini)
{
    no *aux=ini;
    while(aux!=NULL)
    {
        cout<<"Academico: "<<aux->academico.nome<<endl;

        cout<<"curso de graduacao: "<<aux->academico.curso<<endl;

        cout<<"CPF: "<<aux->academico.cpf<<endl;

        cout<<"RG: "<<aux->academico.rg<<endl;

        cout<<"TELEFONE: "<<aux->academico.telefone<<endl;

        aux=aux->prox;
    }
}
void insereLista(no *ini,int p,int ra)
{
    no *ptr;
    if(ini==NULL)
    {
        no temp=criaNo(ra);

        ini=&temp;
        system("cls");

        cout<<"cadastro concluido"<<endl;
        system("pause");
        system("cls");
    }
    else if(ini->prox==NULL)
    {
        if(p==1)
        {
            ptr=ini;

            no temp=criaNo(ra);

            ini = &temp;
            ini->prox=ptr;
            system("cls");

            cout<<"Cadastro concluido"<<endl;
            system("pause");
            system("cls");

        }
        else
        {

            no temp=criaNo(ra);

            ini->prox = &temp;
            system("cls");

            cout<<"Cadastro concluido"<<endl;
            system("pause");
            system("cls");

        }
    }
    else
    {
        no *aux;

        ptr=ini;
        while(p-1>1&&ptr->prox->prox!=NULL)
        {
            p--;
            ptr=ptr->prox;

            no temp = criaNo(ra);

            aux=&temp;
            aux->prox=ptr->prox;
            ptr->prox=aux;
            system("cls");

            cout<<"Cadastro concluido"<<endl;
            system("pause");
            system("cls");
        }
    }
}
no removeLista (no *ini,int p)
{
    no *ptr,retorno;

    if (ini->prox==NULL)
    {
        retorno=*ini;
        delete(ini);
        ini=NULL;
    }
    else
    {
        if(p==1)
        {
            retorno=*ini;
            delete(ini);
            ini=retorno.prox;
        }
        else
        {
            ptr=ini;
            while(p-1>1&&ptr->prox!=NULL)
            {
                p--;
                ptr=ptr->prox;
            }
            retorno=*ptr->prox;
            delete(ptr->prox);
            ptr->prox=retorno.prox;
        }
    }
    return(retorno);
}
no buscaNo(no *ini, int x)
{
    no *aux=ini;
    while(aux->academico.ra!=x&&aux!=NULL)
    {
        aux=aux->prox;
    }
    return *aux;
}
int main()
{
    ifstream arquivo("arquivo.txt");

    no *ini=NULL;

    int opcao,ra=1,x;
    bool repete=true;

    arquivo.open ( "arquivo.txt" );
    setlocale(LC_ALL,"Portuguese");

    while(repete)
    {

        cout<<"##########-MENU DE SELECAO-#########"<<endl;
        cout<<"# 1)Novo                           #"<<endl;
        cout<<"# 2)Editar                         #"<<endl;
        cout<<"# 3)Remover                        #"<<endl;
        cout<<"# 4)Listar                         #"<<endl;
        cout<<"# 5)Buscar                         #"<<endl;
        cout<<"# 0)Sair                           #"<<endl;
        cout<<"####################################"<<endl;
        cout<<"Opcao: ";
        cin>>opcao;
        cin.sync();

        system("cls");

        switch(opcao)
        {
        case 1:
            insereLista(ini,x,ra);
            break;

        case 2:
            if (ini==NULL)
            {
                cout<<"nao contem registro"<<endl;
                system("pause");
                system("cls");
            }
            else
            {
                cout<<"Registro academico(ra): "<<endl;
                cin>>x;
                buscaNo(ini,x);
            }
            break;

        case 3:
            if (ini==NULL)
            {
                cout<<"nao contem registro"<<endl;
                system("pause");
                system("cls");
            }
            else
            {
                removeLista(ini,x);
            }
            break;
        case 4:
            if (ini==NULL)
            {
                cout<<"nao contem registro"<<endl;
                system("pause");
                system("cls");
            }
            else
            {
                listarAcad(ini);
            }
            break;
        case 5:
            if (ini==NULL)
            {
                cout<<"nao contem registro"<<endl;
                system("pause");
                system("cls");
            }
            else
            {
                buscaNo(ini,x);
            }
            break;
        case 0:
            repete=false;
            break;
        default:
            cout<<"Número Inválido"<<endl;
            system("pause");
            system("cls");
            break;


        }

    }

    arquivo.close();

}
