/******************************************************************************
*
*           Module Name: TOSS.C
*        Classification: Unclassified
*               Version: 1.0
*
*           Environment: IBM OS/2 2.0+
*              Compiler: IBM C-Set/2 1.0 /O+
*
*               Purpose: A filter which deletes lines containing any of the 
*                        text passed as command line parameters to this
*                        routine
*
*               Example: icc /Kb xyz.c | toss EDC01234 EDC4321 > xyz.err
*                        this will remove all lines containing the text
*                        "EDC001234" and EDC4321" from the stream.
*
* -- change activity log --
* Ver.  Date     AUTH    Loc.  -  Change
*
* 1.0   92/01/11  IA     10    - program created.
******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]);
char line_buff[32768];      /* 32K line length should be enough */

int main(int argc, char *argv[])
{
   register int i;  /* use register to enforce no taking the address of i */

   while (gets(line_buff)) {
      for (i = 1; i < argc ; i++)
         if (!strstr(line_buff, argv[i]))
            puts(line_buff);
         else
            break;
   } /* endwhile */
   return 0;
}

