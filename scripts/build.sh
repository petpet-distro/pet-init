#!/bin/sh

set -e; # exit on error

if [ "$CC" = "" ]; then
        CC="gcc"
fi

if [ "$LD" = "" ]; then
        LD="ld"
fi

if [ "$CFLAGS" = "" ]; then
        CFLAGS="-march=x86-64 -O0 -static"
fi

objBuildie() {
        printf "\tCCo\t%s\n" "$2"

        "$CC" $CFLAGS -c -o "$1" "$2"
}

binBuildie() {
        printf "\tCCb\t%s\n" "$1"

        "$CC" $CFLAGS -o "$1" "$2"
}

linkieStat() {
        printf "\tLDs\t%s\n" "$1"

        "$LD" $LDFLAGS -r -o $@
}

objBuildie "build/obj/handlers/sigint.o" "src/handlers/sigint.c"
objBuildie "build/obj/handlers/sigterm.o" "src/handlers/sigterm.c"

objBuildie "build/obj/handlerApplicators/applySIGINT.o" "src/handlerApplicators/applySIGINT.c"
objBuildie "build/obj/handlerApplicators/applySIGTERM.o" "src/handlerApplicators/applySIGTERM.c"

objBuildie "build/obj/helpers/applyHandlers.o" "src/helpers/applyHandlers.c"
objBuildie "build/obj/helpers/spawn.o" "src/helpers/spawn.c"

objBuildie "build/obj/main.o" "src/main.c"

linkieStat "build/obj/handlers.o" "build/obj/handlers/sigint.o" "build/obj/handlers/sigterm.o"
linkieStat "build/obj/handlerApplicators.o" "build/obj/handlerApplicators/applySIGTERM.o" "build/obj/handlerApplicators/applySIGINT.o"
linkieStat "build/obj/helpers.o" "build/obj/helpers/applyHandlers.o" "build/obj/helpers/spawn.o"

linkieStat "build/obj/mix.o" "build/obj/handlers.o" "build/obj/handlerApplicators.o" "build/obj/main.o" "build/obj/helpers.o"

binBuildie "build/bin/petinit" "build/obj/mix.o"
