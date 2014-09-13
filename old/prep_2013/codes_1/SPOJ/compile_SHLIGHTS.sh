#!/bin/bash

CFLAGS=

if [[ "$#" == "1" ]] && [[ "$1" == "debug" ]]; then
        echo "Debugging enabled"
        CFLAGS="-DDEBUG -g -O0"
fi

gcc ${CFLAGS} SHLIGHTS_simulate.c -o SHLIGHTS_simulate
gcc ${CFLAGS} SHLIGHTS.c -o SHLIGHTS
