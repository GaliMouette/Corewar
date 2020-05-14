#!/bin/bash

echo Test 1 Missing dump argument. / Argument of -dump option is not hexa.
./corewar/corewar -dump test.cor
echo -e "\n"

echo Test 2 Dump argument is not hexadecimal.
./corewar/corewar -dump gvbhj test.cor
echo -e "\n"

echo Test 3 Double definition of dump.
./corewar/corewar -dump 3 -dump 4 test.cor
echo -e "\n"

echo Test 4 OK
./corewar/corewar -dump 3 test.cor
echo -e "\n"

echo Test 5 OK
./corewar/corewar -dump 3
echo -e "\n"

echo Test 6 Missing argument -n option. / Argument of -n option is not a number.
./corewar/corewar -n test.cor
echo -e "\n"

echo Test 7 Argument of -n option is not a number.
./corewar/corewar -n bik test.cor
echo -e "\n"

echo Test 8 Player number must be between 1 and 4.
./corewar/corewar -n 0 test.cor
echo -e "\n"

echo Test 9 Player number must be between 1 and 4.
./corewar/corewar -n 5 test.cor
echo -e "\n"

echo Test 10 OK
./corewar/corewar -n 4 test.cor
echo -e "\n"

echo Test 11 OK
./corewar/corewar -n 4
echo -e "\n"

echo Test 12 Multiple definition -n option.
./corewar/corewar -n 3 -n 4 test.cor
echo -e "\n"

echo Test 13 Player number already attributed.
./corewar/corewar -n 3 test.cor -n 3 test.cor
echo -e "\n"

echo Test 14 Missing argument -a option. / Argument of -n option is not a number.
./corewar/corewar -a test.cor
echo -e "\n"

echo Test 15 Argument of -a option is not hexadecimal.
./corewar/corewar -a bjknl test.cor
echo -e "\n"

echo Test 16 OK
./corewar/corewar -a A3 test.cor
echo -e "\n"

echo Test 17 OK
./corewar/corewar -a A3
echo -e "\n"

echo Test 18 Multiple definition -a option.
./corewar/corewar -a 1 -a 2 test.cor
echo -e "\n"

echo Test 19 OK
./corewar/corewar -dump 4567F -n 3 -a B4 test.cor -n 2 test1.cor -a 3F test2.cor
echo -e "\n"

echo Test 20 Multiple definition -a option.
./corewar/corewar -a 1 -n 2 -a 2 test.cor
echo -e "\n"

echo Test 21 Multiple definition -n option.
./corewar/corewar -n 1 -a 2 -n 2 test.cor
echo -e "\n"
