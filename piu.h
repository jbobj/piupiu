#ifndef PIU_H
#define PIU_H

#include "user.h"

typedef struct piu_struct {
        int piu_id;
        int piu_id_of_repiu, user_id_of_repiu;    /* zero if not a re-Piu */

        int user_id_of_poster;
        user * poster;              

        char piu_text_utf8[140*4+1];
        unsigned char piu_length;
        unsigned char visible_only_to_followers;
} piu;

// Post a  brand new PUI
piu* post_piu(
    user* poster,
    const char* piu_text,
    unsigned char visible);
    
    
// Post a re-piu
piu* post_repiu(
    user* poster,
    piu* piu_2_repiu,
    unsigned char visible);

// Get a PUI by ID
piu* get_piu(int piu_id);

//Destry PUI storage
void destroy_piu_storage();


#endif