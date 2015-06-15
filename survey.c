#include "user.h"
#include "piu.h"
#include "survey.h"
#include "util.h"
#include "stdlib.h"
#include "memory.h"
#include "assert.h"

// Storage of surveillance requests
static int num_requests;
static surveillance_request * requests_to_scan;

surveillance_request* create_surveillance_request(int num_patterns, FILE* file)
{
    int id = num_requests;
    requests_to_scan = (surveillance_request*)realloc(requests_to_scan, ++num_requests * (sizeof(surveillance_request)));
    requests_to_scan[id].id_number = id;
    requests_to_scan[id].write_here = file;

    requests_to_scan[id].num_patterns = num_patterns;
    requests_to_scan[id].user_patterns = calloc(num_patterns, sizeof(user));
    requests_to_scan[id].piu_patterns = calloc(num_patterns, sizeof(piu));

    return requests_to_scan + id;
}

void add_block_pattern(surveillance_request* request, int pattern_index, int user_id)
{
    assert(request && request->num_patterns > pattern_index);
    add_block_id(request->user_patterns + pattern_index, user_id);
}

void add_follow_pattern(surveillance_request* request, int pattern_index, int user_id)
{
    assert(request && request->num_patterns > pattern_index);
    add_following_id(request->user_patterns + pattern_index, user_id);
}

void set_piu_pattern(surveillance_request* request, int pattern_index, const char* message_substring, int poster_id, int repui_id, int repui_user_id)
{
    assert(request && request->num_patterns > pattern_index);
    piu* piu_message = request->piu_patterns + pattern_index;
    if (message_substring)
    {
        strncpy(piu_message->piu_text_utf8, message_substring, sizeof(piu_message->piu_text_utf8));
        piu_message->piu_length = strlen(piu_message->piu_text_utf8);
    }
    if(poster_id)
        piu_message->user_id_of_poster = poster_id;
    if(repui_id)
        piu_message->piu_id_of_repiu = repui_id;
    if(repui_user_id)
        piu_message->user_id_of_repiu;
}


/*
    A surveillance request is an array of N user-Piu patterns. If the input Piu matches one of these patterns,
    archive (fwrite) the Piu to the FILE handle.

    The input Piu matches a user-piu pattern if:

    1.) The Piu text in the pattern is a substring of the input Piu’s text; AND
    2.) All ids_following and ids_blocked in the user pattern are followed/blocked by the input Piu’s user; AND
    3.) All of the NONZERO fields in the piu pattern match the input Piu. Values set to zero are “don’t care” inputs.

 */
void surveil(piu* entry)
{

}
