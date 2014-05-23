#include <stdio.h>


int main(int argc, char** argv) {
   int inputPipes[2] = {-1,-1}; // input pipes
   int outputPipes[2] = {-1,-1}; // output pipes
   int timeMax = 0; // max time value
   int value = 0, fixed = 0; // current value and whether or not it is fixed
   int uid; // unique id for this cell

   //testing stuff
   //testing more stuff
   //even more testing

   argv++;
   while(*argv) {
      char* arg = *argv;
      int param;
      switch(*arg) {  
         case 'S':
            sscanf(arg, "S%d", &timeMax);
            break;

         case 'O':
            sscanf(arg, "O%d", &param);
            if(param<=12) {
               if(inputPipes[0]<0)
                  inputPipes[0] = param;
               else if(inputPipes[1]<0)
                  inputPipes[1] = param;
            }
            break;

         case 'I':
            sscanf(arg, "I%d", &param);
            if(param<=12) {
               if(outputPipes[0]<0)
                  outputPipes[0] = param;
               else if(outputPipes[1]<0)
                  outputPipes[1] = param;
            }
            break;

         case 'V':
            sscanf(arg, "V%d", &value);
            fixed = 1;
            break;

         case 'D':
            sscanf(arg, "D%d", &uid);
            break;

         default:
            break;
      }

      argv++;
   }

   printf("inputPipes[0] = %d  inputPipes[1] = %d\n", inputPipes[0], inputPipes[1]);
   printf("outputPipes[0] = %d  outputPipes[1] = %d\n", outputPipes[0], outputPipes[1]);
   printf("timeMax = %d\n", timeMax);
   printf("value = %d  fixed = %d\n", value, fixed);
   printf("uid = %d\n", uid);

   return 0;
}
