#include <iostream>

using namespace std;

struct No {
	int data;
	No *next;
	
};

void exibirLista(No *head){
   No *p = head;
    cout << "\n[ ";
   
    while(p != NULL) {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << "]";
}

void inserir(No *&head, int numero) {
	No * novoNo = new No;
	novoNo -> data = numero;
	novoNo -> next = NULL;
	
	if(head == NULL) {
		head = novoNo;
		return;
	}
	
	No * aux = head;
	while(aux -> next != NULL) {
		aux = aux -> next;
	}
	
	aux -> next = novoNo;	
}

bool comparar(No* head, No* head2) {
    while(head != NULL && head2 != NULL) {
        if(head -> data != head2 -> data) {
            return false;
        }
        head = head -> next;
        head2 = head2 -> next;
    }
    return head == NULL && head2 == NULL;
}

int buscar (No* head, int valor, int &contador){
	No* numero = head;
	
	while (numero != NULL){
		if (numero->data == valor){
			contador++;
		}
		numero = numero -> next; 
	}
	
	if (contador == 0){
		cout << "O numero nao esta na lista" << endl;
	}
	else{
		cout << "O numero " << valor << " aparece " << contador << "x" << endl;
	}
	return contador;
}

int main() {
	
	int tamanho, numero;
	int contador = 0;

	cout << "Digite o numero total de itens que deseja adicionar as listas:";
	cin >> tamanho;
	
	No *head = NULL;
	cout << "Lista 1:" << endl;
	
	for(int i = 0; i < tamanho; i++){
		cout << "Digite um numero: ";
		cin >> numero;
		inserir(head, numero);
	}

	No *head2 = NULL;
	cout << "Lista 2:" << endl;
	
	for(int i = 0; i < tamanho; i++){
		cout << "Digite um numero: ";
		cin >> numero;
		inserir(head2, numero);
	}
	
	cout << endl << "Lista 1:";
	exibirLista(head);
	cout << endl;
	cout << "Lista 2:";
	exibirLista(head2);
	cout << endl << endl;

	if (comparar(head, head2)){
		cout << "As listas sao iguais." << endl;
    } else {
        cout << "As listas sao diferentes." << endl;
	}

	cout << endl << "Digite o numero que voce deseja buscar na lista 1: ";
	cin >> numero;
	buscar(head, numero, contador);


	return 0;
}
