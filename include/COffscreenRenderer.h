class COffscreenRenderer{

private:

SDL_Renderer *render;
SDL_Surface *surface;
int alt,larg;

public:

    SDL_Renderer *GetRenderer(){
        return render;
    }

    SDL_Surface *GetSurface(){
        return surface;
    }

    COffscreenRenderer(int altura,int largura){
        alt = altura;
        larg=largura;
        surface = SDL_CreateRGBSurface(0, largura, altura, 32, 0,0,0,0);//0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
        render = SDL_CreateSoftwareRenderer(surface);
        SDL_RenderClear( render );
    }

    void PintarFundo(SDL_Color cor){
        SDL_SetRenderDrawColor(render,cor.r,cor.g,cor.b,cor.a);
        SDL_RenderClear( render );
    }

    void EncerrarDesenho(){
        SDL_RenderPresent(render);
    }


    void DesenhaLinha(int x1,int y1,int x2,int y2,PIG_Cor cor){
        SDL_SetRenderDrawColor(render,cor.r,cor.g,cor.b,cor.a);
        SDL_RenderDrawLine(render,x1,alt-y1,x2,alt-y2);
    }

    void DesenhaRetangulo(int x,int y,int altura,int largura,PIG_Cor cor){
        SDL_Rect r={x,y,largura,altura};

        SDL_SetRenderDrawColor(render,cor.r,cor.g,cor.b,cor.a);
        SDL_RenderFillRect(render,&r);
    }

    void SalvarImagem(char *nomearq){
        SDL_RenderReadPixels(render, NULL, SDL_PIXELFORMAT_ARGB8888, surface->pixels, surface->pitch);
        SDL_SaveBMP(surface, nomearq);
    }

    ~COffscreenRenderer(){
        SDL_DestroyRenderer(render);
        SDL_FreeSurface(surface);
    }

};

typedef COffscreenRenderer* OffscreenRenderer;
