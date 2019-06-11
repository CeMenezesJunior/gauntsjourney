/********************************
Versão 0.4.0 da Biblioteca Pig.h
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
/ Variáveis Globais
/********************************/
Jogo jogo=NULL;


/********************************
A função Cria_Jogo é responsável pela criação da janela do jogo e pelos componentes audio-visuais.
Ela deve ser chamada antes de qualquer outra função da biblioetac PIG.h. Não é possível criar dois
jogos no mesmo progama. Logo, somente a primeira chamada terá efeito.
Parâmetros:
nome_Janela (entrada, passagem por referência*): indica o nome que ajanela do jogo mostrará no seu título
É utilizado o operador * apenas por se tratar de um parâmetro string. O valor do parâmetro não é alterado dentro da função.
********************************/
void Cria_Jogo(char *nome_Janela)
{
    if (jogo==NULL)
        jogo = new CJogo(nome_Janela);
}

/********************************
A função GetEstado_Jogo() indica o estado do jogo. Este estado é apenas um valor inteiro
que pode ser usado para indicar uma fase do jogo ou a vez de algum jogador por exemplo.
Retorno:
inteiro indicando o valor do estado do jogo;
********************************/
int GetEstado_Jogo()
{
    return jogo->estado;
}

/********************************
A função SetEstado_Jogo() atribui um novo valor ao estado do jogo. Este estado é apenas um valor inteiro
que pode ser usado para indicar uma fase do jogo, ou a vez de algum jogador por exemplo.
Parâmetro:
estado (entrada, passagem por valor): indica o novo estado do jogo;
********************************/
void SetEstado_Jogo(int estado)
{
    jogo->estado = estado;
}

/********************************
A função Define_Fundo permite escolher um arquivo fr imagem como fundo (background) do jogo.
Parâmetros:
nome_ArquivoImagem (entrada, passagem por referência*): indica o caminho relativo ou absoluto do arquivo de imagem que será utilizado como fundo do jogo.
É utilizado o operador * apenas por se tratar de um parâmetro string. O valor do parâmetro não é alterado dentro da função.
********************************/
void Define_Fundo(char *nome_ArquivoImagem)
{
    jogo->DefineFundo(nome_ArquivoImagem);
}

/********************************
A função Pega_Teclado() é responsável por fornecer um mapeamento do estado das teclas através de um vetor de variáveis lógicas.
Uma lista dos nomes das teclas (que servem para indicar uma determinada posição no vetor) pode ser vista no final do arquivo PIG.h.
Retorno:
O valor de retorno da função é um vetor de números inteiros que indicam se uma determinada tecla (índice do vetor) foi
pressionada (valor diferente de 0,zero) ou não (valor igual a zero).
********************************/
PIG_Teclado Pega_Teclado()
{
    return jogo->PegaTeclado();
}

/********************************
A função Pega_Evento() indica se houve algum tipo de evento desde a última vez que a função foi chamada.
Um evento pode ser uma tecla pressionada, um clique do mouse ou outra coisa relacionada à tela do jogo.
Maiores informaçõe podem ser vistas no arquivo Tipo_PIG.h
Retorno:
O valor de retorno é um struct contendo o tipo de evento ocorrido e vários outros structs com informações específicas.
********************************/
PIG_Evento Pega_Evento()
{
    return jogo->PegaEvento();
}

/********************************
A função Inicia_Desenho é responsável por preparar a janela do jogo para que os objetos gráficos
possam ser mostrados, além de desenhar a imagem de fundo do jogo.
Deve ser chamada repetidamente a cada novo quadro (frame) a ser desenhado.
********************************/
void Inicia_Desenho()
{
    jogo->IniciaDesenho();
}

/********************************
A função Encerra_Desenho é responsável por encerrar o desenho que foi criado. Após a execução dos frames,
ele encerra a animação. Deve ser chamado toda vez que um frame acabar de ser executado.
********************************/
void Encerra_Desenho()
{
    jogo->EncerraDesenho();
}

