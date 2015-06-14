#include "user.h"
#include "piu.h"
#include "survey.h"


void create_users_1();
void createUsers2();

int main(int argc, char* argv)
{
    create_users_1();
    
    print_all_users();
    
    destroy_user_storage();
}


void create_users_1()
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
    add_following(jason, derpy);
    
    add_block(susan, jason);
    add_block(susan, derpy);
    add_block(susan, marty);
    add_block(derpy, susan);
}