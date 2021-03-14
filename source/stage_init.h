//header file for stage_init

const int PLAYER_SIZE = 50;

class fixture {
  private:
    sf::RectangleShape platform;
    sf::Sprite hazard;
  public:
    bool isHazard;
    bool isWinPoint;
    fixture(bool, bool, sf::Texture&, sf::Vector2f&);
};

class player {
  public:
    float acceleration;
    sf::RectangleShape pSprite;
    player();
};

std::vector<fixture>* stageInit();