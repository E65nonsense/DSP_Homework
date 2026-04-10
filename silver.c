//
// Created by E65 on 2026/4/9.
//
#include<stdio.h>
#include<stdlib.h>

struct sil{
    int wgh ;
    struct sil* next ;
};

typedef struct sil sil ;

sil* create_node(int wgh)
{
    sil* new = (sil*)malloc(sizeof(sil)) ;
    new->next = NULL ;
    new->wgh = wgh ;
    return new ;
}

sil* insert(sil* gud , int* num , sil* new)
{
    /*当没有银块时，直接插在gud后面*/
    if(*num == 0)
    {
        gud->next = new ;
    }
    /*如果有银块*/
    else
    {
        sil* it = gud ;
        int ind = 0 ;
        /*从头遍历找到位置*/
        while(ind <= *num)
        {
            if(it->next == NULL)
            {
                it->next = new ;
            }
            else if(it->next->wgh >= new->wgh)
            {
                new->next = it->next ;
                it->next = new ;
                break ;
            }
            ind++ ;
            it = it->next ;
        }
    }
    (*num)++ ;
    gud->wgh += new->wgh ;
    return gud ;
}

sil* sell(sil* gud , int* num , int need)
{
    sil* it = gud->next ;
    int sum = 0 ;
    while(sum < need)
    {
        sum += it->wgh ;
        gud->next = it->next ;
        gud->wgh -= it->wgh ;
        it = it->next ;
        (*num)-- ;
    }
    if(sum > need)
    {
        sil* new = create_node(sum - need) ;
        insert(gud , num , new) ;
    }
    return gud ;
}

sil* cast(sil* gud , int*num)
{
    int sum = 0 ;
    sil* prev = gud ;
    sil* it = gud->next ;
    while(it != NULL)
    {
        if(it->wgh < 10)
        {
            sum += it->wgh ;
            gud->wgh -= it->wgh ;
            prev->next = it->next ;
            it = it->next ;
            (*num)-- ;
        }
        else
        {
            it = it->next ;
            prev = prev->next ;
        }
    }
    if(sum > 0)
    {
        sil* new = create_node(sum) ;
        gud = insert(gud , num , new) ;
    }
    return gud ;
}

void print(sil* gud , int num)
{
    sil* it = gud->next ;
    int ind = 0 ;
    while(ind < num)
    {
        printf("%d " , it->wgh) ;
        ind++ ;
        it = it->next ;
    }
    return ;
}

int main()
{
    /*建立哨兵gud，gud->wgh是总质量*/
    sil* gud = (sil*)malloc(sizeof(sil)) ;
    gud->next = NULL ;
    gud->wgh = 0 ;
    int num = 0 ;/*已有银块数量*/

    int tmp = 0 ;
    scanf("%d" , &tmp) ;
    while(tmp != 999999)
    {
        // printf("%d\n" , tmp) ;
        if(tmp > 0)
        {
            sil* new = create_node(tmp) ;
            gud = insert(gud , &num , new) ;
        }
        else if(tmp < 0)
        {
            tmp *= -1 ;
            if(tmp <= gud->wgh) gud = sell(gud , &num , tmp) ;
        }
        else
        {
            cast(gud , &num) ;
        }
        // print(gud , num) ;
        scanf("%d" , &tmp) ;
    }
    print(gud , num) ;
    // printf("\ntotal weight : %d" , gud->wgh) ;
    // printf("\ntotal num : %d" , num) ;
    return 0 ;
}
