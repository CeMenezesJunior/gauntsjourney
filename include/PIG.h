/********************************
Vers�o 0.4.0 da Biblioteca Pig.h
********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "Tipos_PIG.h"
#include "CJogo.h"

/********************************
/ Vari�veis Globais
/********************************/
Jogo jogo=NULL;


/********************************
A fun��o Cria_Jogo � respons�vel pela cria��o da janela do jogo e pelos componentes audio-visuais.
Ela deve ser chamada antes de qualquer outra fun��o da biblioetac PIG.h. N�o � poss�vel criar dois
jogos no mesmo progama. Logo, somente a primeira chamada ter� efeito.
Par�metros:
nome_Janela (entrada, passagem por refer�ncia*): indica o nome que ajanela do jogo mostrar� no seu t�tulo
� utilizado o operador * apenas por se tratar de um par�metro string. O valor do par�metro n�o � alterado dentro da fun��o.
********************************/
void Cria_Jogo(char *nome_Janela)
{
    if (jogo==NULL)
        jogo = new CJogo(nome_Janela);
}

/********************************
A fun��o GetEstado_Jogo() indica o estado do jogo. Este estado � apenas um valor inteiro
que pode ser usado para indicar uma fase do jogo ou a vez de algum jogador por exemplo.
Retorno:
inteiro indicando o valor do estado do jogo;
********************************/
int GetEstado_Jogo()
{
    return jogo->estado;
}

/********************************
A fun��o SetEstado_Jogo() atribui um novo valor ao estado do jogo. Este estado � apenas um valor inteiro
que pode ser usado para indicar uma fase do jogo, ou a vez de algum jogador por exemplo.
Par�metro:
estado (entrada, passagem por valor): indica o novo estado do jogo;
********************************/
void SetEstado_Jogo(int estado)
{
    jogo->estado = estado;
}

/********************************
A fun��o Define_Fundo permite escolher um arquivo fr imagem como fundo (background) do jogo.
Par�metros:
nome_ArquivoImagem (entrada, passagem por refer�ncia*): indica o caminho relativo ou absoluto do arquivo de imagem que ser� utilizado como fundo do jogo.
� utilizado o operador * apenas por se tratar de um par�metro string. O valor do par�metro n�o � alterado dentro da fun��o.
********************************/
void Define_Fundo(char *nome_ArquivoImagem)
{
    jogo->DefineFundo(nome_ArquivoImagem);
}

/********************************
A fun��o Pega_Teclado() � respons�vel por fornecer um mapeamento do estado das teclas atrav�s de um vetor de vari�veis l�gicas.
Uma lista dos nomes das teclas (que servem para indicar uma determinada posi��o no vetor) pode ser vista no final do arquivo PIG.h.
Retorno:
O valor de retorno da fun��o � um vetor de n�meros inteiros que indicam se uma determinada tecla (�ndice do vetor) foi
pressionada (valor diferente de 0,zero) ou n�o (valor igual a zero).
********************************/
PIG_Teclado Pega_Teclado()
{
    return jogo->PegaTeclado();
}

/********************************
A fun��o Pega_Evento() indica se houve algum tipo de evento desde a �ltima vez que a fun��o foi chamada.
Um evento pode ser uma tecla pressionada, um clique do mouse ou outra coisa relacionada � tela do jogo.
Maiores informa��e podem ser vistas no arquivo Tipo_PIG.h
Retorno:
O valor de retorno � um struct contendo o tipo de evento ocorrido e v�rios outros structs com informa��es espec�ficas.
********************************/
PIG_Evento Pega_Evento()
{
    return jogo->PegaEvento();
}

/********************************
A fun��o Inicia_Desenho � respons�vel por preparar a janela do jogo para que os objetos gr�ficos
possam ser mostrados, al�m de desenhar a imagem de fundo do jogo.
Deve ser chamada repetidamente a cada novo quadro (frame) a ser desenhado.
********************************/
void Inicia_Desenho()
{
    jogo->IniciaDesenho();
}

/********************************
A fun��o Encerra_Desenho � respons�vel por encerrar o desenho que foi criado. Ap�s a execu��o dos frames,
ele encerra a anima��o. Deve ser chamado toda vez que um frame acabar de ser executado.
********************************/
void Encerra_Desenho()
{
    jogo->EncerraDesenho();
}

