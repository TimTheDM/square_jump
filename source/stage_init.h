//header file for stage_init

const int PLAYER_SIZE = 50;
const int STAGE_TOTAL = 1;

class fixture {
  public:
    sf::RectangleShape platform;
    sf::Sprite hazard;
    bool isHazard;
    bool isWinPoint;
    fixture(bool, bool, sf::Texture&, int, int, int, int);
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
std::vector<fixture> collisionPlayground();