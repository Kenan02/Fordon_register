#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>



typedef struct Search
{
  char s_marke[20];
  char s_name[20];
} search;

typedef struct Person
{
  char name[20];
  int age;
} person;

typedef struct Fordon
{
  char marke[20];
  char fordontyp[20];
  char regNr[7];
  struct Person owner;

} fordon;

void searchPos(fordon *fordonList, int arraysize)
{
  int plats, i;
  printf("Skriv in numret på din bil i listan\n");
  scanf("%d", &plats);
  i = plats - 1;

  if (i + 1 > arraysize || i + 1 <= 0)
  {
    printf("Prova igen\n");
  }
  else
  {

    printf("%s %s %s %s %d\n", fordonList[i].fordontyp, fordonList[i].marke, fordonList[i].regNr, fordonList[i].owner.name, fordonList[i].owner.age);
  }
}

void searchCar(fordon *fordonList, fordon *sList, int arraySize)
{
  int i;
  int result;
  printf("För att söka, ange märke\n");

  scanf("%s %s", sList[0].marke, sList[0].owner.name);

  for (i = 0; i < arraySize; i++)
  {
    result = strcmp(sList[0].marke, fordonList[i].marke) + strcmp(sList[0].owner.name, fordonList[i].owner.name);
    if (result == 0)
    {
      printf("%s %s %s %s %d\n", fordonList[i].fordontyp, fordonList[i].marke, fordonList[i].regNr, fordonList[i].owner.name, fordonList[i].owner.age);
      break;
    }
  }
}

void printList(fordon *fordonList, int arraySize)
{
  int i;
  for (i = 0; i < arraySize; i++)
  {
    printf("%s %s %s %s %d\n", fordonList[i].fordontyp, fordonList[i].marke, fordonList[i].regNr, fordonList[i].owner.name, fordonList[i].owner.age);
  }
}

void addCar(fordon *fordonList, int i)
{

  puts("Ange fordontyp, Märke, Reg nummer, Namn och ålder");
  scanf("%s %s %s %s %d", fordonList[i].fordontyp, fordonList[i].marke, fordonList[i].regNr, fordonList[i].owner.name, &fordonList[i].owner.age);
}

void vektorFile(fordon *fordonList, int arraySize)
{
  FILE *skriv;

  skriv = fopen("register.txt", "w");

  for (int i = 0; i < arraySize; i++)
  {
    fprintf(skriv, "%s %s %s %s %d\n", fordonList[i].fordontyp, fordonList[i].marke, fordonList[i].regNr, fordonList[i].owner.name, fordonList[i].owner.age);
  }
  fclose(skriv);
}

void bSort(fordon *fordonList, int arraysize)
{

  fordon tmp;

  for (int i = 0; i < arraysize - 1; i++)
  {
    for (int j = 0; j < arraysize - 1; j++)
    {
      if (fordonList[j].marke[0] > fordonList[j + 1].marke[0])
      {
        tmp = fordonList[j];
        fordonList[j] = fordonList[j + 1];
        fordonList[j + 1] = tmp;
      }
    }
  }
}

void removeCar(fordon *fordonList, int arraySize)
{
  int plats, i, j;
  int start;
start:
  printf("Skriv in numret på den bil du vill radera i listan! \n");
  scanf("%d", &plats);
  i = plats - 1;

  fordonList[i] = fordonList[0];
  fordonList[0] = fordonList[i];

  for (j = 1; j < arraySize; j++)
  {
    if (i + 1 > arraySize || i + 1 <= 0)
    {
      printf("Fel inmatning, prova igen\n");
      goto start;
    }
    else
    {

      fordonList[j - 1] = fordonList[j];
    }
  }
}

int main()
{
  bool end = false;
  int val, i;
  fordon sList[10];
  fordon fordonList[10];
  
  int arraySize = 0;

  FILE *las = fopen("register.txt", "r");
  if (las == NULL)
  {
    printf("Fil finns inte\n");
  }
  else
  {
    for (i = 0; i < 10; i++)
    {
      arraySize;
      fscanf(las, "%s %s %s %s %d", fordonList[i].fordontyp, fordonList[i].marke, fordonList[i].regNr, fordonList[i].owner.name, &fordonList[i].owner.age);
      if (feof(las))
        break;
      arraySize += 1;
    }
    fclose(las);
  }

  while (!end)
  {
    puts("1.Lägg till ett fordon");
    puts("2.Ta bort ett fordon");
    puts("3.Sortering efter bilmärke");
    puts("4.Skriv ut information om ett fordon");
    puts("5.Skriv ut hela fordonsregistret");
    puts("6.Avsluta");
    scanf("%d", &val);

    switch (val)
    {

    case 1:
      if (arraySize == 10)
      {
        printf("Registret är fullt \n");
        break;
      }

      addCar(fordonList, arraySize);
      arraySize = arraySize + 1;
      break;

    case 2:
      removeCar(fordonList, arraySize);
      arraySize = arraySize - 1;
      break;

    case 3:
      bSort(fordonList, arraySize);
      break;

    case 4:
      searchPos(fordonList, arraySize);
      break;

    case 5:
      printList(fordonList, arraySize);
      break;

    case 6:
      vektorFile(fordonList, arraySize);
      end = true;
      break;
    }
  }
  return 0;
}
