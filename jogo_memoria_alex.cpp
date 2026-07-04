// Jogo da Memória - Trabalho M3
// Disciplina: Algoritmos e Programação - UNIVALI Itajaí
// Professor Responsavel: Alex Luciano Roesler Rese 
// Alunos: Jonas Olos Roslindo, Matheus Pedro Cim


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void pausar(){
    cout<<endl<<"Pressione ENTER para continuar"<<endl;
    cin.ignore();
    cin.get();
}

int main(){
    
    srand(time(NULL));
    
    int num [16], matriz[4][4];
    
    for (int i = 0; i < 16; i++) {
        num[i] = (i / 2) + 1;
    }
    
    for (int i = 15; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matriz[i][j] = num[i * 4 + j];
        }
    }
    
    
    int gabarito[4][4];
    int operacao = rand() % 4;

    if (operacao == 0) {
        // Sem modificação
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                gabarito[i][j] = matriz[i][j];

    } else if (operacao == 1) {
        // Transposta
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                gabarito[j][i] = matriz[i][j];

    } else if (operacao == 2) {
        // Invertida por linha
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                gabarito[i][j] = matriz[3 - i][j];

    } else {
        // Invertida por coluna
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                gabarito[i][j] = matriz[i][3 - j];
    }
    
    
    int jogo[4][4];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            jogo[i][j] = 0;
    
    int jogadas = 0;
    int pares   = 0;
    int lin1, col1, lin2, col2;
    
    while (jogadas < 24 && pares < 8) {

        system("clear");
        cout <<endl<<"          JOGO DA MEMÓRIA              " << endl<<endl;
        cout << "Jogadas: " << jogadas << " / 24" << endl;
        cout << "Pares  : " << pares   << " / 8"  << endl<<endl;
        cout << "      Col1  Col2  Col3  Col4"          << endl;

        for (int i = 0; i < 4; i++) {
            cout << "Lin " << (i + 1) << ": ";
            for (int j = 0; j < 4; j++) {
                if (jogo[i][j] == -1)
                    cout << " [" << gabarito[i][j] << "]  ";
                else
                    cout << " [ ]  ";
            }
            cout << endl;
        }

        
        cout <<endl<<"-- 1ª peça --" << endl;

        cout << "Linha   (1-4): ";
        cin >> lin1;
        while (cin.fail() || cin.peek() != '\n' || lin1 < 1 || lin1 > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida! Digite de 1 a 4: ";
            cin >> lin1;}
        lin1--;

        while (lin1 < 0 || lin1 > 3) {
            cout << "Linha inválida! Digite de 1 a 4: ";
            cin >> lin1;
            lin1--;
        }

        cout << "Coluna   (1-4): ";
        cin >> col1;
        while (cin.fail() || cin.peek() != '\n' || col1 < 1 || col1 > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida! Digite de 1 a 4: ";
            cin >> col1;}
        col1--;

        while (col1 < 0 || col1 > 3 || jogo[lin1][col1] == -1) {
            if (jogo[lin1][col1] == -1)
                cout << "Par já encontrado! Escolha outra peça: ";
            else
                cout << "Coluna inválida! Digite de 1 a 4: ";
            cin >> col1;
            col1--;
        }

        int valor1 = gabarito[lin1][col1];

        cout <<endl<< "          JOGO DA MEMÓRIA              " <<endl<< endl;
        cout << "Jogadas: " << jogadas << " / 24" << endl;
        cout << "Pares  : " << pares   << " / 8"  << endl<<endl;
        cout << "      Col1  Col2  Col3  Col4"          << endl;

        for (int i = 0; i < 4; i++) {
            cout << "Lin " << (i + 1) << ": ";
            for (int j = 0; j < 4; j++) {
                if (jogo[i][j] == -1)
                    cout << " [" << gabarito[i][j] << "]  ";
                else if (i == lin1 && j == col1)
                    cout << " [" << valor1 << "]  ";
                else
                    cout << " [ ]  ";
            }
            cout << endl;
        }
        cout << "1ª peça: (" << (lin1+1) << "," << (col1+1) << ") = " << valor1 << endl;

        cout <<endl<<"-- 2ª peça --" << endl;

        cout << "Linha   (1-4): ";
        cin >> lin2;
        while (cin.fail() || cin.peek() != '\n' || lin2 < 1 || lin2 > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida! Digite de 1 a 4: ";
            cin >> lin2;
        }
        cin.ignore(1000, '\n'); // limpa o \n antes de ler a coluna
        lin2--;
        
        cout << "Coluna  (1-4): ";
        cin >> col2;
        while (cin.fail() || cin.peek() != '\n' || col2 < 1 || col2 > 4 || jogo[lin2][col2-1] == -1 || (lin2 == lin1 && col2-1 == col1)) {
            cin.clear();
            cin.ignore(1000, '\n');
            if (col2 >= 1 && col2 <= 4 && jogo[lin2][col2-1] == -1)
                cout << "Par já encontrado! Escolha outra peça: ";
            else if (col2 >= 1 && col2 <= 4 && lin2 == lin1 && col2-1 == col1)
                cout << "Você já escolheu esta peça! Escolha outra: ";
            else
                cout << "Entrada inválida! Digite de 1 a 4: ";
            cin >> col2;
        }
        cin.ignore(1000, '\n');
        col2--;

        while (col2 < 0 || col2 > 3 || jogo[lin2][col2] == -1 || (lin2 == lin1 && col2 == col1)) {
            if (jogo[lin2][col2] == -1)
                cout << "Par já encontrado! Escolha outra peça: ";
            else if (lin2 == lin1 && col2 == col1)
                cout << "Você já escolheu esta peça! Escolha outra: ";
            else
                cout << "Coluna inválida! Digite de 1 a 4: ";
            cin >> col2;
            col2--;
        }

        int valor2 = gabarito[lin2][col2];
        jogadas++;

        cout << endl<<"          JOGO DA MEMÓRIA              " <<endl<< endl;
        cout << "Jogadas: " << jogadas << " / 24" << endl;
        cout << "Pares  : " << pares   << " / 8"  << endl<<endl;
        cout << "      Col1  Col2  Col3  Col4"          << endl;

        if (valor1 == valor2) {
            jogo[lin1][col1] = -1;
            jogo[lin2][col2] = -1;
            pares++;

            for (int i = 0; i < 4; i++) {
                cout << "Lin " << (i + 1) << ": ";
                for (int j = 0; j < 4; j++) {
                    if (jogo[i][j] == -1)
                        cout << " [" << gabarito[i][j] << "]  ";
                    else
                        cout << " [ ]  ";
                }
                cout << endl;
            }
            cout << "Peça 1: (" << (lin1+1) << "," << (col1+1) << ") = " << valor1 << endl;
            cout << "Peça 2: (" << (lin2+1) << "," << (col2+1) << ") = " << valor2 << endl;
            cout <<endl<< ">>> JOGADA OK! Par encontrado! <<<" << endl;

        } else {
            for (int i = 0; i < 4; i++) {
                cout << "Lin " << (i + 1) << ": ";
                for (int j = 0; j < 4; j++) {
                    if (jogo[i][j] == -1)
                        cout << " [" << gabarito[i][j] << "]  ";
                    else if ((i == lin1 && j == col1) || (i == lin2 && j == col2))
                        cout << " [" << gabarito[i][j] << "]  ";
                    else
                        cout << " [ ]  ";
                }
                cout << endl;
            }
            cout << "Peça 1: (" << (lin1+1) << "," << (col1+1) << ") = " << valor1 << endl;
            cout << "Peça 2: (" << (lin2+1) << "," << (col2+1) << ") = " << valor2 << endl;
            cout << endl<< "JOGADA INVÁLIDA! As peças são diferentes." << endl;
        }

        pausar();
        
    }
    
    cout << "             FIM DE JOGO               " << endl;
    cout << "Jogadas: " << jogadas << " / 24" << endl;
    cout << "Pares  : " << pares   << " / 8"  << endl;
    cout << "      Col1  Col2  Col3  Col4"          << endl;

    for (int i = 0; i < 4; i++) {
        cout << "Lin " << (i + 1) << ": ";
        for (int j = 0; j < 4; j++)
            cout << " [" << gabarito[i][j] << "]  ";
        cout << endl;
    }
    if (pares == 8){
        system("clear");
        cout << endl<< "PARABÉNS! VOCÊ VENCEU! " << endl;}
    else{
        system("clear");
        cout << endl <<"VOCÊ PERDEU! Mais sorte na próxima!" << endl;}

    return 0;
}