/********************************
A função Salva_Tela() é responsável por criar um arquivo Bitmap, contendo uma cópia da tela do jogo naquele momento.
Parâmetros:
nomeBMP (entrada, passagem por referência*): indica o nome do arquivo Bitmap que será salvo. O valor do parâmetro deve conter a extensão ".bmp".
É utilizado o operador * apenas por se tratar de um parâmetro string. O valor do parâmetro não é alterado dentro da função.
********************************/
void Salva_Tela(char *nomeBMP)
{
    jogo->saveScreenshotBMP(nomeBMP);
}

/********************************
A função Jogo_Rodando é reponsável por retornar o funcionamento do jogo. Ela chama o método que
vai retornar um valor inteiro indicando se o jogo ainda está ativo ou não.
Retorno:
inteiro que indica se o jogo ainda está sendo executado (valor diferente de zero) ou não (valor igual a 0, zero).
********************************/
int Jogo_Rodando()
{
    return jogo->rodando;
}

/********************************
A função Espera() "congela" a tela do jogo por alguns milisegundos, impedindo que qualquer outro comando seja executado enquanto isso.
Parâmetros:
tempo (entrada, passagem por valor): indica a quantidade de milisegundos durante a qual o jogo será pausado.
********************************/
void Espera(int tempo)
{
    SDL_Delay(tempo);
}

/********************************
A função Finaliza_Jogo é responsável por encerrar com a execução final do jogo. Após tudo ser realizado
a função pode ser chamada e ela irá realizar a interrupção do jogo e a sua finalização.
********************************/
void Finaliza_Jogo()
{
    delete jogo;
}

/********************************
Seção de elementos geométricos
********************************/

/********************************
A função Desenha_LinhasSimples() é responsável por desenhar uma única linha, cuja início é o ponto (x1,y1) e o fim é o ponto (x2,y2).
Parâmetros:
pontoX1 (entrada, passagem por valor): inteiro que indica o início da linha no eixo X.
pontoY1 (entrada, passagem por valor): inteiro que indica o início da linha no eixo Y.
pontoX2 (entrada, passagem por valor): inteiro que indica o fim da linha no eixo X.
pontoY2 (entrada, passagem por valor): inteiro que indica o fim da linha no eixo Y.
cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho das linhas;
********************************/
void Desenha_LinhaSimples(int pontoX1,int pontoY1,int pontoX2,int pontoY2, PIG_Cor cor)
{
    jogo->DesenhaLinhaSimples(pontoX1,pontoY1,pontoX2,pontoY2,cor);
}

/********************************
A função Desenha_LinhasDisjuntas() é responsável por desenhar linhas separadamente, ou seja, os ponto iniciais de cada linha estão nas posições pares e
os pontos finais estão nas posições ímpares. Assim, os vetores precisam ter tamanho qtd*2.
Parâmetros:
pontosX (entrada, passagem por referência): vetor de inteiros, de tamanho qtd*2, contendo os valores X (inicias e finais) de cada linha.
pontosY (entrada, passagem por referência): vetor de inteiros, de tamanho qtd*2, contendo os valores Y (inicias e finais) de cada linha.
qtd (entrada, passagem por valor): quantidade de linhas a serem desenhadas.
cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho das linhas;
********************************/
void Desenha_LinhasDisjuntas(int *pontosX,int *pontosY,int qtd, PIG_Cor cor)
{
    jogo->DesenhaLinhasDisjuntas(pontosX,pontosY,qtd,cor);
}

/********************************
A função Desenha_LinhasSequencia() é responsável por desenhar linhas em sequência, ou seja, o ponto final da primeira linha
corresponde ao ponto inicial da segunda linha.
Parâmetros:
pontosX (entrada, passagem por referência): vetor de inteiros, de tamanho qtd+1, contendo os valores X de cada linha da sequência.
pontosY (entrada, passagem por referência): vetor de inteiros, de tamanho qtd+1, contendo os valores Y de cada linha da sequência.
qtd (entrada, passagem por valor): quantidade de linhas a serem desenhadas.
cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho das linhas;
********************************/
void Desenha_LinhasSequencia(int *pontosX,int *pontosY,int qtd, PIG_Cor cor)
{
    jogo->DesenhaLinhasSequencia(pontosX,pontosY,qtd,cor);
}

