#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
     Resource* data;

public:
    ResourceManager() 
    { 
        data = new Resource; 
    }
    ~ResourceManager() 
    { 
        delete data; 
    }
    double get() 
    { 
        return data->get(); 
    }
    ResourceManager(const ResourceManager& x) 
    { 
        data = new Resource{*x.data}; 
    }
    ResourceManager& operator=(const ResourceManager& x)
    {
        if (this != &x) {
            delete data;
            data = new Resource{*x.data};
        }
        return *this;
    }
    ResourceManager(ResourceManager&& x)
    {
        data   = x.data;
        x.data = nullptr;
    }
    ResourceManager& operator=(ResourceManager&& x)
    {
        if (this != &x) {
            delete data;
            data   = x.data;
            x.data = nullptr;
        }
        return *this;
    }
};
