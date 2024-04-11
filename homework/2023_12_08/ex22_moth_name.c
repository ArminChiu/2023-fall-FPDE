char *month_name(int n){
    static char *name[]={
        "Illegal month",
        "january","February","March",
        "April","May","June",
        "July","August","September",
        "October","November","December"
    };
    return (n<1||n>12)?name[0]:name[n];
}