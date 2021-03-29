
#include <iostream>
#include <list>
#include <algorithm>
#include <stack>

using namespace std;

class Problema
{
    int P;
    list<int> *adj;
public:
    Problema(int P);
    void adicionarAresta(int p1, int p2);

    void dfs(int p);
};

Problema::Problema(int P)
{
    this->P = P;
    adj = new list<int>[P];
}

void Problema::adicionarAresta(int p1, int p2)
{

    adj[p1].push_back(p2);
}

void Problema::dfs(int p)
{
    stack<int> pilha;
    bool visitados[P];

    // marca todos como não visitados
    for(int i = 0; i < P; i++)
        visitados[i] = false;

    while(true)
    {
        if(!visitados[p])
        {
            cout << "Visitando vertice " << p << " ...\n";
            visitados[p] = true;
            pilha.push(p);
        }

        bool achou = false;
        list<int>::iterator it;


        for(it = adj[p].begin(); it != adj[p].end(); it++)
        {
            if(!visitados[*it])
            {
                achou = true;
                break;
            }
        }

        if(achou)
            p = *it;
        else
        {

            pilha.pop();

            if(pilha.empty())
                break;

            p = pilha.top();
        }
    }
}

int main()
{
    int P = 8;

    Problema problema(P);


    problema.adicionarAresta(0, 1);
    problema.adicionarAresta(0, 2);
    problema.adicionarAresta(1, 3);
    problema.adicionarAresta(1, 4);
    problema.adicionarAresta(2, 5);
    problema.adicionarAresta(2, 6);
    problema.adicionarAresta(6, 7);

    problema.dfs(0);

    return 0;
}