/********************************
A função Desenha_Retangulo() é responsável por desenhar um retângulo com preenchimento sólido na tela em uma posição desejada pelo usuário.
O mesmo pode ser colocado em qualquer lugar do campo de visão da tela.
Parâmetros:
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usuário deseja colocar o retângulo.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usuário deseja colocar o retângulo.
altura (entrada, passagem por valor): Valor onde o usuário irá fornecer o número correspondente em pixels à altura desse retângulo.
largura (entrada, passagem por valor): Valor onde o usuário irá fornecer o número correspondente em pixels à largura desse retângulo.
cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho do retângulo;
********************************/
void Desenha_Retangulo(int posicaoX, int posicaoY, int altura, int largura, PIG_Cor cor)
{
    jogo->DesenhaRetangulo(posicaoX,posicaoY,altura,largura,cor);
}

/********************************
Seção de fontes
********************************/

/********************************
A função CriaFonteNormal() é responsável por disponibilizar uma nova fonte com preenchimento sólido.
Parâmetros:
nome (entrada, passagem por referência): nome do arquivo que contém a fonte (normalmente com extensão ttf).
tamanho (entrada, passagem por valor): tamanho da fonte, que normalmente representa a altura média (em pixels) dos caracteres da fonte.
corLetra (entrada, passagem por valor): representa a cor de preenchimento da fonte.
contorno (entrada, passagem por valor): representa a espessura do contorno que fonte terá. Caso não seja desejado um contorno, basta utilizar um valor 0.
corContorno (entrada, passagem por valor): representa a cor do contorno da fonte.
estilo (entrada, passagem por valor): representa o estilo da fonte. Pode ser uma combinação binária de: ESTILO_NEGRITO, para negrito; ESTILO_SUBLINHADO, para sublinhado; ESTILO_ITALICO, para itálico;
ESTILO_CORTADO, para uma linha horizontal à meia-altura. Caso nenhum estilo seja desejado, pode ser omitido ou usado ESTILO_NORMAL.
retono:
inteiro que representa a ideintificação única da fonte. Futuras referência a esta fonte devem idenitificá-las pelo número.
********************************/
int CriaFonteNormal(char *nome,int tamanho,PIG_Cor corLetra,int contorno=0,PIG_Cor corContorno=BRANCO,PIG_Estilo estilo=ESTILO_NORMAL)
{
    return jogo->CriaFonteNormal(nome,tamanho,estilo,corLetra,contorno,corContorno);
}

/********************************
A função CriaFonteFundo() é responsável por disponibilizar uma nova fonte com preenchimento de um bitmap específico.
Parâmetros:
nome (entrada, passagem por referência): nome do arquivo que contém a fonte (normalmente com extensão ttf).
tamanho (entrada, passagem por valor): tamanho da fonte, que normalmente representa a altura média (em pixels) dos caracteres da fonte.
arquivoFundo (entrada, passagem por referência): indica o nome do arquivo de imagem que servirá de fundo para a fonte.
contorno (entrada, passagem por valor): representa a espessura do contorno que fonte terá. Caso não seja desejado um contorno, basta utilizar um valor 0.
corContorno (entrada, passagem por valor): representa a cor do contorno da fonte.
estilo (entrada, passagem por valor): representa o estilo da fonte. Pode ser uma combinação binária de: ESTILO_NEGRITO, para negrito; ESTILO_SUBLINHADO, para sublinhado; ESTILO_ITALICO, para itálico;
ESTILO_CORTADO, para uma linha horizontal à meia-altura. Caso nenhum estilo seja desejado, pode ser omitido ou usado ESTILO_NORMAL.
retono:
inteiro que representa a ideintificação única da fonte. Futuras referência a esta fonte devem idenitificá-las pelo número.
********************************/
int CriaFonteFundo(char *nome,int tamanho,char *arquivoFundo,int contorno=0,PIG_Cor corContorno=BRANCO,PIG_Estilo estilo=ESTILO_NORMAL)
{
    return jogo->CriaFonteFundo(nome,tamanho,estilo,arquivoFundo,contorno,corContorno);
}

