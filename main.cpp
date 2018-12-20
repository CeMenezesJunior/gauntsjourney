#define ALT_TELA    600
#define LARG_TELA   800

#include "PIG.h"

PIG_Evento evento;
PIG_Teclado meuTeclado;

    int EstadoDoJogo = 1;
    int Capa;
    int James_Gaunt;
    int cont_f=1,cont_t=0,cont_d=0,cont_e=0,cont=0;
    int mov_d=1, mov_e,mov_t,mov_f;
    int James_Gaunt_f2;
    int James_Gaunt_f3;
    int James_Gaunt_t1;
    int James_Gaunt_t2;
    int James_Gaunt_t3;
    int James_Gaunt_d1;
    int James_Gaunt_d2;
    int James_Gaunt_d3;
    int James_Gaunt_e1;
    int James_Gaunt_e2;
    int James_Gaunt_e3;
    int Chara,Chara_1,Chara_2,Chara_3,Chara_4,Chara_5,Chara_6,Chara_7,Chara_8,Chara_9,Chara_10,Chara_11;
    int mov=2;
    int Elixir;
    int mapa = 1;
    int mapa1;
    int c1_mapa1,c2_mapa1,c3_mapa1,c4_mapa1,c5_mapa1,c6_mapa1,c7_mapa1,c8_mapa1,c9_mapa1,c10_mapa1;
    int mapa2;
    int c1_mapa2,c2_mapa2,c3_mapa2,c4_mapa2,c5_mapa2,c6_mapa2,c7_mapa2,c8_mapa2,c9_mapa2,c10_mapa2,c11_mapa2,c12_mapa2,c13_mapa2,c14_mapa2,c15_mapa2;
    int mapa3;
    int c1_mapa3,c2_mapa3,c3_mapa3,c4_mapa3,c5_mapa3,c6_mapa3,c7_mapa3,c8_mapa3,c9_mapa3,c10_mapa3,c11_mapa3,c12_mapa3,c13_mapa3,c14_mapa3,c15_mapa3,c16_mapa3,c17_mapa3;
    int mapa4;
    int c1_mapa4,c2_mapa4,c3_mapa4,c4_mapa4,c5_mapa4,c6_mapa4,c7_mapa4,c8_mapa4,c9_mapa4,c10_mapa4,c11_mapa4,c12_mapa4,c13_mapa4,c14_mapa4,c15_mapa4,c16_mapa4,c17_mapa4,c18_mapa4,c19_mapa4;
    int MenuSeta;
    int MenuOp = 1;
    int turno=1;
    int contb=1;
    int n=200;
    int LutaTimer;
    int contc=0;
    int contba=0;

    int Menup = 0;
    int PauseSeta;
    int VidaTimer;
    int TextoTimer;
    int PauseNum=1;
    int FundoBatalha;
    int BatalhaJames;
    int BatalhaMagico;
    int BatalhaHumano;
    int SetaBatalha;
    char idade[10];
    char xp[10];
    char vida[10];
    char lv[10];
    int contd=0,cont_b=0;



    FILE *save;
    FILE *inicial;

    void MoverChara();

    typedef struct jamesgaunt{
        int idade=19;
        int xp=10;
        int vida=100;
        int lv=1;
    } JamesGaunt;
    JamesGaunt JG;


    typedef struct inimigo{
        char *Tipo;
        int xp;
        int vida;
        int lv;
    }Inimigo;

    Inimigo **ini;

   typedef struct magia{
        char *Nome;
        int dano;
        int lv;
    }Magia;
    Magia **magica;
    typedef struct ataque{
        char *Nome;
        int dano;
    }Ataque;
    Ataque **golpe;

    Magia ** nome_magia(Magia **magica){
        int i;
        time_t t;
        magica = (Magia**) malloc (5*sizeof(Magia*));
        for(i=0;i<5;i++)
            magica[i] = (Magia*) malloc(sizeof(Magia));
        magica[0]->Nome = "Expelliarmus";
        magica[0]->lv = 1;
        srand((unsigned) time(&t));
        magica[0]->dano = rand()%10;
        magica[1]->Nome = "Bombarda";
        magica[1]->lv = 2;
        srand((unsigned) time(&t));
        magica[1]->dano = rand()%20;
        magica[2]->Nome = "Estupore";
        magica[2]->lv = 3;
        srand((unsigned) time(&t));
        magica[2]->dano = rand()%30;
        magica[3]->Nome = "Petrificus Totalus";
        magica[3]->lv = 4;
        srand((unsigned) time(&t));
        magica[3]->dano = rand()%40;
        magica[4]->Nome = "Avada Kedrava";
        magica[4]->lv = 5;
        magica[4]->dano = 100;
        return magica;

    }

    Ataque ** nome_ataque(Ataque **golpe){
        int i;
        time_t t;
        golpe = (Ataque**) malloc(3*sizeof(Ataque*));
        for(i=0;i<3;i++)
            golpe[i]=(Ataque*) malloc(3*sizeof(Ataque*));
        golpe[0]->Nome = "Soco";
        srand((unsigned) time(&t));
        golpe[0]->dano=rand()%5;
        golpe[1]->Nome = "Pedrada";
        srand((unsigned) time(&t));
        golpe[1]->dano= rand()%10;
        golpe[2]->Nome = "Paulada";
        srand((unsigned) time(&t));
        golpe[2]->dano=rand()%15;
        return golpe;
    }

    Inimigo** nome_inimigo(Inimigo **ini)
    {
        int i;
        time_t t,j;
        ini = (Inimigo**) malloc(20*sizeof(Inimigo*));
        for(i=0;i<20;i++)
            ini[i] = (Inimigo*) malloc(sizeof(Inimigo));
        for(i=0;i<10;i++){
            ini[i]->Tipo="Magico";
            srand((unsigned) time(&t));
            ini[i]->lv = rand()%JG.lv;
            ini[i]->xp = 0;
            ini[i]->vida=100;

        }
        for(i=10;i<20;i++){
            ini[i]->Tipo="Humano";
            srand((unsigned) time(&j));
            ini[i]->lv = rand()%JG.lv;
            ini[i]->xp = 0;
            ini[i]->vida=100;
        }
        return ini;
    }


    void Cria_inimigo(){

    Chara= Cria_Objeto("imagens\\Chara\\Chara1.bmp");
    Define_Dimensoes(Chara,30,30);
    Move_Objeto(Chara,300,80);

    Chara_1= Cria_Objeto("imagens\\Chara\\Chara2.bmp");
    Define_Dimensoes(Chara_1,30,30);

    Chara_2= Cria_Objeto("imagens\\Chara\\Chara3.bmp");
    Define_Dimensoes(Chara_2,30,30);

    Chara_3= Cria_Objeto("imagens\\Chara\\Chara4.bmp");
    Define_Dimensoes(Chara_3,30,30);

    Chara_4= Cria_Objeto("imagens\\Chara\\Chara5.bmp");
    Define_Dimensoes(Chara_4,30,30);

    Chara_5= Cria_Objeto("imagens\\Chara\\Chara6.bmp");
    Define_Dimensoes(Chara_5,30,30);

    Chara_6= Cria_Objeto("imagens\\Chara\\Chara7.bmp");
    Define_Dimensoes(Chara_6,30,30);

    Chara_7= Cria_Objeto("imagens\\Chara\\Chara8.bmp");
    Define_Dimensoes(Chara_7,30,30);

    Chara_8= Cria_Objeto("imagens\\Chara\\Chara9.bmp");
    Define_Dimensoes(Chara_8,30,30);

    Chara_9= Cria_Objeto("imagens\\Chara\\Chara10.bmp");
    Define_Dimensoes(Chara_9,30,30);

    Chara_10= Cria_Objeto("imagens\\Chara\\Chara11.bmp");
    Define_Dimensoes(Chara_10,30,30);

    Chara_11= Cria_Objeto("imagens\\Chara\\Chara12.bmp");
    Define_Dimensoes(Chara_11,30,30);
    }
    void DesenhaMagico(){
        int x,y;
        GetXY_Objeto(Chara,&x,&y);
        Desenha_Objeto(Chara);
    }

    void Cria_mapa1(){

    mapa1= Cria_Objeto("imagens\\mapa1.bmp");
    Define_Dimensoes(mapa1,600,800);

    c1_mapa1 = Cria_Objeto("imagens\\Colisao_mapa1\\c1mapa1.bmp");
    Define_Dimensoes(c1_mapa1,600,185);
    Move_Objeto(c1_mapa1,0,0);

    c2_mapa1 = Cria_Objeto("imagens\\Colisao_mapa1\\c2mapa1.bmp");
    Define_Dimensoes(c2_mapa1,600,185);
    Move_Objeto(c2_mapa1,615,0);

    c3_mapa1 = Cria_Objeto("imagens\\Colisao_mapa1\\c3mapa1.bmp");
    Define_Dimensoes(c3_mapa1,235,50);
    Move_Objeto(c3_mapa1,560,90);

    c4_mapa1 = Cria_Objeto("imagens\\Colisao_mapa1\\c4mapa1.bmp");
    Define_Dimensoes(c4_mapa1,90,58);
    Move_Objeto(c4_mapa1,504,141);

    c5_mapa1 = Cria_Objeto("imagens\\Colisao_mapa1\\c5mapa1.bmp");
    Define_Dimensoes(c5_mapa1,278,49);
    Move_Objeto(c5_mapa1,190,136);

    c6_mapa1 = Cria_Objeto("imagens\\Colisao_mapa1\\c6mapa1.bmp");
    Define_Dimensoes(c6_mapa1,135,145);
    Move_Objeto(c6_mapa1,183,463);

    c7_mapa1 = Cria_Objeto("imagens\\Colisao_mapa1\\c7mapa1.bmp");
    Define_Dimensoes(c7_mapa1,137,168);
    Move_Objeto(c7_mapa1,425,462);

    c8_mapa1 = Cria_Objeto("imagens\\Colisao_mapa1\\c8mapa1.bmp");
    Define_Dimensoes(c8_mapa1,50,36);
    Move_Objeto(c8_mapa1,286,409);

    c9_mapa1 = Cria_Objeto("imagens\\Colisao_mapa1\\c9mapa1.bmp");
    Define_Dimensoes(c9_mapa1,50,36);
    Move_Objeto(c9_mapa1,429,409);

    c10_mapa1 = Cria_Objeto("imagens\\Colisao_mapa1\\c10mapa1.bmp");
    Define_Dimensoes(c10_mapa1,114,94);
    Move_Objeto(c10_mapa1,328,462);

    }
    void Cria_mapa2(){
        mapa2= Cria_Objeto("imagens\\mapa2.bmp");
        Define_Dimensoes(mapa2,600,800);

        c1_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c1mapa2.bmp");
        Define_Dimensoes(c1_mapa2,600,128);
        Move_Objeto(c1_mapa2,0,0);

        c2_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c2mapa2.bmp");
        Define_Dimensoes(c2_mapa2,99,37);
        Move_Objeto(c2_mapa2,125,342);

        c3_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c3mapa2.bmp");
        Define_Dimensoes(c3_mapa2,93,65);
        Move_Objeto(c3_mapa2,128,153);

        c4_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c4mapa2.bmp");
        Define_Dimensoes(c4_mapa2,127,239);
        Move_Objeto(c4_mapa2,128,475);

        c5_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c5mapa2.bmp");
        Define_Dimensoes(c5_mapa2,129,47);
        Move_Objeto(c5_mapa2,403,473);

        c6_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c6mapa2.bmp");
        Define_Dimensoes(c6_mapa2,129,63);
        Move_Objeto(c6_mapa2,440,473);

        c7_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c7mapa2.bmp");
        Define_Dimensoes(c7_mapa2,128,255);
        Move_Objeto(c7_mapa2,546,474);

        c8_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c8mapa2.bmp");
        Define_Dimensoes(c8_mapa2,32,70);
        Move_Objeto(c8_mapa2,660,441);

        c9_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c9mapa2.bmp");
        Define_Dimensoes(c9_mapa2,448,94);
        Move_Objeto(c9_mapa2,705,0);

        c10_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c10mapa2.bmp");
        Define_Dimensoes(c10_mapa2,98,578);
        Move_Objeto(c10_mapa2,125,0);

        c11_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c11mapa2.bmp");
        Define_Dimensoes(c11_mapa2,163,99);
        Move_Objeto(c11_mapa2,598,105);

        c12_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c12mapa2.bmp");
        Define_Dimensoes(c12_mapa2,129,33);
        Move_Objeto(c12_mapa2,240,473);

        c13_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c13mapa2.bmp");
        Define_Dimensoes(c13_mapa2,129,36);
        Move_Objeto(c13_mapa2,522,477);

        c14_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c14mapa2.bmp");
        Define_Dimensoes(c14_mapa2,99,191);
        Move_Objeto(c14_mapa2,300,0);

        c15_mapa2 = Cria_Objeto("imagens\\Colisao_mapa2\\c15mapa2.bmp");
        Define_Dimensoes(c10_mapa1,114,94);
        Move_Objeto(c15_mapa2,328,462);


    }
    void Cria_mapa3(){
        mapa3= Cria_Objeto("imagens\\mapa3.bmp");
        Define_Dimensoes(mapa3,500,800);

        c1_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c1mapa3.bmp");
        Define_Dimensoes(c1_mapa3,290,35);
        Move_Objeto(c1_mapa3,0,215);

        c2_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c2mapa3.bmp");
        Define_Dimensoes(c2_mapa3,33,227);
        Move_Objeto(c2_mapa3,0,0);

        c3_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c3mapa3.bmp");
        Define_Dimensoes(c3_mapa3,63,126);
        Move_Objeto(c3_mapa3,45,218);

        c4_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c4mapa3.bmp");
        Define_Dimensoes(c4_mapa3,64,94);
        Move_Objeto(c4_mapa3,110,187);

        c5_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c5mapa3.bmp");
        Define_Dimensoes(c5_mapa3,35,32);
        Move_Objeto(c5_mapa3,143,40);

        c6_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c6mapa3.bmp");
        Define_Dimensoes(c6_mapa3,238,64);
        Move_Objeto(c6_mapa3,248,0);

        c7_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c7mapa3.bmp");
        Define_Dimensoes(c7_mapa3,30,65);
        Move_Objeto(c7_mapa3,317,183);

        c8_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c8mapa3.bmp");
        Define_Dimensoes(c8_mapa3,70,460);
        Move_Objeto(c8_mapa3,320,0);

        c9_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c9mapa3.bmp");
        Define_Dimensoes(c9_mapa3,390,194);
        Move_Objeto(c9_mapa3,600,90);

        c10_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c10mapa3.bmp");
        Define_Dimensoes(c10_mapa3,66,29);
        Move_Objeto(c10_mapa3,423,70);

        c11_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c11mapa3.bmp");
        Define_Dimensoes(c11_mapa3,137,311);
        Move_Objeto(c11_mapa3,106,326);

        c12_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c12mapa3.bmp");
        Define_Dimensoes(c12_mapa3,143,96);
        Move_Objeto(c12_mapa3,450,321);

        c14_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c14mapa3.bmp");
        Define_Dimensoes(c14_mapa3,70,43);
        Move_Objeto(c14_mapa3,418,321);

        c15_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c15mapa3.bmp");
        Define_Dimensoes(c15_mapa3,127,35);
        Move_Objeto(c15_mapa3,71,322);

        c16_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c16mapa3.bmp");
        Define_Dimensoes(c16_mapa3,53,28);
        Move_Objeto(c16_mapa3,249,325);

        c17_mapa3 = Cria_Objeto("imagens\\Colisao_mapa3\\c17mapa3.bmp");
        Define_Dimensoes(c17_mapa3,163,739);
        Move_Objeto(c17_mapa3,0,500);


    }
    void Cria_mapa4(){
        mapa4= Cria_Objeto("imagens\\mapa4.bmp");
        Define_Dimensoes(mapa4,500,800);

        c1_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c1mapa4.bmp");
        Define_Dimensoes(c1_mapa4,433,35);
        Move_Objeto(c1_mapa4,0,0);

        c2_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c2mapa4.bmp");
        Define_Dimensoes(c2_mapa4,295,64);
        Move_Objeto(c2_mapa4,30,240);

        c3_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c3mapa4.bmp");
        Define_Dimensoes(c3_mapa4,184,30);
        Move_Objeto(c3_mapa4,96,315);

        c4_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c4mapa4.bmp");
        Define_Dimensoes(c4_mapa4,113,65);
        Move_Objeto(c4_mapa4,123,386);

        c5_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c5mapa4.bmp");
        Define_Dimensoes(c5_mapa4,161,122);
        Move_Objeto(c5_mapa4,186,310);

        c6_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c6mapa4.bmp");
        Define_Dimensoes(c6_mapa4,84,515);
        Move_Objeto(c6_mapa4,305,422);

        c7_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c7mapa4.bmp");
        Define_Dimensoes(c7_mapa4,420,68);
        Move_Objeto(c7_mapa4,735,0);

        c8_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c8mapa4.bmp");
        Define_Dimensoes(c8_mapa4,75,97);
        Move_Objeto(c8_mapa4,30,0);

        c9_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c9mapa4.bmp");
        Define_Dimensoes(c9_mapa4,78,547);
        Move_Objeto(c9_mapa4,215,0);

        c10_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c10mapa4.bmp");
        Define_Dimensoes(c10_mapa4,49,475);
        Move_Objeto(c10_mapa4,270,35);

        c11_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c11mapa4.bmp");
        Define_Dimensoes(c11_mapa4,98,137);
        Move_Objeto(c11_mapa4,310,98);

        c12_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c12mapa4.bmp");
        Define_Dimensoes(c12_mapa4,153,355);
        Move_Objeto(c12_mapa4,480,0);

        c13_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c13mapa4.bmp");
        Define_Dimensoes(c13_mapa4,36,160);
        Move_Objeto(c13_mapa4,575,155);

        c14_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c14mapa4.bmp");
        Define_Dimensoes(c14_mapa4,32,64);
        Move_Objeto(c14_mapa4,672,198);

        c15_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c15mapa4.bmp");
        Define_Dimensoes(c15_mapa4,40,36);
        Move_Objeto(c15_mapa4,704,230);

        c16_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c16mapa4.bmp");
        Define_Dimensoes(c16_mapa4,84,33);
        Move_Objeto(c16_mapa4,540,75);

        c17_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c17mapa4.bmp");
        Define_Dimensoes(c17_mapa4,35,32);
        Move_Objeto(c17_mapa4,156,40);

        c18_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c18mapa4.bmp");
        Define_Dimensoes(c18_mapa4,30,32);
        Move_Objeto(c18_mapa4,156,125);

        c19_mapa4 = Cria_Objeto("imagens\\Colisao_mapa4\\c19mapa4.bmp");
        Define_Dimensoes(c19_mapa4,84,33);
        Move_Objeto(c19_mapa4,460,70);
    }

    void Colisao(){
        int x,y,PX,PY;
        GetXY_Objeto(James_Gaunt,&x,&y);
        GetXY_Objeto(c1_mapa1,&PX,&PY);

        if(Testa_Colisao(James_Gaunt,c1_mapa1)!=0){
            Move_Objeto(James_Gaunt,x+1,y);
        }
        if(Testa_Colisao(James_Gaunt,c2_mapa1)!=0){
            Move_Objeto(James_Gaunt,x-1,y);
        }
        if(Testa_Colisao(James_Gaunt,c3_mapa1)!=0){
            Move_Objeto(James_Gaunt,x-1,y);
        }
        if(Testa_Colisao(James_Gaunt,c4_mapa1)!=0){
            Move_Objeto(James_Gaunt,x-1,y);
        }
        if(Testa_Colisao(James_Gaunt,c5_mapa1)!=0){
            Move_Objeto(James_Gaunt,x+1,y);
        }
        if(Testa_Colisao(James_Gaunt,c6_mapa1)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c7_mapa1)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c8_mapa1)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c9_mapa1)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c10_mapa1)!=0){
            mapa=2;
            Move_Objeto(James_Gaunt,370,100);




        }
}
    void Colisao2(){
        int x,y,PX,PY;
        GetXY_Objeto(James_Gaunt,&x,&y);
        GetXY_Objeto(c1_mapa2,&PX,&PY);

        if(Testa_Colisao(James_Gaunt,c1_mapa2)!=0){
            Move_Objeto(James_Gaunt,x+1,y);
        }
        if(Testa_Colisao(James_Gaunt,c2_mapa2)!=0){
            Move_Objeto(James_Gaunt,x+1,y);
        }
        if(Testa_Colisao(James_Gaunt,c3_mapa2)!=0){
            Move_Objeto(James_Gaunt,x+1,y);
        }
        if(Testa_Colisao(James_Gaunt,c4_mapa2)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c5_mapa2)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c6_mapa2)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c7_mapa2)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c8_mapa2)!=0){
            Move_Objeto(James_Gaunt,x-1,y);
        }
        if(Testa_Colisao(James_Gaunt,c9_mapa2)!=0){
            Move_Objeto(James_Gaunt,x-1,y);
        }
        if(Testa_Colisao(James_Gaunt,c10_mapa2)!=0){
            Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c11_mapa2)!=0){
           Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c12_mapa2)!=0){
           mapa=3;
           Move_Objeto(James_Gaunt,200,310);
           //Move_Objeto(Chara,150,310);

        }
        if(Testa_Colisao(James_Gaunt,c13_mapa2)!=0){
           mapa=4;
           Move_Objeto(James_Gaunt,580,92);
            //Move_Objeto(Chara,580,400);

        }
        if(Testa_Colisao(James_Gaunt,c14_mapa2)!=0){
           mapa=1;
           Move_Objeto(James_Gaunt,370,420);
        }
        if(Testa_Colisao(James_Gaunt,c15_mapa2)!=0){
           Move_Objeto(James_Gaunt,x,y-1);
        }

    }
    void Colisao3(){
        int x,y,PX,PY;
        GetXY_Objeto(James_Gaunt,&x,&y);
        GetXY_Objeto(c1_mapa3,&PX,&PY);

        if(Testa_Colisao(James_Gaunt,c1_mapa3)!=0){
            Move_Objeto(James_Gaunt,x+1,y);
        }
        if(Testa_Colisao(James_Gaunt,c2_mapa3)!=0){
            Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c3_mapa3)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c4_mapa3)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c5_mapa3)!=0){
            Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c6_mapa3)!=0){
            Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c7_mapa3)!=0){
            Move_Objeto(James_Gaunt,x+1,y);
        }
        if(Testa_Colisao(James_Gaunt,c8_mapa3)!=0){
            Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c9_mapa3)!=0){
            Move_Objeto(James_Gaunt,x-1,y);
        }
        if(Testa_Colisao(James_Gaunt,c10_mapa3)!=0){
            Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c11_mapa3)!=0){
           Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c12_mapa3)!=0){
           Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c14_mapa3)!=0){
           Move_Objeto(James_Gaunt,x,y-1);

        }
        if(Testa_Colisao(James_Gaunt,c15_mapa3)!=0){
           Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c16_mapa3)!=0){
           mapa=2;
           Move_Objeto(James_Gaunt,287,467);


        }
        if(Testa_Colisao(James_Gaunt,c17_mapa3)!=0){
          Move_Objeto(James_Gaunt,x,y-1);

        }

    }
    void Colisao4(){
        int x,y,PX,PY;
        GetXY_Objeto(James_Gaunt,&x,&y);
        GetXY_Objeto(c1_mapa4,&PX,&PY);

        if(Testa_Colisao(James_Gaunt,c1_mapa4)!=0){
            Move_Objeto(James_Gaunt,x+1,y);
        }
        if(Testa_Colisao(James_Gaunt,c2_mapa4)!=0){
            Move_Objeto(James_Gaunt,x+1,y);
        }
        if(Testa_Colisao(James_Gaunt,c3_mapa4)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c4_mapa4)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c5_mapa4)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c6_mapa4)!=0){
            Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c7_mapa4)!=0){
            Move_Objeto(James_Gaunt,x-1,y);
        }
        if(Testa_Colisao(James_Gaunt,c8_mapa4)!=0){
            Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c9_mapa4)!=0){
            Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c10_mapa4)!=0){
            Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c11_mapa4)!=0){
           Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c12_mapa4)!=0){
           Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c13_mapa4)!=0){
           Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c14_mapa4)!=0){
           Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c15_mapa4)!=0){
           Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c16_mapa4)!=0){
           mapa=2;
           Move_Objeto(James_Gaunt,480,450);

        }
        if(Testa_Colisao(James_Gaunt,c17_mapa4)!=0){
           Move_Objeto(James_Gaunt,x,y+1);
        }
        if(Testa_Colisao(James_Gaunt,c18_mapa4)!=0){
           Move_Objeto(James_Gaunt,x,y-1);
        }
        if(Testa_Colisao(James_Gaunt,c19_mapa4)!=0){
           Move_Objeto(James_Gaunt,x,y+1);
        }



    }

    void Colisao_Chara(){
        int x,y,PX,PY;
        GetXY_Objeto(Chara,&x,&y);
        GetXY_Objeto(c1_mapa1,&PX,&PY);

        if(Testa_Colisao(Chara,c1_mapa1)!=0){
            Move_Objeto(Chara,x+1,y);
        }
        if(Testa_Colisao(Chara,c2_mapa1)!=0){
            Move_Objeto(Chara,x-1,y);
        }
        if(Testa_Colisao(Chara,c3_mapa1)!=0){
            Move_Objeto(Chara,x-1,y);
        }
        if(Testa_Colisao(Chara,c4_mapa1)!=0){
            Move_Objeto(Chara,x-1,y);
        }
        if(Testa_Colisao(Chara,c5_mapa1)!=0){
            Move_Objeto(Chara,x+1,y);
        }
        if(Testa_Colisao(Chara,c6_mapa1)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c7_mapa1)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c8_mapa1)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c9_mapa1)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c10_mapa1)!=0){
            mapa=2;
            Move_Objeto(Chara,370,100);


        }
}
    void Colisao2_Chara(){
        int x,y,PX,PY;
        GetXY_Objeto(Chara,&x,&y);
        GetXY_Objeto(c1_mapa2,&PX,&PY);

        if(Testa_Colisao(Chara,c1_mapa2)!=0){
            Move_Objeto(Chara,x+1,y);
        }
        if(Testa_Colisao(Chara,c2_mapa2)!=0){
            Move_Objeto(Chara,x+1,y);
        }
        if(Testa_Colisao(Chara,c3_mapa2)!=0){
            Move_Objeto(James_Gaunt,x+1,y);
        }
        if(Testa_Colisao(Chara,c4_mapa2)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c5_mapa2)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c6_mapa2)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c7_mapa2)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c8_mapa2)!=0){
            Move_Objeto(Chara,x-1,y);
        }
        if(Testa_Colisao(Chara,c9_mapa2)!=0){
            Move_Objeto(Chara,x-1,y);
        }
        if(Testa_Colisao(Chara,c10_mapa2)!=0){
            Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c11_mapa2)!=0){
           Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c12_mapa2)!=0){
           mapa=3;
           Move_Objeto(Chara,180,310);


        }
        if(Testa_Colisao(Chara,c13_mapa2)!=0){
           mapa=4;
           Move_Objeto(Chara,500,100);
           MoverChara();

        }
        if(Testa_Colisao(Chara,c14_mapa2)!=0){
           mapa=1;
           Move_Objeto(Chara,370,300);
           MoverChara();
        }
        if(Testa_Colisao(Chara,c15_mapa2)!=0){
           Move_Objeto(Chara,x,y-1);
        }
    }
    void Colisao3_Chara(){
        int x,y,PX,PY;
        GetXY_Objeto(Chara,&x,&y);
        GetXY_Objeto(c1_mapa3,&PX,&PY);

        if(Testa_Colisao(Chara,c1_mapa3)!=0){
            Move_Objeto(Chara,x+1,y);
        }
        if(Testa_Colisao(Chara,c2_mapa3)!=0){
            Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c3_mapa3)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c4_mapa3)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c5_mapa3)!=0){
            Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c6_mapa3)!=0){
            Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c7_mapa3)!=0){
            Move_Objeto(Chara,x+1,y);
        }
        if(Testa_Colisao(Chara,c8_mapa3)!=0){
            Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c9_mapa3)!=0){
            Move_Objeto(Chara,x-1,y);
        }
        if(Testa_Colisao(Chara,c10_mapa3)!=0){
            Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c11_mapa3)!=0){
           Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c12_mapa3)!=0){
           Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c14_mapa3)!=0){
           Move_Objeto(Chara,x,y-1);

        }
        if(Testa_Colisao(Chara,c15_mapa3)!=0){
           Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c16_mapa3)!=0){
           mapa=2;
           Move_Objeto(Chara,280,467);


        }
        if(Testa_Colisao(Chara,c17_mapa3)!=0){
          Move_Objeto(Chara,x,y-1);

        }

    }
    void Colisao4_Chara(){
        int x,y,PX,PY;
        GetXY_Objeto(Chara,&x,&y);
        GetXY_Objeto(c1_mapa4,&PX,&PY);

        if(Testa_Colisao(Chara,c1_mapa4)!=0){
            Move_Objeto(Chara,x+1,y);
        }
        if(Testa_Colisao(Chara,c2_mapa4)!=0){
            Move_Objeto(Chara,x+1,y);
        }
        if(Testa_Colisao(Chara,c3_mapa4)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c4_mapa4)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c5_mapa4)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c6_mapa4)!=0){
            Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c7_mapa4)!=0){
            Move_Objeto(Chara,x-1,y);
        }
        if(Testa_Colisao(Chara,c8_mapa4)!=0){
            Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c9_mapa4)!=0){
            Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c10_mapa4)!=0){
            Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c11_mapa4)!=0){
           Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c12_mapa4)!=0){
           Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c13_mapa4)!=0){
           Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c14_mapa4)!=0){
           Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c15_mapa4)!=0){
           Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c16_mapa4)!=0){
           mapa=2;
           Move_Objeto(Chara,465,450);

        }
        if(Testa_Colisao(Chara,c17_mapa4)!=0){
           Move_Objeto(Chara,x,y+1);
        }
        if(Testa_Colisao(Chara,c18_mapa4)!=0){
           Move_Objeto(Chara,x,y-1);
        }
        if(Testa_Colisao(Chara,c19_mapa4)!=0){
           Move_Objeto(Chara,x,y+1);
        }



    }

    void Mapas(){
    switch(mapa){
        case 1:{

            Desenha_Objeto(mapa1);
            Colisao();
            Colisao_Chara();
            MoverChara();



            break;
        }
        case 2:{
            Desenha_Objeto(mapa2);
            Colisao2();
            Colisao2_Chara();
            MoverChara();



            break;
        }
        case 3:{
            Desenha_Objeto(mapa3);
            Colisao3();
            Colisao3_Chara();
            MoverChara();



            break;
        }
        case 4:{
            Desenha_Objeto(mapa4);
            Colisao4();
            Colisao4_Chara();
            MoverChara();

            break;
        }

    }

}

    void Cria_Gaunt(){

    James_Gaunt = Cria_Objeto("imagens\\Gaunt\\Gaunt_f1.png");
    Define_Dimensoes(James_Gaunt,30,30);
    Move_Objeto(James_Gaunt,400,300);

    James_Gaunt_f2 = Cria_Objeto("imagens\\Gaunt\\Gaunt_f2.png");
    Define_Dimensoes(James_Gaunt_f2,30,30);

    James_Gaunt_f3 = Cria_Objeto("imagens\\Gaunt\\Gaunt_f3.png");
    Define_Dimensoes(James_Gaunt_f3,30,30);

    James_Gaunt_t1 = Cria_Objeto("imagens\\Gaunt\\Gaunt_t1.png");
    Define_Dimensoes(James_Gaunt_t1,30,30);

    James_Gaunt_t2 = Cria_Objeto("imagens\\Gaunt\\Gaunt_t2.png");
    Define_Dimensoes(James_Gaunt_t2,30,30);

    James_Gaunt_t3 = Cria_Objeto("imagens\\Gaunt\\Gaunt_t3.png");
    Define_Dimensoes(James_Gaunt_t3,30,30);

    James_Gaunt_d1 = Cria_Objeto("imagens\\Gaunt\\Gaunt_d1.png");
    Define_Dimensoes(James_Gaunt_d1,30,30);

    James_Gaunt_d2 = Cria_Objeto("imagens\\Gaunt\\Gaunt_d2.png");
    Define_Dimensoes(James_Gaunt_d2,30,30);

    James_Gaunt_d3 = Cria_Objeto("imagens\\Gaunt\\Gaunt_d3.png");
    Define_Dimensoes(James_Gaunt_d3,30,30);

    James_Gaunt_e1 = Cria_Objeto("imagens\\Gaunt\\Gaunt_e1.png");
    Define_Dimensoes(James_Gaunt_e1,30,30);

    James_Gaunt_e2 = Cria_Objeto("imagens\\Gaunt\\Gaunt_e2.png");
    Define_Dimensoes(James_Gaunt_e2,30,30);

    James_Gaunt_e3 = Cria_Objeto("imagens\\Gaunt\\Gaunt_e3.png");
    Define_Dimensoes(James_Gaunt_e3,30,30);

    }

    void Gaunt(int x, int y){

        if(cont_f==1){
            Desenha_Objeto(James_Gaunt);}
        if(cont_f==2){

            Desenha_Objeto(James_Gaunt_f2);
            Move_Objeto(James_Gaunt_f2,x,y-1);
        }
        if(cont_f==3){
            Desenha_Objeto(James_Gaunt_f3);
            Move_Objeto(James_Gaunt_f3,x,y-1);

        }


        if (cont_t==1){
            Desenha_Objeto(James_Gaunt_t1);
            Move_Objeto(James_Gaunt_t1,x,y+1);
        }
        if (cont_t==2){
            Desenha_Objeto(James_Gaunt_t2);
            Move_Objeto(James_Gaunt_t2,x,y+1);
        }
        if (cont_t==3){
            Desenha_Objeto(James_Gaunt_t3);
            Move_Objeto(James_Gaunt_t3,x,y+1);
        }


        if (cont_d==1){
            Desenha_Objeto(James_Gaunt_d1);
            Move_Objeto(James_Gaunt_d1,x+1,y);
        }
        if (cont_d==2){
            Desenha_Objeto(James_Gaunt_d2);
            Move_Objeto(James_Gaunt_d2,x+1,y);
        }
        if (cont_d==3){
            Desenha_Objeto(James_Gaunt_d3);
            Move_Objeto(James_Gaunt_d3,x+1,y);
        }


        if (cont_e==1){
            Desenha_Objeto(James_Gaunt_e1);
            Move_Objeto(James_Gaunt_e1,x-1,y);
        }
        if (cont_e==2){
            Desenha_Objeto(James_Gaunt_e2);
            Move_Objeto(James_Gaunt_e2,x-1,y);
        }
        if (cont_e==3){
            Desenha_Objeto(James_Gaunt_e3);
            Move_Objeto(James_Gaunt_e3,x-1,y);
        }

        //Realocação dos contadores da função MoverPersonagem() para Gaunt()
        if(cont_f==1){
            cont_d = cont_e = cont_t=0;
        }

        if(cont_t==1){
            cont_f = cont_d = cont_e=0;
        }

        if(cont_d==1){
            cont_f= cont_e= cont_t=0;
        }

        if(cont_e==1){
            cont_d= cont_f= cont_t=0;
        }

        //Mudança no operador logico de ">" para ">=" pois o personagem piscava quando o valor era maior que 3
        if(cont_f>=3){
            cont_f=1;
        }

        if(cont_t>=3){
            cont_t=1;
        }

        if(cont_d>=3){
            cont_d=1;
        }

        if(cont_e>=3){
            cont_e=1;
        }

}
    void IChara(int x, int y){

         if(mov_t==1){
            Desenha_Objeto(Chara);
            Move_Objeto(Chara,x,y+1);
        }
        if (mov_t==2){
            Desenha_Objeto(Chara_1);
            Move_Objeto(Chara_1,x,y+1);
        }
        if (mov_t==3){
            Desenha_Objeto(Chara_2);
            Move_Objeto(Chara_2,x,y+1);
        }

        if (mov_e==1){
            Desenha_Objeto(Chara_3);
            Move_Objeto(Chara_3,x-1,y);
        }
        if (mov_e==2){
            Desenha_Objeto(Chara_4);
            Move_Objeto(Chara_4,x-1,y);
        }
        if (mov_e==3){
            Desenha_Objeto(Chara_5);
            Move_Objeto(Chara_5,x-1,y);
        }

        if (mov_d==1){
            Desenha_Objeto(Chara_6);
            Move_Objeto(Chara_6,x+1,y);
        }
        if (mov_d==2){
            Desenha_Objeto(Chara_7);
            Move_Objeto(Chara_7,x+1,y);
        }
        if (mov_d==3){
            Desenha_Objeto(Chara_8);
            Move_Objeto(Chara_8,x+1,y);
        }

        if(mov_f==1)
            Desenha_Objeto(Chara_9);
        if(mov_f==2){

            Desenha_Objeto(Chara_10);
            Move_Objeto(Chara_10,x,y-1);
        }
        if(mov_f==3){
            Desenha_Objeto(Chara_11);
            Move_Objeto(Chara_11,x,y-1);

        }






        //Realocação dos contadores da função MoverPersonagem() para Gaunt()
        if(mov_f==1){
            mov_d = mov_e = mov_t=0;
        }

        if(mov_t==1){
            mov_f = mov_d = mov_e=0;
        }

        if(mov_d==1){
            mov_f= mov_e= mov_t=0;
        }

        if(mov_e==1){
            mov_d= mov_f= mov_t=0;
        }

        //Mudança no operador logico de ">" para ">=" pois o personagem piscava quando o valor era maior que 3
        if(mov_f>=3){
            mov_f=1;
        }

        if(mov_t>=3){
            mov_t=1;
        }

        if(mov_d>=3){
            mov_d=1;
        }

        if(mov_e>=3){
            mov_e=1;
        }
}

    void VidaJG(){
        if(Tempo_Decorrido(VidaTimer)>=30){
            JG.idade++;
            Reinicia_Timer(VidaTimer);
        }
    }
    void Texto_inicial(){
        char texto[100];
        inicial = fopen("inicio.txt","r");
        if(inicial==NULL){printf("Deu Erro");exit(1);}
        while(fscanf(inicial,"%s",texto)!=EOF){
            Inicia_Desenho();
            EscreverCentralizada(texto,300,500,0);
            Espera(5);
            Encerra_Desenho();
        }
        fclose(inicial);
    }

