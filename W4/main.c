#include "single_list.h"

int main()
{
    CharSingleList* list = createCharSingleList();

    addCharValueToSingleList(list, 3);
    addCharValueToSingleList(list, 2);
    printCharSingleList(list);

    removeFirstElementFromCharSingleList(list);
    printCharSingleList(list);
    removeLastElementFromCharSingleList(list);

    addCharValueToSingleList(list, 3);
    addCharValueToSingleList(list, 2);
    printCharSingleList(list);

    removeLastElementFromCharSingleList(list);
    printCharSingleList(list);
    removeFirstElementFromCharSingleList(list);
    

    addCharValueToSingleList(list, 3);
    addCharValueToSingleList(list, 2);
    printCharSingleList(list);

    removeAllElementFromCharSingleList(list);
    printCharSingleList(list);
 

    addCharValueToSingleList(list, 3);
    addCharValueToSingleList(list, 2);
    printCharSingleList(list);

    insertCharElementToCharSingleListAtIndex(list, 2, 3);
    insertCharElementToCharSingleListAtIndex(list, 3, 2);
    printCharSingleList(list);

    deleteCharSingleList(list);
    return 0;
}