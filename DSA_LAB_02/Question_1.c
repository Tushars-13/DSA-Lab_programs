//  Ques_1. Write the program using recursive function: (i). Find sum of first N numbers.
//  (ii). Find the sum of digits of a number. (iii). Find an (iv). Find prime factors of
//  a number. (v). Find GCD of a number. (vi). Print Fibonacci series

#include<stdio.h>

int sum_of_first_N_numbers(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n + sum_of_first_N_numbers(n-1);
    }
}

int sum_of_digits(int n){
    if(n==0){
        return 0;
    }
    else{
        return(n%10) + sum_of_digits(n/10);
    }

}

int find_nth_term(int a, int d, int n){
    if (n == 1) {
        return a;
    }
    return d + find_nth_term(a, d, n - 1);
}

int prime_factors(int n){
    int i;
    for(i=2; i<=n; i++){
        if(n%i == 0){
            printf("%d", i);
            prime_factors(n/i);
        }
    }
}

int gcd(int a, int b) {
            if (b == 0) {
                return a;
            }
            return gcd(b, a % b);
        }

int fibonacci(int n)
{
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main()
{   printf("\nEnter your choice for the menu driven program.\n");
    printf("1. Find sum of first N numbers.\n");
    printf("2. Find the sum of digits of a number.\n");
    printf("3. Find the n'th term in an AP.\n");
    printf("4. Find prime factors of a number.\n");
    printf("5. Find GCD of a number.\n");
    printf("6. Print Fibonacci series.\n");
    printf("99. Exit the program.\n");

    int choice, N, ans;
   
    while(choice!=99){
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
        
    switch (choice)
    {
    case 1:
        printf("\nEnter the value of N : ");
        scanf("%d",&N);
        ans = sum_of_first_N_numbers(N);
        printf("Result = %d",ans);
        printf("\n");
        break;
    case 2:
        printf("\n"); 
        printf("\nEnter the value of N : ");
        scanf("%d",&N);
        ans = sum_of_digits(N);
        printf("Result = %d",ans);
        printf("\n");
        break;
    case 3:
        printf("\n");
        printf("Finding the nth term in an AP.\n");
        int a, d, n;
        printf("Enter the first term (a): ");
        scanf("%d", &a);
        printf("\nEnter the common difference (d): ");
        scanf("%d", &d);
        printf("\nEnter the number of terms (n): ");
        scanf("%d", &n);
        ans = find_nth_term(a,d,n);
        printf("The %dth term in the AP is %d\n", n, ans);
        printf("\n");
        break;

    case 4:
        printf("\nEnter the value of N : ");
        scanf("%d",&N);
        printf("Prime factors of %d are: ", N);
        prime_factors(N);
        printf("\n");
        break;

     case 5:
        printf("\nEnter two numbers to find GCD: ");
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        ans = gcd(num1, num2);
        printf("GCD of %d and %d is %d\n", num1, num2, ans);
        printf("\n");
        break;

    case 6:
        printf("\nEnter the number of terms in the Fibonacci series: ");
            scanf("%d", &N);
            printf("Fibonacci series: ");
            for (int i = 0; i < N; i++) {
                printf("%d ", fibonacci(i));
            }
            printf("\n");
            break;
    case 99:
        printf("\nExiting the program.\n");
        break;
    default:
        printf("\nEnter a valid choice.\n");
        break;
    }}
}