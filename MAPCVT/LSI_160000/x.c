main()
{
  char x[7];
  strcpy ( x, "00D6DC");
  printf( "Value is %d\n", strtol ( x, '\0' , 16 ) );
}
