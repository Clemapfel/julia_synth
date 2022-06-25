//
// Copyright 2022 Clemens Cords
// Created on 6/25/22 by clem (mail@clemens-cords.com)
//

#pragma once

#include <SFML/Audio.hpp>

extern "C"
{
    size_t sample_rate()
    {
        return 44100;
    }

    void* buffer_create(int16_t* data_ptr, size_t n_samples)
    {
        auto* out = new sf::SoundBuffer();
        out->loadFromSamples(data_ptr, n_samples, 1, sample_rate());
    }

    void buffer_destroy(void* buffer_ptr)
    {
        delete (sf::SoundBuffer*) buffer_ptr;
    }

    void* sound_create(void* buffer_ptr)
    {
        auto* out = new sf::Sound(*((sf::SoundBuffer*) buffer_ptr));
    }

    void sound_destroy(void* sound_ptr)
    {
        delete ((sf::Sound*) sound_ptr);
    }

    void sound_play(void* sound_ptr)
    {
        ((sf::Sound*) sound_ptr)->play();
    }

    void sound_pause(void* sound_ptr)
    {
        ((sf::Sound*) sound_ptr)->pause();
    }

    void sound_stop(void* sound_ptr)
    {
        ((sf::Sound*) sound_ptr)->stop();
    }
}