/********************************
A função CalculaLarguraPixels() por realizar a soma das larguras de cada letra da string informada.
Parâmetros:
str (entrada, passagem por referência): string a ser escrita na tela.
numFonte (entrada, passagem por valor): número da fonte a ser utilizada. Caso o usuário não deseje uma fonte especial, será utilizada a fonte padrão (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
retorno:
inteiro que representa o total de pixels (no eixo x) necessários para escrever a string.
********************************/
int CalculaLarguraPixels(char *str,int numFonte=0)
{
    return jogo->GetLarguraPixels(str);
}

/********************************
A função EscreverDireita() é responsável por exibir uma string na tela de jogo, com alinhamento à direita do valor de X.
Parâmetros:
str (entrada, passagem por referência): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usuário deseja começar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usuário deseja começar a escrever a string.
numFonte (entrada, passagem por valor): número da fonte a ser utilizada. Caso o usuário não deseje uma fonte especial, será utilizada a fonte padrão (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void EscreverDireita(char *str,int posicaoX,int posicaoY,int numFonte=0)
{
    jogo->EscreverDireita(str,posicaoX,posicaoY,numFonte);
}

/********************************
A função EscreverEsquerda() é responsável por exibir uma string na tela de jogo, com alinhamento à esquerda do valor de X.
Parâmetros:
str (entrada, passagem por referência): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usuário deseja começar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usuário deseja começar a escrever a string.
numFonte (entrada, passagem por valor): número da fonte a ser utilizada. Caso o usuário não deseje uma fonte especial, será utilizada a fonte padrão (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void EscreverEsquerda(char *str,int posicaoX,int posicaoY,int numFonte=0)
{
    jogo->EscreverEsquerda(str,posicaoX,posicaoY,numFonte);
}

/********************************
A função EscreverCentralizada() é responsável por exibir uma string na tela de jogo, com alinhamento em relação ao valor de X.
Parâmetros:
str (entrada, passagem por referência): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usuário deseja começar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usuário deseja começar a escrever a string.
numFonte (entrada, passagem por valor): número da fonte a ser utilizada. Caso o usuário não deseje uma fonte especial, será utilizada a fonte padrão (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void EscreverCentralizada(char *str,int posicaoX,int posicaoY,int numFonte=0)
{
    jogo->EscreverCentralizada(str,posicaoX,posicaoY,numFonte);
}

/********************************
Seção de objetos
********************************/

/********************************
A função Cria_Objeto() é responsável por criar um objeto. Qualquer objeto que for necessário,
pode ser criado através dessa função. O objeto ainda não será desenhado, apenas criado dentro do jogo.
Parâmetros:
nomeArquivo (entrada, passagem por referência): string que informa o nome do arquivo da imagem do objeto a ser criado.
retiraFundo (entrada, passagem por valor): inteiro que indica se o fundo da imagem deve ser retirado ou não ao ler o arquivo em questão.
Retorno:
inteiro que representa o identificador único do objeto. Todas as operações subsequentes com este objeto deverão receber este identificador como parâmetro.
********************************/
int Cria_Objeto(char* nomeArquivo,int retiraFundo=1)
{
    return jogo->Cria_Objeto(0,0,nomeArquivo,retiraFundo);
}

/********************************
A função Destroi_Objeto() é responsável por eliminar o objeto em questão do jogo.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser excluído.
********************************/
void Destroi_Objeto(int id_objeto)
{
    jogo->Destroi_Objeto(id_objeto);
}

/********************************
A função SetValorInt_Objeto() é responsável incorporar a um objeto um atributo inteiro.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): relaciona um número inteiro ao atributo indicado.
valor (entrada, passagem por valor): valor do atributo inteiro a ser associado ao objeto.
********************************/
void SetValorInt_Objeto(int id_objeto,int indice,int valor)
{
    jogo->objetos[id_objeto]->SetValorInt(indice,valor);
}

