#define CATCH_CONFIG_MAIN

#include "../funkcijos.h"
#include "catch.hpp"



TEST_CASE( "/FUNKCIJOS ""NUSKAITYMAS"" TESTAVIMAS/" ) {
    SECTION(" NUSKAITYMAS IS NE ESANCIO FAILO "){

        REQUIRE(Nuskaitymas("tikrai_tokio_nera", Mmap) == 0);
    }
    SECTION(" NUSKAITYMAS IS TUSCIO FAILO "){
        Nuskaitymas("tuscias", Mmap);

        REQUIRE(Mmap.size() == 0);
    }
    SECTION(" NUSKAITYMAS IS FAILO TEKSTAS.TXT "){
        Nuskaitymas("tekstas", Mmap);

        REQUIRE(Mmap.size()== 2828);
    }

}

