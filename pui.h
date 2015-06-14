#ifndef PUI_H
#define PUI_H

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



#endif