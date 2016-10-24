/* 
 * Alternativa ao rand() em C++
 * 
 * File:   main.cpp
 * Author: ronaldfalcao
 *
 * Created on 24 de Outubro de 2016, 12:40
 */

#include <cstdlib>
#include <random>
#include <functional>

using namespace std;

int main(int argc, char** argv) {

    //Usando como gerador o Mersenne Twister, pseudo-random de 32bits. 
    std::mt19937 engine;
    
    //Usando um algoritmo de distribuição contínua e uniforme, onde a probabilidade
    //de gerar um ponto é proporcional ao tamanho do intervalo. No caso, 30.
    std::uniform_int_distribution<int> distribution(1, 30);
    
    //Usando as condições descritas acima para gerar números aleatórios.
    for (int i = 0; i < 10; ++i)
        std::printf("%2d -> %1d\n", i + 1, distribution(engine));
    
    //Retornando via functor
    auto dice = std::bind(distribution, engine);

    //Usando o functor para gerar números aleatórios.
    for (int i = 0; i < 10; ++i)
        std::printf("%2d -> %1d\n", i + 1, dice());

    
    return 0;
}