#!/bin/sh

# CHEMIN ASM NOUS
ASM=./asm/asm

# CHEMIN ASM CORRECTION
CORRECTION=./corewar_binaries/asm/asm

# FICHIER DES ERREURS
DIR=./redirection_test

execute () {

    echo -en  "\033[1;36m$4\033[00m"
    if ! [ -e $1 ]; then
        echo -e "\033[1;33m	 UNKNOWN\033[00m"
        return
    fi
    # CREER LE DOSSIER STOCKAGE RESULTAT
    mkdir -p    $DIR/$4

    $ASM        $1 2> /dev/null
    $CORRECTION $1 2> /dev/null
    if [ -e $2 ] || [ -e $3 ]; then

        # CREER LES OUTPUTS DE LA CORRECTION ET NOUS
        hexdump -C  $2  >   $DIR/$4/output.$4
        hexdump -C  $3  >   $DIR/$4/correction.$4

        # CHECK LES DIFFS
        diff    -N  $DIR/$4/output.$4 $DIR/$4/correction.$4 >   $DIR/$4/diff.$4

        # SI EXACT ON SUPPRIME LE DOSSIER

        if ! [[ -s ./redirection_test/$4/diff.$4 ]]; then
            rm -r $DIR/$4
            echo -e  "\033[1;32m	 OK\033[00m"
        else
            echo -e  "\033[1;31m	 DIFFERENCE\033[00m"
        fi

        # SUPPRESION DES ".cor"
        rm $2 $3
    else
            echo -e  "\033[1;31m	 ERROR\033[00m"
    fi
}


#EXECUTE FILES TO COMPILE (.s)      FILE TO COMPILE WITH US (.cor)      FILE TO COMPILE WITH CORRECTION         NAME TEST

execute ./corewar_binaries/corewar/assets/champions/src/abel.s  ./corewar_binaries/corewar/assets/champions/src/abel.cor   abel.cor    abel
execute ./corewar_binaries/corewar/assets/champions/src/bill.s  ./corewar_binaries/corewar/assets/champions/src/bill.cor   bill.cor    bill
execute ./tests/bad/empty.s                                     ./tests/bad/empty.cor                                      empty.cor   empty
