//header file for stage_init

const int PLAYER_SIZE = 50;

class fixture {
  public:
    sf::RectangleShape platform;
    sf::Sprite hazard;
    bool isHazard;
    bool isWinPoint;
    fixture(bool, bool, sf::Texture&, sf::Vector2f&);
    sf::RectangleShape* getPlatform();
    sf::Sprite* getHazard();
};

class player {
  public:
    float acceleration;
    sf::RectangleShape pSprite;
    player();
};

std::vector<fixture>* stageInit();