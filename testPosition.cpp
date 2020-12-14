#include "doctest.h"
#include<sstream>
#include "position.h"

TEST_CASE("Test des déplacements") {
  double x = 31;
  double y = 15;
  int deplacement = 10;
  position pos=position(31,15);
SUBCASE( "Le deplacement de x est correct" ) {
    pos.deplaceX(10);
    REQUIRE_EQ(pos.x(), x+deplacement);
}
SUBCASE( "Le deplacement de y est correct" ) {
    pos.deplaceY(10);
    REQUIRE_EQ(pos.y(), y+deplacement);

}
}
