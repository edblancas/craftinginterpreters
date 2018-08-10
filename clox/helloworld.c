#include <stdio.h>

struct node
{
    struct node *prev;
    char *text;
    struct node *next;
};

int sum(int a, int b)
{
    return a + b;
}

void print_list(struct node ini_node);
void print_node(struct node node_to_print);

int main()
{
    // printf("Hello, World!\n");
    // printf("sum: %d\n", sum(1, 2));

    struct node node0 = {NULL, "node0", NULL};
    struct node node1 = {NULL, "node1", NULL};
    struct node node2 = {NULL, "node2", NULL};

    node0.next = &node1;
    node1.prev = &node0;
    node1.next = &node2;
    node2.prev = &node1;
    printf("%s, %d\n", node0.text, &node0);
    printf("%s, %d\n", node1.text, &node1);
    printf("%s, %d\n", node2.text, &node2);

    print_list(node0);

    return 0;
}

void print_list(struct node ini_node)
{
    struct node next_node = ini_node;
    while (next_node.next != NULL)
    {
        print_node(next_node);
        next_node = *next_node.next;
    }
    print_node(next_node);
}

void print_node(struct node node_to_print) {
    printf("[next=%d, text=%s, prev=%d]\n", node_to_print.next, node_to_print.text, node_to_print.prev);
}