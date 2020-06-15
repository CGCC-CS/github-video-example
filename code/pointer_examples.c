#include<stdio.h>

/* Pointer examples:
 *   - introduction
 *   - struct pointers
 *   - array pointers
 *   - pointer & array function parameters
 *   - void pointers
 *   - double pointers
 */

#define LEN 10

typedef struct {
    int num;
    char name[LEN];
} mystruct_t;

/* We are assuming str is at least 6 characters */
void print_string_array(char str[]) {
    printf("print_string_array:\n");
    printf("  %c %c %c\n", str[0], str[1], str[2]);
    printf("  %c %c %c\n", *(str+3), *(str+4), *(str+5));
}
void print_string_ptr(char * str) {
    printf("print_string_array:\n");
    printf("  %c %c %c\n", *str, *(str+1), *(str+2));
    printf("  %c %c %c\n", str[3], str[4], str[5]);
}

void swap(void ** into, void * what) {
    *into = what;
}

int main(void) {

    int abc = 100;
    int * iptr = &abc;

    int nums[LEN];
    int * ptr = nums;   /* ptr points to the nums array */

    void * vptr;

    char hello[] = "Hello, World!";
    char * alpha = "ABCDEFGHIJK";
    int ii;

    mystruct_t info = {15, "Bob"};
    mystruct_t * sptr;  /* sptr points to nothing yet! */
    sptr = &info;       /* sptr points to info */

    for(ii=0;ii<LEN;ii++) {
        nums[ii]=ii*11;
    }
    
    /* Go through array with a pointer */
    for(ii=0;ii<LEN;ii++) {
        printf("nums[ii]=%d at %p\n", *(ptr+ii), (void*) (ptr+ii));
    }

    printf("\n");
    printf("info[%p]:  %d %s\n", (void*) &info, info.num, info.name);
    printf("sptr[%p]:  %d %s at %p\n", (void*) &sptr, sptr->num, sptr->name, (void*) sptr);

    printf("\n");
    printf("variable, & vs *\n");
    printf("abc=%d  &abc=%p\n", abc, (void*) &abc);
    printf("iptr=%p  &iptr=%p  *iptr=%d\n", (void*) iptr, (void*) &iptr, *iptr);

    print_string_array(hello);
    print_string_ptr(hello);

    print_string_array(alpha);
    print_string_ptr(alpha);

    vptr = iptr;
    printf("vptr=iptr : %d\n", *((int *) vptr));
    vptr = sptr;
    printf("vptr=sptr : %d %s\n", ((mystruct_t *) vptr)->num, ((mystruct_t *) vptr)->name);
    vptr = hello;
    printf("vptr=hello (vptr): %s\n", ((char *) vptr));
    printf("vptr=hello (*vptr): %c\n", *((char *) vptr));

    
    swap(&vptr, alpha);
    printf("swap(vptr,alpha) (vptr): %s\n", ((char *) alpha));
    swap(&vptr, sptr);
    printf("swap(vptr,sptr) : %d %s\n", ((mystruct_t *) vptr)->num, ((mystruct_t *) vptr)->name);


    return 0;
}