/********************************
A fun��o Salva_Tela() � respons�vel por criar um arquivo Bitmap, contendo uma c�pia da tela do jogo naquele momento.
Par�metros:
nomeBMP (entrada, passagem por refer�ncia*): indica o nome do arquivo Bitmap que ser� salvo. O valor do par�metro deve conter a extens�o ".bmp".
� utilizado o operador * apenas por se tratar de um par�metro string. O valor do par�metro n�o � alterado dentro da fun��o.
********************************/
void Salva_Tela(char *nomeBMP)
{
    jogo->saveScreenshotBMP(nomeBMP);
}

/********************************
A fun��o Jogo_Rodando � repons�vel por retornar o funcionamento do jogo. Ela chama o m�todo que
vai retornar um valor inteiro indicando se o jogo ainda est� ativo ou n�o.
Retorno:
inteiro que indica se o jogo ainda est� sendo executado (valor diferente de zero) ou n�o (valor igual a 0, zero).
********************************/
int Jogo_Rodando()
{
    return jogo->rodando;
}

/********************************
A fun��o Espera() "congela" a tela do jogo por alguns milisegundos, impedindo que qualquer outro comando seja executado enquanto isso.
Par�metros:
tempo (entrada, passagem por valor): indica a quantidade de milisegundos durante a qual o jogo ser� pausado.
********************************/
void Espera(int tempo)
{
    SDL_Delay(tempo);
}

/********************************
A fun��o Finaliza_Jogo � respons�vel por encerrar com a execu��o final do jogo. Ap�s tudo ser realizado
a fun��o pode ser chamada e ela ir� realizar a interrup��o do jogo e a sua finaliza��o.
********************************/
void Finaliza_Jogo()
{
    delete jogo;
}

/********************************
Se��o de elementos geom�tricos
********************************/

/********************************
A fun��o Desenha_LinhasSimples() � respons�vel por desenhar uma �nica linha, cuja in�cio � o ponto (x1,y1) e o fim � o ponto (x2,y2).
Par�metros:
pontoX1 (entrada, passagem por valor): inteiro que indica o in�cio da linha no eixo X.
pontoY1 (entrada, passagem por valor): inteiro que indica o in�cio da linha no eixo Y.
pontoX2 (entrada, passagem por valor): inteiro que indica o fim da linha no eixo X.
pontoY2 (entrada, passagem por valor): inteiro que indica o fim da linha no eixo Y.
cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho das linhas;
********************************/
void Desenha_LinhaSimples(int pontoX1,int pontoY1,int pontoX2,int pontoY2, PIG_Cor cor)
{
    jogo->DesenhaLinhaSimples(pontoX1,pontoY1,pontoX2,pontoY2,cor);
}

/********************************
A fun��o Desenha_LinhasDisjuntas() � respons�vel por desenhar linhas separadamente, ou seja, os ponto iniciais de cada linha est�o nas posi��es pares e
os pontos finais est�o nas posi��es �mpares. Assim, os vetores precisam ter tamanho qtd*2.
Par�metros:
pontosX (entrada, passagem por refer�ncia): vetor de inteiros, de tamanho qtd*2, contendo os valores X (inicias e finais) de cada linha.
pontosY (entrada, passagem por refer�ncia): vetor de inteiros, de tamanho qtd*2, contendo os valores Y (inicias e finais) de cada linha.
qtd (entrada, passagem por valor): quantidade de linhas a serem desenhadas.
cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho das linhas;
********************************/
void Desenha_LinhasDisjuntas(int *pontosX,int *pontosY,int qtd, PIG_Cor cor)
{
    jogo->DesenhaLinhasDisjuntas(pontosX,pontosY,qtd,cor);
}

/********************************
A fun��o Desenha_LinhasSequencia() � respons�vel por desenhar linhas em sequ�ncia, ou seja, o ponto final da primeira linha
corresponde ao ponto inicial da segunda linha.
Par�metros:
pontosX (entrada, passagem por refer�ncia): vetor de inteiros, de tamanho qtd+1, contendo os valores X de cada linha da sequ�ncia.
pontosY (entrada, passagem por refer�ncia): vetor de inteiros, de tamanho qtd+1, contendo os valores Y de cada linha da sequ�ncia.
qtd (entrada, passagem por valor): quantidade de linhas a serem desenhadas.
cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho das linhas;
********************************/
void Desenha_LinhasSequencia(int *pontosX,int *pontosY,int qtd, PIG_Cor cor)
{
    jogo->DesenhaLinhasSequencia(pontosX,pontosY,qtd,cor);
}

