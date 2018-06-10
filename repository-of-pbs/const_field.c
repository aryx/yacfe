// can not have const_field ? but sometimes would like to say
// that after a certain time, this field is constant


  struct sunos_ttysize {
!!	int st_lines;   /* Lines on the terminal */
  	int st_columns; /* Columns on the terminal */
  };
