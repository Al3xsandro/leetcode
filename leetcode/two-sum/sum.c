#include "stdio.h"
#include "stdlib.h"

#define MAX 10007

typedef struct no *p_no;

struct no
{
    int key;
    int value;
    p_no prox;
};

typedef struct hash *p_hash;

struct hash
{
    p_no array[MAX];
};

int hash(int key)
{
    return (key < 0 ? -key : key) % MAX;
}

p_no insert_array(p_no item, int key, int value)
{
    p_no new;
    new = malloc(sizeof(struct no));
    new->key = key;
    new->value = value;
    new->prox = item;
    return new;
}

void insert(p_hash table, int key, int value)
{
    int n = hash(key);
    table->array[n] = insert_array(table->array[n], key, value);
}

p_hash create_list()
{
    p_hash hash_table = malloc(sizeof(struct hash));

    if (hash_table == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < MAX; i++)
    {
        hash_table->array[i] = NULL;
    }

    return hash_table;
}

p_no find_item(p_hash table, int key)
{
    int n = hash(key);
    p_no curr = table->array[n];

    while (curr != NULL)
    {
        if (curr->key == key)
        {
            return curr;
        }
        curr = curr->prox;
    }

    return NULL;
}

int *twoSumHash(int *nums, int numsSize, int target, int *returnSize)
{
    p_hash list;
    list = create_list();

    int number_to_sum;

    for (int i = 0; i < numsSize; i++)
    {
        number_to_sum = target - nums[i];

        // verificar se esta na lista
        p_no item = find_item(list, number_to_sum);
        if (item != NULL)
        {
            int *result = malloc(2 * sizeof(int));
            if (!result)
                return NULL;

            result[0] = item->value;
            result[1] = i;

            *returnSize = 2;
            return result;
        }
        insert(list, nums[i], i);
    }

    return NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *numbers = malloc(2 * sizeof(int));
    int sum = 0;

    *returnSize = 2;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            sum = nums[i] + nums[j];

            if (sum == target)
            {
                numbers[0] = i;
                numbers[1] = j;
                return numbers;
            }
        }
    }

    *returnSize = 0;
    free(numbers);
    return NULL;
}

int main()
{
    int nums[] = {0, 7, 2, 15};
    int target = 9;
    int returnSize;

    // int *result = twoSum(nums, 4, target, &returnSize);
    int *result = twoSumHash(nums, 4, target, &returnSize);

    if (result != NULL)
    {
        printf("[%d %d]\n", result[0], result[1]);
    }

    return 0;
}