/********************************
A fun��o Desenha_Retangulo() � respons�vel por desenhar um ret�ngulo com preenchimento s�lido na tela em uma posi��o desejada pelo usu�rio.
O mesmo pode ser colocado em qualquer lugar do campo de vis�o da tela.
Par�metros:
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja colocar o ret�ngulo.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja colocar o ret�ngulo.
altura (entrada, passagem por valor): Valor onde o usu�rio ir� fornecer o n�mero correspondente em pixels � altura desse ret�ngulo.
largura (entrada, passagem por valor): Valor onde o usu�rio ir� fornecer o n�mero correspondente em pixels � largura desse ret�ngulo.
cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho do ret�ngulo;
********************************/
void Desenha_Retangulo(int posicaoX, int posicaoY, int altura, int largura, PIG_Cor cor)
{
    jogo->DesenhaRetangulo(posicaoX,posicaoY,altura,largura,cor);
}

/********************************
Se��o de fontes
********************************/

/********************************
A fun��o CriaFonteNormal() � respons�vel por disponibilizar uma nova fonte com preenchimento s�lido.
Par�metros:
nome (entrada, passagem por refer�ncia): nome do arquivo que cont�m a fonte (normalmente com extens�o ttf).
tamanho (entrada, passagem por valor): tamanho da fonte, que normalmente representa a altura m�dia (em pixels) dos caracteres da fonte.
corLetra (entrada, passagem por valor): representa a cor de preenchimento da fonte.
contorno (entrada, passagem por valor): representa a espessura do contorno que fonte ter�. Caso n�o seja desejado um contorno, basta utilizar um valor 0.
corContorno (entrada, passagem por valor): representa a cor do contorno da fonte.
estilo (entrada, passagem por valor): representa o estilo da fonte. Pode ser uma combina��o bin�ria de: ESTILO_NEGRITO, para negrito; ESTILO_SUBLINHADO, para sublinhado; ESTILO_ITALICO, para it�lico;
ESTILO_CORTADO, para uma linha horizontal � meia-altura. Caso nenhum estilo seja desejado, pode ser omitido ou usado ESTILO_NORMAL.
retono:
inteiro que representa a ideintifica��o �nica da fonte. Futuras refer�ncia a esta fonte devem idenitific�-las pelo n�mero.
********************************/
int CriaFonteNormal(char *nome,int tamanho,PIG_Cor corLetra,int contorno=0,PIG_Cor corContorno=BRANCO,PIG_Estilo estilo=ESTILO_NORMAL)
{
    return jogo->CriaFonteNormal(nome,tamanho,estilo,corLetra,contorno,corContorno);
}

/********************************
A fun��o CriaFonteFundo() � respons�vel por disponibilizar uma nova fonte com preenchimento de um bitmap espec�fico.
Par�metros:
nome (entrada, passagem por refer�ncia): nome do arquivo que cont�m a fonte (normalmente com extens�o ttf).
tamanho (entrada, passagem por valor): tamanho da fonte, que normalmente representa a altura m�dia (em pixels) dos caracteres da fonte.
arquivoFundo (entrada, passagem por refer�ncia): indica o nome do arquivo de imagem que servir� de fundo para a fonte.
contorno (entrada, passagem por valor): representa a espessura do contorno que fonte ter�. Caso n�o seja desejado um contorno, basta utilizar um valor 0.
corContorno (entrada, passagem por valor): representa a cor do contorno da fonte.
estilo (entrada, passagem por valor): representa o estilo da fonte. Pode ser uma combina��o bin�ria de: ESTILO_NEGRITO, para negrito; ESTILO_SUBLINHADO, para sublinhado; ESTILO_ITALICO, para it�lico;
ESTILO_CORTADO, para uma linha horizontal � meia-altura. Caso nenhum estilo seja desejado, pode ser omitido ou usado ESTILO_NORMAL.
retono:
inteiro que representa a ideintifica��o �nica da fonte. Futuras refer�ncia a esta fonte devem idenitific�-las pelo n�mero.
********************************/
int CriaFonteFundo(char *nome,int tamanho,char *arquivoFundo,int contorno=0,PIG_Cor corContorno=BRANCO,PIG_Estilo estilo=ESTILO_NORMAL)
{
    return jogo->CriaFonteFundo(nome,tamanho,estilo,arquivoFundo,contorno,corContorno);
}