void MoverPersonagem(){
    Espera(5);
    int X, Y;
    GetXY_Objeto(James_Gaunt,&X,&Y);


    //Reorganização dos movimentos para adição de movimento em diagonal
    if(meuTeclado[TECLA_DIREITA] == 1 && meuTeclado[TECLA_CIMA] == 1){

        cont_d++;
        Move_Objeto(James_Gaunt, X+1, Y+1);

    }else if(meuTeclado[TECLA_DIREITA] == 1 && meuTeclado[TECLA_BAIXO] == 1){

        cont_d++;
        Move_Objeto(James_Gaunt, X+1, Y-1);

    }else if(meuTeclado[TECLA_ESQUERDA] == 1 && meuTeclado[TECLA_CIMA] == 1){

        cont_e++;
        Move_Objeto(James_Gaunt, X-1, Y+1);

    }else if(meuTeclado[TECLA_ESQUERDA] == 1 && meuTeclado[TECLA_BAIXO] == 1){

        cont_e++;
        Move_Objeto(James_Gaunt, X-1, Y-1);

    }else{

        if(meuTeclado[TECLA_BAIXO] == 1)
        {
            cont_t++;
            Move_Objeto(James_Gaunt,X,Y-1);
        }
        if(meuTeclado[TECLA_CIMA] == 1)
        {
            cont_f++;
            Move_Objeto(James_Gaunt,X,Y+1);
        }
        if(meuTeclado[TECLA_ESQUERDA] == 1)
        {
            cont_e++;
            Move_Objeto(James_Gaunt,X-1,Y);
        }
        if(meuTeclado[TECLA_DIREITA] == 1)
        {
            cont_d++;
            Move_Objeto(James_Gaunt,X+1,Y);
        }
    }

    if((X>800)||(Y>600)){
        X=400;
        Y=300;
    }

    Gaunt(X,Y);
}
void MoverChara(){

    Espera(10);
    int X, Y;
    int h, v;
    GetXY_Objeto(Chara,&h, &v);
    GetXY_Objeto(James_Gaunt, &X, &Y);

     if((h>800)||(v>600)){
        h=400;
        v=300;
    }

    //Reorganização dos movimentos para adição de movimento em diagonal
    if( X > h && Y > v){

        mov_d++;
        Move_Objeto(Chara, h+1, v+1);
        mov = 3;

    }else if(X > h && Y < v){

        mov_d++;
        Move_Objeto(Chara, h+1, v-1);
        mov = 2;

    }else if(X < h && Y > v){

        mov_e++;
        Move_Objeto(Chara, h-1, v+1);
        mov = 3;

    }else if(X < h && Y < v){

        mov_e++;
        Move_Objeto(Chara, h-1, v-1);
        mov = 2;

    }else{

        if(Y < v)
        {
            mov_t++;
            Move_Objeto(Chara, h, v-1);
            mov = 2;
        }
        if(Y > v)
        {
            mov_f++;
            Move_Objeto(Chara, h, v+1);
            mov = 3;
        }
        if(X < h)
        {
            mov_e++;
            Move_Objeto(Chara, h-1, v);
            mov = 4;
        }
        if(X > h)
        {
            mov_d++;
            Move_Objeto(Chara, h+1, v);
            mov = 1;
        }
    }

    IChara(h, v);

}

