template <typename Container, typename Func>
void operator|(Container& c, Func f) {
    
    for (auto& elemento : c) {
        f(elemento);
    }
    
}

template <typename T, typename Func>
void operator|(std::initializer_list<T> lista, Func f) {
    
    for (const auto& elemento : lista) {
        f(elemento);
    }
    
}