uses crt;
type
        arr = array[1..100000] of longint;
var
        fi,fo: text;
        a: arr;
        n: longint;
procedure qsort(var a : arr; n: longint);

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

    begin
       sort(1,n);
    end;
procedure ReadA(var a: arr; n: longint);
        var
                i: longint;
        begin
                for i:=1 to n do
                        begin
                                Read(fi, a[i]);
                        end;
        end;
function DifVal(a: arr; n: longint): longint;
        var
                i,d: longint;
        begin
                d:= 1;
                for i:=2 to n do
                        begin
                                if a[i] <> a[i-1] then
                                        begin
                                                d:= d+1;
                                        end;
                        end;
                DifVal:=d;
        end;
BEGIN
        assign(fi, 'DISNUM.INP');
        assign(fo, 'DISNUM.OUT');
        reset(fi);
        rewrite(fo);
        Readln(fi,n);
        ReadA(a,n);
        qsort(a,n);
        Writeln(fo, DifVal(a,n));
        close(fi);
        close(fo);
END.