void Elixir_da_vida(){
    int X,Y,EX=300,EY=400;
    time_t t;
    GetXY_Objeto(James_Gaunt,&X,&Y);
    Move_Objeto(Elixir,EX,EY);
    if(JG.vida<=20){
        Desenha_Objeto(Elixir);
        if(Testa_Colisao(James_Gaunt,Elixir)!=0){
            srand((unsigned) time(&t));
            JG.vida=JG.vida+rand()%50;
        }
    }
}


void Salva_Jogo(){
    save = fopen("Save.txt","w");
    fprintf(save,"%d\n%d\n%d\n%d",JG.idade,JG.xp,JG.vida,JG.lv);
    fclose(save);
}
void Load_Jogo(){
    save = fopen("Save.txt","r");
    if(save==NULL){exit(1);}
    fscanf(save,"%d\n%d\n%d\n%d",&JG.idade,&JG.xp,&JG.vida,&JG.lv);
    fclose(save);
}
int BatalhaInimigo(int *nume){
    if(*nume<1){
    time_t t;
    srand((unsigned) time(&t));
    n = rand()%20;
    *nume = 1;
    }
    return n;
}
    Testa_LV(int i){
        time_t j;
        if(strcmp(ini[i]->Tipo,"Magico")==0){
            srand((unsigned) time(&j));
            JG.xp=JG.xp+rand()%10;
        }
        if(strcmp(ini[i]->Tipo,"Humano")==0){
            srand((unsigned) time(&j));
            JG.xp=JG.xp+rand()%5;
        }
            JG.lv = JG.xp/10;
    }
    void Testa_Vida(int i){
    if(ini[i]->vida<=0){
        PauseNum=1;
        Move_Objeto(Chara,rand()%600,rand()%800);
        contc=0;
        contba=0;
        Testa_LV(i);
    }
    if(JG.vida<=0){
        PauseNum=3;
    }
    return;
}

