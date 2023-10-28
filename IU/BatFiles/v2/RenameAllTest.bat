for /l %%x in (1, 1, 22) do (
   echo %%x
   cd Test%%x\
   rename %%x.inp SELLINGCPUs.inp
   rename %%x.out SELLINGCPUs.out
   cd ..
)