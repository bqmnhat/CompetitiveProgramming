for /l %%x in (1, 1, 22) do (
   echo %%x
   mkdir Test%%x
   copy %%x.in Test%%x\
   copy %%x.ans Test%%x\
   cd Test%%x\
   rename %%x.in WHEELS.inp
   rename %%x.ans WHEELS.out
   cd ..
   del %%x.in
   del %%x.ans
)