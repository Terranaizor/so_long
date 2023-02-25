/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_between_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:57:42 by nradin            #+#    #+#             */
/*   Updated: 2023/02/13 17:52:06 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	enqueue(queue_t *queue, t_point p)
{
	if (queue->tail == MAX_QUEUE_SIZE)
	{
		printf("Queue overflow\n");
		exit(1);
	}
	queue->queue[queue->tail] = p;
	queue->tail++;
}

t_point	dequeue(queue_t *queue)
{
	t_point	p;

	if (queue->head == queue->tail)
	{
		printf("Queue underflow\n");
		exit(1);
	}
	p = queue->queue[queue->head];
	queue->head++;
	return (p);
}

int	is_valid(int x, int y)
{
	return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

int	is_viable_path(char **grid, int x, int y)
{
	return (grid[x][y] == 'P' || grid[x][y] == 'C' || \
	grid[x][y] == '0' || grid[x][y] == 'E');
}

int	shortest_path(char **grid, t_point src, t_point dest)
{
	int		**visited;
	queue_t	queue;
	t_point	start;
	t_point	curr;

	start = {src.x, src.y, 0};
	visited[src.x][src.y] = 1;
	queue.head = 0;
	queue.tail = 0;
	enqueue(&queue, start);
	while (queue->head != queue->tail)
	{
		curr = dequeue(&queue);
		if (curr.x == dest.x && curr.y == dest.y)
			return (curr.dist);
		int dx[] = {-1, 0, 1, 0};
		int dy[] = {0, 1, 0, -1};
		for (int i = 0; i < 4; i++)
		{
			int x = curr.x + dx[i];
			int y = curr.y + dy[i];

			if (is_valid(x, y) && is_viable_path(grid, x, y) && !visited[x][y])
			{
				visited[x][y] = 1;
				t_point p = {x, y, curr.dist + 1};
				enqueue(&queue, p);
			}
		}
	}
	return (-1);
}
