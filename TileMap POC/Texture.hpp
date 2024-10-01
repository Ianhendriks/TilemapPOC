#pragma once
#include <algorithm>
#include <memory>
#include <SDL2/SDL_render.h>
using namespace std;

class Texture {
public:
    Texture() : _texture(nullptr), _width(0), _height(0) {}
    Texture(SDL_Texture* texture, int width, int height);
    ~Texture() = default;

    Texture(const Texture& other) = default;
    Texture& operator=(const Texture&) = default;
    Texture(Texture&&) noexcept = default;
    Texture& operator=(Texture&&) noexcept = default;

    [[nodiscard]] SDL_Texture* texture() const;
    void set_texture(SDL_Texture* texture);
    [[nodiscard]] int width() const;
    void set_width(int width);
    [[nodiscard]] int height() const;
    void set_height(int height);

private:
    SDL_Texture* _texture;
    int _width;
    int _height;
};
