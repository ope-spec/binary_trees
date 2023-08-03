#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

/**
 * struct queue_node - Queue node
 *
 * @data: Data stored in the node
 * @next: Pointer to the next node
 */
typedef struct queue_node
{
	void *data;
	struct queue_node *next;
} queue_node_t;

/**
 * struct queue - Queue structure
 *
 * @front: Pointer to the front of the queue
 * @rear: Pointer to the rear of the queue
 */
typedef struct queue
{
	queue_node_t *front;
	queue_node_t *rear;
} queue_t;

queue_t *queue_create(void);
void queue_delete(queue_t *queue);
int enqueue(queue_t *queue, void *data);
void *dequeue(queue_t *queue);
int queue_is_empty(const queue_t *queue);

#endif /* QUEUE_H */
