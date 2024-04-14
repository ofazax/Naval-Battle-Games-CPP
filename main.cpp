#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

const int TAMANHO_TABULEIRO = 5;
int linhaNavio, colunaNavio;

std::vector<std::vector<char>> tabuleiro(TAMANHO_TABULEIRO, std::vector<char>(TAMANHO_TABULEIRO, 'O'));

void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 'O';
        }
    }
}

void exibirTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            std::cout << tabuleiro[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void posicionarNavio() {
    linhaNavio = std::rand() % TAMANHO_TABULEIRO;
    colunaNavio = std::rand() % TAMANHO_TABULEIRO;
    tabuleiro[linhaNavio][colunaNavio] = 'N';
}

int main() {
    std::srand(std::time(nullptr));
    int palpiteLinha, palpiteColuna;
    int turno;

    inicializarTabuleiro();
    posicionarNavio();

    std::cout << "Bem-vindo ao Jogo de Batalha Naval!" << std::endl;
    std::cout << "Escolha uma linha e uma coluna de 0 a 4 para atacar." << std::endl;
  
    for (turno = 0; turno < 4; turno++) {
        std::cout << "Turno " << turno + 1 << std::endl;
        std::cout << "Adivinhe a linha: ";
        std::cin >> palpiteLinha;
        std::cout << "Adivinhe a coluna: ";
        std::cin >> palpiteColuna;

        if (palpiteLinha < 0 || palpiteLinha >= TAMANHO_TABULEIRO || palpiteColuna < 0 || palpiteColuna >= TAMANHO_TABULEIRO) {
            std::cout << "Palpite fora do tabuleiro! Tente novamente." << std::endl;
        } else if (tabuleiro[palpiteLinha][palpiteColuna] == 'X') {
            std::cout << "Você já tentou esta posição. Tente novamente." << std::endl;
        } else if (tabuleiro[palpiteLinha][palpiteColuna] == 'N') {
            std::cout << "Parabéns! Você afundou o navio!" << std::endl;
            tabuleiro[palpiteLinha][palpiteColuna] = 'X';
            exibirTabuleiro();
            break;
        } else {
            std::cout << "Você errou!" << std::endl;
            tabuleiro[palpiteLinha][palpiteColuna] = 'X';
        }
    }

    if (turno == 4) {
        std::cout << "Fim do jogo! O navio estava na linha " << linhaNavio << " e coluna " << colunaNavio << "." << std::endl;
          tabuleiro[linhaNavio][colunaNavio] = 'N';
          exibirTabuleiro();
    }
    return 0;
}

