#include <SFML/Graphics.hpp>
#include "Poker.h"
#include <ctime>


int main()
{
    srand(time(NULL));

    // переменные созданы в другом файле
    extern card* player1;
    extern card* player2;
    
    // создаем экземпляр класса покер
    // количество фишек 50
    Poker poker(50);

    // перемешиваем карты
    poker.shuffleCards();

    // раздаем
    poker.game();

    // получаем кол-во фишек по ссылке
    unsigned int& nominals = poker.getNominals();

    // получаем количество карт по ссылке
    short& countСards = poker.getCountCards();
    std::string path = "G://C++//projects//gamePoker//texture//carts//";

    // проверяем сделана ставка или нет
    // с номиналами 1, 2, 3
    bool isTextureBet1 = false;
    bool isTextureBet2 = false;
    bool isTextureBet3 = false;

    // проверка на победу
    bool isWin = false;

    // проверка на поражение
    bool isLose = false;
    bool isPas = false;

    // конец игры
    bool isEnd = false;

    // начать игру
    bool startGame = false;

    // обменять карты
    bool isExc = false;

    // в этот массив добавляем позиции карт, которые собираемся менять
    short arrayExc[5]{ -1, -1, -1, -1, -1 };

    // ставка
    size_t bet{ 0 };

    // эти переменные содержат число, на которое нужно сдвинуть
    // карты, которые собираемся менять. i-ю карту сдвинет на s_i
    int8_t s1{ 0 }, s2{ 0 }, s3{ 0 }, s4{ 0 }, s5{ 0 };

    // путь к каждой карте. К каждому path будет добавляться название карты
    std::string imgCards[5]{ path, path, path, path, path };

    // создаем окно в SFML
    sf::RenderWindow window(sf::VideoMode(1100, 600), "POKER");
    while (window.isOpen())
    {
        // следующие 5 блоков кода создают спрайты карт
        imgCards[0] += std::to_string(player2[0].number);
        imgCards[0] += player2[0].card_suit + ".png";
        sf::Texture texturePlayer2Cards1;
        texturePlayer2Cards1.loadFromFile(imgCards[0]);
        sf::Sprite spritePlayer2Cards1(texturePlayer2Cards1);
        spritePlayer2Cards1.move(500, 360 - s1);
        imgCards[0] = path;

        imgCards[1] += std::to_string(player2[1].number);
        imgCards[1] += player2[1].card_suit + ".png";
        sf::Texture texturePlayer2Cards2;
        texturePlayer2Cards2.loadFromFile(imgCards[1]);
        sf::Sprite spritePlayer2Cards2(texturePlayer2Cards2);
        spritePlayer2Cards2.move(550, 360 - s2);
        imgCards[1] = path;

        imgCards[2] += std::to_string(player2[2].number);
        imgCards[2] += player2[2].card_suit + ".png";
        sf::Texture texturePlayer2Cards3;
        texturePlayer2Cards3.loadFromFile(imgCards[2]);
        sf::Sprite spritePlayer2Cards3(texturePlayer2Cards3);
        spritePlayer2Cards3.move(600, 360 - s3);
        imgCards[2] = path;

        imgCards[3] += std::to_string(player2[3].number);
        imgCards[3] += player2[3].card_suit + ".png";
        sf::Texture texturePlayer2Cards4;
        texturePlayer2Cards4.loadFromFile(imgCards[3]);
        sf::Sprite spritePlayer2Cards4(texturePlayer2Cards4);
        spritePlayer2Cards4.move(650, 360 - s4);
        imgCards[3] = path;

        imgCards[4] += std::to_string(player2[4].number);
        imgCards[4] += player2[4].card_suit + ".png";
        sf::Texture texturePlayer2Cards5;
        texturePlayer2Cards5.loadFromFile(imgCards[4]);
        sf::Sprite spritePlayer2Cards5(texturePlayer2Cards5);
        spritePlayer2Cards5.move(700, 360 - s5);
        imgCards[4] = path;

        // следующие 3 блока кода создают спрайт фишек
        sf::Texture texChip1;
        texChip1.loadFromFile("G://C++//projects//gamePoker//texture//1.png");
        sf::Sprite spriteChip1(texChip1);
        spriteChip1.move(100, 500);

        sf::Texture texChip2;
        texChip2.loadFromFile("G://C++//projects//gamePoker//texture//5.png");
        sf::Sprite spriteChip2(texChip2);
        spriteChip2.move(200, 500);

        sf::Texture texChip3;
        texChip3.loadFromFile("G://C++//projects//gamePoker//texture//10.png");
        sf::Sprite spriteChip3(texChip3);
        spriteChip3.move(300, 500);

        // спрайт-кнопка для обмена карт
        // при нажатии обменяются карты и выведется победитель
        sf::Texture texExc;
        texExc.loadFromFile("G://C++//projects//gamePoker//texture//exchange.png");
        sf::Sprite spriteExc(texExc);
        spriteExc.move(900, 400);

        // бросить карты
        sf::Texture texPas;
        texPas.loadFromFile("G://C++//projects//gamePoker//texture//pas.png");
        sf::Sprite spritePas(texPas);
        spritePas.move(900, 350);

        // спрайт для победы
        sf::Texture texWin;
        texWin.loadFromFile("G://C++//projects//gamePoker//texture//win.png");
        sf::Sprite spriteWin(texWin);
        spriteWin.move(300, 65);

        // спрайт чтобы продолжить
        sf::Texture texContinue;
        texContinue.loadFromFile("G://C++//projects//gamePoker//texture//continue.png");
        sf::Sprite spriteContinue(texContinue);
        spriteContinue.move(100, 165);

        // спрайт чтобы закончить игру
        sf::Texture texEnd;
        texEnd.loadFromFile("G://C++//projects//gamePoker//texture//end.png");
        sf::Sprite spriteEnd(texEnd);
        spriteEnd.move(100, 265);

        // спрайт чтобы начать игру
        sf::Texture texGameStart;
        texGameStart.loadFromFile("G://C++//projects//gamePoker//texture//startGame.png");
        sf::Sprite spriteGameStart(texGameStart);
        spriteGameStart.move(450, 300);

        // спрайт конца игры, когда закончились фишки
        sf::Texture texGameOver;
        texGameOver.loadFromFile("G://C++//projects//gamePoker//texture//endGame.jpg");
        sf::Sprite spriteEndGame(texGameOver);
        spriteEndGame.move(350, 100);
        
        // переменная сбвигает карты, чтобы он  накладывались друг на друга
        int8_t k = 0;

        // события
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие окна
            if (event.type == sf::Event::Closed)
                window.close();
            // если нажали на кнопку мыши
            if (event.type == sf::Event::MouseButtonPressed)
                // а именно левую
                if (event.key.code == sf::Mouse::Left)
                { 
                    // далее проверяем на какой именно спрайт сделано нажатие
                    if (spriteGameStart.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        startGame = true;
                        isWin = false;
                        isLose = false;
                        isExc = false;
                        bet = 0;
                        countСards = 52;
                        poker.shuffleCards();
                        poker.game();
                    }

                    if (spriteEndGame.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        startGame = true;
                        isWin = false;
                        isLose = false;
                        isExc = false;
                        bet = 0;
                        countСards = 52;
                        nominals = 50;
                        poker.shuffleCards();
                        poker.game();
                    }

                    // если нажали на карту, чтобы сдвинуть для обмена
                    // то сохраняем прежние позиции, чтобы при клике 
                    // на одну карту не сдвигалась вместе с ней другая
                    // так как карты накладываются друг на друга
                    int8_t x1 = s1, x2 = s2, x3 = s3, x4 = s4, x5 = s5;

                    // также с массивами. сохраняем прежние значения массива
                    // чтобы при клике на одну карту не добавилась позиция другой карты
                    int8_t y1 = arrayExc[0], y2 = arrayExc[1];
                    int8_t y3 = arrayExc[2], y4 = arrayExc[3], y5 = arrayExc[4];
                    if (spritePlayer2Cards1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        // сдвигаем только ту на которую нажали
                        // а значения остальных оставляем прежними
                        if (s1 == 0)
                        {
                            s1 += 20;
                            arrayExc[0] = 0;
                        }
                        else
                        {
                            s1 -= 20;
                            arrayExc[0] = -1;
                        }
                        s2 = x2;
                        s3 = x3;
                        s4 = x4;
                        s5 = x5;
                        arrayExc[1] = y2, arrayExc[2] = y3, arrayExc[3] = y4, arrayExc[4] = y5;
                    }
                    if (spritePlayer2Cards2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        if (s2 == 0)
                        {
                            s2 += 20;
                            arrayExc[1] = 1;
                        }
                        else
                        {
                            s2 -= 20;
                            arrayExc[1] = -1;
                        }
                        s1 = x1;
                        s3 = x3;
                        s4 = x4;
                        s5 = x5;
                        arrayExc[0] = y1, arrayExc[2] = y3, arrayExc[3] = y4, arrayExc[4] = y5;
                    }
                    if (spritePlayer2Cards3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        if (s3 == 0)
                        {
                            s3 += 20;
                            arrayExc[2] = 2;
                        }
                        else
                        {
                            s3 -= 20;
                            arrayExc[2] = -1;
                        }
                        s1 = x1;
                        s2 = x2;
                        s4 = x4;
                        s5 = x5;
                        arrayExc[0] = y1, arrayExc[1] = y2, arrayExc[3] = y4, arrayExc[4] = y5;
                    }
                    if (spritePlayer2Cards4.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        if (s4 == 0)
                        {
                            s4 += 20;
                            arrayExc[3] = 3;
                        }
                        else
                        {
                            s4 -= 20;
                            arrayExc[3] = -1;
                        }
                        s1 = x1;
                        s2 = x2;
                        s3 = x3;
                        s5 = x5;
                        arrayExc[0] = y1, arrayExc[1] = y2, arrayExc[2] = y3, arrayExc[4] = y5;
                    }
                    if (spritePlayer2Cards5.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        if (s5 == 0)
                        {
                            s5 += 20;
                            arrayExc[4] = 4;
                        }
                        else
                        {
                            s5 -= 20;
                            arrayExc[4] = -1;
                        }
                        s1 = x1;
                        s2 = x2;
                        s3 = x3;
                        s4 = x4;
                        arrayExc[0] = y1, arrayExc[1] = y2, arrayExc[2] = y3, arrayExc[3] = y4;
                    }

                    // если нажали на фишки, то выполняется ставка
                    if (spriteChip1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        int i = nominals - 1;
                        if (i >= 0)
                        {
                            nominals -= 1;
                            bet += 1;
                            isTextureBet1 = true;
                        }  
                    }
                    if (spriteChip2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        int i = nominals - 5;
                        if (i >= 0)
                        {
                            nominals -= 5;
                            bet += 5;
                            isTextureBet2 = true;
                        }
                    }
                    if (spriteChip3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        int i = nominals - 10;
                        if (i >= 0)
                        {
                            nominals -= 10;
                            bet += 10;
                            isTextureBet3 = true;
                        }
                    }

                    // если сделана ставка, то можем обменять карты и вывить победителя
                    if(isTextureBet1 || isTextureBet2 || isTextureBet3)
                    if (spriteExc.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        // обмен карт
                        poker.exchange(arrayExc);

                        // зануляем заново все s_i-ые после обмена
                        s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;

                        // присваем заново элементам массива -1 после обмена
                        arrayExc[0] = -1, arrayExc[1] = -1, arrayExc[2] = -1, arrayExc[3] = -1, arrayExc[4] = -1;

                        // проверяем чьи карты лучше
                        short result1 = poker.combinations(player1);
                        short result2 = poker.combinations(player2);

                        // в этом случае я выграл
                        if (result2 > result1)
                        {
                            isWin = true;
                            nominals += 2 * bet;
                        }
                        // проиграл
                        else isLose = true;

                        isExc = true;

                        // убераем ставку
                        isTextureBet1 = false;
                        isTextureBet2 = false;
                        isTextureBet3 = false;
                    }
                    // если игра продолжается, то устанавливаем прежние счетчики
                    // размешиваем карты и раздаем игрокам
                    if (spriteContinue.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        isWin = false;
                        isLose = false;
                        isExc = false;
                        bet = 0;
                        countСards = 52;
                        poker.shuffleCards();
                        poker.game();
                    }

                    // если сделана ставка и карты плохие
                    // то бросаем их
                    if (isTextureBet1 || isTextureBet2 || isTextureBet3)
                    if (spritePas.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        isLose = true;
                    }
                    // если нажали на закончить
                    if (spriteEnd.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        startGame = false;
                        isWin = false;
                        isLose = false;
                        isPas = false;
                        isEnd = false;
                    }
                }
        }
        window.clear(sf::Color(0, 95, 18));

        // если игра начата
        if (startGame)
        {
            sf::CircleShape circle(50.f);
            circle.setFillColor(sf::Color::Red);
            circle.move(500, 250);
            window.draw(circle);

            // рисуем карты соперника
            // во время игры отображается внешняя сторона карт
            // когда смотрим карты внутренняя
            if (!isExc)
                for (int8_t i = 0; i < 5; ++i)
                {
                    sf::Texture texture;
                    texture.loadFromFile("G://C++//projects//gamePoker//texture//outsideCard.png", sf::IntRect(0, 0, 140, 240));
                    sf::Sprite sprite(texture);
                    sprite.move(500 + i * 50, 0);
                    window.draw(sprite);

                }
            else
            {
                for (int8_t i = 0; i < 5; ++i)
                {
                    imgCards[i] += std::to_string(player1[i].number);
                    imgCards[i] += player1[i].card_suit + ".png";

                    sf::Texture texture;
                    texture.loadFromFile(imgCards[i], sf::IntRect(0, 0, 140, 240));
                    sf::Sprite sprite(texture);
                    sprite.move(500 + i * 50, 0);
                    window.draw(sprite);
                    imgCards[i] = path;
                }
            }

            // отображается фишка с номиналом 1
            window.draw(spriteChip1);

            // отображается ставка с номиналом 1
            if (isTextureBet1)
            {
                sf::Texture texChp1;
                texChp1.loadFromFile("G://C++//projects//gamePoker//texture//1.png");
                sf::Sprite spriteChp1(texChp1);
                spriteChp1.move(550, 250);
                window.draw(spriteChp1);
            }

            // отображается фишка с номиналом 5
            window.draw(spriteChip2);

            // отображается ставка с номиналом 5
            if (isTextureBet2)
            {
                sf::Texture texChp;
                texChp.loadFromFile("G://C++//projects//gamePoker//texture//5.png");
                sf::Sprite spriteChp(texChp);
                spriteChp.move(600, 250);
                window.draw(spriteChp);
            }

            // отображается фишка с номиналом 10
            window.draw(spriteChip3);

            // отображается ставка с номиналом 10
            if (isTextureBet3)
            {
                sf::Texture texChp;
                texChp.loadFromFile("G://C++//projects//gamePoker//texture//10.png");
                sf::Sprite spriteChp(texChp);
                spriteChp.move(650, 250);
                window.draw(spriteChp);
            }

            // отображаем свои мои карты        
            window.draw(spritePlayer2Cards1);

            window.draw(spritePlayer2Cards2);

            window.draw(spritePlayer2Cards3);

            window.draw(spritePlayer2Cards4);

            window.draw(spritePlayer2Cards5);

            // устанавливаем шрифт
            sf::Font font;
            font.loadFromFile("fonts//Impact_Regular.ttf");

            // отображаем колчество денег
            std::string nom = std::to_string(nominals);
            sf::Text text;
            text.setFont(font);
            text.setString(nom);
            text.setCharacterSize(40);
            text.setPosition(900, 500);
            window.draw(text);

            // отображаем ставку
            std::string nom2 = std::to_string(bet);
            sf::Text txt;
            txt.setFont(font);
            txt.setString(nom2);
            txt.setCharacterSize(40);
            txt.setPosition(800, 275);
            window.draw(txt);

            // отобрааем колоду
            for (int8_t i = 0; i < 5; ++i)
            {
                sf::Texture texture;
                texture.loadFromFile("G://C++//projects//gamePoker//texture//outsideCard.png", sf::IntRect(0, 0, 140, 240));
                sf::Sprite sprite(texture);
                sprite.move(100 + i, 160 + i);
                window.draw(sprite);
            }

            // отображаем обмен и пас
            window.draw(spriteExc);
            window.draw(spritePas);

            // победа
            if (isWin)
            {
                window.draw(spriteContinue);
                window.draw(spriteEnd);
                window.draw(spriteWin);
            }

            // проигрышь
            sf::Texture texLose;
            texLose.loadFromFile("G://C++//projects//gamePoker//texture//lose.png");
            sf::Sprite spriteLose(texLose);
            spriteLose.move(300, 100);
            if (isLose)
            {
                window.draw(spriteLose);
                window.draw(spriteContinue);
                window.draw(spriteEnd);
            }
        }
        else
        {
            window.draw(spriteGameStart);
        }

        // если фишки закончились, то игра окончена
        if (isLose && !nominals)
        {
            window.draw(spriteEndGame);
        }

        window.display();
    }


    return 0;
}