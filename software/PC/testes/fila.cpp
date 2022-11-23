#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	queue <string> cartas;
	cartas.push("test3");
	cartas.push("test1");
	cartas.push("test2");


	cout << "tamanho da fila: " << cartas.size() << endl;
	cout << "primeira: " << cartas.front() << endl;
	cout << "ultima: " << cartas.back() << endl;

	return 0;
}