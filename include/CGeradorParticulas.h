#include "CParticula.h"
#define MAX_PARTICULAS_GDP 1000

class CGeradorParticulas{

private:
Particula parts[MAX_PARTICULAS_GDP];
int px,py;
int maxX,maxY,minX,minY;
SDL_Renderer* renderer;
int maxParticulas;
char nome[80];
PoolNumeros numLivres;

public:
    int ativas;

    CGeradorParticulas(int maximoParticulas, int pontoX,int pontoY, int menorX,int maiorX,int menorY,int maiorY,SDL_Renderer* renderizador, char *nomeArq){
        maxParticulas = maximoParticulas;
        strcpy(nome,nomeArq);

        for (int i=0;i<maxParticulas;i++)
            parts[i] = NULL;
        numLivres = new CPoolNumeros(maxParticulas);

        renderer = renderizador;

		ativas = 0;
		minX = menorX;
		minY = menorY;
		maxX = maiorX;
		maxY = maiorY;
		px = pontoX;
		py = pontoY;
    }

    ~CGeradorParticulas(){
        for (int i=0;i<maxParticulas;i++)
            if (parts[i]) delete parts[i];
        delete numLivres;
    }

    void MoveParticulas(){
        for (int i=0;i<maxParticulas;i++)
            if (parts[i]) {
                parts[i]->Move();
                if (!parts[i]->viva){
                    delete parts[i];
                    parts[i] = NULL;
                    numLivres->DevolveUsado(i);
                    ativas--;
                }
            }
    }

    void Move(int nx,int ny){
        px = nx;
        py = ny;
    }

    void Desenha(){
        for (int i=0;i<maxParticulas;i++)
            if ((parts[i])&&(parts[i]->viva)) {
                parts[i]->Desenha();
            }
    }

    int CriaParticula(int dx,int dy,int maxColisoes,float tempoMax,int fadingOut){
        if (ativas==maxParticulas) return -1;
        int i=numLivres->RetiraLivre();
        parts[i] = new CParticula(px,py,dx,dy,maxColisoes,fadingOut,renderer,nome);
        parts[i]->DefineLimites(minX,maxX,minY,maxY,tempoMax);
        ativas++;
        return i;
    }

    int Colisao(Objeto outro){
        int resp = 0;
        int i=0,cont=0;
        while (!resp && i<maxParticulas && cont<ativas){
            if (parts[i]){
                cont++;
                resp = parts[i]->Colisao(outro);
            }
            i++;
        }
        return resp;
    }
};

typedef CGeradorParticulas* GeradorParticulas;