void Confronto(int i){
    int j,num;
    time_t t,s;
    j=BatalhaInimigo(&contc);
    switch(turno){
        case 1:{
            if(strcmp(ini[j]->Tipo,"Magico")==0){

                ini[j]->vida=ini[j]->vida-magica[i]->dano;
            }
            if(strcmp(ini[j]->Tipo,"Humano")==0){
                ini[j]->vida=ini[j]->vida-2*magica[i]->dano;
            }
            Testa_Vida(j);
            turno = 2;
            break;
        }
        case 2:{
            if(strcmp(ini[j]->Tipo,"Magico")==0){
                srand((unsigned) time(&t));
                num = ini[j]->lv;
                JG.vida=JG.vida-magica[num]->dano;
            }
             if(strcmp(ini[j]->Tipo,"Humano")==0){
                srand((unsigned) time(&s));
                num = ini[j]->lv;
                if (num>2)
                    num=2;
                JG.vida=JG.vida-golpe[num]->dano;
            }
            Testa_Vida(j);
            turno = 1;
            return;
            break;
            }
        }
    }

void MenuBatalha(){
    Espera(200);
    int i,vida;
    Desenha_Retangulo(0,0,150,800,VERMELHO);
    Desenha_Objeto(SetaBatalha);

    if(JG.lv==1){
        EscreverEsquerda(magica[0]->Nome,50,90);
        EscreverEsquerda(magica[1]->Nome,50,40);
        if(meuTeclado[TECLA_BAIXO]==1){
            Move_Objeto(SetaBatalha,5,40);
            i=1;
        }
        if(meuTeclado[TECLA_CIMA]==1){
            Move_Objeto(SetaBatalha,5,90);
            i=0;
        }
        if(meuTeclado[TECLA_ENTER]==1){
            Confronto(i);
        }
    }
    if(JG.lv==2){
        EscreverEsquerda(magica[0]->Nome,50,90);
        EscreverEsquerda(magica[1]->Nome,50,40);
        EscreverEsquerda(magica[2]->Nome,300,90);
        if(meuTeclado[TECLA_BAIXO]==1){
            Move_Objeto(SetaBatalha,5,40);
            i=1;
        }
        if(meuTeclado[TECLA_CIMA]==1){
            Move_Objeto(SetaBatalha,5,90);
            i=0;
        }
        if(meuTeclado[TECLA_DIREITA]==1){
            Move_Objeto(SetaBatalha,255,90);
            i=2;
        }
        if(meuTeclado[TECLA_ENTER]==1){
            Confronto(i);
        }

    }
    if(JG.lv==3){
        EscreverEsquerda(magica[0]->Nome,50,90);
        EscreverEsquerda(magica[1]->Nome,50,40);
        EscreverEsquerda(magica[2]->Nome,300,90);
        EscreverEsquerda(magica[3]->Nome,500,90);
        if(meuTeclado[TECLA_BAIXO]==1)
            cont_b++;
        if(meuTeclado[TECLA_CIMA]==1)
            cont_b--;
        if(meuTeclado[TECLA_DIREITA]==1)
            contd++;
        if(meuTeclado[TECLA_ESQUERDA]==1)
            contd--;
        if((contd==0)&&(cont_b==0)){
            Move_Objeto(SetaBatalha,5,90);
            i=0;
        }
        if((contd==0)&&(cont_b==1)){
            Move_Objeto(SetaBatalha,5,40);
            i=1;
        }
        if((contd==1)&&(cont_b==0)){
            Move_Objeto(SetaBatalha,255,90);
            i=2;
        }
        if((contd==2)&&(cont_b==0)){
            Move_Objeto(SetaBatalha,455,90);
            i=3;
        }
        if(contd>2)
            contd=0;
        if(cont_b>1)
            cont_b=0;

        if(meuTeclado[TECLA_ENTER]==1){
            Confronto(i);
        }

    }
    if(JG.lv>3){
        EscreverEsquerda(magica[0]->Nome,50,90);
        EscreverEsquerda(magica[1]->Nome,50,40);
        EscreverEsquerda(magica[2]->Nome,300,90);
        EscreverEsquerda(magica[3]->Nome,500,90);
        EscreverEsquerda(magica[4]->Nome,500,40);
        if(meuTeclado[TECLA_BAIXO]==1)
            cont_b++;
        if(meuTeclado[TECLA_CIMA]==1)
            cont_b--;
        if(meuTeclado[TECLA_DIREITA]==1)
            contd++;
        if(meuTeclado[TECLA_ESQUERDA]==1)
            contd--;
        if((contd==0)&&(cont_b==0)){
            Move_Objeto(SetaBatalha,5,90);
            i=0;
        }
        if((contd==0)&&(cont_b==1)){
            Move_Objeto(SetaBatalha,5,40);
            i=1;
        }
        if((contd==1)&&(cont_b==0)){
            Move_Objeto(SetaBatalha,255,90);
            i=2;
        }
        if((contd==2)&&(cont_b==0)){
            Move_Objeto(SetaBatalha,455,90);
            i=3;
        }
        if((contd==2)&&(cont_b==1)){
            Move_Objeto(SetaBatalha,455,40);
            i=4;
        }if(contd>2)
            contd=0;
        if(cont_b>1)
            cont_b=0;
        if(meuTeclado[TECLA_ENTER]==1){
            Confronto(i);
        }
    }

}

