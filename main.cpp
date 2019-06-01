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

    RenderWindow window(VideoMode(800, 800), "Checkers");
    Image deskimage;
    Image black;
    Image white;
    Image black_dam;
    Image white_dam;
    black.loadFromFile("Image/black.png");
    black.createMaskFromColor(Color(255, 255, 255));

    white.loadFromFile("Image/white.png");
    white.createMaskFromColor(Color(255,255,255));

    white_dam.loadFromFile("Image/white-dam.png");
    white_dam.createMaskFromColor(Color(255,255,255));

    black_dam.loadFromFile("Image/black-dam.png");
    black_dam.createMaskFromColor(Color(255,255,255));

    deskimage.loadFromFile("Image/Desk.png");
    Texture desktexture;
    desktexture.loadFromImage(deskimage);

    Texture blacktexture;
    blacktexture.loadFromImage(black);
    Sprite blacksprite;
    blacksprite.setTexture(blacktexture);

    Texture whitetexture;
    whitetexture.loadFromImage(white);
    Sprite whitesprite;
    whitesprite.setTexture(whitetexture);

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






    //Игровой цикл

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if(event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonPressed)
            {
                printf("Check: %d\n",KillCheck(map,s));
                printf("Turn: %d\n",s);

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
                        if(f == s && !(kill(map,step, &s)) && !KillCheck(map,s))
                            Step(step,map, &s);
                    }
            }


            if(event.type == Event::Closed)
                window.close();
        }


        //Отрисовка доски
        window.draw(desksprite);

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
            }
        }


        window.display();
    }

    return 0;
}