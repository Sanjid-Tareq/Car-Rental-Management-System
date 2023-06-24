#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dos.h>


void recursiveLoading(int progress) {
    //Loading bar
    // Base case: stop recursion when progress reaches 100%
    if (progress > 100) {
        return;
    }

    // Code to be executed in each iteration
    printf("Project is Loading [%d%%]", progress);
    fflush(stdout);
    usleep(10000);
    printf("\r");

    // Recursive call to the function with an incremented progress value
    recursiveLoading(progress + 1);
}



void splash (void)
{

    system("cls");
    printf("...................Project Loading Complete!..........\n\n\n");
    sleep(1);
    printf("-------------Press any key to continue-------------\n");
    getchar();
    system("cls");


char ris[]=" \n"


"                                                           __      __       .__                                ___________________                                                            \n"
"                                                          /  \\    /  \\ ____ |  |   ____  ____   _____   ____   \\__    ___/\\_____  \\                                                           \n"
"                                                          \\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\    |    |    /   |   \\                                                          \n"
"                                                           \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/    |    |   /    |    \\                                                         \n"
"                                                            \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >   |____|   \\_______  /                                                         \n"
"                                                                 \\/       \\/          \\/            \\/     \\/                     \\/                                                          \n"
"_________                __________               __         .__        _____                                                             __      _________               __                   \n"
"\\_   ___ \\_____ _______  \\______   \\ ____   _____/  |______  |  |      /     \\ _____    ____ _____     ____   ____   _____   ____   _____/  |_   /   _____/__.__. _______/  |_  ____   _____  \n"
"/    \\  \\/\\__  \\\\_  __ \\  |       _// __ \\ /    \\   __\\__  \\ |  |     /  \\ /  \\\\__  \\  /    \\\\__  \\   / ___\\_/ __ \\/     \\\\_/ __ \\/    \\   __\\  \\_____  <   |  |/  ___/\\   __\\/ __ \\ /     \\ \n"
"\\     \\____/ __ \\|  | \\/  |    |   \\  ___/|   |  \\  |  / __ \\|  |__  /    Y    \\/ __ \\|   |  \\/ __ \\_/ /_/  >  ___/|  Y Y  \\\\  ___/|   |  \\  |    /        \\___  |\\___ \\  |  | \\  ___/|  Y Y  \\\n"
" \\______  (____  /__|     |____|_  /\\___  >___|  /__| (____  /____/  \\____|__  (____  /___|  (____  /\\___  / \\___  >__|_|  /\\___  >___|  /__|   /_______  / ____/____  > |__|  \\___  >__|_|  /\n"
"        \\/     \\/                \\/     \\/     \\/          \\/                \\/     \\/     \\/     \\/     \\/      \\/      \\/     \\/     \\/               \\/\\/         \\/            \\/      \\/";



  // Showing Ascii text
    for(int i=0;i<strlen(ris);i++)
    {

    printf("%c",ris[i]);
    if(ris[i]=='\n')
    {
        usleep(353535);
    }

   }
   printf("\n\n\n\n\n");
   sleep(1);

   FILE *sp;
   sp=fopen("image.txt","r");
   char img[1000];

   //reading image from text file

   while(!feof(sp))
   {
       fgets(img,sizeof(sp),sp);
       printf("%s",img);

   }
printf("\n\n\n\n");
   fclose(sp);
   printf("...............Press any key to continue............\n");
   getchar();




}
