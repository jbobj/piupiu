
#include "user.h"
#include "piu.h"
#include "survey.h"


void setup();

int main(int argc, char* argv)
{
    setup();
    
    print_all_users();
    print_all_pius();
    
    destroy_user_storage();
    destroy_piu_storage();
}


void setup()
{
    user* bobby = create_user("Bobby", "bob39");
    user* billy = create_user("Billy", "killbill");
    user* susan = create_user("Susan", "smexysusan");
    user* marty = create_user("Marty", "DevilMayCare");
    user* ronda = create_user("Ronda", "RollingRonda");
    user* teddy = create_user("Teddy", "Bear");
    user* jason = create_user("Jason", "Villnas93");
    user* derpy = create_user("Derpy", "Doo");
    
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
    
    sleep(1);

    // Insert stupid PIU's here
    piu* piu1 = post_piu(susan, "Bill smells", 0);
    piu* piu2 = post_repiu(marty, piu1, 0);
    piu* piu3 = post_piu(billy, "Thats not nice!", 0);
    piu* piu4 = post_piu(billy, "Help me out here Bro.", 1);
    piu* piu5 = post_piu(derpy, "Sure thing dude.", 1);
    piu* piu6 = post_piu(derpy, "I think Bill smells quite nice.", 0);
    piu* piu7 = post_repiu(jason, piu6, 0);
    piu* piu8 = post_piu(billy, "That isn't what I meant...", 1);
}