/********************************
A fun��o CalculaLarguraPixels() por realizar a soma das larguras de cada letra da string informada.
Par�metros:
str (entrada, passagem por refer�ncia): string a ser escrita na tela.
numFonte (entrada, passagem por valor): n�mero da fonte a ser utilizada. Caso o usu�rio n�o deseje uma fonte especial, ser� utilizada a fonte padr�o (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
retorno:
inteiro que representa o total de pixels (no eixo x) necess�rios para escrever a string.
********************************/
int CalculaLarguraPixels(char *str,int numFonte=0)
{
    return jogo->GetLarguraPixels(str);
}

/********************************
A fun��o EscreverDireita() � respons�vel por exibir uma string na tela de jogo, com alinhamento � direita do valor de X.
Par�metros:
str (entrada, passagem por refer�ncia): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja come�ar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja come�ar a escrever a string.
numFonte (entrada, passagem por valor): n�mero da fonte a ser utilizada. Caso o usu�rio n�o deseje uma fonte especial, ser� utilizada a fonte padr�o (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void EscreverDireita(char *str,int posicaoX,int posicaoY,int numFonte=0)
{
    jogo->EscreverDireita(str,posicaoX,posicaoY,numFonte);
}

/********************************
A fun��o EscreverEsquerda() � respons�vel por exibir uma string na tela de jogo, com alinhamento � esquerda do valor de X.
Par�metros:
str (entrada, passagem por refer�ncia): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja come�ar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja come�ar a escrever a string.
numFonte (entrada, passagem por valor): n�mero da fonte a ser utilizada. Caso o usu�rio n�o deseje uma fonte especial, ser� utilizada a fonte padr�o (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void EscreverEsquerda(char *str,int posicaoX,int posicaoY,int numFonte=0)
{
    jogo->EscreverEsquerda(str,posicaoX,posicaoY,numFonte);
}

/********************************
A fun��o EscreverCentralizada() � respons�vel por exibir uma string na tela de jogo, com alinhamento em rela��o ao valor de X.
Par�metros:
str (entrada, passagem por refer�ncia): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja come�ar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja come�ar a escrever a string.
numFonte (entrada, passagem por valor): n�mero da fonte a ser utilizada. Caso o usu�rio n�o deseje uma fonte especial, ser� utilizada a fonte padr�o (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void EscreverCentralizada(char *str,int posicaoX,int posicaoY,int numFonte=0)
{
    jogo->EscreverCentralizada(str,posicaoX,posicaoY,numFonte);
}

/********************************
Se��o de objetos
********************************/

/********************************
A fun��o Cria_Objeto() � respons�vel por criar um objeto. Qualquer objeto que for necess�rio,
pode ser criado atrav�s dessa fun��o. O objeto ainda n�o ser� desenhado, apenas criado dentro do jogo.
Par�metros:
nomeArquivo (entrada, passagem por refer�ncia): string que informa o nome do arquivo da imagem do objeto a ser criado.
retiraFundo (entrada, passagem por valor): inteiro que indica se o fundo da imagem deve ser retirado ou n�o ao ler o arquivo em quest�o.
Retorno:
inteiro que representa o identificador �nico do objeto. Todas as opera��es subsequentes com este objeto dever�o receber este identificador como par�metro.
********************************/
int Cria_Objeto(char* nomeArquivo,int retiraFundo=1)
{
    return jogo->Cria_Objeto(0,0,nomeArquivo,retiraFundo);
}

/********************************
A fun��o Destroi_Objeto() � respons�vel por eliminar o objeto em quest�o do jogo.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser exclu�do.
********************************/
void Destroi_Objeto(int id_objeto)
{
    jogo->Destroi_Objeto(id_objeto);
}

