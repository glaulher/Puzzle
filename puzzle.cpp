#include "puzzle.hpp"


Puzzle::Puzzle(const std::vector<int>& nums){
  window = std::make_shared<sf::RenderWindow>(
    sf::VideoMode(512, 512),
    "Puzzle::Remix",
    sf::Style::Titlebar | sf::Style::Close
  );
  window->setPosition(sf::Vector2i(50, 50));
  window->setFramerateLimit(60);
  event = std::make_shared<sf::Event>();

  texture.loadFromFile("./assets/puzzle.png");
    
  w = {128}; n = x = y = dx = dy = {0};

  grid = {0};
  for (size_t i {}; i < 4; ++i) {
    for (size_t j{}; j < 4; ++j) {
      ++n;
      sprite[n].setTexture(texture);
      sprite[n].setTextureRect(sf::IntRect(i*w, j*w, w, w)); 
      grid[i + 1][j + 1] = nums[n - 1];
    }
  
  } 
}

void Puzzle::events(){
  while(window->pollEvent(*event)){
    if(event->type == sf::Event::Closed){
      window->close();
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      this->logic();
    }
  }
}

void Puzzle::draw(){
  window->clear(sf::Color::Black);
 for (size_t i {}; i < 4; ++i) {
    for (size_t j{}; j < 4; ++j) {
      n = grid[i + 1][j + 1];
      sprite[n].setPosition(i * w, j * w);
      window->draw(sprite[n]);
    }
  
  }
  window->display();  
}

void Puzzle::logic(){
  sf::Vector2i pos = sf::Mouse::getPosition(*window);
  this->x = pos.x / w + 1;
  this->y = pos.y / w + 1;
  // std::cout << "Você clicou no " << grid[y][x] << '\n';
  
  if(grid[x + 1][y] == 16){
    dx = 1;
  }

  if(grid[x - 1][y] == 16){
    dx = -1;
  }

  if(grid[x][y + 1] == 16){
    dy = 1;
  }

  if(grid[x][y - 1] == 16){
    dy = -1;
  }

  n = grid[x][y];
  grid[x][y] = 16;
  grid[x + dx][y + dy] = n;
  dx = 0; dy = 0;
}

void Puzzle::run(){
  while(window->isOpen()){
    this->events();
    this->draw();
  }
}

// Puzzle em C++ tem três métodos: Puzzle::Puzzle, Puzzle::events e Puzzle::draw.
// O método Puzzle::Puzzle é um construtor que recebe um vetor de inteiros chamado nums como argumento.
// Ele inicializa uma janela de renderização do SFML com dimensões 512x512 pixels, define o título da janela
// como “Puzzle::Remix” e define o estilo da janela como Titlebar | Close.
// Em seguida, ele carrega uma textura de imagem de um arquivo chamado puzzle.png e define a largura da grade como 128 pixels.
// Ele também inicializa várias variáveis, incluindo n, x, y, dx, dy e grid. Em seguida,
// ele itera sobre os elementos do vetor nums e inicializa a grade com os valores do vetor.
// O método Puzzle::events é um loop que processa eventos de entrada do usuário, como fechar a janela ou clicar no botão esquerdo do mouse.
// Se o botão esquerdo do mouse for clicado, ele chama o método Puzzle::logic.
// O método Puzzle::draw desenha a grade na janela de renderização.
// Ele itera sobre os elementos da grade e define a posição de cada sprite na grade.
// Em seguida, ele desenha cada sprite na janela de renderização e exibe a janela.
// O método Puzzle::logic atualiza a posição do sprite selecionado com base na posição do mouse.
// Ele verifica se o sprite selecionado pode ser movido para a esquerda,
// direita ou para baixo e atualiza a posição do sprite selecionado de acordo.
