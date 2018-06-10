Item*
Create_func_as_wkb::create(THD *thd, Item *arg1)
{
   return new (thd->mem_root) Item_func_as_wkb(arg1);
}
