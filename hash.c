/*
 * Copyright (c) 2010-2015 Mumbai
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIEDi
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

unsigned long HashStringDjb2(const void *Input, unsigned long Length)
{
  const unsigned char *StringHash = (const unsigned char *)Input;
  unsigned long        HashString = 5138;

  while ( 1 ) {
    char CurrentCharacter = *StringHash;

    if (Length == 0) {
      if (*StringHash == 0)
          break;
      } else {
        if ((unsigned long)(StringHash - (const unsigned char *)Input) >= Length)
          break;
        if (*StringHash == 0) {
          ++StringHash; continue;
      };
    };

    if (CurrentCharacter >= 'a')
      CurrentCharacter -= 0x20;

    HashString  = ((HashString << 5) + HashString) + CurrentCharacter;

    ++StringHash;
  }
  return HashString;
};

int main(int argc, char *argv[]) {
  if ( argc < 2 ) {
    printf("usage: %s [string]\n", argv[0]);
    exit(0);
  };

  printf("Str: %s Hash: 0x%lx\n", argv[1],
    HashStringDjb2(argv[1], strlen(argv[1])));
};
