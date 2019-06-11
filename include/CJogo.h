#include "CPoolNumeros.h"
#include "CObjeto.h"
#include "CTimer.h"
#include "CGeradorParticulas.h"
#include "CMapaCaracteres.h"

#define MAX_OBJETOS 500
#define MAX_TIMERS 5000
#define MAX_GERADORPARTICULAS 100
#define MAX_FONTES 100

class CJogo{

private:

    SDL_Texture* text_fundo;
    TTF_Font **gFont;
    PIG_Cor corFundo;
    PIG_Evento ultimoEvento;
    PoolNumeros numTimers;
    PoolNumeros numObjetos;
    PoolNumeros numGeradores;
    PIG_Teclado teclado;
    int fontesUsadas;

public:
    SDL_Window* window;
    static SDL_Renderer* renderer;
    static int estado;
    static int rodando;
    static Objeto objetos[MAX_OBJETOS];
    static Timer timers[MAX_TIMERS];
    static MapaCaracteres fontes[MAX_FONTES];
    static GeradorParticulas geradores[MAX_GERADORPARTICULAS];

    CJogo(char *nome){
        rodando = true;
        teclado = SDL_GetKeyboardState(NULL);
        estado = 0;

		text_fundo = NULL;
        if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ){
            printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        }else{
            window = SDL_CreateWindow( nome, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARG_TELA, ALT_TELA, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL|SDL_SWSURFACE );
            if( window == NULL ){
                printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            }else{
                renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_TARGETTEXTURE);
                SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
                SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
            }
        }

        TTF_Init();

        //inicializa o vetor contendo as fontes a serem usadas no jogo
        for (int i=0;i<MAX_FONTES;i++)
            fontes[i] = NULL;

        //criação da fonte padrão da PIG (fonte com identificador 0)
        fontes[0] = new CMapaCaracteres("..//resources//arial.ttf",renderer,36,ESTILO_NORMAL,BRANCO,0,BRANCO);
        fontesUsadas = 1;

        for (int i=0;i<MAX_OBJETOS;i++)
            objetos[i] = NULL;
        numObjetos = new CPoolNumeros(MAX_OBJETOS);

        for (int i=0;i<MAX_TIMERS;i++)
            timers[i] = NULL;
        numTimers = new CPoolNumeros(MAX_TIMERS);

        for (int i=0;i<MAX_GERADORPARTICULAS;i++)
            geradores[i] = NULL;
        numGeradores = new CPoolNumeros(MAX_GERADORPARTICULAS);

        corFundo = PRETO;
    }

    ~CJogo(){
        for (int i=0;i<MAX_OBJETOS;i++){
            if (objetos[i]) delete objetos[i];
        }
        delete numObjetos;

        for (int i=0;i<MAX_TIMERS;i++){
            if (timers[i]) delete timers[i];
        }
        delete numTimers;

        for (int i=0;i<MAX_GERADORPARTICULAS;i++){
            if (geradores[i]) delete geradores[i];
        }
        delete numGeradores;

        for (int i=0;i<MAX_FONTES;i++)
            if (fontes[i]) delete fontes[i];
        TTF_Quit();

        if (text_fundo) SDL_DestroyTexture(text_fundo);
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);

        SDL_Quit();
    }

    void DefineFundo(char *nomeArquivo){
        SDL_Surface* bitmap = SDL_LoadBMP(nomeArquivo);
        if (text_fundo)
            SDL_DestroyTexture(text_fundo);
        text_fundo = SDL_CreateTextureFromSurface(renderer,bitmap);
        SDL_FreeSurface(bitmap);
    }

    PIG_Evento PegaEvento(){
        SDL_Event event;
        if (SDL_PollEvent((&event))){
            if (event.type==SDL_QUIT)
                rodando = false;

            switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                ultimoEvento.tipoEvento = EVENTO_MOUSE;
                ultimoEvento.mouse.acao = MOUSE_PRESSIONADO;
                ultimoEvento.mouse.botao= event.button.button;
                ultimoEvento.mouse.posX = event.button.x;
                ultimoEvento.mouse.posY = ALT_TELA - event.button.y;
                break;
            case SDL_MOUSEBUTTONUP:
                ultimoEvento.tipoEvento = EVENTO_MOUSE;
                ultimoEvento.mouse.acao = MOUSE_LIBERADO;
                ultimoEvento.mouse.botao= event.button.button;
                ultimoEvento.mouse.posX = event.button.x;
                ultimoEvento.mouse.posY = ALT_TELA - event.button.y;
                break;
            case SDL_MOUSEMOTION:
                ultimoEvento.tipoEvento = EVENTO_MOUSE;
                ultimoEvento.mouse.acao = MOUSE_MOVIDO;
                ultimoEvento.mouse.posX = event.motion.x;
                ultimoEvento.mouse.posY = ALT_TELA - event.motion.y;
                ultimoEvento.mouse.relX = event.motion.xrel;
                ultimoEvento.mouse.relY = -event.motion.yrel;
                break;
            case SDL_MOUSEWHEEL:
                ultimoEvento.tipoEvento = EVENTO_MOUSE;
                ultimoEvento.mouse.acao = MOUSE_RODINHA;
                ultimoEvento.mouse.relX = event.wheel.x;
                ultimoEvento.mouse.relY = event.wheel.y;
                break;
            case SDL_KEYDOWN:
                ultimoEvento.tipoEvento = EVENTO_TECLADO;
                ultimoEvento.teclado.acao = TECLA_PRESSIONADA;
                ultimoEvento.teclado.tecla = event.key.keysym.scancode;
                ultimoEvento.teclado.repeticao = event.key.repeat;
                break;
            case SDL_KEYUP:
                ultimoEvento.tipoEvento = EVENTO_TECLADO;
                ultimoEvento.teclado.acao = TECLA_LIBERADA;
                ultimoEvento.teclado.tecla = event.key.keysym.scancode;
                ultimoEvento.teclado.repeticao = event.key.repeat;
                break;
            case SDL_TEXTEDITING:
                ultimoEvento.tipoEvento = EVENTO_TECLADO;
                ultimoEvento.teclado.acao = TECLA_EDICAO;
                ultimoEvento.teclado.inicio = event.edit.start;
                ultimoEvento.teclado.tamanhoSelecao = event.edit.length;
                strcpy(ultimoEvento.teclado.texto,event.edit.text);
                break;
            case SDL_TEXTINPUT:
                ultimoEvento.tipoEvento = EVENTO_TECLADO;
                ultimoEvento.teclado.acao = TECLA_INPUT;
                strcpy(ultimoEvento.teclado.texto,event.edit.text);
                break;
            case SDL_WINDOWEVENT:
                ultimoEvento.tipoEvento = EVENTO_JANELA;
                ultimoEvento.janela.acao = event.window.event;
                ultimoEvento.janela.dado1 = event.window.data1;
                ultimoEvento.janela.dado2 = event.window.data2;
                break;
            }
        }else ultimoEvento.tipoEvento = EVENTO_NULO;
        return ultimoEvento;
    }

    PIG_Teclado PegaTeclado(){
        return teclado;
    }

    void IniciaInputTextoTela(){
        SDL_StartTextInput();
    }

    void EncerraInputTextoTela(){
        SDL_StopTextInput();
    }

    void IniciaDesenho(){
        if (text_fundo==NULL) {
            SDL_SetRenderDrawColor(renderer,corFundo.r,corFundo.g,corFundo.b,255);
            SDL_RenderClear( renderer );
        }
        else SDL_RenderCopy(renderer,text_fundo,NULL,NULL);
    }

    void EncerraDesenho(){
        SDL_RenderPresent(renderer);
    }

    void DesenhaRetangulo(int x, int y, int altura, int largura, PIG_Cor cor){
        SDL_Rect rect;
        rect.x = x;
        rect.y = ALT_TELA-(y+altura);
        rect.h = altura;
        rect.w = largura;


        SDL_SetRenderDrawColor(renderer, cor.r,cor.g,cor.b,cor.a);
        SDL_RenderFillRect(renderer,&rect);
    }

    void DesenhaLinhaSimples(int x1,int y1,int x2,int y2,PIG_Cor cor){
        SDL_SetRenderDrawColor(renderer,cor.r,cor.g,cor.b,255);
        SDL_RenderDrawLine(renderer,x1,ALT_TELA-y1,x2,ALT_TELA-y2);
    }

    void DesenhaLinhasDisjuntas(int *x,int *y,int qtd,PIG_Cor cor){
        SDL_SetRenderDrawColor(renderer,cor.r,cor.g,cor.b,255);
        for (int k=0;k<qtd*2;k+=2){
            SDL_RenderDrawLine(renderer,x[k],ALT_TELA-y[k],x[k+1],ALT_TELA-y[k+1]);
        }
    }

    void DesenhaLinhasSequencia(int *x,int *y,int qtd,PIG_Cor cor){
        SDL_SetRenderDrawColor(renderer,cor.r,cor.g,cor.b,255);
        for (int k=0;k<qtd-1;k++){
            SDL_RenderDrawLine(renderer,x[k],ALT_TELA-y[k],x[k+1],ALT_TELA-y[k+1]);
        }
    }

    int CriaFonteFundo(char *nome,int tamanho,int estilo,char *arquivoFundo,int contorno=0,PIG_Cor corContorno=BRANCO){
        int aux = fontesUsadas;
        fontes[fontesUsadas] = new CMapaCaracteres(nome,renderer,tamanho,estilo,arquivoFundo,contorno,corContorno);
        fontesUsadas++;
        return aux;
    }

    int CriaFonteNormal(char *nome,int tamanho,int estilo,PIG_Cor corLetra,int contorno=0,PIG_Cor corContorno=BRANCO){
        int aux = fontesUsadas;
        fontes[fontesUsadas] = new CMapaCaracteres(nome,renderer,tamanho,estilo,corLetra,contorno,corContorno);
        fontesUsadas++;
        return aux;
    }

    int GetLarguraPixels(char *str,int numFonte=0){
        fontes[numFonte]->GetLarguraPixelsString(str);
    }

    void EscreverCentralizada(char *str,int x,int y,int numFonte=0){
        if (numFonte>=fontesUsadas)
            printf("Erro: fonte %d nao foi criada\n",numFonte);
        fontes[numFonte]->EscreveStringCentralizado(str,x,y);
    }

    void EscreverDireita(char *str,int x,int y,int numFonte=0){
        if (numFonte>=fontesUsadas)
            printf("Erro: fonte %d nao foi criada\n",numFonte);
        fontes[numFonte]->EscreveStringDireita(str,x,y);
    }

    void EscreverEsquerda(char *str,int x,int y,int numFonte=0){
        if (numFonte>=fontesUsadas)
            printf("Erro: fonte %d nao foi criada\n",numFonte);
        fontes[numFonte]->EscreveStringEsquerda(str,x,y);
    }

    int Cria_Objeto(int posx,int posy,char* nomeArquivoBMP,int transp=255){
        int resp = numObjetos->RetiraLivre();
        objetos[resp] = new CObjeto(posx,posy,renderer,nomeArquivoBMP,transp);
        return resp;
    }

    void Destroi_Objeto(int id_objeto){
        numObjetos->DevolveUsado(id_objeto);
        delete objetos[id_objeto];
        objetos[id_objeto] = NULL;
    }

    int Cria_Timer(){
        int resp = numTimers->RetiraLivre();
        timers[resp] = new CTimer();
        return resp;
    }

    void Destroi_Timer(int id_timer){
        numTimers->DevolveUsado(id_timer);
        delete timers[id_timer];
        timers[id_timer] = NULL;
    }

    void Pausa(){
        for (int i=0;i<MAX_TIMERS;i++){
            if (timers[i])
                timers[i]->Pausa();
        }
    }

    void Despausa(){
        for (int i=0;i<MAX_TIMERS;i++){
            if (timers[i]){
                timers[i]->Despausa();
            }
        }
    }

    int Cria_GeradorParticulas(int maxParticulas,int origemX,int origemY,int menorX,int maiorX,int menorY,int maiorY,char* nomeArquivoBMP){
        int resp = numGeradores->RetiraLivre();
        geradores[resp] = new CGeradorParticulas(maxParticulas,origemX,origemX,menorX,maiorX,menorY,maiorY,renderer,nomeArquivoBMP);
        return resp;
    }

    void Destroi_GeradorParticulas(int id_gerador){
        numGeradores->DevolveUsado(id_gerador);
        delete geradores[id_gerador];
        geradores[id_gerador] = NULL;
    }

    void GetPixel(int x,int y,int &r,int &g,int &b) {
        if (x<0 || x>=LARG_TELA  ||y<0 ||y>=ALT_TELA) return;

        SDL_Surface* saveSurface = NULL;
        SDL_Surface* infoSurface = NULL;
        infoSurface = SDL_GetWindowSurface(window);
        if (infoSurface != NULL) {
            unsigned char * pixels = new unsigned char[infoSurface->w * infoSurface->h * infoSurface->format->BytesPerPixel];
            if (pixels != 0) {
                if (SDL_RenderReadPixels(renderer, &infoSurface->clip_rect, infoSurface->format->format, pixels, infoSurface->w * infoSurface->format->BytesPerPixel) == 0) {
                    Uint8 mr,mg,mb;
                    Uint32 *p = (Uint32*) pixels;
                    p += (x+(ALT_TELA-y)*LARG_TELA);
                    SDL_GetRGB(*p,(const SDL_PixelFormat*) &infoSurface->format->format,&mr,&mg,&mb);
                    r = mr;
                    g = mg;
                    b = mb;
                }
                delete[] pixels;
            }
            SDL_FreeSurface(infoSurface);
        }
    }

    void saveScreenshotBMP(char *nome) {
        SDL_Surface* saveSurface = NULL;
        SDL_Surface* infoSurface = NULL;
        infoSurface = SDL_GetWindowSurface(window);
        if (infoSurface != NULL) {
            unsigned char * pixels = new unsigned char[infoSurface->w * infoSurface->h * infoSurface->format->BytesPerPixel];
            if (pixels != 0) {
                if (SDL_RenderReadPixels(renderer, &infoSurface->clip_rect, infoSurface->format->format, pixels, infoSurface->w * infoSurface->format->BytesPerPixel) == 0) {
                    saveSurface = SDL_CreateRGBSurfaceFrom(pixels, infoSurface->w, infoSurface->h, infoSurface->format->BitsPerPixel, infoSurface->w * infoSurface->format->BytesPerPixel, infoSurface->format->Rmask, infoSurface->format->Gmask, infoSurface->format->Bmask, infoSurface->format->Amask);
                    if (saveSurface != NULL) {
                        SDL_SaveBMP(saveSurface, nome);
                        SDL_FreeSurface(saveSurface);
                    }
                }
                delete[] pixels;
            }
            SDL_FreeSurface(infoSurface);
        }
    }
};

int CJogo::rodando;
int CJogo::estado;

Objeto CJogo::objetos[MAX_OBJETOS];
Timer CJogo::timers[MAX_TIMERS];
MapaCaracteres CJogo::fontes[MAX_FONTES];
GeradorParticulas CJogo::geradores[MAX_GERADORPARTICULAS];
SDL_Renderer* CJogo::renderer;

typedef CJogo* Jogo;
