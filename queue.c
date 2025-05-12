#include "queue.h"
#include "tile_game.h"

void enqueue(struct queue *q, struct game_state state) {
    uint64_t cur_state = serialize(state);
    insert_at_head(&q->data, cur_state);
}

struct game_state dequeue(struct queue *q) {
    size_t cur_value = remove_from_tail(&q->data);
    struct game_state cur_game_state = deserialize(cur_value);
    return (cur_game_state); 
}

int number_of_moves(struct game_state start) { 

    return 0; 
}
