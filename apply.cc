template <typename Colecao, typename Funcao>
auto apply(const Colecao& c, Funcao f) {
    
    using TipoRetorno = decltype(f(*std::begin(c))); 
    std::vector<TipoRetorno> resultado;
    
    for (const auto& item : c) {
        resultado.push_back(f(item));
    }
    return resultado;
}

template <typename T, typename Funcao>
auto apply(const std::initializer_list<T>& c, Funcao f) {
        using TipoRetorno = decltype(f(*std::begin(c))); 
    std::vector<TipoRetorno> resultado;
    
    for (const auto& item : c) {
        resultado.push_back(f(item));
    }
    return resultado;
}