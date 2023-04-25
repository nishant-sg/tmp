#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

struct Node
{
    pid_t pid;
    struct Node *parent;
    struct Node *child;
};

struct Node *root;

void add_node(pid_t pid)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->pid = pid;
    node->parent = NULL;
    node->child = NULL;

    if (root == NULL)
    {
        root = node;
    }
    else
    {
        pid_t ppid = getppid();
        struct Node *parent_node = root;

        while (parent_node != NULL)
        {
            if (parent_node->pid == ppid)
            {
                node->parent = parent_node;

                if (parent_node->child == NULL)
                {
                    parent_node->child = node;
                }
                else
                {
                    struct Node *child_node = parent_node->child;
                    while (child_node->child != NULL)
                    {
                        child_node = child_node->child;
                    }
                    child_node->child = node;
                }

                break;
            }
            parent_node = parent_node->child;
        }
    }
}

void print_tree(struct Node *node, int depth)
{
    int i;
    for (i = 0; i < depth; i++)
    {
        printf("|   ");
    }

    printf("|-- %d\n", node->pid);

    if (node->child != NULL)
    {
        print_tree(node->child, depth + 1);
    }
}

int main()
{
    root = NULL;

    while (1)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            // child process
            add_node(getpid());
            sleep(1);
        }
        else
        {
            // parent process
            add_node(pid);
            print_tree(root, 0);
            sleep(1);
        }
    }

    return 0;
}