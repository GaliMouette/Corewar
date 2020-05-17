#!/bin/sh

CHAMPS=./bonus/corewar/champs
BIN=./corewar/corewar
CORRECTION=./bonus/corewar/.corewar_correction
DIR_TEST=./bonus/corewar/tests/

function check_status {
    if [ $STATUS_BIN -ne 0 ] && [ $STATUS_CORRECTION -eq 0 ]; then
        echo -e    "\033[1;31m\"\tDIFF BETWEEN EXIT STATUS\"\n\033[00m"
        return
    elif [ $STATUS_BIN -eq 0 ] && [ $STATUS_CORRECTION -ne 0 ]; then
        echo -e    "\033[1;31m\"\tDIFF BETWEEN EXIT STATUS\"\n\033[00m"
        return
    else
        echo -e    "\033[1;32m\tOK\033[00m"
    fi
}

function get_status {
    if [ $3 -eq 0 ]; then
        $CORRECTION 2> /dev/null $1  | grep "gagné" | cut -d ' ' -f3,4 > "$2/correction"
        STATUS_CORRECTION=$?
        echo -n " : "
        $BIN        2> /dev/null $1  | grep "has won" | cut -d ' ' -f3,4> "$2/corewar"
        STATUS_BIN=$?
    else
        $CORRECTION 2> /dev/null $1  > /dev/null
        STATUS_CORRECTION=$?
        $BIN        2> /dev/null $1  > /dev/null
        STATUS_BIN=$?
    fi
}

function check_diff {
    diff -N "$1/correction" "$1/corewar" > "$1/diff"
    if [ ! -s "$1.diff" ]; then
        rm -r "$1"
        echo    -e  "\033[1;32m\tOK\033[00m"
    else
        echo    -e  "\033[1;31m\tDIFFERENCE\033[00m"
    fi
}

function execution {
    echo -en         "\033[1;36m$1\033[00m"
    if [ $3 -eq 0 ]; then
        mkdir -p    "$DIR_TEST$1"
    fi
    get_status      "$2" "$DIR_TEST$1" $3
    if [ $3 -eq 1 ]; then
        check_status
        return
    fi
    check_diff "$DIR_TEST$1"
}

if [ ! -e $BIN ] || [ ! -e $CORRECTION ] || [ ! -e $CHAMPS ] || [ ! -e $DIR_TEST ]; then
    echo "Missing binary files or directory to send result."
    exit 1
fi

echo -e "\033[1;33mBAD\033[00m"
execution "Bad option : -n, manquant"       "-n $CHAMPS/abel.cor $CHAMPS/42.cor"        1
execution "Bad option : -n, value"          "$CHAMPS/abel.cor -n 5 $CHAMPS/42.cor"      1
execution "Bad option : -a, manquant"       "-a $CHAMPS/abel.cor $CHAMPS/42.cor"        1
execution "Bad option : -a, value"          "$CHAMPS/abel.cor -a QSD $CHAMPS/42.cor"    1
execution "Bad option : nothing"            ""                                          1
execution "Bad option : bad files"          "$CHAMPS/no.aze"                            1
echo -e "\033[1;33mGOOD\033[00m"
# echo "TEST 1 champion"
# execution "1 champion rien"                                     "$CHAMPS/abel.cor" 0
#
# execution "1 champion une adresse renseignée"                   "-a 5F5 $CHAMPS/abel.cor" 0
# execution "1 champion un numéro renseigné"                      "-n 2 $CHAMPS/abel.cor" 0
#
# execution "1 champion numéro et adresses renseigné"             "-n 2 -a 5F5$CHAMPS/abel.cor" 0
#

# echo "TEST 2 champions"
execution "2champs"                 "$CHAMPS/abel.cor $CHAMPS/42.cor" 0                         #2 champions
execution "2champs_1_address1"      "-a 5F5 $CHAMPS/abel.cor $CHAMPS/42.cor" 0                  #2 champions une adresse renseignée pos 1
execution "2champs_1_address2"      "$CHAMPS/abel.cor -a 5F5 $CHAMPS/42.cor" 0                  #2 champions une adresse renseignée pos 2
execution "2champs_2_address1_2"    "-a 5F5 $CHAMPS/abel.cor -a BA $CHAMPS/42.cor" 0            #2 champions deux adresses renseignées
execution "2champs_1_numero1"       "-n 2 $CHAMPS/abel.cor $CHAMPS/42.cor" 0                    #2 champions un numéro renseigné pos 1
execution "2champs_1_numero2"       "$CHAMPS/abel.cor -n 2 $CHAMPS/42.cor" 0                    #2 champions un numéro renseigné pos 2
execution "2champs_2_numero1_2"     "-n 1 $CHAMPS/abel.cor -n 2 $CHAMPS/42.cor" 0               #2 champions deux numéros renseignés
execution "2champs_2_numero1_2"     "-n 1 -a 5F5 $CHAMPS/abel.cor -n 3 -a BA $CHAMPS/42.cor" 0  #2 champions deux adresses et numéros renseignées


