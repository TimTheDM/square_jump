//header file for stage_init

const int PLAYER_SIZE = 50;

class fixture {
  
};

class player {
  public:
    float acceleration;
    sf::RectangleShape pSprite;
    player();
};

std::vector<fixture>* stageInit();