#include <flecs.h>
#include <iostream>

struct tag_scene_entity_t {};

void load_scene(const flecs::world& world) {
    for(size_t i = 0; i < 10; i++) {
      flecs::entity entity = world.entity().add<tag_scene_entity_t>();

      printf("Add Entity: %llu\n", entity.raw_id());
    }
}

void end_scene(const flecs::world& world) {
    world.filter_builder<>().term<tag_scene_entity_t>()
      .each([&](flecs::entity entity) {
          printf("Remove Entity: %llu\n", entity.raw_id());
          entity.destruct();
      });

    printf("count %llu\n", world.entity().raw_id());
}

int main() {
    flecs::world world;
    
    for(uint32_t i = 0; i < 5; i++) {
        load_scene(world);
        end_scene(world);
    }

    return 0;
}
