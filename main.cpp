#include "header.h"

int main() {

    //Инициализация переменных и спрайтов
    int f = 0;
    int step[4];
    int p = 0;
    int ip,jp;
    int s = 1;
    int map[8][8] = {
            {0, 1, 0, 1, 0, 1, 0, 1},
            {1, 0, 1, 0, 1, 0, 1, 0},
            {0, 1, 0, 1, 0, 1, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {2, 0, 2, 0, 2, 0, 2, 0},
            {0, 2, 0, 2, 0, 2, 0, 2},
            {2, 0, 2, 0, 2, 0, 2, 0}
    };
    Font font;//шрифт
    font.loadFromFile("word.ttf");//передаем нашему шрифту файл шрифта
    Text text("", font, 40);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
    text.setColor(Color::Blue);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    Text text1("",font,40);
    text1.setColor(Color::Blue);




    RenderWindow window(VideoMode(800, 850), "Checkers");
    Image deskimage;
    Image black;
    Image white;
    Image black_dam;
    Image white_dam;
    Image blackwin;
    Image whitewin;
    Image draw;
    black.loadFromFile("Image/black.png");
    black.createMaskFromColor(Color(255, 255, 255));

    draw.loadFromFile("Image/Draw.png");

    white.loadFromFile("Image/white.png");
    white.createMaskFromColor(Color(255,255,255));

    white_dam.loadFromFile("Image/white-dam.png");
    white_dam.createMaskFromColor(Color(255,255,255));

    whitewin.loadFromFile("Image/Whitew.png");
    //whitewin.createMaskFromColor(Color(255,255,255));

    black_dam.loadFromFile("Image/black-dam.png");
    black_dam.createMaskFromColor(Color(255,255,255));

    blackwin.loadFromFile("Image/Blackw.png");
   // blackwin.createMaskFromColor(Color(255,255,255));

    deskimage.loadFromFile("Image/Desk.png");
    Texture desktexture;
    desktexture.loadFromImage(deskimage);

    Texture blacktexture;
    blacktexture.loadFromImage(black);
    Sprite blacksprite;
    blacksprite.setTexture(blacktexture);

    Texture drawtexture;
    drawtexture.loadFromImage(draw);
    Sprite drawsprite;
    drawsprite.setTexture(drawtexture);

    Texture whitetexture;
    whitetexture.loadFromImage(white);
    Sprite whitesprite;
    whitesprite.setTexture(whitetexture);

    Texture WhiteWinTexture;
    WhiteWinTexture.loadFromImage(whitewin);
    Sprite WhiteWinSprite;
    WhiteWinSprite.setTexture(WhiteWinTexture);

    Texture BlackWinTexture;
    BlackWinTexture.loadFromImage(blackwin);
    Sprite BlackWinSprite;
    BlackWinSprite.setTexture(BlackWinTexture);

    Texture blacktexture_dam;
    blacktexture_dam.loadFromImage(black_dam);
    Sprite blacksprite_dam;
    blacksprite_dam.setTexture(blacktexture_dam);

    Texture whitetexture_dam;
    whitetexture_dam.loadFromImage(white_dam);
    Sprite whitesprite_dam;
    whitesprite_dam.setTexture(whitetexture_dam);

    Sprite desksprite;
    desksprite.setTexture(desktexture);


    int t = 0;
    printf("Choose the match length:\n"
           "1. Blitz - 5 minutes\n"
           "2. Fast checkers (Rapid) - 15 minutes\n"
           "3. Classic - 45 minutes\n");
    scanf("%d",&t);

    int r = 0;
    printf("Choose the rules:\n"
           "1. Classic\n"
           "2. Feeding\n");
    scanf("%d",&r);

    WhiteWinSprite.setPosition(225,325);
    BlackWinSprite.setPosition(225,325);
    drawsprite.setPosition(225,325);

    Time time;

    //Игровой цикл
    Clock clock;
    while (window.isOpen())
    {
        if(WinCheck(map) != 0)
        {
            if(WinCheck(map) == 2)
            {
                if(r == 1)
                {
                    window.draw(BlackWinSprite);
                    window.display();
                    sleep(seconds(5));
                    window.close();
                } else{
                    window.draw(WhiteWinSprite);
                    window.display();
                    sleep(seconds(5));
                    window.close();
                }

            }
            else
            {
                if(r == 1)
                {
                    window.draw(WhiteWinSprite);
                    window.display();
                    sleep(seconds(5));
                    window.close();
                } else
                {
                    window.draw(BlackWinSprite);
                    window.display();
                    sleep(seconds(5));
                    window.close();
                }

            }
        }
        time = clock.getElapsedTime();
        switch (t) {
            case 1:
                if (time.asSeconds() > 5*60) {

                    if(r == 1)
                    {
                        if(WhiteCount(map) > BlackCount(map))
                            window.draw(WhiteWinSprite);
                        else if(WhiteCount(map) < BlackCount(map))
                            window.draw(BlackWinSprite);
                        else
                            window.draw(drawsprite);
                    } else{
                        if(WhiteCount(map) > BlackCount(map))
                            window.draw(BlackWinSprite);
                        else if(WhiteCount(map) < BlackCount(map))
                            window.draw(WhiteWinSprite);
                        else
                            window.draw(drawsprite);
                    }



                        window.display();
                        sleep(seconds(5));
                        window.close();

                }
                break;
            case 2:
                if (time.asSeconds() > 15 * 60) {
                    if(r == 1)
                    {
                        if(WhiteCount(map) > BlackCount(map))
                            window.draw(WhiteWinSprite);
                        else if(WhiteCount(map) < BlackCount(map))
                            window.draw(BlackWinSprite);
                        else
                            window.draw(drawsprite);
                    } else{
                        if(WhiteCount(map) > BlackCount(map))
                            window.draw(BlackWinSprite);
                        else if(WhiteCount(map) < BlackCount(map))
                            window.draw(WhiteWinSprite);
                        else
                            window.draw(drawsprite);
                    }

                    window.display();
                    sleep(seconds(5));
                    window.close();

                    window.close();
                }
                break;
            case 3:
                if(time.asSeconds() > 45 * 60)
                {
                    if(r == 1)
                    {
                        if(WhiteCount(map) > BlackCount(map))
                            window.draw(WhiteWinSprite);
                        else if(WhiteCount(map) < BlackCount(map))
                            window.draw(BlackWinSprite);
                        else
                            window.draw(drawsprite);
                    } else{
                        if(WhiteCount(map) > BlackCount(map))
                            window.draw(BlackWinSprite);
                        else if(WhiteCount(map) < BlackCount(map))
                            window.draw(WhiteWinSprite);
                        else
                            window.draw(drawsprite);
                    }

                    window.display();
                    sleep(seconds(5));
                    window.close();

                    window.close();
                }
            default:
                if(time.asSeconds() > 45 * 60)
                {
                    if(r == 1)
                    {
                        if(WhiteCount(map) > BlackCount(map))
                            window.draw(WhiteWinSprite);
                        else if(WhiteCount(map) < BlackCount(map))
                            window.draw(BlackWinSprite);
                        else
                            window.draw(drawsprite);
                    } else{
                        if(WhiteCount(map) > BlackCount(map))
                            window.draw(BlackWinSprite);
                        else if(WhiteCount(map) < BlackCount(map))
                            window.draw(WhiteWinSprite);
                        else
                            window.draw(drawsprite);
                    }

                    window.display();
                    sleep(seconds(5));
                    window.close();

                    window.close();
                }
                break;
        }

        Event event;
        while (window.pollEvent(event))
        {
            if(event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonPressed)
            {
                printf("Check: %d\n",KillCheck(map,s));
                printf("Turn: %d\n",s);
                printf("Queen: %d\n",QueenCheck(map,s));

                ip = Mouse::getPosition(window).y/100;
                jp = Mouse::getPosition(window).x/100;

                if(IsChecker(ip,jp,map))
                {
                    f = IsChecker(ip,jp,map);
                    step[p] = ip;
                    step[p+1] = jp;
                    continue;
                }

                    p+=2;
                    step[p] = ip;
                    step[p+1] = jp;
                    if(p > 0)
                    {
                        p = 0;
                        if(f == s && !(kill(map, step, &s)) && !KillCheck(map,s) && !QueenCheck(map,s))
                            Step(step,map, &s);
                    }
            }


            if(event.type == Event::Closed)
                window.close();
        }

        window.clear();
        //Отрисовка доски
        window.draw(desksprite);

        //рисую этот текст
        window.draw(text1);
        Queen(map);
        //Цикл отрисовки шашек
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(map[j][i] == 1)
                {
                    whitesprite.setPosition(i*100,j*100);
                    window.draw(whitesprite);
                }
                if(map[j][i] == 2)
                {
                    blacksprite.setPosition(i*100,j*100);
                    window.draw(blacksprite);
                }
                if(map[j][i] == 3)
                {
                    whitesprite_dam.setPosition(i*100,j*100);
                    window.draw(whitesprite_dam);
                }
                if(map[j][i] == 4)
                {
                    blacksprite_dam.setPosition(i*100,j*100);
                    window.draw(blacksprite_dam);
                }


            }
        }

        ostringstream playerScoreString;    // объявили переменную
        playerScoreString << 12 - BlackCount(map);		//занесли в нее число очков, то есть формируем строку
        text.setString("White - " + playerScoreString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()
        text.setPosition(20,800);//задаем позицию текста, отступая от центра камеры
        window.draw(text);

        ostringstream playerScoreString1;    // объявили переменную
        playerScoreString1 << 12 - WhiteCount(map);		//занесли в нее число очков, то есть формируем строку
        text1.setString("Black - " + playerScoreString1.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()
        text1.setPosition(600,800);//задаем позицию текста, отступая от центра камеры

        window.display();
    }

    return 0;
}