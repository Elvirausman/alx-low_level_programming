#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"

skiplist_t *create_node(int value, size_t index)
{
	    skiplist_t *node = malloc(sizeof(skiplist_t));
	        if (!node)
			        return (NULL);
		    node->n = value;
		        node->index = index;
			    node->next = NULL;
			        node->express = NULL;
				    return (node);
}

skiplist_t *create_skiplist(int *array, size_t size)
{
	    skiplist_t *head = NULL, *tail = NULL, *express_tail = NULL;
	        size_t i, step = sqrt(size);

		    for (i = 0; i < size; i++)
			        {
					        skiplist_t *node = create_node(array[i], i);
						        if (!node)
								        {
										            free_skiplist(head);
											                return (NULL);
													        }

							        if (!head)
									            head = tail = node;
								        else
										        {
												            tail->next = node;
													                tail = node;
															        }

									        if (i % step == 0)
											        {
													            if (!express_tail)
															                    express_tail = head;
														                else
																	            {
																			                    express_tail->express = node;
																					                    express_tail = node;
																							                }
																        }
										    }
		        return (head);
}

void print_skiplist(const skiplist_t *list)
{
	    const skiplist_t *node = list;
	        const skiplist_t *express = list ? list->express : NULL;

		    printf("List:\n");
		        while (node)
				    {
					            printf("Index [%lu] = [%d]\n", node->index, node->n);
						            node = node->next;
							        }

			    printf("\nExpress lane:\n");
			        while (express)
					    {
						            printf("Index [%lu] = [%d]\n", express->index, express->n);
							            express = express->express;
								        }
}

void free_skiplist(skiplist_t *list)
{
	    skiplist_t *node;

	        while (list)
			    {
				            node = list->next;
					            free(list);
						            list = node;
							        }
}

