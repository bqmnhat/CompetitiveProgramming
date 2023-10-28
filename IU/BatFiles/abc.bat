for /l %%x in (2, 1, 22) do (
   echo %%x
   copy %%x.inp Test%%x\
   copy %%x.out Test%%x\
)