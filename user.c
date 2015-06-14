#include "user.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// static user storage
static int total_users = 0;
static int user_list_size = 0;
static user** user_list;

user* create_user(char* user_name, char* url)
{
    //Resize user list array
    if(user_list_size <= total_users)
    {
        user_list_size = user_list_size == 0 ? 10 : user_list_size * 2;
        user_list = (user**)realloc(user_list, user_list_size * ((sizeof(void*))));
    }
    
    int index = total_users++;
    user* newUser = user_list[index] = (user*)calloc(1, sizeof(user));

    newUser->user_id = index;
    newUser->name = (char*)malloc(strlen(user_name) + 1);
    strcpy(newUser->name, user_name);
    newUser->last_activity = newUser->when_created = time(NULL);
    newUser->URL_of_avatar = (char*)malloc(strlen(url) + 1);
    strcpy(newUser->URL_of_avatar, url);
    
    printf("Created new userID: %d\n:", newUser->user_id);
    return newUser;
}

user* get_user(int user_id)
{
    return user_id < total_users ? user_list[user_id] : NULL;
}

int get_num_users()
{
    return total_users;
}

void print_time(const char* pfstring, time_t time)
{
    struct tm * timeinfo;
    timeinfo = localtime (&time);
    printf (pfstring, asctime(timeinfo));
}

void print_user(user* user)
{
    if (!user)
        return;
    
    printf("User: \n");
    printf("ID: %d\n", user->user_id); 
    printf("Name: %s\n", user->name);  
    printf("URL: %s\n", user->URL_of_avatar);
    print_time("Created: %s", user->when_created);
    print_time("Last Active: %s", user->last_activity);
    printf("Following: ");
    for (int i = 0; i < user->num_following; ++i)
        printf("%d ", user->ids_following[i]); 
    printf("\nBlocked: ");
    for (int i = 0; i < user->num_blocked; ++i)
        printf("%d ", user->ids_blocked[i]);
    printf("\n\n");
}

void print_all_users()
{
    for(int i = 0; i < total_users; ++i)
        print_user(user_list[i]);
}

void add_following(user* user1, user* user2)
{
    //No selfies
    if(user1 == user2 || !user1 || !user2)
        return;
    
    printf("User %d follows User %d\n", user1->user_id, user2->user_id);

    user1->ids_following = (int*)realloc(user1->ids_following, (user1->num_following + 1) * sizeof(int));
    user1->ids_following[user1->num_following++] = user2->user_id;
}

void add_block(user* user1, user* user2)
{
    //No selfies
    if(user1 == user2 || !user1 || !user2)
        return;

    printf("User %d blocks User %d\n", user1->user_id, user2->user_id);
    
    user1->ids_blocked = (int*)realloc(user1->ids_blocked, (user1->num_blocked + 1) * sizeof(int));
    user1->ids_blocked[user1->num_blocked++] = user2->user_id;
}

void destroy_user_storage()
{
    for(int i = 0; i < total_users; ++i)
    {
        user* user = user_list[i];
        if(user != NULL)
        {
            if(user->name != NULL)
                free(user->name);
            if(user->URL_of_avatar!= NULL)
                free(user->URL_of_avatar);
            if(user->ids_blocked != NULL)
                free(user->ids_blocked);
            if(user->ids_following != NULL)
                free(user->ids_following);
            free(user);
        }
    }
    free(user_list);
}