# echo "TEST 3 champions"
execution "3champs"                 "$CHAMPS/abel.cor $CHAMPS/42.cor $CHAMPS/abel.cor" 0                        # 3 champions
execution "3champs_1_address1"      "-a 5F5 $CHAMPS/abel.cor $CHAMPS/42.cor $CHAMPS/bill.cor" 0                 # 3 champions une adresse renseignée pos 1
execution "3champs_1_address2"      "$CHAMPS/abel.cor -a 5F5 $CHAMPS/42.cor $CHAMPS/bill.cor" 0                 # 3 champions une adresse renseignée pos 2
execution "3champs_1_address3"      "$CHAMPS/abel.cor $CHAMPS/42.cor -a 5F5 $CHAMPS/bill.cor" 0                 # 3 champions une adresse renseignée pos 3
execution "3champs_2_address1_2"    "-a 5E3 $CHAMPS/abel.cor -a 162E $CHAMPS/42.cor $CHAMPS/bill.cor" 0         # 3 champions deux adresses renseignées pos 1 et 2
execution "3champs_2_address2_3"    "$CHAMPS/abel.cor -a 162E $CHAMPS/42.cor -a 5E3 $CHAMPS/bill.cor" 0         # 3 champions deux adresses renseignées pos 2 et 3
execution "3champs_2_address1_3"    "-a 5E3 $CHAMPS/abel.cor $CHAMPS/42.cor -a 162E $CHAMPS/bill.cor" 0         # 3 champions deux adresses renseignées pos 1 et 3
execution "3champs_3_address1_2_3"  "-a 5E3 $CHAMPS/abel.cor -a 162E $CHAMPS/42.cor -a 8F $CHAMPS/bill.cor" 0   # 3 champions trois adresses renseignées
execution "3champs_1_numero1"       "-a 5F5 $CHAMPS/abel.cor $CHAMPS/42.cor $CHAMPS/bill.cor" 0                 # 3 champions un numéro renseigné pos 1
execution "3champs_1_numero2"       "$CHAMPS/abel.cor -a 5F5 $CHAMPS/42.cor $CHAMPS/bill.cor" 0                 # 3 champions un numéro renseigné pos 2
execution "3champs_1_numero3"       "$CHAMPS/abel.cor $CHAMPS/abel.cor -a 5F5 $CHAMPS/bill.cor" 0               # 3 champions une numéro renseigne pos 3
execution "3champs_2_numero1_2"     "-a 5E3 $CHAMPS/abel.cor -a 162E $CHAMPS/42.cor $CHAMPS/bill.cor" 0         # 3 champions deux numéros renseignés pos 1 et 2
execution "3champs_2_numero2_3"     "$CHAMPS/abel.cor -a 162E $CHAMPS/42.cor -a 5E3 $CHAMPS/bill.cor" 0         # 3 champions deux numéros renseignés pos 2 et 3
execution "3champs_2_numero1_3"     "-a 5E3 $CHAMPS/abel.cor $CHAMPS/42.cor -a 162E $CHAMPS/bill.cor" 0         # 3 champions deux numéros renseignés pos 1 et 3
execution "3champs_3_numero1_2_3"   "-a 5E3 $CHAMPS/abel.cor -a 162E $CHAMPS/42.cor -a 8F $CHAMPS/bill.cor" 0   # 3 champions trois numéros renseignés


# echo "TEST 4 champions"
# execution "4 champions aucune adresse renseigné"        "$CHAMPS/abel.cor $CHAMPS/42.cor $CHAMPS/bill.cor $CHAMPS/ebola.cor" 0
# execution "4 champions une adresse renseignée"          "$CHAMPS/abel.cor -a 3654 $CHAMPS/42.cor $CHAMPS/bill.cor $CHAMPS/ebola.cor" 0
# execution "4 champions deux adresses renseignées"       "$CHAMPS/abel.cor $CHAMPS/42.cor -a 4763 $CHAMPS/bill.cor -a 3D7 $CHAMPS/ebola.cor" 0
# execution "4 champions quatre adresses renseignées"     "-a 346 $CHAMPS/abel.cor -a 2 $CHAMPS/42.cor -a FD45 $CHAMPS/bill.cor -a 68A $CHAMPS/ebola.cor" 0
