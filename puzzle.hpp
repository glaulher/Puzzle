//é usada para evitar a inclusão repetida de um arquivo de cabeçalho
#pragma once

#include <SFML/Graphics.hpp>
// memory fornece recursos para gerenciamento de memória
#include<memory>
// fornece uma classe de contêiner de matriz estática./
#include<array>


class Puzzle
{
  std::shared_ptr<sf::RenderWindow> window;
  std::shared_ptr<sf::Event> event;

  sf::Texture texture;  
  int w, n, x, y, dx, dy;
  std::array<std::array<int,6>, 6>grid;
  std::array<sf::Sprite, 17>sprite; 

  protected:
    void events();
    void draw();
    void logic();

  public:
    Puzzle(const std::vector<int>&);
    void run(); 
};


// A classe Puzzle é uma classe que representa um jogo de quebra-cabeça. 
// Ela contém membros de dados privados, como window, event, texture, w, n, x, y, dx, dy, grid e sprite. 
// A classe também tem membros de função públicos, como Puzzle, run, e membros de função protegidos, como events, draw e logic.
// O construtor Puzzle recebe um vetor de inteiros como argumento e inicializa os membros de dados privados da classe.
// O método run é responsável por executar o jogo de quebra-cabeça.
// Os membros de função protegidos events, draw e logic são responsáveis por lidar com eventos, desenhar o jogo e atualizar a lógica do jogo,respectivamente.
// A classe Puzzle usa a biblioteca SFML para renderizar gráficos e lidar com eventos.
// Ela também usa a biblioteca memory para gerenciamento de memória e a biblioteca array para armazenar dados em matrizes estáticas