void ColisaoBatalha(){
    if(Testa_Colisao(James_Gaunt,Chara)!=0){
        PauseNum=4;
    }
}
void Batalha(){
    int i;
    char vidaJG[10],lvJG[10],xpJG[10],vidaini[10],lvini[10],xpini[10];
    Desenha_Objeto(FundoBatalha);

    Desenha_Objeto(BatalhaJames);
    i=BatalhaInimigo(&contba);
    if(strcmp(ini[i]->Tipo,"Magico")==0){
        Desenha_Objeto(BatalhaMagico);
    }
    if(strcmp(ini[i]->Tipo,"Humano")==0){
        Desenha_Objeto(BatalhaHumano);
    }
    sprintf(vidaJG,"Vida %d",JG.vida);
    sprintf(lvJG,"Level %d", JG.lv);
    sprintf(xpJG,"Xp %d",JG.xp);
    sprintf(vidaini,"Vida %d",ini[i]->vida);
    sprintf(lvini,"Level %d",ini[i]->lv);
    sprintf(xpini,"Xp %d",ini[i]->xp);
    EscreverEsquerda(vidaJG,100,550);
    EscreverEsquerda(lvJG,100,500);
    EscreverEsquerda(xpJG,100,450);
    EscreverDireita(vidaini,500,260);
    EscreverDireita(lvini,500,210);
    EscreverDireita(xpini,500,160);
    MenuBatalha();

}
void Pause(){
    Pausa_Timer(VidaTimer);
    Desenha_Objeto(Capa);
    EscreverEsquerda("Retorne",150,400);
    EscreverEsquerda("Salvar",150,300);
    EscreverEsquerda("Sair", 150,200);
    if(meuTeclado[TECLA_BAIXO] == 1)
       cont++;
    if(meuTeclado[TECLA_CIMA] == 1)
        cont--;
    Espera(100);
    if (cont==1)
    {
        Move_Objeto(PauseSeta,90,290);
        Menup = 2;
    }
    if(cont==0)
    {
        Move_Objeto(PauseSeta,90,390);
        Menup = 1;
    }
    if(cont==2)
    {
        Move_Objeto(PauseSeta,90,190);
        Menup = 3;
    }
    Desenha_Objeto(PauseSeta);
    if(cont>2)
        cont=0;
    if(cont<0)
        cont=2;
    if(meuTeclado[TECLA_ENTER] == 1)
    {
        if(Menup == 1)
        {
            Reinicia_Timer(VidaTimer);
            PauseNum=1;
        }
        if(Menup == 2)
        {
            Salva_Jogo();
            exit(1);
        }
        if(Menup == 3)
        {
            exit(1);
        }
    }

}

