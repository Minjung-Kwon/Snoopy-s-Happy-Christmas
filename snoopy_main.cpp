/*
*
*   Snoopy's Happy Christmas
*
*   2021.12.04
*
*   Kwon Minjing
*   Kim Sunjae
*   Jung Woojin
*
*
*/




#define _CRT_SECURE_NO_WARNINGS

#include <bangtal>
#include <iostream>
#include <stdio.h>
#include <time.h>


using namespace bangtal;
using namespace std;

int main_score = 0;


ScenePtr startScene, mainScene, endScene, end2Scene;

ObjectPtr main_button1, main_button2, main_button3, main_button4, main_button5;
ObjectPtr startcartoon[15], main_intro, endcartoon[4];

SoundPtr BGM1, BGM2, BGM3;



extern void letter_init();

extern void coloring_init();

extern void piano_init();

extern void pizza_init();

extern void hanoi_init();


void init_intro();


// ó�� ���� ����
void bgm1_start()
{
    BGM1 = Sound::create("main_sounds/intro.mp3");
    BGM1->play();
}


// ũ�������� ���� . ���� �޴� �뷡
void bgm2_start()
{
    BGM2 = Sound::create("main_sounds/jinglebell.mp3");
    BGM2->play();
}


// ũ�������� ���� . ���� �޴� �뷡
void bgm3_start()
{
    BGM3 = Sound::create("main_sounds/final.mp3");
    BGM3->play();
}





void end2_scene()
{
    end2Scene->enter();

    auto end_button = Object::create("main_images/snoopy-main_end.png", end2Scene, 500, 50);
    end_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        // ���� ��ü ����
        endGame();


        return true;
    });

    /*
    auto restart_button = Object::create("main_images/snoopy-main_restart.png", end2Scene, 700, 50);
    restart_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        // ���� �����
        BGM3->stop();
        startScene->enter();
        init_intro();


        return true;
    });
    */

}



void end_scene()
{
    endScene->enter();
    BGM2->stop();
    bgm3_start();


    endcartoon[0] = Object::create("main_images/snoopy_end_0.png", endScene, 0, 0);
    endcartoon[0]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        endcartoon[0]->hide();
        endcartoon[1] = Object::create("main_images/snoopy_end_1.png", endScene, 0, 0);
        endcartoon[1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

            endcartoon[1]->hide();
            endcartoon[2] = Object::create("main_images/snoopy_end_2.png", endScene, 0, 0);
            endcartoon[2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

                endcartoon[2]->hide();
                endcartoon[3] = Object::create("main_images/snoopy_end_3.png", endScene, 0, 0);
                endcartoon[3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

                    endcartoon[3]->hide();
                    end2_scene();

                    return true;
                });
                return true;
            });
            return true;
        });
        return true;
    });



}






// 5������ ������ ��� Ŭ�����ϰ� �Դ��� Ȯ���ϴ� �Լ�
void check_all_clear()
{

    if (++main_score >= 5)
    {
        auto enter_xmas_button = Object::create("main_images/snoopy-main_enter_christmas.png", mainScene, 535, 20);
        enter_xmas_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {


            end_scene();

            return true;

        });
    }
}




// 01 ���� ���� Ȩ ȭ��
void main_scene()
{
    mainScene->enter();



    main_intro->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        main_intro->hide();

        return true;

    });




    ObjectPtr main_color_button[5];
    main_color_button[0] = Object::create("main_images/snoopy-main_color_button1.png", mainScene, 170, 520);
    main_color_button[1] = Object::create("main_images/snoopy-main_color_button2.png", mainScene, 370, 480);
    main_color_button[2] = Object::create("main_images/snoopy-main_color_button3.png", mainScene, 570, 510);
    main_color_button[3] = Object::create("main_images/snoopy-main_color_button4.png", mainScene, 770, 470);
    main_color_button[4] = Object::create("main_images/snoopy-main_color_button5.png", mainScene, 970, 490);







    // 01 ���� ���� ���� ��ư
    main_button1 = Object::create("main_images/snoopy-main_button1.png", mainScene, 170, 520);
    main_button1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        BGM2->stop();

        letter_init();


        return true;

    });


    // 02 �׸� �׸��� ���� ��ư
    main_button2 = Object::create("main_images/snoopy-main_button2.png", mainScene, 370, 480);
    main_button2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        BGM2->stop();

        coloring_init();

        return true;

    });



    // 03 �ǾƳ� ���� ��ư
    main_button3 = Object::create("main_images/snoopy-main_button3.png", mainScene, 570, 510);
    main_button3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        BGM2->stop();

        piano_init();

        return true;

    });



    // 04 ���� ���� ��ư
    main_button4 = Object::create("main_images/snoopy-main_button4.png", mainScene, 770, 470);
    main_button4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        BGM2->stop();

        pizza_init();

        return true;

    });




    // 05 �ϳ��� ���� ��ư
    main_button5 = Object::create("main_images/snoopy-main_button5.png", mainScene, 970, 490);
    main_button5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        BGM2->stop();

        hanoi_init();

        return true;

    });



}




void init_intro()
{
    bgm1_start();

    startScene = Scene::create("Snoopy's Happy Christmas", "main_images/snoopy_start_s.png");   //���� �� ȭ��
    // ��Ʈ�� ȭ��. �����ǿ� ��彺Ź���� ��ȭ

    auto startimage = Object::create("main_images/snoopy-main_press.png", startScene, 0, 0);
    startimage->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

        for (int i = 14; i >= 0; i--)
        {
            char buf[50];
            sprintf(buf, "main_images/snoopy_start_%d.png", i);
            startcartoon[i] = Object::create(buf, startScene, 0, 0);
            startcartoon[i]->setOnMouseCallback([&, i](ObjectPtr object, int x, int y, MouseAction action)->bool {
                startcartoon[i]->hide();
                if (i == 12)
                {
                    BGM1->stop();
                    bgm2_start();
                }
                if (i == 14)
                {
                    main_intro = Object::create("main_images/snoopy_main_0.png", mainScene, 0, 0);
                    // ���� ���� �޴� ȭ��
                    main_scene();
                }
                return true;
            });
        }
        return true;
    });
}






int main()
{

    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    //setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);


    mainScene = Scene::create("Snoopy's Happy Christmas", "main_images/snoopy_main_s.png"); //���� ���� ȭ��
    endScene = Scene::create("Snoopy's Happy Christmas", "main_images/snoopy_end_s.png"); // ���� ���� ȭ��
    end2Scene = Scene::create("Snoopy's Happy Christmas", "main_images/snoopy_endgame_s.png"); // ���� ���� ȭ��


    init_intro();

    startGame(startScene);
    return 0;
}