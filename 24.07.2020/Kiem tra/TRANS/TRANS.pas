uses crt,math;
type
        arr = array[1..4] of longint;
var
        fi,fo: text;
        TH: arr;
        n: longint;
        a,b: integer;
function Min(a: arr): longint;
        var
                i: byte;
                temp: longint;
        begin
                temp:=1;
                for i:= 2 to 4 do
                        begin
                                if a[i]<a[temp] then
                                        temp:=i;
                        end;
                Min:= temp;
        end;
procedure Traffic(var TH: arr; n: longint; a,b: integer);
        begin
                TH[1]:= ceil(n/50)*a;
                TH[2]:= ceil(n/4)*b;
                TH[3]:= (n div 50)*a + ceil((n - (n div 50))/4)*b;
                TH[4]:= (n div 4)*a + ceil((n - (n div 4))/50)*b;
                if Min(TH) = 1 then
                        begin
                                Writeln(fo, ceil(n/50),' ',0);
                        end
                else if Min(TH) = 2 then
                        begin
                                Writeln(fo, 0,' ',ceil(n/4));
                        end
                else if Min(TH) = 3 then
                        begin
                                Writeln(fo, n div 50, ' ', ceil((n - (n div 50))/4));
                        end
                else
                        begin
                                Writeln(fo, n div 4, ' ', ceil((n - (n div 4))/50));
                        end;
        end;
BEGIN
        assign(fi, 'TRANS.INP');
        assign(fo, 'TRANS.OUT');
        reset(fi);
        rewrite(fo);
        Readln(fi, n,a,b);
        Traffic(TH,n,a,b);
        close(fi);
        close(fo);
END.