/********************************
A fun��o SetValorInt_Objeto() � respons�vel incorporar a um objeto um atributo inteiro.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): relaciona um n�mero inteiro ao atributo indicado.
valor (entrada, passagem por valor): valor do atributo inteiro a ser associado ao objeto.
********************************/
void SetValorInt_Objeto(int id_objeto,int indice,int valor)
{
    jogo->objetos[id_objeto]->SetValorInt(indice,valor);
}

/********************************
A fun��o SetValorDouble_Objeto() � respons�vel incorporar a um objeto um atributo double.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): relaciona um n�mero double ao atributo indicado.
valor (entrada, passagem por valor): valor do atributo double a ser associado ao objeto.
********************************/
void SetValorDouble_Objeto(int id_objeto,int indice,double valor)
{
    jogo->objetos[id_objeto]->SetValorDouble(indice,valor);
}

/********************************
A fun��o GetValorInt_Objeto() � respons�vel recuperar o valor de um atributo int relacionado a um objeto.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): indica o n�mero do atributo que se deseja recuperar.
Retorno:
Retorna o valor do atributo int solicitado pelo usu�rio.
********************************/
int GetValorInt_Objeto(int id_objeto,int indice)
{
    return jogo->objetos[id_objeto]->GetValorInt(indice);
}

/********************************
A fun��o GetValorDouble_Objeto() � respons�vel recuperar o valor de um atributo double relacionado a um objeto.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): indica o n�mero do atributo que se deseja recuperar.
Retorno:
Retorna o valor do atributo double solicitado pelo usu�rio.
********************************/
double GetValorDouble_Objeto(int id_objeto,int indice)
{
    return jogo->objetos[id_objeto]->GetValorDouble(indice);
}

/********************************
A fun��o GetXY_Objeto() � respons�vel recuperar o valor da posi��o (X,Y) do objeto de acordo com o sistema de coordenadas do jogo.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
posicaoX (sa�da, passagem por referencia): indica a posicao no eixo X do objeto.
posicaoY (sa�da, passagem por referencia): indica a posicao no eixo Y do objeto.
********************************/
void GetXY_Objeto(int id_objeto,int *posicaoX,int *posicaoY)
{
    jogo->objetos[id_objeto]->GetXY(*posicaoX,*posicaoY);
}

/********************************
A fun��o Move_Objeto() � respons�vel por movimentar um determinado obeto para uma nova posi��o informada.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser movido.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja reposicionar o objeto.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja reposicionar o objeto.
********************************/
void Move_Objeto(int id_objeto,int posicaoX,int posicaoY)
{
    jogo->objetos[id_objeto]->Move(posicaoX,posicaoY);
}

/********************************
A fun��o Define_Angulo() � respons�vel pela angula��o de determinado objeto. A angula��o � calculada em sentido
anti-hor�rio a partir do eixo X (0 graus). O objeto ser� desenhado com a angula��o informada no pr�ximo comando
Desenha_Objeto(). A detec��o de colis�o n�o funciona com objetos fora da angula��o padr�o (0 graus).
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
angulo (entrada, passagem por valor): valor para indicar a angula��o do objeto em graus.
********************************/
void Define_Angulo(int id_objeto, float angulo)
{
    jogo->objetos[id_objeto]->SetAngulo(angulo);
}

/********************************
A fun��o Define_Pivo() define um ponto (X,Y) em rela��o ao ponto (0,0) do objeto, sobre o qual o objeto ser�
rotacionado quando a fun��o Define_Angulo() for executada. Al�m disso, futuras movimenta��es do objetos utilizar�o o ponto piv� como refer�ncia.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
posicaoX (entrada, passagem por valor): Valor da coordenada X em rela��o ao ponto (0,0) do objeto.
posicaoY (entrada, passagem por valor): Valor da coordenada Y em rela��o ao ponto (0,0) do objeto.
********************************/
void Define_Pivo(int id_objeto,int posicaoX,int posicaoY)
{
    jogo->objetos[id_objeto]->SetPivo(posicaoX,posicaoY);
}

