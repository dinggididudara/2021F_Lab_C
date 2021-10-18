 int office = 1; /*initialize*/
    int subscriber = 1; /*initialize*/
    int num = 1;
    while(1)
    {
        printf("Enter a phone number: ");
        scanf("%d", &num); /*scanning numbers*/

        if (num == 0) /*if input is zero*/
        {
            return 0;
        } /*if end*/
        else if (num > 0)
        {
            if(num > 0 && num < 100000) /*if less than digits*/
            {
                printf("Invalid phone number: too few digits\n");
            }
            else if (num > 9999999) /*if over 7 digits*/
            {
                printf("Invalid phone number: too many digits\n");
            }
            else if(num < 10000000 && num > 199999) /*if within valid range = 7 digits*/
            {
                printf("%d-%d\n",(num/10000),(num-(num/10000*10000))); /*format 000-0000*/
            } /*else-if end*/
        } /*else-if end*/
    } /*while end*/