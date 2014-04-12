/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Sat Apr 12 16:47:32 2014 alex-odet
*/

/*
** Ne pas passer ce fichier dans la moulinette de Norme.
*/

#include "op.h"

op_t    op_tab[] =
  {
    /* 0*/{"live", 1, {T_DIR}, 1, 10, "alive"},
    /*1*/{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    /*2*/{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    /*3*/{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    /*4*/{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    /*5*/{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    /*6*/{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    /*7*/{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    /*8*/{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    /*9*/{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    /*10*/{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    /*11*/{"fork", 1, {T_DIR}, 12, 800, "fork"},
    /*12*/{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    /*13*/{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    /*14*/{"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    /*15*/{"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
  };
