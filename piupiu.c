
#include "user.h"
#include "piu.h"
#include "survey.h"
#include "unistd.h"

void create_users();
void create_requests();
void create_pius();

// Users
static user* bobby, * billy, * susan, * marty, * ronda, * teddy, * jason, * derpy;

// Output Files
FILE* file1;

int main(int argc, char* argv)
{
    create_users();
    create_requests();
    sleep(1);
    create_pius();

    print_all_users();
    print_all_pius();

    destroy_user_storage();
    destroy_piu_storage();
}


void create_users()
{
    bobby = create_user("Bobby", "bob39");
    billy = create_user("Billy", "killbill");
    susan = create_user("Susan", "smexysusan");
    marty = create_user("Marty", "DevilMayCare");
    ronda = create_user("Ronda", "RollingRonda");
    teddy = create_user("Teddy", "Bear");
    jason = create_user("Jason", "Villnas93");
    derpy = create_user("Derpy", "Doo");

    add_following(bobby, billy);
    add_following(susan, bobby);
    add_following(billy, marty);
    add_following(susan, marty);
    add_following(marty, ronda);
    add_following(ronda, teddy);
    add_following(teddy, jason);
    add_following(derpy, billy);
    add_following(jason, derpy);

    add_block(susan, jason);
    add_block(susan, derpy);
    add_block(susan, marty);
    add_block(derpy, susan);
}

void create_requests()
{
    // Request1: All posts of users following Sketch Susan using key words
    surveillance_request* request1 = create_surveillance_request(2, file1);
    add_follow_pattern(request1, 0, susan->user_id);
    add_follow_pattern(request1, 1, susan->user_id);
    set_piu_pattern(request1, 0, "Bomb", 0, 0, 0);
    set_piu_pattern(request1, 1, "shell", 0, 0, 0);
}


void create_pius()
{
    // Insert stupid PIU's here
    piu* piu1 = post_piu(susan, "Bill smells", 0);
    piu* piu2 = post_repiu(marty, piu1, 0);
    piu* piu3 = post_piu(billy, "Thats not nice!", 0);
    piu* piu4 = post_piu(billy, "Help me out here Bro.", 1);
    piu* piu5 = post_piu(derpy, "Sure thing dude.", 1);
    piu* piu6 = post_piu(derpy, "Bill smells quite nice.", 0);
    piu* piu7 = post_repiu(jason, piu6, 0);
    piu* piu8 = post_piu(billy, "That isn't what I meant...", 1);
}
