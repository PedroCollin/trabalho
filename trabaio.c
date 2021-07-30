//Copia o código e roda ele nesse site -> https://www.onlinegdb.com/online_c_compiler

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Função para gerar a matriz a ser decifrada.
void matriz_padrao();

int main(){
    int matriz[4][4],matrizFoi[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}} , linhanaorepetiveis[4], colunanaorepetiveis[2], reinicio = 1, acerto, erro, linha, coluna, valor1, valor2;

// Uso do while para reiniciar o jogo após seu término.
    while(reinicio != 0){
        acerto = 0;
        erro = 10; 

        //Geração aleatória da matriz.
        srand(time(NULL));
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                matriz[i][j] = rand() % 9;
                while(matriz[i][j-1] == matriz[i][j]){
                    matriz[i][j] = rand() % 9;
                }
            }
        }

        //Impressão da matriz.
        for(int i = 0; i < 4; i++){
            printf("\n\n");
            for(int j = 0; j < 4; j++){
                if(j % 2 == 0){
                printf("(%d,", matriz[i][j]);
                }
            else{
                printf(" %d)  ", matriz[i][j]);
            }
            }        
        }
        printf("\n");
        //Função sleep para permitir a visualização da matriz por apenas 5 segundos.
        sleep(5);
        //Função system, inserindo o parâmetro "clear", apagando assim o conteúdo da tela do output.
        system("clear");
        //Geração da matriz a ser decifrada.
        matriz_padrao();

        //Uso do while para as variáveis "acerto" e "erro". Isto permite a repetição das tentativas até o limite definido para acertos e erros.
        
        
        while(acerto < 8 && erro > 0){
            printf("\nInsira a linha (1 a 4): ");
            scanf("%d", &linha);
            printf("Insira a coluna (1 a 2): ");
            scanf("%d", &coluna);
        
            if(matrizFoi[linha][coluna] == 0){
                
                //Uso do while para evitar a entrada de linhas ou colunas inexistentes.
                while(linha < 1 || linha > 4 || coluna < 1 || coluna > 2){
                    printf("\nOpcao invalida! Tente novamente!\n");
                    printf("Insira a linha (1 a 4): ");
                    scanf("%d", &linha);
                    printf("Insira a coluna (1 a 2): ");
                    scanf("%d", &coluna);
                }
                //Obter os valores das células.
                printf("Insira o primeiro valor da celula: ");
                scanf("%d", &valor1);
                printf("Insira o segundo valor da celula: ");
                scanf("%d", &valor2);
            }else{
                printf("Posição já utilizada\n");
                linha = 10;
            }
          

            
            /*Pelo fato de 2 colunas da matrizes estarem dentro de uma célula, usa-se o if para coluna = 1, e portanto novamente um if para checar se:
               1º - valor da matriz em linha - 1 (evitando usar o 0 como primeiro valor da matriz) e coluna - 1 (novamente para evitar o uso do 0) equivale
                    ao valor da variável "valor1".
               2º - valor da matriz em linha - 1 e coluna (nao necessita de alteração, por isso foi usado o "if(coluna == 1)") equivale a variável "valor2". */
           
            if(coluna == 1 && linha != 10){
                if(valor1 == matriz[linha-1][coluna-1] && valor2 == matriz[linha-1][coluna]){
                    //Contabilização de acerto ao somar 1 unidade na variável "acerto".
                    acerto = acerto + 1;
                    matrizFoi[linha][coluna] = 1;
                    printf("\nCorreto!\n+1 Ponto\nTotal de acertos: (%d/8)", acerto);
                    puts("\a");   
                }
                else{
                    printf("\nIncorreto!\n-1 Tentativa\nRestam %d tentativas.", erro);
                    //Contabilização de erro ao somar 1 unidade na variável "erro".
                    erro = erro - 1;
                }
            }

            /*Neste caso, se coluna = 2, quer dizer que a segunda célula da matriz exibida foi selecionada (contendo as colunas 2 e 3), portanto um if é usado para checar:
                1º - valor da matriz em linha - 1 (evitando usar o 0 como primeiro valor da matriz) e coluna equivale ao valor da variável "valor1".
                2º - valor da matriz em linha - 1 e coluna   1 (para referir-se ao segundo valor da célula) equivale a variável "valor2". */
            else{
                if(valor1 == matriz[linha-1][coluna] && valor2 == matriz[linha-1][coluna+1]){
                    //Contabilização de acerto ao somar 1 unidade na variável "acerto".
                    acerto = acerto + 1;
                    printf("\nCorreto!\n+1 Ponto\nTotal de acertos: (%d/8)", acerto);
                    puts("\a");
                }
                else{
                    if(linha != 10){
                    printf("\nIncorreto!\n-1 Tentativa\nRestam %d tentativas.", erro);
                    //Contabilização de erro ao somar 1 unidade na variável "erro".
                    erro = erro - 1;
                    }
                }
            }
            
        }

        //Scanf para checar se o jogo será reiniciado e while para evitar respostas incorretas.
        printf("\n\nFIM DE JOGO!\nDeseja jogar novamente? (Digite 1 para sim e 0 para nao): ");
        scanf("%d", &reinicio);
        while(reinicio != 1 && reinicio != 0){
            printf("\n\nOpçao invalida! Tente novamente.\n");
            printf("\n\nFIM DE JOGO!\nDeseja jogar novamente? (Digite 1 para sim e 0 para nao): ");
            scanf("%d", &reinicio);
        }
    }
    return 0;
}

//Precisa trocar os zeros pelos caracteres da tabela ASCII!
void matriz_padrao(){
    int matrizp[4][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matrizp[i][j] = 0;
        }
    }

    for(int i = 0; i < 4; i++){
        printf("\n\n");
        for(int j = 0; j < 4; j++){
            if(j % 2 == 0){
            printf("(%d,", matrizp[i][j]);
            }
            else{
                printf(" %d)  ", matrizp[i][j]);
            }
        }
    }
    printf("\n");
}
