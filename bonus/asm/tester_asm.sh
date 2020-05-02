#!/bin/sh

# CHEMIN ASM NOUS
ASM=./../../asm/asm

# CHEMIN ASM CORRECTION
CORRECTION=./.asm_correction
# FICHIER DES ERREURS
DIR=./redirection_test

execute_correct () {
    echo -en  "\033[1;36m$4\033[00m"
    if ! [ -e $1 ]; then
        echo -e "\033[1;33m	 	    UNKNOWN\033[00m"
        return
    fi
    # CREER LE DOSSIER STOCKAGE RESULTAT
    mkdir -p    $DIR/$4

    # CRER LES BIN
    $ASM        $1 2> /dev/null
    $CORRECTION $1 2> /dev/null
    if [ -e $2 ] || [ -e $3 ]; then

        # CREER LES OUTPUTS DE LA CORRECTION ET NOUS
        if [ -e $2 ]; then
        hexdump -C  $2  >   $DIR/$4/output.$4
        fi
        if [ -e $3 ]; then
        hexdump -C  $3  >   $DIR/$4/correction.$4
        fi

        # CHECK LES DIFFS
        diff    -N  $DIR/$4/output.$4 $DIR/$4/correction.$4 >   $DIR/$4/diff.$4

        # SI EXACT ON SUPPRIME LE DOSSIER

        if [ ! -e $2 ] || [ ! -e $3 ]; then
            echo    -ne  "\033[1;31m	    FICHIER CREER AVEC ERREUR POUR\033[00m"
            if [ -e $2 ]; then
                echo -e "\033[1;31m \"NOUS\"\033[00m"
            elif [ -e $3 ]; then
                echo -e "\033[1;31m \"CORRECTION\"\033[00m"
            fi
            return;
        elif  [ ! -s ./redirection_test/$4/diff.$4 ]; then
            rm -r $DIR/$4
            echo    -e  "\033[1;32m	    OK\033[00m"
        else
            echo    -e  "\033[1;31m	    DIFFERENCE\033[00m"
        fi

        # SUPPRESION DES ".cor"
        rm $2 $3
    else
            echo -e  "\033[1;31m	    ERROR\033[00m"
    fi
}

execute_bad () {
    echo -en  "\033[1;36m$4\033[00m"
    if ! [ -e $1 ]; then
        echo -e "\033[1;33m	 	    UNKNOWN\033[00m"
        return
    fi
    # CREER LE DOSSIER STOCKAGE RESULTAT
    mkdir -p    $DIR/$4

    # CREER LES BIN
    $ASM        $1 2> /dev/null
    $CORRECTION $1 2> /dev/null

    # CHECK SI LE FICHIER A ETE CREE POUR l'UN DES DEUX
    if [ -e $2 ] || [ -e $3 ]; then
        echo    -e  "\033[1;32m	    PAS UNE ERREUR\033[00m"
        echo    -e  "\033[1;32m	    GOOD\033[00m"
        execute_correct $1 $2 $3 $4
    elif [ -e $2 ] || [ -e $3 ]; then
        echo    -ne  "\033[1;31m	    FICHIER CREER AVEC ERREUR POUR\033[00m"
        if [ -e $2 ]; then
            echo -e "\033[1;31m \"NOUS\"\033[00m"
        elif [ -e $3 ]; then
            echo -e "\033[1;31m \"CORRECTION\"\033[00m"
        fi
    else
        echo    -e  "\033[1;32m	    OK\033[00m"
        rm -d $DIR/$4
    fi
}

# EXEMPLE (surtout copie)
#   TEST_NAME=NOM DU FICHIER (sans .s)
#   execute_correct ./tests/good/$TEST_NAME.s   ./tests/good/$TEST_NAME.cor     ./$TEST_NAME.cor    $TEST_NAME

# GOOD
echo -e "\033[1;35mGOOD\033[00m"
TEST_NAME=abel
execute_correct ./tests/good/$TEST_NAME.s   ./tests/good/$TEST_NAME.cor     ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=comment
execute_correct ./tests/good/$TEST_NAME.s   ./tests/good/comment.cor        ./comment.cor       $TEST_NAME
TEST_NAME=bill
execute_correct ./tests/good/$TEST_NAME.s   ./tests/good/$TEST_NAME.cor     ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=ok
execute_correct ./tests/good/$TEST_NAME.s   ./tests/good/$TEST_NAME.cor     ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=only_header
execute_correct ./tests/good/$TEST_NAME.s   ./tests/good/$TEST_NAME.cor     ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=pdd
execute_correct ./tests/good/$TEST_NAME.s   ./tests/good/$TEST_NAME.cor     ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=tyron
execute_correct ./tests/good/$TEST_NAME.s   ./tests/good/$TEST_NAME.cor     ./$TEST_NAME.cor    $TEST_NAME

# BAD
echo -e "\n\033[1;35mBAD\033[00m"
TEST_NAME=label
execute_bad ./tests/bad/$TEST_NAME.s    ./tests/good/$TEST_NAME.cor ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=empty
execute_bad ./tests/bad/$TEST_NAME.s    ./tests/good/$TEST_NAME.cor ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=no_header
execute_bad ./tests/bad/$TEST_NAME.s    ./tests/good/$TEST_NAME.cor ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=args
execute_bad ./tests/bad/$TEST_NAME.s    ./tests/good/$TEST_NAME.cor ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=comment
execute_bad ./tests/bad/$TEST_NAME.s    ./tests/good/$TEST_NAME.cor ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=name
execute_bad ./tests/bad/$TEST_NAME.s    ./tests/good/$TEST_NAME.cor ./$TEST_NAME.cor    $TEST_NAME
TEST_NAME=zjmp
execute_bad ./tests/bad/$TEST_NAME.s    ./tests/good/$TEST_NAME.cor ./$TEST_NAME.cor    $TEST_NAME
