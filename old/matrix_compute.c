#include "matrix.h"
#include "string.h"
#define LENGTH 256

void print_m(m_double *m){
   for(int i=0;i<(int)m->row;i++){
      for(int j=0;j<(int)m->col;j++){
         printf(" %g ", m->content[i][j]);
      }
      printf("\n");
   }
}

m_double* read_file(char* filename){
   char line[LENGTH];
   FILE *fp;
   m_double *m = NULL;

   fp = fopen(filename,"r");
   if (!fp) {
      fprintf(stderr,"file not found: %s \n", filename);
      return NULL;
   }

   int cnt = 0;
   while ((fgets(line,LENGTH,fp)) != NULL )
   {
      cnt++;
   }
      rewind(fp);


   char sep[] = " ";
   int nb_fields = 2;
   int max_line;
   cnt = 0;

   while ((fgets(line, LENGTH, fp)) != NULL )
    {
      char *token;
      token = strtok(line, sep);
      int cnt_col = 0;
      char *fields[nb_fields];
      while (token)
       {

         fields[cnt_col] = token;
         token = strtok(NULL, sep);
         cnt_col++;
      }
      if(cnt == 0){
         max_line = atoi(fields[0]);
         nb_fields = atoi(fields[1]);
         m = matrix_alloc(max_line,nb_fields);
      }else{
         if(cnt>max_line){
            break;
         }
         for(int i=0;i<nb_fields;i++)
            m->content[cnt-1][i] = atof(fields[i]);
      }
      cnt++;
   }

   // Close the file
   fclose(fp);
   return m;
}

m_double* all_operations(char* oper, m_double *m1, m_double *m2){
   if(strcmp(oper,"mult") == 0)
      {
        if (m1->row==m2->col) {
          return matrix_mult(m1,m2);
        } else {
          return NULL;
        }
      }
   if(strcmp(oper,"add") == 0)
      {
         return matrix_add(m1,m2);
      }
   if(strcmp(oper,"transpose") == 0)
      {
         return matrix_transpose(m1);
      }
   return NULL;
}


int main(int argc,char** argv){
   m_double *first = NULL;
   m_double *second = NULL;

   if (argc > 4) {
      printf("Too man arguments");
      return EXIT_FAILURE;
   }
   first = read_file(argv[2]);

   if(argc > 3){
      second = read_file(argv[3]);
   }
   m_double *matrix_res = NULL;
   matrix_res = all_operations(argv[1],first,second);

   if(matrix_res)
      {print_m(matrix_res);
      }
   matrix_free(matrix_res);
   matrix_free(first);
   matrix_free(second);
}