void Menu()
{
    int fonte;
    Desenha_Objeto(Capa);
    fonte = CriaFonteNormal("Quiet Streets.ttf",40,BRANCO,0,BRANCO,0x00);
    EscreverEsquerda("Novo Jogo",200,200,fonte);
    EscreverEsquerda("Sair",200,150,fonte);
    if(meuTeclado[TECLA_BAIXO] == 1)
    {
        Move_Objeto(MenuSeta,140,140);
        MenuOp = 2;
    }
    if(meuTeclado[TECLA_CIMA] == 1)
    {
        Move_Objeto(MenuSeta,140,190);
        MenuOp = 1;
    }
    Desenha_Objeto(MenuSeta);

    if(meuTeclado[TECLA_ENTER] == 1)
    {
        if(MenuOp == 1)
        {
            EstadoDoJogo = 2;
            Reinicia_Timer(VidaTimer);
        }
        if(MenuOp == 2)
        {
            EstadoDoJogo = 0;
        }
    }
}
void Tela(){
    sprintf(idade,"Idade %d",JG.idade);
    sprintf(xp,"Xp %d",JG.xp);
    sprintf(vida,"Vida %d",JG.vida);
    sprintf(lv,"Level %d",JG.lv);
    EscreverEsquerda(idade,50,550,0);
    EscreverEsquerda(xp,250,550,0);
    EscreverEsquerda(vida,450,550,0);
    EscreverEsquerda(lv,650,550,0);
}
void GameOver(){
    Espera(1000);
    EscreverCentralizada("GAMEOVER",300,300,0);
    EstadoDoJogo = 1;
    PauseNum = 1;
}
void NovoJogo()
{
    if (meuTeclado[TECLA_ESC]==1)
        PauseNum = 2;
    switch(PauseNum){

    case 1:{
        VidaJG();
        Mapas();
        Tela();
        Elixir_da_vida();
        ColisaoBatalha();
        MoverPersonagem();
        break;
    }
    case 2:{
        Pause();
        break;
    }
    case 3:{
        GameOver();
        break;
    }
    case 4:{
        Batalha();
        break;
    }
    }


}

