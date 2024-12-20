#pragma once
#include <unordered_map>
#include <string>
#include "raylib.h" // Assuming you are using raylib

class ResourceManager
{
public:
    static Texture2D &GetTexture(const std::string &path)
    {
        if (textures.find(path) == textures.end())
        {
            textures[path] = LoadTexture(path.c_str()); // Load and store
        }
        return textures[path];
    }

    static void UnloadAllTextures()
    {
        for (auto &pair : textures)
        {
            UnloadTexture(pair.second);
        }
        textures.clear();
    }
    static void DeleteTexture(const std::string *texture)
    {
        UnloadTexture(textures[*texture]);
        textures.erase(*texture);
    }

private:
    static std::unordered_map<std::string, Texture2D> textures;
};
std::unordered_map<std::string, Texture2D> ResourceManager::textures;
