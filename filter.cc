#include <vector>
#include <type_traits>
#include <iterator>


template <typename Container, typename Func>
auto operator|(const Container& c, Func f) {
    
    using ElementType = std::decay_t<decltype(*std::begin(c))>;
    using RetType = std::invoke_result_t<Func, ElementType>;

    if constexpr (std::is_same_v<RetType, void>) {

        for (const auto& elemento : c) {
            f(elemento);
        }
        
    } 
    else if constexpr (std::is_same_v<RetType, bool>) {
        std::vector<ElementType> resultado;
        
        for (const auto& elemento : c) {
            if (f(elemento)) {
                resultado.push_back(elemento);
            }
        }
        
        return resultado;
    } 
    else {
        std::vector<RetType> resultado;
        
        for (const auto& elemento : c) {
            resultado.push_back(f(elemento));
        }
        return resultado;    }
}

template <typename T, typename Func>
auto operator|(std::initializer_list<T> lista, Func f) {
    
    using RetType = std::invoke_result_t<Func, T>;

    if constexpr (std::is_same_v<RetType, void>) {

        for (const auto& elemento : lista)
        {
            f(elemento);
        }
        
        
    } 
    else if constexpr (std::is_same_v<RetType, bool>) {
        std::vector<T> resultado;
        
        for (const auto& elemento : lista)
        {
            if (f(elemento)) {
                resultado.push_back(elemento);
            }
        }
        
        return resultado;
    } 
    else {
        std::vector<RetType> resultado;
        
        for (const auto& elemento : lista)
        {
            resultado.push_back(f(elemento));
        }
        
        return resultado;
    }
}