/********************************
A função SetValorDouble_Objeto() é responsável incorporar a um objeto um atributo double.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): relaciona um número double ao atributo indicado.
valor (entrada, passagem por valor): valor do atributo double a ser associado ao objeto.
********************************/
void SetValorDouble_Objeto(int id_objeto,int indice,double valor)
{
    jogo->objetos[id_objeto]->SetValorDouble(indice,valor);
}

/********************************
A função GetValorInt_Objeto() é responsável recuperar o valor de um atributo int relacionado a um objeto.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): indica o número do atributo que se deseja recuperar.
Retorno:
Retorna o valor do atributo int solicitado pelo usuário.
********************************/
int GetValorInt_Objeto(int id_objeto,int indice)
{
    return jogo->objetos[id_objeto]->GetValorInt(indice);
}

/********************************
A função GetValorDouble_Objeto() é responsável recuperar o valor de um atributo double relacionado a um objeto.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): indica o número do atributo que se deseja recuperar.
Retorno:
Retorna o valor do atributo double solicitado pelo usuário.
********************************/
double GetValorDouble_Objeto(int id_objeto,int indice)
{
    return jogo->objetos[id_objeto]->GetValorDouble(indice);
}

/********************************
A função GetXY_Objeto() é responsável recuperar o valor da posição (X,Y) do objeto de acordo com o sistema de coordenadas do jogo.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
posicaoX (saída, passagem por referencia): indica a posicao no eixo X do objeto.
posicaoY (saída, passagem por referencia): indica a posicao no eixo Y do objeto.
********************************/
void GetXY_Objeto(int id_objeto,int *posicaoX,int *posicaoY)
{
    jogo->objetos[id_objeto]->GetXY(*posicaoX,*posicaoY);
}

/********************************
A função Move_Objeto() é responsável por movimentar um determinado obeto para uma nova posição informada.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser movido.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usuário deseja reposicionar o objeto.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usuário deseja reposicionar o objeto.
********************************/
void Move_Objeto(int id_objeto,int posicaoX,int posicaoY)
{
    jogo->objetos[id_objeto]->Move(posicaoX,posicaoY);
}

/********************************
A função Define_Angulo() é responsável pela angulação de determinado objeto. A angulação é calculada em sentido
anti-horário a partir do eixo X (0 graus). O objeto será desenhado com a angulação informada no próximo comando
Desenha_Objeto(). A detecção de colisão não funciona com objetos fora da angulação padrão (0 graus).
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
angulo (entrada, passagem por valor): valor para indicar a angulação do objeto em graus.
********************************/
void Define_Angulo(int id_objeto, float angulo)
{
    jogo->objetos[id_objeto]->SetAngulo(angulo);
}

/********************************
A função Define_Pivo() define um ponto (X,Y) em relação ao ponto (0,0) do objeto, sobre o qual o objeto será
rotacionado quando a função Define_Angulo() for executada. Além disso, futuras movimentações do objetos utilizarão o ponto pivô como referência.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
posicaoX (entrada, passagem por valor): Valor da coordenada X em relação ao ponto (0,0) do objeto.
posicaoY (entrada, passagem por valor): Valor da coordenada Y em relação ao ponto (0,0) do objeto.
********************************/
void Define_Pivo(int id_objeto,int posicaoX,int posicaoY)
{
    jogo->objetos[id_objeto]->SetPivo(posicaoX,posicaoY);
}

/********************************
A função Define_Flip() é responsável por virar o objeto, invertendo-o em alguma direção. O objeto somente será
desenhado na nova orientação no próximo comando Desenha_Objeto().
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser virado.
valor (entrada, passagem por valor): valor do tipo de Flip. Pode ser FLIP_NENHUM (nenhum tipo de inversão),
FLIP_HORIZONTAL (inverte da esquerda para a direita), FLIP_VERTICAL (inverte de cima para baixo),
ou FLIP_HORIZ_VERT (inverte da esquerda para direita e de cima para baixo).
********************************/
void Define_Flip(int id_objeto,PIG_Flip valor)
{
    jogo->objetos[id_objeto]->SetFlip(valor);
}

