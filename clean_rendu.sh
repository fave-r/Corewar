#!/bin/sh
grep -rs --exclude=clean_rendu.sh --color=always "printf"
grep -rs --exclude=clean_rendu.sh --color=always "<stdio.h>"
grep --exclude=clean_rendu.sh --color=always "ggdb3" Makefile
grep --exclude=clean_rendu.sh --color=always "g3" Makefile
grep -rs --exclude=clean_rendu.sh --color=always "coucou"
make fclean
rm -rf *~
cp ~/Downloads/norme .
python norme -nocheat *
echo "-------------------"
python norme -nocheat */*
echo "-------------------"
rm norme
mv clean_rendu.sh ~/
