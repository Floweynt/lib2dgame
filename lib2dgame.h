#ifndef __LIB2DGAME_H__
#define __LIB2DGAME_H__

#include "camera.h"
#include "spriteloader.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <queue>

namespace world
{
    enum event_lib
    {
        HB_COLLISION,
        CB_COLLISION,
        IB_COLLISION
    };

    struct builtin_event
    {
        int id_1;
        int id_2;
        event_lib event;
    };

    class room : tilemap
    {
        spritelist sprites;
        stileset_t stileset;
        std::thread event_thread;
        std::atomic_bool stop_thread;
        std::queue<builtin_event> events;

        void poll_events();
    public:
        inline room() : tilemap::tilemap() {};
        inline room(types::tileset_t _tileset, types::level_t _levels, size_t _tilesize, stileset_t _stileset, spritelist _sprites)
            : tilemap::tilemap() { this->init(_tileset, _levels, _tilesize, _stileset, _sprites); }
        void init(types::tileset_t _tileset, types::level_t _levels, size_t _tilesize, stileset_t _stileset, spritelist _sprites);
        int render();
    };
}
#endif