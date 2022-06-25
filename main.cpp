//
// Created by clem on 6/25/22.
//

#include <cmath>
#include <cassert>

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <SDL2/SDL_mixer.h>

#include <chrono>
#include <thread>

#include <iostream>
#include <cmath>

int main()
{
    const size_t sample_rate = 44100;

    size_t n = sample_rate * 10;
    std::vector<int16_t> samples;
    for (size_t i = 0; i < n; ++i)
        samples.push_back(sin(i / M_PI) * pow(2, 16) / 2);

    auto chunk = sf::SoundBuffer();
    chunk.loadFromSamples(samples.data(), samples.size(), 1, sample_rate);

    auto sound = sf::Sound();

    auto chunk2 = sf::SoundBuffer();
    chunk2.loadFromFile("/home/clem/Workspace/Telescope/test/ok_desu_ka.wav");

    auto chunk1 = sf::SoundBuffer();
    chunk1.loadFromSamples(samples.data(), samples.size(), 1, sample_rate);
    sound.setBuffer(chunk1);
    sound.play();

    for (size_t i = 0; i < chunk1.getSampleCount(); ++i)
    {
        auto val = chunk1.getSamples()[i];

        if (abs(val) > 16)
            std::cout << val << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));
}
