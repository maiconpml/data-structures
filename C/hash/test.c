#include "hash.h"
#include "table.h"
#include <stdio.h>

int main(){

    Table hashTable;

    alloc_table(&hashTable, 20);
 
    printf("23 inserted in position: %d\n", insert_value(hashTable, 23));
    printf("3450 inserted in position: %d\n", insert_value(hashTable, 3450));
    printf("2341 inserted in position: %d\n", insert_value(hashTable, 2341));
    printf("213 inserted in position: %d\n", insert_value(hashTable, 213));
    printf("543 inserted in position: %d\n", insert_value(hashTable, 543));
    printf("65 inserted in position: %d\n", insert_value(hashTable, 65));
    printf("123 inserted in position: %d\n", insert_value(hashTable, 123));/* collision and 123 inserted at 
                                                                            * (123 + 17 * 1 + 19 * 1 * 1) % 100 = 59 */
    printf("323 inserted in position: %d\n", insert_value(hashTable, 323));/* two collisions and 323 inserted at
                                                                            * (323 + 17 * 2 + 19 * 2 * 2) % 100 = 33 */
    
    printf("123 founded in position: %d\n", search(hashTable, 123));

    printf("123 removed from position: %d\n", remove_value(hashTable, 123));

    printf("123 founded in position: %d\n", search(hashTable, 123));

    printf("323 founded in position: %d\n", search(hashTable, 323));/* after the removal of 123, the search for 323
                                                                     * continues to work because of the deleted field
                                                                     * that indicates that 123 was removed */

    return 0;
}