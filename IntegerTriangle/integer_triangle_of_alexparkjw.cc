#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE		30000
#define MAX_OFFSET			10
#define MAX_INPUTS			500

char Buffer[MAX_BUFFER_SIZE + MAX_OFFSET];
char *pPtr = Buffer;
char *pEnd = Buffer;

int more = 1;

int Result1[MAX_INPUTS];
int Result2[MAX_INPUTS];

int GetNumber();
int PrintNumber(int num);

int main(void) {
  register int num, max;
  int *pCur = Result1, *pNext = Result2;

  size_t lines = GetNumber();
  max = GetNumber();
  pCur[0] = max;

  for (int j = 1; j < lines; j++)	{
    for (int i = 0; i < j; i++) {
      if (i == 0)
	pNext[i] = pCur[i] + GetNumber();
      else
	pNext[i] = (pNext[i] > pCur[i] + num) ? pNext[i] : pCur[i] + num;

      num = GetNumber();
      pNext[i + 1] = pCur[i] + num;

      if (max < pNext[i])
	max = pNext[i];
      if (max < pNext[i+1])
	max = pNext[i + 1];
    }

    if (pCur == Result1) {
      pCur = Result2;
      pNext = Result1;
    }
    else {
      pCur = Result1;
      pNext = Result2;
    }
  }

  PrintNumber(max);
  return 0;
}

int PrintNumber(int num) {
  char buf[64];
  sprintf(buf, "%d", num);
  return write(1, buf, strlen(buf));
}

int ReadData() {
  int size, offset;
  offset = pEnd - pPtr;
  if (offset > 0 && offset < MAX_OFFSET)
    memcpy(Buffer, pPtr, offset);
  size = read(0, Buffer + offset, MAX_BUFFER_SIZE);
  pPtr = Buffer;
  pEnd = Buffer + offset + size;
  more = (size != 0)? 1 : 0;
  return size;
}

int GetNumber() {
  int num = 0;
  if (more == 1 && (pEnd - pPtr < MAX_OFFSET))
    ReadData();
  while (pPtr < pEnd && (*pPtr < '0' || *pPtr > '9'))
    pPtr++;
  while (pPtr < pEnd && (*pPtr >= '0' && *pPtr <= '9'))
    num = (num * 10) + (*pPtr++ - '0');
  return num;
}

