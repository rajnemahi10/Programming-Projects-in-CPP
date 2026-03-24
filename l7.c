#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_ID_SIZE 50
#define NAME_SIZE 256

struct transaction
{
    char id[MAX_ID_SIZE];
    int amount;
    struct transaction *next;
    struct transaction *prev;
};

int main()
{

    struct transaction *head = (struct transaction *)malloc(sizeof(struct transaction));
    struct transaction *tail = (struct transaction *)malloc(sizeof(struct transaction));
    struct transaction *cursor;

    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;

    cursor = head;

    int total_queries;
    scanf("%d", &total_queries);

    while (total_queries--)
    {

        char type;
        scanf(" %c", &type);

        if (type == 'I')
        {

            int pos;
            scanf("%d", &pos);

            char id[MAX_ID_SIZE];
            scanf("%s", id);

            int amount;
            scanf("%d", &amount);

            // Insert Transaction
            struct transaction *node = (struct transaction *)(malloc)(sizeof(struct transaction));
            strcpy(node->id, id);
            node->amount = amount;

            struct transaction *ptr = cursor;
            int i = 0;
            if (pos == 0)
                continue;
            if (pos > 0)
            {

                while (i < pos && ptr != NULL)
                {
                    ptr = ptr->next;
                    i++;
                }
                if (ptr == NULL || ptr == head) // invalid
                {
                    free(node);
                    continue;
                }

                ptr->prev->next = node;
                node->next = ptr;
                node->prev = ptr->prev;
                ptr->prev = node;
            }
            else
            {

                pos = -1 * pos;
                while (i < pos && ptr != NULL)
                {
                    ptr = ptr->prev;
                    i++;
                }
                if (ptr == NULL)
                {
                    free(node);
                    continue;
                }
                node->next = ptr->next;
                node->prev = ptr;
                ptr->next->prev = node;
                ptr->next = node;
                char new[288];
                strcpy(new, id);
                strcat(new, ".txn");
                FILE *fp = fopen(new, "r");

                char s[MAX_ID_SIZE];
                char n[257];
                long long int b;
                fscanf(fp, "%s %lld", s, &b);
                b += amount;
                fclose(fp);
                fp = fopen(new, "w");
                fprintf(fp, "%s %lld", s, b);
                fclose(fp);
            }
        }
        else if (type == 'D')
        {

            int pos;
            scanf("%d", &pos);
            struct transaction *ptr = cursor;

            // Delete Transaction
            if (pos == 0)
            {
                if (cursor == head || cursor == tail)
                {
                    continue;
                }
                else
                {
                    char new[270];
                    strcpy(new, ptr->id);
                    strcat(new, ".txn");
                    FILE *fp = fopen(new, "r");
                    char s[MAX_ID_SIZE];
                    char n[257];
                    long long int b;
                    fscanf(fp, "%s %lld", s, &b);
                    b -= ptr->amount;
                    fclose(fp);
                    fp = fopen(new, "w");
                    fprintf(fp, "%s %lld", s, b);
                    fclose(fp);
                    cursor->next->prev = cursor->prev;
                    cursor->prev->next = cursor->next;
                    struct transaction *temp = cursor->prev;
                    free(cursor);
                    cursor = temp;
                }
            }
            else if (pos > 0)
            {
                int i = 0;
                while (i < pos && ptr != tail)
                {
                    ptr = ptr->next;
                    i++;
                }
                if (ptr == tail)
                    continue;

                ptr->next->prev = ptr->prev;
                ptr->prev->next = ptr->next;
                free(ptr);
            }
            else
            {
                pos = -1 * pos;
                int i = 0;
                while (i < pos && ptr != head)
                {
                    ptr = ptr->prev;
                    i++;
                }
                if (ptr == head)
                    continue;
                char new[270];
                strcpy(new, ptr->id);
                strcat(new, ".txn");
                FILE *fp = fopen(new, "r");
                char s[MAX_ID_SIZE];
                char n[257];
                long long int b;
                fscanf(fp, "%s %lld", s, &b);
                b -= ptr->amount;
                fclose(fp);
                fp = fopen(new, "w");
                fprintf(fp, "%s %lld", s, b);
                fclose(fp);
                ptr->next->prev = ptr->prev;
                ptr->prev->next = ptr->next;
                free(ptr);
            }
        }
        else if (type == 'U')
        {

            // Undo Transaction
            if (cursor == head)
                continue;

            struct transaction *ptr = cursor;
            char new[270];
            strcpy(new, ptr->id);
            strcat(new, ".txn");
            FILE *fp = fopen(new, "r");
            char s[MAX_ID_SIZE];
            char n[257];
            long long int b;
            fscanf(fp, "%s %lld", s, &b);
            b -= ptr->amount;
            fclose(fp);
            fp = fopen(new, "w");
            fprintf(fp, "%s %lld", s, b);
            cursor = cursor->prev;
        }
        else if (type == 'E')
        {

            // Execute Transaction
            if (cursor->next == tail)
                continue;
            struct transaction *ptr = cursor->next;
            char new[270];
            strcpy(new, ptr->id);
            strcat(new, ".txn");
            FILE *fp = fopen(new, "r");
            char s[MAX_ID_SIZE];
            char n[257];
            long long int b;
            fscanf(fp, "%s %lld", s, &b);

            b += ptr->amount;

            fclose(fp);
            fp = fopen(new, "w");

            fprintf(fp, "%s %lld", s, b);
            fclose(fp);
        }
        else if (type == 'C')
        {

            // Commit Transactions
            struct transaction *ptr = cursor;
            while (ptr->next != tail)
            {
                char new[270];
                strcpy(new, ptr->id);
                strcat(new, ".txn");
                FILE *fp = fopen(new, "r");
                char s[MAX_ID_SIZE];
                char n[257];
                long long int b;
                fscanf(fp, "%s %lld", s, &b);
                b += ptr->amount;
                fclose(fp);
                fp = fopen(new, "w");
                fprintf(fp, "%s %lld", s, b);
                fclose(fp);
                ptr = ptr->next;
            }
        }
        else if (type == 'G')
        {

            char id[MAX_ID_SIZE];
            scanf("%s", id);

            // Print Balance
            char new[270];
            strcpy(new, id);

            strcat(new, ".txn");
            FILE *fp = fopen(new, "r");
            char s[MAX_ID_SIZE];
            char n[257];
            long long int b;
            fscanf(fp, "%s %lld", s, &b);
            printf("%lld\n", b);
            fclose(fp);
        }
    }

    // Don't forget to free memory

    return 0;
}