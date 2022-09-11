#include "single_list.h"
#include <stdio.h>
#include <stdlib.h>


SingleListCharElement* createSingleListCharElement(char value) {
    SingleListCharElement* result = (SingleListCharElement*)malloc(sizeof(SingleListCharElement));

    if (NULL != result) {
        result->value = value;
        result->next = NULL;
    }
    return result;
}
void deleteSingleListCharElement(SingleListCharElement* element) {
    if (NULL != element) {
        free(element);
    }
}
void printSingleListCharElement(SingleListCharElement* element) {
    if (NULL != element) {
        printf("%c", element->value);
    }
}
CharSingleList* createCharSingleList(void) {
    CharSingleList* result = (CharSingleList*)malloc(sizeof(CharSingleList));
    if (NULL != result) {
        result->head = NULL;
    }
    return result;
}
void deleteCharSingleList(CharSingleList* list) {
    if (NULL == list) {
        return;
    }
    SingleListCharElement* element = list->head;

    while (NULL != element) {
        SingleListCharElement* tmp = element->next;
        deleteSingleListCharElement(element);
        element = tmp;
    }
    free(list);
}
void printCharSingleList(CharSingleList* list) {

    if (NULL == list) {
        printf("Invalid a pointer to the list\n");
        return;
    }
    printf("[");
    for (SingleListCharElement* element = list->head; element != NULL; element = element->next) {
        printSingleListCharElement(element);
        if (element->next != NULL) {
            printf(",");
        }
    }
    printf("]\n");
}
long countOfCharSingleList(CharSingleList* list) {
    if (NULL == list) {
        return 0;
    }
    long count = 0;

    for (SingleListCharElement* element = list->head; element != NULL; element = element->next, count++);
    return count;
}
int addCharValueToSingleList(CharSingleList* list, char value) {
    if (NULL == list) {
        return 0;
    }
    SingleListCharElement* element = createSingleListCharElement(value);
    if (NULL == element) {
        return 0;
    }
    if (NULL == list->head) {
        list->head = element;
        return 1;
    }
    SingleListCharElement* tail = list->head;

    while (NULL != tail->next) {
        tail = tail->next;
    }
    tail->next = element;
    return 1;
}
void removeLastElementFromCharSingleList(CharSingleList* list) {
    if (NULL == list) {
        return 0;
    }
    if (NULL == list->head) {
        return;
    }
    SingleListCharElement* element = list->head;

    if (NULL == element->next) {
        list->head = NULL;
        deleteSingleListCharElement(element);
        return;
    }

    while (NULL != element->next && NULL != element->next->next) {
        element = element->next;
    }
    deleteSingleListCharElement(element->next);
    element->next = NULL;
}
void removeFirstElementFromCharSingleList(CharSingleList* list) {
    if (NULL == list) {
        return 0;
    }
    if (NULL == list->head) {
        return;
    }
    SingleListCharElement* element = list->head->next;
    deleteSingleListCharElement(list->head);
    list->head = element;
}

void removeAllElementFromCharSingleList(CharSingleList* list) {
    if (NULL == list) {
        return 0;
    }
    if (NULL == list->head) {
        return;
    }
    SingleListCharElement* element = list->head;

    while (NULL != element->next) {
        list->head = NULL;
        deleteSingleListCharElement(element);
        return;
    }
}

int insertCharElementToCharSingleListAtIndex(CharSingleList* list, int index, char value)
{
    if (NULL == list) {
        return 0;
    }
    long count = countOfCharSingleList(list);

    if (count == index) {
        return addCharValueToSingleList(list, value);
    }
    SingleListCharElement* element = createSingleListCharElement(value);
    if (NULL == element) {
        return 0;
    }
    if (0 == index) {
        element->next = list->head;
        list->head = element;
    }
    else {
        int current = 0;
        SingleListCharElement* ex_element = list->head;
        for (ex_element != NULL && current < index - 1; ex_element = ex_element->next; current++);

        element->next = ex_element->next;
        ex_element->next = element;

    }
    return 1;
}
int removeCharElementToCharSingleListAtIndex(CharSingleList* list, int index)
{
    if (NULL == list) {
        return 0;
    }
    long count = countOfCharSingleList(list);
    if (index >= count)
    {
        return 0;
    }
    if (0 == index)
    {
        removeFirstElementFromCharSingleList(list);
        return 1;
    }
    else if (index == count - 1)
    {
        removeLastElementFromCharSingleList(list);
        return 1;
    }
    else
    {
        int current = 0;
        SingleListCharElement* ex_element = list->head;
        for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++)
        {
            SingleListCharElement* to_delete = ex_element->next;
            ex_element->next = to_delete->next;
            deleteSingleListCharElement(to_delete);
        }
    }
    return 1;
}