/********************************
A fun��o Define_Flip() � respons�vel por virar o objeto, invertendo-o em alguma dire��o. O objeto somente ser�
desenhado na nova orienta��o no pr�ximo comando Desenha_Objeto().
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser virado.
valor (entrada, passagem por valor): valor do tipo de Flip. Pode ser FLIP_NENHUM (nenhum tipo de invers�o),
FLIP_HORIZONTAL (inverte da esquerda para a direita), FLIP_VERTICAL (inverte de cima para baixo),
ou FLIP_HORIZ_VERT (inverte da esquerda para direita e de cima para baixo).
********************************/
void Define_Flip(int id_objeto,PIG_Flip valor)
{
    jogo->objetos[id_objeto]->SetFlip(valor);
}

/********************************
A fun��o Define_Dimensoes() � respons�vel por delimitar a altura e a largura do objeto que ser� desenhado na tela,
independentemente do tamanho original do arquivo de imagem.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
altura (entrada, passagem por valor): altura em pixels do objeto a ser desenhado.
largura (entrada, passagem por valor): largura em pixels do objeto a ser desenhado.
********************************/
void Define_Dimensoes(int id_objeto, int altura, int largura)
{
    jogo->objetos[id_objeto]->SetDimensoes(altura,largura);
}

/********************************
A fun��o Pega_Dimensoes() � respons�vel por recuperar a altura e a largura da �rea a ser usada
para desenhar o objeto na tela.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
altura (sa�da, passagem por refer�ncia): altura em pixels do objeto a ser desenhado.
largura (sa�da, passagem por refer�ncia): largura em pixels do objeto a ser desenhado.
********************************/
void Pega_Dimensoes(int id_objeto, int *altura, int *largura)
{
    jogo->objetos[id_objeto]->GetDimensoes(*altura,*largura);
}

/********************************
A fun��o Define_Frame() � respons�vel por delimitar o posicionamento dos pixels do arquivo de imagem
que ser�o utilizados para representar o objeto na tela. Desta forma, nem toda a imagem ser� automaticamente
utilizada para representar o objeto.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
xBitmap (entrada, passagem por valor): indica o ponto horizontal de in�cio do frame.
yBitmap (entrada, passagem por valor): indica o ponto vertical de in�cio do frame.
altura (entrada, passagem por valor): altura em pixels do objeto a ser desenhado.
largura (entrada, passagem por valor): largura em pixels do objeto a ser desenhado.
********************************/
void Define_Frame(int id_objeto,int xBitmap, int yBitmap,int altura,int largura)
{
    jogo->objetos[id_objeto]->CriaFrame(0,xBitmap,yBitmap,altura,largura);
}

/********************************
A fun��o Modifica_Coloracao() � respons�vel por mesclar uma determinada cor com os pixels do arquivo de imagem.
Ap�s a modifica��o, todos os desenhos deste objeto ser�o mostrados j� com a mesclagem definida.
Para voltar ao padr�o original de pixels, deve-se chamar a fun��o, passando a cor branca (255,255,255).
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
cor (entrada,passagem por valor): cor do sistema RGB utilizada para mesclagem com o arquivo de imagem
********************************/
void Define_Coloracao(int id_objeto,PIG_Cor cor)
{
    jogo->objetos[id_objeto]->SetColoracao(cor);
}

/********************************
A fun��o Define_Transparencia() � respons�vel por modificar o n�vel de transpar�ncia do objeto.
O n�vel de transpar�ncia varia de 0-255, sendo 0 totalmente transparente e 255 totalmente opaco.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
valor (entrada,passagem por valor): n�vel de transpar�ncia do objeto na faixa 0-255.
********************************/
void Define_Transparencia(int id_objeto,int valor)
{
    jogo->objetos[id_objeto]->SetTransparencia(valor);
}

/********************************
A fun��o Desenha_Objeto() � respons�vel por desenhar um objeto na tela. O objeto ser� desenhado de acordo com todos as defini��es
de posi��o e �ngulo informado at� o momento. Al�m disso, se o objeto estiver virado (flipping), isso tamb�m ser� levado em considera��o.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
********************************/
void Desenha_Objeto(int id_objeto)
{
    jogo->objetos[id_objeto]->Desenha();
}

