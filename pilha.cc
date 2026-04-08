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
    int* pilha;
    int topo;
    int capacidade_maxima;
};

PilhaInt::PilhaInt(int cap) {
    capacidade_maxima = cap;
    pilha = (int*)malloc(capacidade_maxima * sizeof(int));
    for (int i = 0; i < capacidade_maxima; i++) {
        pilha[i] = 0;
    }
    topo = 0;
}

void PilhaInt::empilha(int valor) {
    if (topo == capacidade_maxima) {
        redimensiona(capacidade_maxima * 2);
    }
    pilha[topo] = valor;
    topo++;
}

void PilhaInt::print(std::ostream& o) {
    o << "[ ";
    for (int i = 0; i < topo; i++) {
        o << pilha[i];
        if (i < topo - 1) o << ", ";
    }
    o << " ]";
}

int PilhaInt::desempilha() {
    if (topo > 0) {
        topo--;
        return pilha[topo];
    } else {
        std::cout << "Pilha vazia!" << std::endl;
        return -1;
    }
}

PilhaInt::~PilhaInt() {
    free(pilha);
}

PilhaInt& PilhaInt::operator=(const PilhaInt& outra) {
    if (this != &outra) {
        if (this ->capacidade_maxima != outra.capacidade_maxima) {
            free(pilha);
            capacidade_maxima = outra.capacidade_maxima;
            pilha = (int*)malloc(capacidade_maxima * sizeof(int));
        }
        topo = outra.topo;
        for (int i = 0; i < topo; i++) {
            pilha[i] = outra.pilha[i];
        }
    }
    return *this;
}

PilhaInt& PilhaInt::operator<<(int valor) {
    empilha(valor);
    return *this;
}

PilhaInt::PilhaInt(const PilhaInt& outra) {
    capacidade_maxima = outra.capacidade_maxima;
    topo = outra.topo;
    pilha = (int*)malloc(capacidade_maxima * sizeof(int));
    for (int i = 0; i < topo; i++) {
        pilha[i] = outra.pilha[i];
    }
}

int PilhaInt::capacidade() {
    return capacidade_maxima;
}

void PilhaInt::redimensiona(int nova_capacidade) {
    if (nova_capacidade < topo) {
        topo = nova_capacidade;
    }
    pilha = (int*)realloc(pilha, nova_capacidade * sizeof(int));
    capacidade_maxima = nova_capacidade;
}