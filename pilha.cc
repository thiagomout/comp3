#include <vector>
#include <iostream>

class PilhaInt {
    public:
    PilhaInt(int cap = 10);
    PilhaInt(const PilhaInt& outra);
    ~PilhaInt();

    void empilha(int valor);
    int desempilha();
    void print(std::ostream& o);
    int capacidade();
    void redimensiona(int nova_capacidade);
    
    PilhaInt& operator=(const PilhaInt& outra);
    PilhaInt& operator<<(int valor);

    private:
    std::vector<int> pilha;
};

PilhaInt::PilhaInt(int cap) {
    pilha.reserve(cap);
}

void PilhaInt::empilha(int valor) {
    if (pilha.size() == pilha.capacity()) {
        redimensiona(pilha.capacity() * 2);
    }
    pilha.push_back(valor);
}

void PilhaInt::print(std::ostream& o) {
    o << "[ ";
    for (size_t i = 0; i < pilha.size(); i++) {
        o << pilha[i];
        if (i < pilha.size() - 1) o << ", ";
    }
    o << " ]";
}

int PilhaInt::desempilha() {
    if (!pilha.empty()) {
        int valor = pilha[pilha.size() - 1];
        pilha.pop_back();
        return valor;
    } else {
        std::cout << "Pilha vazia!" << std::endl;
        return -1;
    }
}

PilhaInt::~PilhaInt() {
}

PilhaInt& PilhaInt::operator=(const PilhaInt& outra) {
if (this != &outra) {
        std::vector<int> copia_exata;
        copia_exata.reserve(outra.pilha.capacity());
        copia_exata.assign(outra.pilha.begin(), outra.pilha.end());
        pilha.swap(copia_exata);
    }
    return *this;
}

PilhaInt& PilhaInt::operator<<(int valor) {
    empilha(valor);
    return *this;
}

PilhaInt::PilhaInt(const PilhaInt& outra) {
    pilha = outra.pilha;
}

int PilhaInt::capacidade() {
    return pilha.capacity();
}

void PilhaInt::redimensiona(int nova_capacidade) {
    if (nova_capacidade < (int)pilha.size()) {
         pilha.resize(nova_capacidade);
    }
    std::vector<int> temp;
    temp.reserve(nova_capacidade);
    temp.assign(pilha.begin(), pilha.end());
    pilha.swap(temp);
}