/********************************
A função Define_Dimensoes() é responsável por delimitar a altura e a largura do objeto que será desenhado na tela,
independentemente do tamanho original do arquivo de imagem.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
altura (entrada, passagem por valor): altura em pixels do objeto a ser desenhado.
largura (entrada, passagem por valor): largura em pixels do objeto a ser desenhado.
********************************/
void Define_Dimensoes(int id_objeto, int altura, int largura)
{
    jogo->objetos[id_objeto]->SetDimensoes(altura,largura);
}

/********************************
A função Pega_Dimensoes() é responsável por recuperar a altura e a largura da área a ser usada
para desenhar o objeto na tela.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
altura (saída, passagem por referência): altura em pixels do objeto a ser desenhado.
largura (saída, passagem por referência): largura em pixels do objeto a ser desenhado.
********************************/
void Pega_Dimensoes(int id_objeto, int *altura, int *largura)
{
    jogo->objetos[id_objeto]->GetDimensoes(*altura,*largura);
}

/********************************
A função Define_Frame() é responsável por delimitar o posicionamento dos pixels do arquivo de imagem
que serão utilizados para representar o objeto na tela. Desta forma, nem toda a imagem será automaticamente
utilizada para representar o objeto.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
xBitmap (entrada, passagem por valor): indica o ponto horizontal de início do frame.
yBitmap (entrada, passagem por valor): indica o ponto vertical de início do frame.
altura (entrada, passagem por valor): altura em pixels do objeto a ser desenhado.
largura (entrada, passagem por valor): largura em pixels do objeto a ser desenhado.
********************************/
void Define_Frame(int id_objeto,int xBitmap, int yBitmap,int altura,int largura)
{
    jogo->objetos[id_objeto]->CriaFrame(0,xBitmap,yBitmap,altura,largura);
}

/********************************
A função Modifica_Coloracao() é responsável por mesclar uma determinada cor com os pixels do arquivo de imagem.
Após a modificação, todos os desenhos deste objeto serão mostrados já com a mesclagem definida.
Para voltar ao padrão original de pixels, deve-se chamar a função, passando a cor branca (255,255,255).
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
cor (entrada,passagem por valor): cor do sistema RGB utilizada para mesclagem com o arquivo de imagem
********************************/
void Define_Coloracao(int id_objeto,PIG_Cor cor)
{
    jogo->objetos[id_objeto]->SetColoracao(cor);
}

/********************************
A função Define_Transparencia() é responsável por modificar o nível de transparência do objeto.
O nível de transparência varia de 0-255, sendo 0 totalmente transparente e 255 totalmente opaco.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
valor (entrada,passagem por valor): nível de transparência do objeto na faixa 0-255.
********************************/
void Define_Transparencia(int id_objeto,int valor)
{
    jogo->objetos[id_objeto]->SetTransparencia(valor);
}

/********************************
A função Desenha_Objeto() é responsável por desenhar um objeto na tela. O objeto será desenhado de acordo com todos as definições
de posição e ângulo informado até o momento. Além disso, se o objeto estiver virado (flipping), isso também será levado em consideração.
Parâmetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
********************************/
void Desenha_Objeto(int id_objeto)
{
    jogo->objetos[id_objeto]->Desenha();
}

/********************************
A função Testa_Colisão() é responsável por testar se dois objetos se colidiram ou não, ao passar
os identificadores dos objetos por parâmetro.
Parâmetros:
id_objeto1 (entrada, passagem por valor): Identificador do primeiro objeto.
id_objeto2 (entrada, passagem por valor): Identificador do segundo objeto.
Retorno:
Inteiro indicando se houve colisão (valor diferente de zero) ou não (valor igual a 0, zero).
********************************/
int Testa_Colisao(int id_objeto1,int id_objeto2)
{
    Objeto obj1 = jogo->objetos[id_objeto1];
    Objeto obj2 = jogo->objetos[id_objeto2];
    return obj2->Colisao(obj1);
}