int main( int argc, char* args[] )
{
    Cria_Jogo("Gaunt's Journey");
    meuTeclado = Pega_Teclado();

    Capa = Cria_Objeto("imagens\\capa.jpg");
    Define_Dimensoes(Capa,600,800);
    Move_Objeto(Capa,0,0);

    BatalhaMagico = Cria_Objeto("imagens\\Magico.png",1);
        Define_Dimensoes(BatalhaMagico,100,100);
        Move_Objeto(BatalhaMagico,100,210);

    SetaBatalha = Cria_Objeto("imagens\\seta.bmp",1);
    Define_Dimensoes(SetaBatalha,40,40);
    Move_Objeto(SetaBatalha,10,90);

    BatalhaJames = Cria_Objeto("imagens\\JamesGaunt.bmp",1);
    Define_Dimensoes(BatalhaJames,100,100);
    Move_Objeto(BatalhaJames,550,500);

    MenuSeta = Cria_Objeto("imagens\\seta.bmp",1);
    Define_Dimensoes(MenuSeta,50,50);
    Move_Objeto(MenuSeta,140,190);

    PauseSeta = Cria_Objeto("imagens\\seta.bmp",1);
    Define_Dimensoes(PauseSeta,50,50);
    Move_Objeto(PauseSeta,140,390);

    Elixir = Cria_Objeto("imagens\\elixir.bmp",1);
    Define_Dimensoes(Elixir,15,20);

    BatalhaHumano = Cria_Objeto("imagens\\Humano.png",1);
    Define_Dimensoes(BatalhaHumano,100,100);
    Move_Objeto(BatalhaHumano,100,210);

    FundoBatalha = Cria_Objeto("imagens\\DemonicWorld1.png");
    Define_Dimensoes(FundoBatalha,600,800);
    Move_Objeto(FundoBatalha,0,0);

    Cria_mapa1();
    Cria_mapa2();
    Cria_mapa3();
    Cria_mapa4();
    Cria_Gaunt();
    Cria_inimigo();
    ini = nome_inimigo(ini);
    magica = nome_magia(magica);
    golpe = nome_ataque(golpe);

    VidaTimer = Cria_Timer();
    LutaTimer = Cria_Timer();
    Pausa_Timer(LutaTimer);

    while(Jogo_Rodando()!=0)
    {
        evento = Pega_Evento();

        Inicia_Desenho();
        switch(EstadoDoJogo)
        {
            case 0:
            {
                Finaliza_Jogo();
            }   break;
            case 1:
            {
                Menu();
            }   break;
            case 2:
            {
                NovoJogo();
            }   break;
        }
        Encerra_Desenho();
    }
    Finaliza_Jogo();
    return 0;
}
