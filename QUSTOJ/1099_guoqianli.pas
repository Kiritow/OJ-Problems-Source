var a,b:array[1..10000]of longint;
c,d:array[1..10000]of boolean;
n,m,i,j,k,max:longint;
begin
max:=0;
fillchar(c,sizeof(c),true);
d:=c;
readln(n,m);
for i:=1 to n do readln(a[i]);
for i:=1 to m do readln(b[i]);
for i:=1 to n-1 do
for j:=i+1 to n do
if a[i]<a[j] then begin k:=a[i]; a[i]:=a[j]; a[j]:=k; end; for i:=1 to m-1 do for j:=i+1 to m do if b[i]<b[j] then begin k:=b[i]; b[i]:=b[j]; b[j]:=k; end; for i:=1 to n do for j:=1 to m do if b[j]>0 then
if (a[i]>b[j])and(c[i])and(d[j])then
begin
inc(max);
c[i]:=false;
d[j]:=false;
break;
end;
writeln(m-max);
end.
