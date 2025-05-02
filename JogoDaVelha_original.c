#include <stdio.h>
#include <stdbool.h>
//mantenha a mesma formatacao: campo = gameBoard[linha][coluna]
char gameBoard[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};

void printJogo() {
	//        [][0]  [][1]  [][2]
	printf("\n  %c  |  %c  |  %c  ", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]); // [0][]
	printf("\n-----------------");
	printf("\n  %c  |  %c  |  %c  ", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]); // [1][]
	printf("\n-----------------");
	printf("\n  %c  |  %c  |  %c  ", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]); // [2][]
}

void inserirX(int linha,int coluna) {

	while (gameBoard[linha][coluna] != ' ') { // se espaço ocupado
	    // pede nova linha/coluna
		printf("\nJogador X - digite outra linha:");
		printf("\n(0, 1 ou 2): ");
		scanf("%d", &linha);
		printf("\nLinha X: %d", linha);

		printf("\nJogador X - digite outra coluna:");
		printf("\n(0, 1 ou 2): ");
		scanf("%d", &coluna);
		printf("\nColuna X: %d", coluna);
	} 
	gameBoard[linha][coluna] = 'x';
}

void inserirO(int linha,int coluna) {

	while (gameBoard[linha][coluna] != ' ') { // se espaço ocupado
    // pede nova linha/coluna
	printf("\nJogador O - digite outra linha:");
	printf("\n(0, 1 ou 2): ");
	scanf("%d", &linha);
	printf("\nLinha O: %d", linha);

	printf("\nJogador O - digite outra coluna:");
	printf("\n(0, 1 ou 2): ");
	scanf("%d", &coluna);
	printf("\nColuna O: %d", coluna);
	} 
	gameBoard[linha][coluna] = 'o';
}
// && "and"/"e"
// || "or"/"ou"
// == "equal"/"igual"
// != diferente"
bool alguemFezLinha() {
    bool retVal = false;
    int i;
    int j;
    int l;
    int c;
    int countX;
    int countO;
    
    for (j = 0; j<3; j++){
        // prepara para nova linha
        l = j;
        countX = 0;
        countO = 0;
        
        // conta os Xs e Os para a linha 0
        for (i = 0; i < 3; i++){
          c = i;
          if (gameBoard[l][c] == 'x'){
              countX++;
          }
          if (gameBoard[l][c] == 'o'){
              countO++;
          }
        }
        
        // ve se ganhou
        if (countX == 3) {
            
            printf("\n l=%d,c=%d  X ganhou e fez linha\n", l, c);
            retVal = true;
        } 
        if (countO == 3) {
            
            printf("\nO ganhou e fez linha\n");
            retVal = true;
        } 
    }
    return retVal;
}

bool alguemFezColuna() {
    bool retVal = false;
    int i;
    int j;
    int l;
    int c;
    int countX;
    int countO;
    
    for (j = 0; j<3; j++){
        // prepara para nova linha
        c = j;
        countX = 0;
        countO = 0;
        
        // conta os Xs e Os para a linha 0
        for (i = 0; i < 3; i++){
          l = i;
          if (gameBoard[l][c] == 'x'){
              countX++;
          }
          if (gameBoard[l][c] == 'o'){
              countO++;
          }
        }
        
        // ve se ganhou
        if (countX == 3) {
            
            printf("\n l=%d,c=%d  X ganhou e fez coluna\n", l, c);
            retVal = true;
        } 
        if (countO == 3) {
            
            printf("\nO ganhou e fez coluna\n");
            retVal = true;
        } 
    }
    return retVal;
}

bool ganhouDiag() {
    bool retVal = false; // verdadeiro se alguem fez
    
    //Diagonal principal
    if ( (  (gameBoard[0][0] == 'x') && (gameBoard[1][1] == 'x')    ) && 
            (gameBoard[2][2] == 'x') ) 
    {
        printf("\nX ganhou e fez diagonal");
        retVal = true;
    } 
    
    if ( (  (gameBoard[0][0] == 'o') && (gameBoard[1][1] == 'o')    ) && 
            (gameBoard[2][2] == 'o') ) 
    {
        printf("\nO ganhou e fez diagonal");
        retVal = true;
    }
    
    //Diagonal secundaria
    if ( (  (gameBoard[0][2] == 'x') && (gameBoard[1][1] == 'x')    ) && 
            (gameBoard[2][0] == 'x') ) 
    {
        printf("\nX ganhou e fez diagonal");
        retVal = true;
    }
    
    if ( (  (gameBoard[0][2] == 'o') && (gameBoard[1][1] == 'o')    ) && 
            (gameBoard[2][0] == 'o') ) 
    {
        printf("\nO ganhou e fez diagonal");
        retVal = true;
    }
    
    return retVal;
}

int main() {

	int l, c;

	while (1) {
		//rodada 1 jogador X
		printf("\nJogador X - digite linha:");
		printf("\n(0, 1 ou 2): ");
		scanf("%d", &l);
		printf("\nLinha X: %d", l);

		printf("\nJogador X - digite coluna:");
		printf("\n(0, 1 ou 2): ");
		scanf("%d", &c);
		printf("\nColuna X: %d", c);
        
        
		inserirX(l,c);
		printJogo();
        if(alguemFezLinha() || alguemFezColuna() || ganhouDiag())
            break;

		//rodada 1 jogador O
		printf("\nJogador O - digite linha:");
		printf("\n(0, 1 ou 2): ");
		scanf("%d", &l);
		printf("\nLinha O: %d", l);

		printf("\nJogador O - digite coluna:");
		printf("\n(0, 1 ou 2): ");
		scanf("%d", &c);
		printf("\nColuna O: %d", c);

		inserirO(l,c);
		printJogo();
        if(alguemFezLinha() || alguemFezColuna() || ganhouDiag())
            break;
	}

	return 0;
}

