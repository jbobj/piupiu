#ifndef PUIPUISTRUCTS_H
#define PUIPUISTRUCTS_H

#include <stdio.h>
#include <time.h>


typedef struct user_struct {
        int user_id;
        time_t when_created;
        time_t last_activity;
        char * name;
        char * URL_of_avatar;

        int num_following, * ids_following;
        int num_blocked, * ids_blocked;
} user;

typedef struct piu_struct {
        int piu_id;
        int piu_id_of_repiu, user_id_of_repiu;    /* zero if not a re-Piu */

        int user_id_of_poster;
        user * poster;              

        char piu_text_utf8[140*4+1];
        unsigned char piu_length;
        unsigned char visible_only_to_followers;
} piu;


// Create a new user
user* create_user(char* user_name, char* url);

// Get user if exists or NULL if not
user* get_user(int user_id);

int get_num_users();

// Print user
void print_user(user* user);

// Print all users
void print_all_users();

// Make User 1 follow user 2
void add_following(user* user1, user* user2);

// Make user 1 block user 2
void add_block(user* user1, user* user2);

// Destroy user storage
void destroy_user_storage();


#endif