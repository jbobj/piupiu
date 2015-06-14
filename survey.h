#ifndef SURVEY_H
#define SURVEY_H

#include "user.h"


typedef struct surveillance_request_struct {
        int id_number;
        int num_patterns;
        user * user_patterns;
        piu * piu_patterns;
        FILE * write_here;
} surveillance_request;

#endif