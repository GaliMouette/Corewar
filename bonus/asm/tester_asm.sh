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
        hexdump -C  $2  >   $DIR/$4/output.$4
        hexdump -C  $3  >   $DIR/$4/correction.$4

        # CHECK LES DIFFS
        diff    -N  $DIR/$4/output.$4 $DIR/$4/correction.$4 >   $DIR/$4/diff.$4

        # SI EXACT ON SUPPRIME LE DOSSIER

        if [ ! -e $2 ] || [ ! -e $3 ]; then
            echo    -e  "\033[1;31m	    FICHIER CREER POUR L'UN DES DEUX ASSEMBLEUR\033[00m"
        elif ! [[ -s ./redirection_test/$4/diff.$4 ]]; then
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
    fi
}


#EXECUTE FILES TO COMPILE (.s)      FILE TO COMPILE WITH US (.cor)      FILE TO COMPILE WITH CORRECTION         NAME TEST

# GOOD
echo -e "\033[1;35mGOOD\033[00m"
execute_correct ./tests/good/abel.s         ./tests/good/abel.cor          ./abel.cor           abel
execute_correct ./tests/good/comment        ./tests/good/comment.cor        ./comment.cor       comment
execute_correct ./tests/good/bill.s         ./tests/good/bill.cor          ./bill.cor           bill
execute_correct ./tests/good/ok.s           ./tests/good/ok.cor            ./ok.cor             ok
execute_correct ./tests/good/only_header.s  ./tests/good/only_header.cor   ./only_header.cor    only_header
execute_correct ./tests/good/pdd.s          ./tests/good/pdd.cor           ./pdd.cor            pdd
execute_correct ./tests/good/tyron.s        ./tests/good/tyron.cor         ./tyron.cor          tyron
execute_correct ./tests/good/try.s          ./tests/good/try.cor           ./try.cor            try

# BAD
echo -e "\n\033[1;35mBAD\033[00m"
execute_bad     ./tests/bad/label.s         ./tests/good/label.cor         ./label.cor          label
execute_bad     ./tests/bad/empty.s         ./tests/good/empty.cor         ./empty.cor          empty
execute_bad     ./tests/bad/no_header.s     ./tests/good/no_header.cor     ./no_header.cor      no_header
execute_bad     ./tests/bad/args.s          ./tests/good/args.cor          ./args.cor           args
execute_bad     ./tests/bad/comment.s       ./tests/good/comment.cor       ./comment.cor        comment
execute_bad     ./tests/bad/name.s          ./tests/good/name.cor          ./name.cor           name
