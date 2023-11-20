#include "sub.h"

void libft() {
    char s[] = "Rnpu cebwrpg bs gur 97 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe rnpu pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe gur arkg pvepyr. Guvf punyyratr vf vaqvivqhny, gurer vf bayl n cevmr sbe bar fghqrag jvaare cebivqvat nyy qrpbqrq zrffntrf. Nal nqinagntrq crbcyr pna cynl, yvxr pheerag be sbezre fgnss, ohg gur cevmr jvyy erznva flzobyvp. Gur uvag sbe guvf svefg cebwrpg vf: Ynetr pbjf trarebfvgl pbzrf jvgu punegf naq sbhe oybaqr ungf gb qrsl hccre tenivgl ureb";

    int shift = 13;
    int i = 0;
    
    while (s[i]) {
        if (isalpha(s[i])) {
            char base = (s[i] >= 'a' && s[i] <= 'z') ? 'a' : 'A';
            s[i] = base + (s[i] - base - shift + 26) % 26;
        }
        i++;
    }

    printf("%s\n", s);

    /*

    Each project of the 97 Common Core contains an encoded hint. For each circle, only one project provides the correct hint needed for the next circle. This challenge is individual, there is only a prize for one student winner providing all decoded messages. Any advantaged people can play, like current or former staff, but the prize will remain symbolic. The hint for this first project is: Large cows generosity comes with charts and four blonde hats to defy upper gravity hero

    */

}