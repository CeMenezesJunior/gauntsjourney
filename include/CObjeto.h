class CObjeto{

#define MAX_ATRIBUTOS_OBJETO    100
#define MAX_FRAMES_OBJETO       400

protected:
    int alt, larg;
    float angulo;
    int *valoresInt;
    double *valoresDouble;
    SDL_Rect dest;
    SDL_Texture* text;
    SDL_Rect *origem;
    SDL_Point pivo;
    SDL_Renderer* renderer;
    SDL_RendererFlip flip;
    SDL_Surface* bitmap;
public:

    int x,y;
    int estado;

    CObjeto(int posx,int posy, SDL_Renderer* renderizador,char* nomeArquivo,int retiraFundo=1,int transp=255){
        estado = 0;

        x = posx;
        y = posy;

        renderer = renderizador;
        angulo = 0;
        pivo.x = pivo.y = 0;
        valoresInt = (int*) calloc(sizeof(int),MAX_ATRIBUTOS_OBJETO);
        valoresDouble = (double*) calloc(sizeof(double),MAX_ATRIBUTOS_OBJETO);

        flip = SDL_FLIP_NONE;
        bitmap = IMG_Load(nomeArquivo);
        if (!bitmap)
            printf("Erro ao ler arquivo: %s\n",nomeArquivo);
        alt = bitmap->h;
        larg = bitmap->w;

        dest.x = x;
        dest.y = ALT_TELA-y-alt;
        dest.h = alt;
        dest.w = larg;

        origem = (SDL_Rect*) malloc(MAX_FRAMES_OBJETO*sizeof(SDL_Rect));

        origem[0].x = origem[0].y = 0;
        origem[0].h = alt;
        origem[0].w = larg;

        Uint8 red, green, blue, alpha;
        SDL_LockSurface(bitmap);
        if (bitmap->format->BitsPerPixel==8){
            Uint8 *pixel;

            pixel = (Uint8*)bitmap->pixels;
            SDL_GetRGBA(*pixel,bitmap->format,&red,&green,&blue,&alpha);
        }else{
            Uint32 *pixel;

            pixel = (Uint32*)bitmap->pixels;
            SDL_GetRGBA(*pixel,bitmap->format,&red,&green,&blue,&alpha);
        }
        SDL_UnlockSurface(bitmap);

        if (retiraFundo)
            SDL_SetColorKey( bitmap, SDL_TRUE, SDL_MapRGBA(bitmap->format, red, green, blue,alpha) );

        text = SDL_CreateTextureFromSurface(renderizador, bitmap);
        if (transp<255)
            SDL_SetTextureAlphaMod(text,transp);
    }

    ~CObjeto(){
        free(origem);
        free(valoresInt);
        free(valoresDouble);
        if (text) SDL_DestroyTexture(text);
        if (bitmap) SDL_FreeSurface(bitmap);
    }

    void CriaFrame(int codFrame,int xBitmap, int yBitmap,int altura,int largura){
        origem[codFrame].x = xBitmap;
        origem[codFrame].y = yBitmap;
        origem[codFrame].h = altura;
        origem[codFrame].w = largura;
    }

    void GetXY(int &x,int &y){
        x = this->x;
        y = this->y;
    }

    void SetColoracao(PIG_Cor cor){
        SDL_SetTextureColorMod(text,cor.r,cor.g,cor.b);
    }

    void Desenha(){
        SDL_RenderCopyEx(renderer, text, &(origem[estado]),&dest,angulo,&pivo,flip);
    }

    int Colisao(CObjeto* outro){
        int x1,x2,y1,y2;
        int a1,a2,b1,b2;
        x1 = x;
        x2 = x1 + larg;
        y1 = y;
        y2 = y1 + alt;

        a1 = outro->x;
        a2 = a1+outro->larg;
        b1 = outro->y;
        b2 = b1+outro->alt;

        if (x1>=a1 && x1<=a2 && y1>=b1 && y1<=b2){
            return 1;
        }
        if (x1>=a1 && x1<=a2 && y2>=b1 && y2<=b2){
            return 1;
        }
        if (x2>=a1 && x2<=a2 && y1>=b1 && y1<=b2){
            return 1;
        }
        if (x2>=a1 && x2<=a2 && y2>=b1 && y2<=b2){
            return 1;
        }
        if (a1>=x1 && a1<=x2 && b1>=y1 && b1<=y2){
            return 1;
        }
        if (a2>=x1 && a2<=x2 && b2>=y1 && b2<=y2){
            return 1;
        }

        return 0;
    }

    void SetFlip(PIG_Flip valor){
        flip = valor;
    }

    void SetAngulo(float a){
        angulo = -a;
    }

    void SetPivo(int px,int py){
        pivo.x = px;
        pivo.y = py;
        dest.x = x-pivo.x;
        dest.y = ALT_TELA-y-alt+pivo.y;
    }

    void SetValorInt(int indice, int valor){
        valoresInt[indice] = valor;
    }

    void SetValorDouble(int indice, double valor){
        valoresDouble[indice] = valor;
    }

    int GetValorInt(int indice){
        return valoresInt[indice];
    }

    double GetValorDouble(int indice){
        return valoresDouble[indice];
    }

    void Move(int nx,int ny){
        x = nx;
        y = ny;
        dest.x = x-pivo.x;
        dest.y = ALT_TELA-y-alt+pivo.y;
    }

    void SetDimensoes(int altura,int largura){
        dest.h = alt = altura;
        dest.w = larg = largura;
        dest.x = x-pivo.x;
        dest.y = ALT_TELA-y-alt-pivo.y;
    }

    void GetDimensoes(int &altura, int &largura){
        altura = alt;
        largura = larg;
    }

    void SetTransparencia(int valor){
        SDL_SetTextureAlphaMod(text,valor);
    }

};

typedef CObjeto* Objeto;
