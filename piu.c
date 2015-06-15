#include "piu.h"
#include "survey.h"
#include "assert.h"
#include "stdlib.h"
#include "string.h"

static piu** piu_list = NULL;
static int piu_list_size = 0;
static int total_pius = 0;


// Fill out common fileds between normal and re piu's
piu* create_piu(user* poster, const char* piu_text, unsigned char private_post)
{
    assert(poster);
    assert(piu_text);

    //Resize user list array
    if(piu_list_size <= total_pius)
    {
        piu_list_size = piu_list_size == 0 ? 10 : piu_list_size * 2;
        piu_list = (piu**)realloc(piu_list, piu_list_size * ((sizeof(void*))));
    }

    int index = total_pius++;
    piu* new_piu = piu_list[index] = (piu*)calloc(1, sizeof(piu));

    // 0 is an empty PIU ID, so all IDs are index + 1
    new_piu->piu_id = index + 1;
    strncpy(new_piu->piu_text_utf8, piu_text, sizeof(new_piu->piu_text_utf8));
    new_piu->piu_length = strlen(new_piu->piu_text_utf8);

    new_piu->poster = poster;
    new_piu->user_id_of_poster = poster->user_id;
    new_piu->visible_only_to_followers = private_post;

    // Update last active time on user
    poster->last_activity = time(NULL);
    return new_piu;
}

// Perform preprocessing before PIU is databased
int preprocess(piu* entry)
{
    // TODO Uncomment when Hadrian finishs validation function
    //if (validate(entry))
    {
        surveil(entry);
        // TODO Uncomment when Jenny finishes database functions
        // database_piu(entry);
        return 1;
    }
    return 0;
}

piu* post_piu(user* poster, const char* piu_text, unsigned char private_post)
{
    piu* new_piu =  create_piu(poster, piu_text, private_post);

    preprocess(new_piu);
    return new_piu;
}


piu* post_repiu(user* poster, piu* piu_2_repiu, unsigned char private_post)
{
    //assert(user);
    assert(piu_2_repiu);
    piu* repiu = create_piu(poster, piu_2_repiu->piu_text_utf8, private_post);
    repiu->piu_id_of_repiu = piu_2_repiu->piu_id;
    repiu->user_id_of_repiu = piu_2_repiu->user_id_of_poster;

    preprocess(repiu);

    return repiu;
}

piu* get_piu(int piu_id)
{
    // PUI-ID 0 is invalid, so all PUI-ID is offset by 1 to the index
    if (piu_id > 0 && piu_id <= total_pius)
    {
        return piu_list[piu_id - 1];
    }
    return NULL;
}


void print_all_pius()
{
    for(int i = 0; i < total_pius; ++i)
        print_piu(piu_list[i]);
}

void print_piu(piu* piu)
{
    printf("Poster: %s (%d)\n", piu->poster->name, piu->poster->user_id);
    printf(piu->visible_only_to_followers ?
        "Private Message: %s\n" : "Public Message: %s\n", piu->piu_text_utf8);
    if(piu->piu_id_of_repiu)
    {
        user* repiu_user = get_user(piu->user_id_of_repiu);
        printf("RE-PIU of User %s (%d)\n", repiu_user->name, repiu_user->user_id);
    }
    printf("\n");
}


void destroy_piu_storage()
{
    for (int i = 0; i < total_pius; ++i)
    {
        free(piu_list[i]);
    }
    free(piu_list);
    piu_list_size = total_pius = 0;
    piu_list = NULL;
}