/********************************
Seção de gerador de partículas
********************************/

/********************************
A função Cria_GeradorParticulas() cria um novo gerador de partículas (GDP). As partículas em si precisam ser criadas
posteriormente através da função Cria_Particula(), passando o identificador do GDP como parâmetro.
Parâmetros:
maxParticulas (entrada, passagem por valor): informa o maior número de partículas que o gerador terá simultaneamente. O maior valor aceito é 1000 partículas.
origemX (entrada, passagem por valor): ponto no eixo X de onde vão ser criadas as partículas
origemY (entrada, passagem por valor): ponto no eixo Y de onde vão ser criadas as partículas
menorX (entrada, passagem por valor): menor valor possível no eixo X para que uma partícula seja considerada ativa;
maiorX (entrada, passagem por valor): maior valor possível no eixo X para que uma partícula seja considerada ativa;
menorY (entrada, passagem por valor): menor valor possível no eixo Y para que uma partícula seja considerada ativa;
maiorY (entrada, passagem por valor): maior valor possível no eixo Y para que uma partícula seja considerada ativa;
nomeArquivo (entrada, passagem por referência): indica o caminho relativo ou absoluto do arquivo de imagem,
 que será utilizado para cada partícula do GDP.
********************************/
int Cria_GeradorParticulas(int maxParticulas,int origemX,int origemY,int menorX,int maiorX,int menorY,int maiorY,char* nomeArquivo)
{
    return jogo->Cria_GeradorParticulas(maxParticulas,origemX,origemY,menorX,maiorX,menorY,maiorY,nomeArquivo);
}

/********************************
A função Destroi_GeradorParticulas() encerra um gerador de partículas (GDP). Todas as partículas relacionadas a ele também são finalizadas
neste momento.
Parâmetros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da função Cria_GeradorParticulas().
********************************/
void Destroi_GeradorParticulas(int id_gerador)
{
    jogo->Destroi_GeradorParticulas(id_gerador);
}

/********************************
A função Move_GeradorParticulas() reposiciona um gerador de partículas (GDP). Na prática, isto significa que as novas partículas que
forem criadas posteriormente terão esse ponto de origem.
Parâmetros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da função Cria_GeradorParticulas().
posicaoX (entrada, passagem por valor): informa a nova posição X do GDP, em relação ao sistema de coordenadas do jogo.
posicaoY (entrada, passagem por valor): informa a nova posição Y do GDP, em relação ao sistema de coordenadas do jogo.
********************************/
void Move_GeradorParticulas(int id_gerador,int posicaoX,int posicaoY)
{
    jogo->geradores[id_gerador]->Move(posicaoX,posicaoY);
}

/********************************
A função Cria_Particula() adiciona uma nova partícula ao jogo relacionada com o GDP passado como parâmetro.
Parâmetros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da função Cria_GeradorParticulas().
deslocX (entrada, passagem por valor): deslocamento da partícula por segundo no eixo X
deslocY (entrada, passagem por valor): deslocamento da partícula por segundo no eixo Y
maxColisoes (entrada, passagem por valor): número máximo de colisões que uma partícula suporta antes de ser inativada;
tempoMax (entrada, passagem por valor): tempo máximo de vida da partícula (em segundos)
fadingOut (entrada, passagem por valor): valor lógico que indica se a partícula deve esmaecer ao longo do tempo
Retorno:
inteiro indicando se a partícula foi criada (valor maior ou igual a zero) ou não (valor menor do que zero).
A partícula não será criada se já houver o número máximo de partículas ativas.
********************************/
int Cria_Particula(int id_gerador,int deslocX,int deslocY,int maxColisoes,float tempoMax,int fadingOut)
{
    return jogo->geradores[id_gerador]->CriaParticula(deslocX,deslocY,maxColisoes,tempoMax,fadingOut);
}

