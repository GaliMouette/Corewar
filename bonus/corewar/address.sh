#!/bin/sh

echo "TEST 1 champion"
echo "1champion"
./corewar/corewar 2.cor
echo ""
echo ""

echo "TEST 2 champions\n"
echo "2 champions aucune adresse renseigné"
./corewar/corewar 2.cor 3.cor
echo ""
echo "2 champions une adresse renseignée"
./corewar/corewar -a 5F5 2.cor 3.cor
echo ""
echo "2 champions deux adresses renseignées"
./corewar/corewar -a 5F5 2.cor -a BA 3.cor
echo ""
echo ""

echo "TEST 3 champions"
echo "3 champions aucune adresse renseigné"
./corewar/corewar 2.cor 3.cor 4.cor
echo ""
echo "3 champions une adresse renseignée"
./corewar/corewar -a 5F5 2.cor 3.cor 4.cor
echo ""
echo "3 champions deux adresses renseignées"
./corewar/corewar -a 5E3 2.cor -a 162E 3.cor 4.cor
echo ""
echo "3 champions trois adresses renseignées"
./corewar/corewar -a 3 2.cor -a 3FF 3.cor -a 22F 4.cor

echo ""
echo ""
echo "TEST 4 champions"
echo "4 champions aucune adresse renseigné"
./corewar/corewar 2.cor 3.cor 4.cor defeat.cor
echo ""
echo "4 champions une adresse renseignée"
./corewar/corewar 2.cor -a 3654 3.cor 4.cor defeat.cor
echo ""
echo "4 champions deux adresses renseignées"
./corewar/corewar 2.cor 3.cor -a 4763 4.cor -a 3D7 defeat.cor
echo ""
echo "4 champions trois adresses renseignées"
./corewar/corewar -a 10DE 2.cor 3.cor -a 20C 4.cor -a 4C6 defeat.cor
echo ""
./corewar/corewar -a 0 2.cor -a 200 3.cor 4.cor -a D00 defeat.cor
echo ""
./corewar/corewar -a 278 2.cor -a 2AFB 3.cor -a 1F4 4.cor defeat.cor
echo ""
echo "4 champions quatre adresses renseignées"
./corewar/corewar -a 346 2.cor -a 2 3.cor -a FD45 4.cor -a 68A defeat.cor
