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

// Create a new request with specific number of patterns
surveillance_request* create_surveillance_request(int num_patterns, FILE* file);

// Set fields to search for in a PIU in a surveillance_request. 0 or NULL is optional
void set_piu_pattern(surveillance_request* request, int pattern_index, const char* message_substring, int poster_id, int repui_id, int repui_user_id);

// Add a block user id to a pattern within a surveillance_request
void add_follow_pattern(surveillance_request* request, int pattern_index, int user_id);

// Add a following user id to a pattern within a surveillance_request
void add_block_pattern(surveillance_request* request, int pattern_index, int user_id);

// DOCUMENTATION REDACTED
void surveil( piu * entry );


#endif
