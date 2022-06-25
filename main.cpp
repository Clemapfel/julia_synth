//
// Created by clem on 6/25/22.
//

#include <cmath>

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <SDL2/SDL_mixer.h>

#include <chrono>
#include <thread>

#include <iostream>

#include <Telescope/telescope.hpp>

int main()
{

    only do adio initialize
    ts::initialize();
    auto window = ts::Window();
    window.create(0, 0);


    while (window.is_open())
    {
        auto time = ts::start_frame(&window);

        if (ts::InputHandler::was_pressed(ts::SPACE))
        {
            std::cout << "start" << std::endl;
        }

        if (ts::InputHandler::was_released(ts::SPACE))
        {
            std::cout << "stop" << std::endl;
        }

        ts::end_frame(&window);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
}
