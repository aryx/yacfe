char *text = "mystring $Id: compare1.c,v 1.1 2007/03/08 13:47:50 pad Exp $ str2 $Date: 2007/03/08 13:47:50 $ str3 ";
#define DRIVER_VERSION         "a $Id: compare1.c,v 1.1 2007/03/08 13:47:50 pad Exp $"


#define foo 1

struct sht v = { 
  .field1 = f1,
  .field2 = f2
};

void main(int i) 
{
  foo(); 
  /* here is a comment */

#if 0
  //babar();
  bar();
#endif

}


static struct pcmcia_driver mgslpc_driver = {.owner = THIS_MODULE, .drv = {.name = "synclink_cs"}, .attach = mgslpc_attach, .detach = mgslpc_detach};

 
static int __init synclink_cs_init(void)
{int error;
}

