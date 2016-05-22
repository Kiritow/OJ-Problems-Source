program num;
var s:array[0..10000000] of integer;
l,a,b,c,d,t,h,w,p:int64;
i,j,m,n:longint;
begin
readln(a,b,c,d,t);
for i:=a to b do
begin
for j:=1 to i-1 do inc(s[j]);
for m:=0 to i-1 do
for n:=0 to i-1 do
if m<>n then
begin
w:=n;
p:=1;
l:=1;
while w<=d do
begin
l:=l+1;p:=p*i;
if l mod 2=0 then
begin
if m<>0 then
begin
w:=w+p*m;
if w<=d then s[w]:=s[w]+1;
end;
end
else
begin
if n<>0 then
begin
w:=w+p*n;
if w<=d then s[w]:=s[w]+1;
end;
end;
end;
end;
end;
for i:=c to d do if s[i]=t then writeln(i);
end.