/********************************
A fun��o Testa_Colis�o() � respons�vel por testar se dois objetos se colidiram ou n�o, ao passar
os identificadores dos objetos por par�metro.
Par�metros:
id_objeto1 (entrada, passagem por valor): Identificador do primeiro objeto.
id_objeto2 (entrada, passagem por valor): Identificador do segundo objeto.
Retorno:
Inteiro indicando se houve colis�o (valor diferente de zero) ou n�o (valor igual a 0, zero).
********************************/
int Testa_Colisao(int id_objeto1,int id_objeto2)
{
    Objeto obj1 = jogo->objetos[id_objeto1];
    Objeto obj2 = jogo->objetos[id_objeto2];
    return obj2->Colisao(obj1);
}

/********************************
Se��o de gerador de part�culas
********************************/

/********************************
A fun��o Cria_GeradorParticulas() cria um novo gerador de part�culas (GDP). As part�culas em si precisam ser criadas
posteriormente atrav�s da fun��o Cria_Particula(), passando o identificador do GDP como par�metro.
Par�metros:
maxParticulas (entrada, passagem por valor): informa o maior n�mero de part�culas que o gerador ter� simultaneamente. O maior valor aceito � 1000 part�culas.
origemX (entrada, passagem por valor): ponto no eixo X de onde v�o ser criadas as part�culas
origemY (entrada, passagem por valor): ponto no eixo Y de onde v�o ser criadas as part�culas
menorX (entrada, passagem por valor): menor valor poss�vel no eixo X para que uma part�cula seja considerada ativa;
maiorX (entrada, passagem por valor): maior valor poss�vel no eixo X para que uma part�cula seja considerada ativa;
menorY (entrada, passagem por valor): menor valor poss�vel no eixo Y para que uma part�cula seja considerada ativa;
maiorY (entrada, passagem por valor): maior valor poss�vel no eixo Y para que uma part�cula seja considerada ativa;
nomeArquivo (entrada, passagem por refer�ncia): indica o caminho relativo ou absoluto do arquivo de imagem,
 que ser� utilizado para cada part�cula do GDP.
********************************/
int Cria_GeradorParticulas(int maxParticulas,int origemX,int origemY,int menorX,int maiorX,int menorY,int maiorY,char* nomeArquivo)
{
    return jogo->Cria_GeradorParticulas(maxParticulas,origemX,origemY,menorX,maiorX,menorY,maiorY,nomeArquivo);
}

/********************************
A fun��o Destroi_GeradorParticulas() encerra um gerador de part�culas (GDP). Todas as part�culas relacionadas a ele tamb�m s�o finalizadas
neste momento.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
********************************/
void Destroi_GeradorParticulas(int id_gerador)
{
    jogo->Destroi_GeradorParticulas(id_gerador);
}

/********************************
A fun��o Move_GeradorParticulas() reposiciona um gerador de part�culas (GDP). Na pr�tica, isto significa que as novas part�culas que
forem criadas posteriormente ter�o esse ponto de origem.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
posicaoX (entrada, passagem por valor): informa a nova posi��o X do GDP, em rela��o ao sistema de coordenadas do jogo.
posicaoY (entrada, passagem por valor): informa a nova posi��o Y do GDP, em rela��o ao sistema de coordenadas do jogo.
********************************/
void Move_GeradorParticulas(int id_gerador,int posicaoX,int posicaoY)
{
    jogo->geradores[id_gerador]->Move(posicaoX,posicaoY);
}

/********************************
A fun��o Cria_Particula() adiciona uma nova part�cula ao jogo relacionada com o GDP passado como par�metro.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
deslocX (entrada, passagem por valor): deslocamento da part�cula por segundo no eixo X
deslocY (entrada, passagem por valor): deslocamento da part�cula por segundo no eixo Y
maxColisoes (entrada, passagem por valor): n�mero m�ximo de colis�es que uma part�cula suporta antes de ser inativada;
tempoMax (entrada, passagem por valor): tempo m�ximo de vida da part�cula (em segundos)
fadingOut (entrada, passagem por valor): valor l�gico que indica se a part�cula deve esmaecer ao longo do tempo
Retorno:
inteiro indicando se a part�cula foi criada (valor maior ou igual a zero) ou n�o (valor menor do que zero).
A part�cula n�o ser� criada se j� houver o n�mero m�ximo de part�culas ativas.
********************************/
int Cria_Particula(int id_gerador,int deslocX,int deslocY,int maxColisoes,float tempoMax,int fadingOut)
{
    return jogo->geradores[id_gerador]->CriaParticula(deslocX,deslocY,maxColisoes,tempoMax,fadingOut);
}

