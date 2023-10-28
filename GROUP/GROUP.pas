const fi='GROUP.INP';
      fo='GROUP.OUT';
var n,m,i: integer;
    a: array[1..210] of longint;
    f: array[1..210] of longint;
//
procedure sort;
var i,j: integer;
    temp: longint;
begin
      for i:=1 to n-1 do
            for j:=i+1 to n do if a[i]>a[j] then begin
                  temp:=a[i];
                  a[i]:=a[j];
                  a[j]:=temp;
            end;
end;
//
procedure xuli;
var i,j,k: integer;
    temp: longint;
begin
      fillchar(f,sizeof(f),0);
      for i:=1 to n do f[i]:=a[n]-a[i];
      for k:=2 to m do begin
            for i:=1 to n do begin
                  for j:=i to n do begin
                        temp:=(a[j]-a[i])+f[j+1];
                        if temp<f[i] then f[i]:=temp;
                  end;
            end;
      end;
      writeln(f[1]);
end;
//
begin
      assign(input,fi); reset(input);
      assign(output,fo); rewrite(output);
      readln(n,m);
      for i:=1 to n do read(a[i]);
      sort;
      xuli;
      close(input); close(output);
end.