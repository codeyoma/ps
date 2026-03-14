#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list {
    struct s_list* next;
    void*          content;
} t_list;

t_list* ft_lstnew(void* content) {
}

void ft_lstadd_front(t_list** lst, t_list* new) {
}

int ft_lstsize(t_list* lst) {
}

t_list* ft_lstlast(t_list* lst) {
}

void ft_lstadd_back(t_list** lst, t_list* new) {
}

void ft_lstclear(t_list** lst, void (*del)(void*)) {
}

void ft_lstdelone(t_list* lst, void (*del)(void*)) {
    if (lst) {
        if (del) {
            del(lst->content);
        }
        free(lst);
    }
}

void ft_lstiter(t_list* lst, void (*f)(void*)) {
    if (!lst || !f) {
        return;
    }
    while (lst) {
        f(lst->content);
        lst = lst->next;
    }
}

void print(void* content) {
    printf("%d\n", *(int*)content);
}

int main() {
    t_list* root = NULL;
}