#include <iostream>

using namespace std;

struct No {
    int data;
    No *next;
};

void buscaBinaria(No* head, int tamanho, int valorBuscado, int *encontrado) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        No* num = head;
        for (int i = 0; i < meio; i++) {
            num = num->next;
        }

        if (valorBuscado == num->data) {
            *encontrado = 1;
            cout << "O valor esta na posicao: " << meio << endl;
            inicio = meio + 1;  
        } else if (valorBuscado < num->data) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
}

void inserir(No*& head, int numero) {
    No* novoNo = new No;
    novoNo->data = numero;
    novoNo->next = NULL;

    if (head == NULL) {
        head = novoNo;
    } else {
        No* aux = head;
        while (aux->next) {
            aux = aux->next;
        }
        aux->next = novoNo;
    }
}

int main() {
    int tamanho, numero;

    cout << "Digite o tamanho do vetor:";
    cin >> tamanho;

    No* head = NULL;
    cout << "Vetor:" << endl;

    for (int i = 0; i < tamanho; i++) {
        cout << "Digite um numero: ";
        cin >> numero;
        inserir(head, numero);
    }

    int valorBuscado, encontrado = 0;
    cout << "Digite o valor a ser buscado: ";
    cin >> valorBuscado;

    buscaBinaria(head, tamanho, valorBuscado, &encontrado);

    if (encontrado == 0) {
        cout << "Valor nao encontrado!";
    }

    return 0;
}

