# primelib
 C++ library focused on prime numbers and number theory.

## usage

> ```cpp
> #include <iostream>
> #include "primelib.h"
> 
> int main() {
>   primelib* pl = new primelib(); //initialize library.
>   
>   pl->atkins(n); //populate set with primes. using sieve of atkins.
> 
>   //output primes
>   for (uint64_t prime : pl->oprimes) {
>     std::cout << prime << std::endl;
>   }
> 
>   return 0;
> }
> ```

## showcase
> ![bruns_constant](https://github.com/Kobley/primelib/blob/main/media/b2.gif)


## this project is licensed with the GNU GPLv3 license.
> ### below is a summary.

The GNU General Public License version 3 (GPLv3) is a free software license designed to ensure that software remains free and open for all users. It allows anyone to use, study, modify, and distribute the software, provided that any distributed versions, including modified ones, are also licensed under GPLv3, ensuring that derivative works remain free. The license includes protections against patent claims and prohibits the use of hardware restrictions to prevent users from running modified versions of the software. This strong copyleft license ensures that the freedoms granted by the original software are preserved in all copies and derivative works.
