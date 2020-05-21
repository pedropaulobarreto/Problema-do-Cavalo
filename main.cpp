#include <stdio.h>

const int N = 2;

struct posicao{
    int x, y;
};

class Posicao{
    public:
        posicao pos;
        bool check;
};

class TourCavalo
{
    public:
    Posicao tab[(2*N+1)][(2*N+1)];
    int cont=1;
    int movi[16] = {-2,-2,-1,-1,1,1,2,2,1,-1,2,-2,2,-2,-1,1} ;

    void realizaPasseio()
    {
        posicao inicial {0,0};
        for(int i=0;i<(2*N+1);i++)
            for(int j=0;j<(2*N+1);j++){
                tab[i][j].pos.x =-N+i;
                tab[i][j].pos.y =-N+j;
                tab[i][j].check = false;
            }

        tab[N][N].check = true;

        int i;
        for(i=0;i<8;i++)
        {
            if(tentativa(posicao {inicial.x+movi[i],inicial.y+movi[i+8]}))
                break;
        }
        if(i==8)
            printf("Nao foi encontrado nenhuma solucao\n");
        else
            printf("Solucao encontrada\n");

    }

    bool tentativa(posicao a)
    {
        cont++;
        tab[a.x+N][a.y+N].check = true;
        if(esta_cheio())
            return true;
        for(int i=0;i<8;i++)
        {
            if(e_aceitavel(posicao {a.x+movi[i],a.y+movi[i+8]})){
                if(tentativa(posicao {a.x+movi[i],a.y+movi[i+8]}))
                    return true;
            }
        }
        cont--;

        tab[a.x+N][a.y+N].check = false;
        return false;

    }

    bool e_aceitavel(posicao a)
    {
        if(((a.x > N) ||(a.y > N)||(a.x<-N)||(a.y< -N))||tab[a.x+N][a.y+N].check)
            return false;
        return true;
    }

    bool esta_cheio()
    {
        if(cont==((2*N+1)*(2*N+1)))
            return true;
        return false;
    }
};

int main()
{
    TourCavalo teste;
    teste.realizaPasseio();
    return 0;
}
