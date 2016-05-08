var
i,j,n,min,max,x,y:longint;
s:Array[1..10000000]of shortint;
function long(x,k:longint):longint;
begin
long:=0;
while x>0 do
begin
inc(long);
x:=x div k;
end;
end;
function power(a,b:longint):longint;
var
t:integer;
begin
power:=1;
for t:=1 to b do
power:=power*a;
end;
function num(a,b,l,k:longint):longint;
var
i:longint;
begin
num:=0;
for i:=1 to l do
if odd(i)
then inc(num, a*trunc(power(k,l-i)) )
else inc(num, b*trunc(power(k,l-i)) );
end;
procedure all(k:longint);
var
i,j,l,l1,l2,m:longint;
begin
l1:=long(min,k);
l2:=long(max,k);
for i:=1 to k-1 do
for j:=0 to k-1 do
if i<>j then
begin
for l:=l1 to l2 do
begin
m:=num(i,j,l,k);
if (m<=max)and(m>=min) then
inc(s[m]);
end;
end;
end;
begin
readln(x,y,min,max,n);
fillchar(s,sizeof(s),0);
for i:=x to y do all(i);
for i:=min to max do
if s[i]=n then writeln(i);
end.
