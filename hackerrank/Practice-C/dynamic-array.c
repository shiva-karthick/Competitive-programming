#include "/home/shankar/Shiva/Competitive-programming/header-files/common.h"

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* This expamle is for 3 shelves, which is indexing 0, 1, 2
r[2]: 1 books: book1(35 pages)
r[1]: 3 books: book1(63 pages), book2(21 pages), book2(32 pages)
r[0]: 2 books: book1(12 pages), book2(52 pages)

You can see the layout, So here we have to reallocate memory for pages as per required number of books.
   __              ___
  |  |            |   |
2 |1 |          2 |35 |
  |--|            |---|---|---|
1 |3 |          1 |63 |21 |32 |
  |--|            |---|---|---|
0 |2 |          0 |12 |52 |
  |  |            |   |   |
  ````            ``` ````
books           Pages

If we get new query: 1(add), 1, 57
Now we have to add one more book with 57 pages.
So this time: books[1]++ ie. books[1] will be 4,
and reallocate memory to pages for 4 integers and add 57 at index 3 ie. pages[3] = 57.
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int *total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int **total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    int *total_number_of_books = (int *)malloc(sizeof(int) * total_number_of_shelves);
    int **total_number_of_pages = (int **)malloc(sizeof(int *) * total_number_of_shelves);

    for (int i = 0; i < total_number_of_shelves; i += 1)
    {
        total_number_of_books[i] = 0;
        total_number_of_pages[i] = (int *)malloc(sizeof(int));
    }

    while (total_number_of_queries--)
    {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1)
        {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            total_number_of_books[x] += 1;
            total_number_of_pages[x] = realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));
            total_number_of_pages[x][total_number_of_books[x] - 1] = y;
        }
        else if (type_of_query == 2)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books)
    {
        free(total_number_of_books);
    }

    for (int i = 0; i < total_number_of_shelves; i++)
    {
        if (*(total_number_of_pages + i))
        {
            free(*(total_number_of_pages + i));
        }
    }

    if (total_number_of_pages)
    {
        free(total_number_of_pages);
    }

    return 0;
}