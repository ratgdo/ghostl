#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "circular_queue.h"
#include "lfllist.h"

extern "C" void app_main(void)
{
    printf("ghostl ESP-IDF Example\n");
    
    // Example using circular_queue
    circular_queue<int, 32> queue;
    
    // Push some values
    for (int i = 0; i < 10; i++) {
        queue.push(i);
        printf("Pushed: %d\n", i);
    }
    
    // Pop values
    int value;
    while (queue.pop(value)) {
        printf("Popped: %d\n", value);
    }
    
    // Example using lock-free list
    lfllist<int> list;
    list.add(42);
    list.add(84);
    
    printf("Lock-free list size: %d\n", list.size());
    
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}