/********************************
A função Move_Particulas() faz com que todas as partícula ativas do GDP em questão se movimentem de acordo com as componentes
X e Y passadas na criação de cada partícula. As partículas que saírem da área válida definida na criação do GDP, aqueles que já ultrapassarem o tempo de vida
ou que sofrerem colisões demais serão consideradas inativas e deixarão de existir.
Parâmetros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da função Cria_GeradorParticulas().
********************************/
void Move_Particulas(int id_gerador)
{
    jogo->geradores[id_gerador]->MoveParticulas();
}

/********************************
A função Quantidade_ParticulasAtivas() indica quantas partículas do GDP em questão ainda estão ativas. As partículas deixam de
ser ativas quando saem da área definida na criação do GDP, quando sofrem colisões demais ou quando esgotam seu tempo de vida.
Parâmetros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da função Cria_GeradorParticulas().
Retorno:
inteiro que indica o número de partículas ativas.
********************************/
int Quantidade_ParticulasAtivas(int id_gerador)
{
    return jogo->geradores[id_gerador]->ativas;
}

/********************************
A função Desenha_Particulas() desenha todas as partículas ativas do GDP na posição que estiverem.
Parâmetros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da função Cria_GeradorParticulas().
********************************/
void Desenha_Particulas(int id_gerador)
{
    jogo->geradores[id_gerador]->Desenha();
}

/********************************
A função Colisao_Particulas() indica se houve colisão de alguma partícula ativa do GDP com um outro objeto específico, através do seu identificador.
Parâmetros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da função Cria_GeradorParticulas().
id_objeto (entrada, passagem por valor): identificador do objeto que pode ter colidido com as partículas do GDP.
Retorno:
inteiro que indica se houve colisão de alguma partícula ativa do GDP (valor diferente de zero) ou não (valor igual a 0, zero).
********************************/
int Colisao_Particulas(int id_gerador,int id_objeto)
{
    Objeto obj = jogo->objetos[id_objeto];
    return jogo->geradores[id_gerador]->Colisao(obj);
}

/********************************
Seção dos temporizadores
********************************/

/********************************
A função Cria_Timer() é responsável por criar um timer (temporizador). Após a criação o tempo decorrido
poderá ser obtido a partir da função Tempo_Decorrido(), informando o identificador que é passado na resposta.
Retorno:
inteiro que identifica o timer criado.
********************************/
int Cria_Timer()
{
    return jogo->Cria_Timer();
}

/********************************
A função Tempo_Decorrido() é responsável por informar o tempo decorrido desde a criação do timer
até a hora em que a função for chamada.
Parâmetros:
id_timer (entrada, passagem por valor): identificador do timer.
Retorno:
número real indicando o tempo (em segundos) desde a criação do timer.
********************************/
float Tempo_Decorrido(int id_timer)
{
    return jogo->timers[id_timer]->GetTempoDecorrido();
}

/********************************
A função Pausa() é responsável por realizar uma pausa na contagem do tempo de um timer. Após a despausa,
o timer continuará a contar o tempo normalmente.
Parâmetros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Pausa_Timer(int id_timer)
{
    jogo->timers[id_timer]->Pausa();
}

/********************************
A função Despausa() é responsável por retomar a contagem do tempo de um timer após uma pausa.
Parâmetros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Despausa_Timer(int id_timer)
{
    jogo->timers[id_timer]->Despausa();
}

/********************************
A função Reinicia_Timer() é responsável por zerar a contagem do tempo de um timer, idependente do tempo já decorrido.
Na prática, é equivalente a encerrer um temporizador e recriá-lo em seguida.
Parâmetros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Reinicia_Timer(int id_timer)
{
    jogo->timers[id_timer]->Reinicia();
}

/********************************
A função Destroi_Timer() é responsável por encerrar a utilização de timer.
Seu identificador não poderá ser utilizado após a função ser executada.
Parâmetros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Destroi_Timer(int id_timer)
{
    jogo->Destroi_Timer(id_timer);
}
