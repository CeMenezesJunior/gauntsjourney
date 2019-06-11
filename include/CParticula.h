class CParticula: public CObjeto{

private:
Timer tempo;
int xini,yini;
int dx,dy;
int menor_x,maior_x,menor_y,maior_y;
int maxColisoes;
int fading;
float lim_tempo;

public:
    bool viva;

    CParticula(int px,int py,int desloc_x,int desloc_y,int vida,int fadeOut, SDL_Renderer* renderizador,char *nomeArq):CObjeto(px,py,renderizador,nomeArq){
        xini = px;
        yini = py;
        dx = desloc_x;
        dy = desloc_y;
        maxColisoes = vida;
        fading = fadeOut;

        tempo = new CTimer();
        viva = true;
    }

    void DefineLimites(int xMenor,int xMaior,int yMenor,int yMaior, float tempoMax){
        menor_x = xMenor;
        maior_x = xMaior;
        menor_y = yMenor;
        maior_y = yMaior;
        lim_tempo = tempoMax;
    }

    ~CParticula(){
        delete tempo;
    }

    void Move(){
        if (!viva) return;
        float decorrido = tempo->GetTempoDecorrido();
        x = xini + dx*decorrido;
        y = yini + dy*decorrido;
        if (fading)
            CObjeto::SetTransparencia(255*(1-(decorrido/lim_tempo)));
        CObjeto::Move(x,y);
        viva = (x>menor_x)&&(x<maior_x)&&(y>menor_y)&&(y<maior_y)&&(decorrido<lim_tempo);
    }

    void MudaDirecao(int novaDx,int novaDy){
        dx = novaDx;
        dy = novaDy;
    }

    int Colisao(Objeto outro){
        int resp = CObjeto::Colisao(outro);
        if (resp){
            maxColisoes--;
            viva = maxColisoes>0;
        }
        return resp;
    }
};

typedef CParticula* Particula;