/********************************
A fun��o Move_Particulas() faz com que todas as part�cula ativas do GDP em quest�o se movimentem de acordo com as componentes
X e Y passadas na cria��o de cada part�cula. As part�culas que sa�rem da �rea v�lida definida na cria��o do GDP, aqueles que j� ultrapassarem o tempo de vida
ou que sofrerem colis�es demais ser�o consideradas inativas e deixar�o de existir.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
********************************/
void Move_Particulas(int id_gerador)
{
    jogo->geradores[id_gerador]->MoveParticulas();
}

/********************************
A fun��o Quantidade_ParticulasAtivas() indica quantas part�culas do GDP em quest�o ainda est�o ativas. As part�culas deixam de
ser ativas quando saem da �rea definida na cria��o do GDP, quando sofrem colis�es demais ou quando esgotam seu tempo de vida.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
Retorno:
inteiro que indica o n�mero de part�culas ativas.
********************************/
int Quantidade_ParticulasAtivas(int id_gerador)
{
    return jogo->geradores[id_gerador]->ativas;
}

/********************************
A fun��o Desenha_Particulas() desenha todas as part�culas ativas do GDP na posi��o que estiverem.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
********************************/
void Desenha_Particulas(int id_gerador)
{
    jogo->geradores[id_gerador]->Desenha();
}

/********************************
A fun��o Colisao_Particulas() indica se houve colis�o de alguma part�cula ativa do GDP com um outro objeto espec�fico, atrav�s do seu identificador.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
id_objeto (entrada, passagem por valor): identificador do objeto que pode ter colidido com as part�culas do GDP.
Retorno:
inteiro que indica se houve colis�o de alguma part�cula ativa do GDP (valor diferente de zero) ou n�o (valor igual a 0, zero).
********************************/
int Colisao_Particulas(int id_gerador,int id_objeto)
{
    Objeto obj = jogo->objetos[id_objeto];
    return jogo->geradores[id_gerador]->Colisao(obj);
}

/********************************
Se��o dos temporizadores
********************************/

/********************************
A fun��o Cria_Timer() � respons�vel por criar um timer (temporizador). Ap�s a cria��o o tempo decorrido
poder� ser obtido a partir da fun��o Tempo_Decorrido(), informando o identificador que � passado na resposta.
Retorno:
inteiro que identifica o timer criado.
********************************/
int Cria_Timer()
{
    return jogo->Cria_Timer();
}

/********************************
A fun��o Tempo_Decorrido() � respons�vel por informar o tempo decorrido desde a cria��o do timer
at� a hora em que a fun��o for chamada.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
Retorno:
n�mero real indicando o tempo (em segundos) desde a cria��o do timer.
********************************/
float Tempo_Decorrido(int id_timer)
{
    return jogo->timers[id_timer]->GetTempoDecorrido();
}

/********************************
A fun��o Pausa() � respons�vel por realizar uma pausa na contagem do tempo de um timer. Ap�s a despausa,
o timer continuar� a contar o tempo normalmente.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Pausa_Timer(int id_timer)
{
    jogo->timers[id_timer]->Pausa();
}

/********************************
A fun��o Despausa() � respons�vel por retomar a contagem do tempo de um timer ap�s uma pausa.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Despausa_Timer(int id_timer)
{
    jogo->timers[id_timer]->Despausa();
}

/********************************
A fun��o Reinicia_Timer() � respons�vel por zerar a contagem do tempo de um timer, idependente do tempo j� decorrido.
Na pr�tica, � equivalente a encerrer um temporizador e recri�-lo em seguida.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Reinicia_Timer(int id_timer)
{
    jogo->timers[id_timer]->Reinicia();
}

/********************************
A fun��o Destroi_Timer() � respons�vel por encerrar a utiliza��o de timer.
Seu identificador n�o poder� ser utilizado ap�s a fun��o ser executada.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Destroi_Timer(int id_timer)
{
    jogo->Destroi_Timer(id_timer);
}
