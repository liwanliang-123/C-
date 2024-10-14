#include <iostream>
#include <ctime>

#include "speaker.h"
#include "speechManager.h"

int main()
{
    int choice = 0;
    SpeechManager sm;
//  添加随机数种子
    srand((unsigned int)time(NULL));

    while (true) {
        sm.ShowMenu();
        std::cout << "请输入你的选择" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            sm.StartSpeech();
            break;
        case 2:
            sm.showRecord();
            break;
        case 3:
            sm.ClearRecord();
            break;
        case 0:
            sm.ExitSystem();
            break;

        default:
            break;
        }
    }

    return 0;
}