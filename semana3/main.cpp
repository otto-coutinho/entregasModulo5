#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable {
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < hashGroups; i++)
        sum += table[i].size();

    return sum == 0;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "Este espaco ja esta ocupado! Reposicionado." << endl;
            break;
        }
    }

    if (!keyExists) {
        cell.emplace_back(key, value);
    }
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "Item removido." << endl;
            break;
        }
    }

    if (!keyExists) {
        cout << "A posicao nao existe." << endl;
    }
}

void HashTable::printTable() {
    for (int i = 0; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "Key: " << bItr->first << "; Value: " << bItr->second << endl;
        }
    }
}

int main() {
    HashTable HT;

    if (HT.isEmpty()) {
        cout << "Resposta Correta." << endl;
    }
    else {
        cout << "Houve algum erro no codigo." << endl;
    }

  // CASO DE TESTE 1: ADICIONAR ITENS À TABELA HASH

    HT.insertItem(123, "Caneta");
    HT.insertItem(531, "Caderno");
    HT.insertItem(235, "Lapis");
    HT.insertItem(346, "Borracha");
    HT.insertItem(452, "Apontador");
    HT.insertItem(189, "Marca-texto");

  // CASO DE TESTE 2: MOSTRAR OS ITENS DA TABELA HASH

    HT.printTable();

  // CASO DE TESTE 3: REMOVER UM ITENS DA TABELA HASH

    HT.removeItem(235);
    HT.removeItem(672);

  // CASO DE TESTE 4: ATUALIZAR UM ITEM DA TABELA QUE JÁ EXISTE
  
    HT.insertItem(452, "Lapiseira");
    HT.printTable();

    if (HT.isEmpty()) {
        cout << "Resposta correta." << endl;
    }
    else {
        cout << "Houve algum erro no codigo." << endl;
    }

    return 0;
}
