
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}
	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	if (posicaoElemento(novo->valor) != NULL) {
		cout << "Esse valor j� se encontra na lista\n";
		return;
	}
	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		// procura o final da lista
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void excluirElemento()
{
	int valueToDelete = 0;
	cout << "Digite o valor a ser deletado: \n";
	cin >> valueToDelete;
	NO* knotToDelete = posicaoElemento(valueToDelete);
	if (knotToDelete == NULL || primeiro == NULL) {
		cout << "O valor nao foi encontrado para ser deletado ou a lista está vazia\n";
		return;
	}
	if (knotToDelete->prox != NULL) {
		NO* knotToSearch = primeiro;
		NO* previousKnot = NULL;
		while (knotToSearch->valor != valueToDelete && knotToSearch->prox != NULL) {
			previousKnot = knotToSearch;
			knotToSearch = knotToSearch->prox;
		}
		if(previousKnot == NULL){ //caso onde precisamos deletar o primeiro elemento
			primeiro = primeiro->prox;
			return;
			if(knotToSearch->prox == NULL){ //caso onde precisamos deletar o único elemento da lista
				primeiro = NULL;
				return;
			}
		}
		if(knotToSearch->prox == NULL){//caso onde precisamos deletar o útlimo elemento
			previousKnot->prox = NULL;
			free(knotToSearch);
			return;
		}
		previousKnot->prox = knotToSearch->prox;
		free(knotToSearch);
		cout << "Lista atual\n";
		exibirElementos();
  }
}
void buscarElemento()
{	
	int valueToFind = 0;
	cout << "Digite um valor para ser buscado: ";
	cin >> valueToFind;

	NO* result = posicaoElemento(valueToFind);

	if (result != NULL) {
		cout << "O valor foi encontrado\n";
		return;
	}
	cout << "O valor nao foi encontrado\n";
}


// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}